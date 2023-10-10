#ifndef _DUNGEON_GAME_H_
#define _DUNGEON_GAME_H_

#include <SDL2/SDL.h>

namespace Dungeon
{
	class Game
	{
	private:
		SDL_Window *mWindow;//!< 先声明 *mWindow，窗口
		bool mIsRunning;//!< 运行状态
		SDL_Renderer *mRenderer;

	public:
		//! 构造函数
		Game();

		//! 初始化
		bool Initialize();

		//! 主循环
		void Loop();

		//! 游戏结束
		void Shutdown();

	private:
		//! 处理事件
		void Event();

		//! 更新各种状态
		void Update(long delay);

		//! 渲染
		void Draw();
	};
}

#endif // !_DUNGEON_GAME_H_

