#ifndef _DUNGEON_GAME_H_
#define _DUNGEON_GAME_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	class Game
	{
	private:
		SDL_Window *mWindow;//Window窗口
		bool mIsRunning;

	public:
		Game();
		~Game();
		bool Initialize();//初始化
		void Loop();//主循环
		void Shutdown();//游戏结束

	private:
		void Event();//处理事件
		void Update(long delay);//更新各种状态
		void Draw();//渲染
	};
}
#endif // !_DUNGEON_GAME_H_

