#include "SuperComputer.h"

#include <iostream>

namespace Dungeon
{
#define MAKE_THREAD_SIZE 4 //多线程数量
#define USE_THREAD_SIZE 5 //多线程数量
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
		if (mMakeCond)
		{
			SDL_Log("Create Make Cond Failure");
		}
		this->mUseCond = SDL_CreateCond();//创建条件变量
		if (mUseCond)
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
		UseAudio();//多线程消费音频
		MakeAudio();//多线程生产音频
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
					if (audioList->size() >= MAX_SIZE)
					{
						//释放mMutex锁,并阻塞在这里,等待条件变量mMakeCond有信号才继续往下执行
						SDL_CondWait(computer->mMakeCond, computer->mMutex);//等待有mMakeCond信号,才继续生产音频
					}

					//模拟生产出一个音频,并添加到列表
					AudioInfo *audio = (AudioInfo *)malloc(sizeof(AudioInfo));
					if (audio)
					{
						audio->pcm = (char *)malloc(sizeof(char) * 128);
						data->amount++;
						audio->serialNumber = data->amount;
						if (audio->pcm)
						{
							sprintf(audio->pcm, "PCM_Audio_%ld", data->amount);
						}
						int sn = audio->serialNumber;
						char *pcm = audio->pcm;
						SDL_Log("Make:: sn:%ld,pcm:%s", sn, pcm);
						audioList->push_back(audio);//向容器尾部添加数据
					}
				}
				SDL_UnlockMutex(computer->mMutex);//解锁
				SDL_CondSignal(computer->mUseCond);//发送信号mUseCond给使用线程,可以使用音频了
				SDL_Delay(100);//生产快一点
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
				SDL_LockMutex(computer->mMutex);//加锁
				ComputerData *data = computer->mComputerData;
				list<AudioInfo *> *audioList = data->audioList;
				if (audioList)
				{
					//容器是空的,等有数据再使用
					if (audioList->size() == 0)
					{
						//释放mMutex锁,并阻塞在这里,等待条件变量mUseCond有信号才继续往下执行
						SDL_CondWait(computer->mUseCond, computer->mMutex);//等待有mUseCond信号,才继续使用音频
					}

					//获取列表保存的已经生产好的音频数据
					AudioInfo *audio = nullptr;
					audio = audioList->front();//从列表头开始获取
					if (audio)
					{
						int sn = audio->serialNumber;
						char *pcm = audio->pcm;
						SDL_Log("Use:: sn:%ld,pcm:%s", sn, pcm);
						free(audio->pcm);//释放空间
						free(audio);
					}
					audioList->pop_front();//移除列表头部元素
				}
				SDL_UnlockMutex(computer->mMutex);//解锁
				SDL_CondSignal(computer->mMakeCond);//发送信号mMakeCond给生产线程,可以生产音频了
				SDL_Delay(150);//使用慢一点
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