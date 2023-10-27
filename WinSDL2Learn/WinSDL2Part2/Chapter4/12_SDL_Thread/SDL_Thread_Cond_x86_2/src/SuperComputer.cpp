#include "SuperComputer.h"

#include <iostream>
#include "Config.h"

namespace Dungeon
{
#define MAKE_THREAD_SIZE 1 //多线程数量
#define USE_THREAD_SIZE 1 //多线程数量
#define MAX_SIZE 20 //保存音频容器的最大容量

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
	void SuperComputer::Start()
	{
		//PCM_1_FILE_NAME
		//PCM_2_FILE_NAME
		//PCM_3_FILE_NAME
		//MP3_FILE_NAME
		if (!OpenFile(PCM_2_FILE_NAME))
		{
			return;
		}
		//获取文件大小
		this->mComputerData->size = GetFileSize(this->mComputerData->file);
		UseAudio();//多线程消费音频
		MakeAudio();//多线程生产音频
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

	SDL_bool SuperComputer::OpenFile(const char *fileName)
	{
		if (this->mComputerData)
		{
			mComputerData->file = fopen(fileName, "rb");//打开文件
			if (!mComputerData->file)
			{
				SDL_Log("open file failed: %s", fileName);
				return SDL_FALSE;
			}
			mComputerData->fileName = (char *)malloc(sizeof(char) * strlen(fileName) + 1);
			if (!mComputerData->fileName)
			{
				return SDL_FALSE;
			}
			strcpy(mComputerData->fileName, PCM_1_FILE_NAME);//赋值文件名

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

			while (computer->isRunning)
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
						audio->pcm = (char *)malloc(sizeof(char) * AUDIO_CAPACITY);//申请保存音频的空间512个字节
						if (data->amount >= SDL_MAX_SINT32)
						{
							data->amount = 0;
						}
						if (audio->pcm)
						{
							//sprintf(audio->pcm, "PCM_Audio_%ld", data->amount);
							size_t len = fread(audio->pcm, 1, AUDIO_CAPACITY, data->file);
							if (len > 0)
							{
								data->amount++;
								audio->serialNumber = data->amount;
								long sn = audio->serialNumber;
								char *pcm = audio->pcm;
								//SDL_Log("Make:: sn:%ld,pcm:%s", sn, pcm);
								SDL_Log("Make:: sn:%ld,pcm audio size:%d", sn, len);
								audioList->push_back(audio);//向容器尾部添加数据	
							}
							else if (len == 0)
							{
								const char *endStr = "============ Read Audio End ================";
								SDL_Log("%s", endStr);
								data->amount = 0;
								audio->serialNumber = data->amount;
								rewind(data->file);//重置文件指针到开头
							}
						}
					}
				}
				//SDL_Log("Make:: 2 sn:,pcm audio");
				SDL_UnlockMutex(computer->mMutex);//解锁,一定要先释放锁,然后再发送信号
				SDL_CondSignal(computer->mUseCond);//发送信号mUseCond给使用线程,可以使用音频了
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
			while (computer->isRunning)
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
						audio = audioList->front();//从列表头开始获取
						if (audio)
						{
							long sn = audio->serialNumber;
							char *pcm = audio->pcm;
							//SDL_Log("Use:: sn:%ld,pcm:%s", sn, pcm);
							SDL_Log("Use:: sn:%ld,pcm audio", sn);
							free(audio->pcm);//释放空间
							free(audio);
						}
						audioList->pop_front();//移除列表头部元素
					}
				}
				//SDL_Log("In Use Audio Thread: 3");
				SDL_UnlockMutex(computer->mMutex);//解锁,一定要先释放锁,然后再发送信号
				SDL_CondSignal(computer->mMakeCond);//发送信号mMakeCond给生产线程,可以生产音频了
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