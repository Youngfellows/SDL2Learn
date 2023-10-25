#include "SuperComputer.h"

#include <iostream>

namespace Dungeon
{
#define THREAD_SIZE 5 //多线程数量

	SuperComputer::SuperComputer() :mComputerData(nullptr), mThreads(nullptr)
	{
		//动态申请内存
		this->mComputerData = (ComputerData *)malloc(sizeof(ComputerData));
		if (mComputerData)
		{
			mComputerData->amount = 0;
		}
		this->mMutex = SDL_CreateMutex();//创建互斥量
		if (!mMutex)
		{
			SDL_Log("Create Mutex Failure");
		}
	}

	SuperComputer::~SuperComputer()
	{
		if (mThreads)
		{
			delete[] mThreads;//释放二维数组
			mThreads = nullptr;
		}
		if (mMutex)
		{
			SDL_DestroyMutex(mMutex);//销毁互斥量,释放互斥锁资源
		}
	}

	/*
	* 开启多线程
	*/
	void SuperComputer::Start()
	{
		mThreads = new SDL_Thread * [THREAD_SIZE];//创建二维数组
		void *userdata = (void *)this;
		for (int i = 0; i < THREAD_SIZE; i++)
		{
			char msg[128];
			sprintf(msg, "MyThread_%d", i);
			if (mComputerData)
			{
				mComputerData->threadName = (char *)malloc(sizeof(char) * strlen(msg) + 1);
				if (mComputerData->threadName)
				{
					strcpy(mComputerData->threadName, msg);
				}
			}
			//创建线程并立即执行
			mThreads[i] = SDL_CreateThread(&CalculateCallback, msg, userdata);
		}
	}

	/*
	* 线程回调函数
	*/
	int SuperComputer::CalculateCallback(void *userdata)
	{
		SuperComputer *computer = (SuperComputer *)userdata;//获取主线程传递给子线程的参数
		if (computer)
		{
			ComputerData *data = computer->mComputerData;
			//SDL_Log("Start In Thread: %s", data->threadName);//获取到的threadName不精确,是最后一次赋值的
			SDL_Log("Start In Thread:");
			for (int i = 0; i < 100000; i++)
			{
				SDL_LockMutex(computer->mMutex);//加锁
				data->amount++;
				SDL_UnlockMutex(computer->mMutex);//解锁
			}
			//SDL_Log("Calculate In Thread: %s,%ld", data->threadName, data->amount);
			SDL_Log("Calculate In Thread: %ld", data->amount);
		}

		return 1;
	}

	/*
	* 等待所以的子线程执行结束
	*/
	void SuperComputer::Wait()
	{
		if (mThreads)
		{
			int state;
			for (int i = 0; i < THREAD_SIZE; i++)
			{
				SDL_WaitThread(mThreads[i], &state);
			}
			SDL_Log("SuperComputer::Wait():: result:%ld", this->mComputerData->amount);
		}
	}
}