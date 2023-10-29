#include "SuperComputer.h"

#include <iostream>
#include "Config.h"

namespace Dungeon
{
	SuperComputer::SuperComputer() :
		isRunning(SDL_TRUE),
		mComputerData(nullptr),
		mMakeThreads(nullptr), mUseThreads(nullptr)
	{
		//动态申请内存
		this->mComputerData = (ComputerData *)malloc(sizeof(ComputerData));
		if (mComputerData)
		{
			mComputerData->amount = 0;
			mComputerData->audioList = new list<AudioInfo *>();
			SDL_Log("Create audioList:%p", mComputerData->audioList);
		}
		this->mMutex = SDL_CreateMutex();//创建互斥量
		if (!mMutex)
		{
			SDL_Log("Create Mutex Failure");
		}

		this->mMakeCond = SDL_CreateCond();//创建条件变量
		if (!mMakeCond)
		{
			SDL_Log("Create Make Cond Failure");
		}
		this->mUseCond = SDL_CreateCond();//创建条件变量
		if (!mUseCond)
		{
			SDL_Log("Create Use Cond Failure");
		}
	}

	SuperComputer::~SuperComputer()
	{
		isRunning = SDL_FALSE;
		if (mComputerData)
		{
			if (mComputerData->audioList)
			{
				list<AudioInfo *> *audioList = mComputerData->audioList;
				//vector<AudioInfo *>::iterator iter = audioList->begin();//获取迭代器
				//while (iter != audioList->end())
				//{
				//	AudioInfo *audioInfo = *iter;//获取元素
				//	free(audioInfo->pcm);
				//	free(audioInfo);
				//	audioInfo = nullptr;
				//	iter++;
				//}

				list<AudioInfo *>::iterator iter;//获取迭代器
				for (iter = audioList->begin(); iter != audioList->end(); iter++)
				{
					AudioInfo *audioInfo = *iter;//获取元素
					/*delete audioInfo;
					audioInfo = nullptr;*/
					free(audioInfo->pcm);
					free(audioInfo);
					audioInfo = nullptr;
				}
			}
			if (mComputerData->srcFile)
			{
				fclose(mComputerData->srcFile);
			}
			if (mComputerData->srcFileName)
			{
				free(mComputerData->srcFileName);
			}

			if (mComputerData->destFile)
			{
				fclose(mComputerData->destFile);
			}
			if (mComputerData->destFileName)
			{
				free(mComputerData->destFileName);
			}
		}
		if (mMakeThreads)
		{
			delete[] mMakeThreads;//释放二维数组
			mMakeThreads = nullptr;
		}
		if (mUseThreads)
		{
			delete[] mUseThreads;//释放二维数组
			mUseThreads = nullptr;
		}
		if (mMutex)
		{
			SDL_DestroyMutex(mMutex);//销毁互斥量,释放互斥锁资源
		}
		if (mMakeCond)
		{
			SDL_DestroyCond(mMakeCond);//销毁条件变量,释放条件变量资源
		}
		if (mUseCond)
		{
			SDL_DestroyCond(mUseCond);//销毁条件变量,释放条件变量资源
		}

	}

	/*
	* 开启多线程
	*/
	SDL_bool SuperComputer::Start(const char *srcFileName, const char *destFileName,
		SDL_bool save, AudioPlayer *audioPlayer, OnAudioCallback onAudioCallback)
	{
		//PCM_1_FILE_NAME
		//PCM_2_FILE_NAME
		//PCM_3_FILE_NAME
		//MP3_FILE_NAME
		//if (!OpenFile(PCM_2_FILE_NAME, SAVE_FILE_NAME))
		if (!OpenFile(srcFileName, destFileName))
		{
			return SDL_FALSE;
		}
		this->mComputerData->save = save;//是否保存文件
		this->mComputerData->audioPlayer = audioPlayer;//设置播放器
		this->mComputerData->AudioCallback = onAudioCallback;//设置回调函数
		//获取文件大小
		this->mComputerData->size = GetFileSize(this->mComputerData->srcFile);
		this->mComputerData->pos = 0;

#ifdef USE_AUDIO_IN_CALLBACK
		UseAudio();//多线程消费音频
#endif // USE_AUDIO_IN_CALLBACK

		MakeAudio();//多线程生产音频
		return SDL_TRUE;
	}

	/*
	* 获取文件大小
	*/
	long SuperComputer::GetFileSize(FILE *file)
	{
		long size = -1;
		if (file)
		{
			if (fseek(file, 0L, SEEK_END) == 0)//指针移到文件末尾
			{
				size = ftell(file);
			}
			rewind(file);//指针又移到文件开头
		}
		SDL_Log("file size: %ld", size);
		return size;
	}

