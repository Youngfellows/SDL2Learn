#ifndef _DUNGEON_SUPER_COMPUTER_H_
#define _DUNGEON_SUPER_COMPUTER_H_

#define _CRT_SECURE_NO_WARNINGS
#include "SDL2/SDL.h"

namespace Dungeon
{
	typedef struct ComputerData
	{
		long amount;//金额
		char *threadName;//线程名称
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
		SDL_Thread **mThreads;//线程列表
		SDL_mutex *mMutex;//互斥量
	
	public:
		ComputerData *mComputerData;
	
	public:
		SuperComputer();
		~SuperComputer();
		void Start();
		void Wait();
	private:
		static int SDLCALL CalculateCallback(void *userdata);//线程回调函数
	};


}

#endif // !_DUNGEON_SUPER_COMPUTER_H_
