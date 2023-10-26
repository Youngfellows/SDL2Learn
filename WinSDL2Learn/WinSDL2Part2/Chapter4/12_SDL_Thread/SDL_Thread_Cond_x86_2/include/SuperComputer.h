#ifndef _DUNGEON_SUPER_COMPUTER_H_
#define _DUNGEON_SUPER_COMPUTER_H_

#define _CRT_SECURE_NO_WARNINGS
#include "SDL2/SDL.h"
#include <list>

using namespace std;

namespace Dungeon
{
	//音频消息结构体
	typedef struct AudioInfo
	{
		long serialNumber;//序列号
		char *pcm;//音频数据
	}AudioInfo;


	typedef struct ComputerData
	{
		long amount;//金额
		char *threadName;//线程名称
		list<AudioInfo *> *audioList;//保存音频的列表
	}ComputerData;


}

namespace Dungeon
{
	/*
	* 超级计算机: SDL线程锁的使用
	*/
	class SuperComputer
	{
	private:
		SDL_Thread **mMakeThreads;//线程列表
		SDL_Thread **mUseThreads;//线程列表
		SDL_mutex *mMutex;//互斥量
		SDL_cond *mUseCond;//容器为空的条件变量
		SDL_cond *mMakeCond;//容器为空的条件变量
		SDL_bool isRunning;//是否运行

	public:
		ComputerData *mComputerData;

	public:
		SuperComputer();
		~SuperComputer();
		void Start();
		void Wait();

	private:
		static int SDLCALL MakeAudioThreadCallback(void *userdata);//生产音频线程回调函数
		static int SDLCALL UseAudioThreadCallback(void *userdata);//使用音频线程回调函数
		void MakeAudio();//生产音频
		void UseAudio();//使用音频
	};


}

#endif // !_DUNGEON_SUPER_COMPUTER_H_