	SDL_bool SuperComputer::OpenFile(const char *srcFileName, const char *destFileName)
	{
		if (this->mComputerData)
		{
			mComputerData->srcFile = fopen(srcFileName, "rb");//打开要读取的文件
			if (!mComputerData->srcFile)
			{
				SDL_Log("open src file failed: %s", srcFileName);
				return SDL_FALSE;
			}
			mComputerData->srcFileName = (char *)malloc(sizeof(char) * strlen(srcFileName) + 1);
			if (!mComputerData->srcFileName)
			{
				return SDL_FALSE;
			}
			strcpy(mComputerData->srcFileName, srcFileName);//赋值文件名
			SDL_Log("open src file:%s", mComputerData->srcFileName);

			mComputerData->destFile = fopen(destFileName, "wb");//打开要保存的文件
			if (!mComputerData->destFileName)
			{
				SDL_Log("open dest file failed: %s", destFileName);
				return SDL_FALSE;
			}
			mComputerData->destFileName = (char *)malloc(sizeof(char) * strlen(destFileName) + 1);
			if (!mComputerData->destFileName)
			{
				return SDL_FALSE;
			}
			strcpy(mComputerData->destFileName, destFileName);//赋值文件名
		}
		return SDL_TRUE;
	}

	/*
	* 多线程生产音频
	*/
	void SuperComputer::MakeAudio()
	{
		mMakeThreads = new SDL_Thread * [MAKE_THREAD_SIZE];//创建二维数组
		void *userdata = (void *)this;
		for (int i = 0; i < MAKE_THREAD_SIZE; i++)
		{
			char msg[128];
			sprintf(msg, "MakeThread_%d", i);
			if (mComputerData)
			{
				mComputerData->threadName = (char *)malloc(sizeof(char) * strlen(msg) + 1);
				if (mComputerData->threadName)
				{
					strcpy(mComputerData->threadName, msg);
				}
			}
			//创建线程并立即执行
			mMakeThreads[i] = SDL_CreateThread(&MakeAudioThreadCallback, msg, userdata);
		}
	}

	/*
	* 1.使用多线程方式获取列表中的音频数据
	* 2.该函数是阻塞的
	*/
	AudioInfo *SuperComputer::GetAudio()
	{
		AudioInfo *audio = nullptr;
		SuperComputer *computer = (SuperComputer *)this;//获取主线程传递给子线程的参数
		if (computer)
		{
			SDL_Log("SuperComputer::GetAudio:: In Use Audio Thread");
			SDL_LockMutex(computer->mMutex);//加锁
			ComputerData *data = computer->mComputerData;
			list<AudioInfo *> *audioList = data->audioList;
			if (audioList)
			{
				//容器是空的,等有数据再使用
				if (audioList->empty())
				{
					const char *emptyStr = "============ Audio List Is Empty,Wait mUseCond ================";
					SDL_Log("%s", emptyStr);
					//释放mMutex锁,并阻塞在这里,等待条件变量mUseCond有信号才继续往下执行
					SDL_CondWait(computer->mUseCond, computer->mMutex);//等待有mUseCond信号,才继续使用音频
				}

				//获取列表保存的已经生产好的音频数据
				if (!audioList->empty())
				{
					audio = audioList->front();//从列表头开始获取
					audioList->pop_front();//移除列表头部元素
					if (audio)
					{
						long sn = audio->serialNumber;
						char *pcm = audio->pcm;
						long len = audio->len;
						long size = audio->size;
						long pos = audio->pos;
						SDL_bool begin = audio->begin;
						SDL_bool end = audio->end;
						SDL_Log("SuperComputer::GetAudio:: pcm audio,sn:%ld,len:%ld,pos:%ld,size:%ld,begin:%d,end:%d",
							sn, len, pos, size, begin, end);

						//把多线程读取到的音频写入到文件中
						if (data->save)
						{
							if (data->destFile && len > 0)
							{
								fwrite(pcm, 1, len, data->destFile);
							}
						}

						//把音频数据传递给播放器播放
						if (data->AudioCallback)
						{
							data->AudioCallback(data->audioPlayer, audio);
						}
						//free(audio->pcm);//释放内存
						//free(audio);
					}
				}
			}
			SDL_UnlockMutex(computer->mMutex);//解锁,一定要先释放锁,然后再发送信号
			SDL_CondSignal(computer->mMakeCond);//发送信号mMakeCond给生产线程,可以生产音频了
		}
		return audio;
	}

	/*
	* 多线程消费音频
	*/
	void SuperComputer::UseAudio()
	{
		mUseThreads = new SDL_Thread * [USE_THREAD_SIZE];//创建二维数组
		void *userdata = (void *)this;
		for (int i = 0; i < USE_THREAD_SIZE; i++)
		{
			char msg[128];
			sprintf(msg, "UseThread_%d", i);
			if (mComputerData)
			{
				mComputerData->threadName = (char *)malloc(sizeof(char) * strlen(msg) + 1);
				if (mComputerData->threadName)
				{
					strcpy(mComputerData->threadName, msg);
				}
			}
			//创建线程并立即执行
			mUseThreads[i] = SDL_CreateThread(&UseAudioThreadCallback, msg, userdata);
		}
	}

	/*
	* 多线程生产音频: 线程回调函数
	*/
	int SuperComputer::MakeAudioThreadCallback(void *userdata)
	{
		SuperComputer *computer = (SuperComputer *)userdata;//获取主线程传递给子线程的参数
		if (computer)
		{
			SDL_Log("Start In Make Audio Thread:");

			while (computer->isRunning == SDL_TRUE)
			{
				SDL_LockMutex(computer->mMutex);//加锁
				ComputerData *data = computer->mComputerData;
				list<AudioInfo *> *audioList = data->audioList;
				if (audioList)
				{
					//容器满了,等容器有空间了再继续往下执行
					if (!audioList->empty() && audioList->size() >= MAX_SIZE)
					{
						const char *fullStr = "============ Audio List Is Full,Wait mMakeCond ================";
						SDL_Log("%s", fullStr);
						//释放mMutex锁,并阻塞在这里,等待条件变量mMakeCond有信号才继续往下执行
						SDL_CondWait(computer->mMakeCond, computer->mMutex);//等待有mMakeCond信号,才继续生产音频
					}

					//模拟生产出一个音频,并添加到列表
					AudioInfo *audio = (AudioInfo *)malloc(sizeof(AudioInfo));
					if (audio)
					{
						//申请保存音频的空间AUDIO_CAPACITY个字节
						audio->pcm = (char *)malloc(sizeof(char) * AUDIO_CAPACITY);
						if (data->amount >= SDL_MAX_SINT32)
						{
							data->amount = 0;
						}
						if (audio->pcm)
						{
							//sprintf(audio->pcm, "PCM_Audio_%ld", data->amount);
							size_t len = fread(audio->pcm, 1, AUDIO_CAPACITY, data->srcFile);
							if (len > 0)
							{
								data->amount++;
								audio->serialNumber = data->amount;
								audio->len = len;
								audio->size = data->size;

								if (data->pos == 0)//是文件开始的一个buffer数据
								{
									audio->begin = SDL_TRUE;//第1次读取到数据,是头	
									audio->end = SDL_FALSE;//第1次读取到数据,不是尾
								}
								else if (len < AUDIO_CAPACITY)//没有读满,是最后的一个buffer数据
								{
									audio->begin = SDL_FALSE;
									audio->end = SDL_TRUE;
								}
								else //不是头,也不是尾
								{
									audio->begin = SDL_FALSE;
									audio->end = SDL_FALSE;
								}
								data->pos += audio->len;
								audio->pos = data->pos;//更新当前读取到的位置
								if (audio->end)//读完了,把读取到的进度重置
								{
									data->pos = 0;
								}

								//获取一次读取到的数据信息
								long sn = audio->serialNumber;
								char *pcm = audio->pcm;
								long len = audio->len;
								long size = audio->size;
								long pos = audio->pos;
								SDL_bool begin = audio->begin;
								SDL_bool end = audio->end;
								//SDL_Log("Use:: sn:%ld,pcm:%s", sn, pcm);
								SDL_Log("Make:: pcm audio,sn:%ld,len:%ld,pos:%ld,size:%ld,begin:%d,end:%d",
									sn, len, pos, size, begin, end);
								//SDL_Log("Make:: sn:%ld,pcm audio size:%d", sn, len);
								audioList->push_back(audio);//向容器尾部添加数据	
							}
							else if (len == 0)
							{
								const char *endStr = "============ Read Audio End ================";
								SDL_Log("%s", endStr);
								data->amount = 0;
								//audio->serialNumber = data->amount;
								data->pos = 0;//更新当前读取到的位置
								rewind(data->srcFile);//重置文件指针到开头
							}
						}
					}
				}
				SDL_Log("Make:: 2 sn:,pcm audio,isRunning:%d", computer->isRunning);
				if (computer->isRunning == SDL_TRUE)
				{
					SDL_UnlockMutex(computer->mMutex);//解锁,一定要先释放锁,然后再发送信号
					SDL_CondSignal(computer->mUseCond);//发送信号mUseCond给使用线程,可以使用音频了
				}
				//SDL_Delay(100);//生产快一点
			}
		}
		return 1;
	}

	/*
	* 多线程使用音频: 线程回调函数
	*/
	int SuperComputer::UseAudioThreadCallback(void *userdata)
	{
		SuperComputer *computer = (SuperComputer *)userdata;//获取主线程传递给子线程的参数
		if (computer)
		{
			SDL_Log("Start In Use Audio Thread:");
			while (computer->isRunning == SDL_TRUE)
			{
				//SDL_Log("In Use Audio Thread: 1");
				SDL_LockMutex(computer->mMutex);//加锁
				//SDL_Log("In Use Audio Thread: 2");
				ComputerData *data = computer->mComputerData;
				list<AudioInfo *> *audioList = data->audioList;
				if (audioList)
				{
					//容器是空的,等有数据再使用
					if (audioList->empty())
					{
						const char *emptyStr = "============ Audio List Is Empty,Wait mUseCond ================";
						SDL_Log("%s", emptyStr);
						//释放mMutex锁,并阻塞在这里,等待条件变量mUseCond有信号才继续往下执行
						SDL_CondWait(computer->mUseCond, computer->mMutex);//等待有mUseCond信号,才继续使用音频
					}

					//获取列表保存的已经生产好的音频数据
					AudioInfo *audio = nullptr;
					if (!audioList->empty())
					{
						AudioPlayer *audioPlayer = data->audioPlayer;
						if (audioPlayer)
						{
							SoundInfo *soundInfo = audioPlayer->mSoundInfo;
							SDL_AudioDeviceID device = soundInfo->device;

							audio = audioList->front();//从列表头开始获取
							//audioList->pop_front();//移除列表头部元素
							if (audio)
							{
								uint32_t queueSize = SDL_GetQueuedAudioSize(device);
								long sn = audio->serialNumber;
								char *pcm = audio->pcm;
								long len = audio->len;
								long size = audio->size;
								long pos = audio->pos;
								SDL_bool begin = audio->begin;
								SDL_bool end = audio->end;
								SDL_Log("Use:: queueSize:%d", queueSize);
								SDL_Log("Use:: pcm audio,sn:%ld,len:%ld,pos:%ld,size:%ld,begin:%d,end:%d", sn, len, pos, size, begin, end);

								//如果播放器缓冲区还需要数据就取出列表中的音频喂过过去，如果还有，就先等等
								if (queueSize <= size)
								{
									audioList->pop_front();//移除列表头部元素

									//把多线程读取到的音频写入到文件中
									if (data->save)
									{
										if (data->destFile && len > 0)
										{
											fwrite(pcm, 1, len, data->destFile);
										}
									}

									//把音频数据传递给播放器播放
									if (data->AudioCallback)
									{
										SDL_Log("Use:: audioPlayer:%p", data->audioPlayer);
										SDL_Log("Use:: mSoundInfo:%p", data->audioPlayer->mSoundInfo);
										data->AudioCallback(data->audioPlayer, audio);
									}
									free(audio->pcm);//释放空间
									free(audio);
								}
							}
						}
					}
				}
				SDL_Log("In Use Audio Thread: 3 isRunning:%d", computer->isRunning);
				if (computer->isRunning == SDL_TRUE)
				{
					SDL_UnlockMutex(computer->mMutex);//解锁,一定要先释放锁,然后再发送信号
					SDL_CondSignal(computer->mMakeCond);//发送信号mMakeCond给生产线程,可以生产音频了
				}
				//SDL_Delay(150);//使用慢一点
			}
		}

		return 1;
	}

	/*
	* 等待所以的子线程执行结束
	*/
	void SuperComputer::Wait()
	{
		if (mMakeThreads)
		{
			int state;
			for (int i = 0; i < MAKE_THREAD_SIZE; i++)
			{
				SDL_WaitThread(mMakeThreads[i], &state);
			}
			SDL_Log("SuperComputer::Wait():: result:%ld", this->mComputerData->amount);
		}

		if (mUseThreads)
		{
			int state;
			for (int i = 0; i < USE_THREAD_SIZE; i++)
			{
				SDL_WaitThread(mUseThreads[i], &state);
			}
			SDL_Log("SuperComputer::Wait():: result:%ld", this->mComputerData->amount);
		}
	}
}