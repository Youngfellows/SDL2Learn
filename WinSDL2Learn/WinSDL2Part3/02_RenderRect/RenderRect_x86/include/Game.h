#ifndef __Dungeon_Game__
#define __Dungeon_Game__
#include "SDL2/SDL.h"

namespace Dungeon
{
	class Game
	{
	private:
		SDL_Window *mWindow;//!<窗口
		SDL_Renderer *mRenderer;//!<渲染器
		bool mIsRunning;//!<运行状态

	public:
		//!	构造函数
		Game();
		//!	初始化
		bool Initialize();
		//!	主循环
		void Loop();
		//!	游戏结束
		void Shutdown();

	private:
		//!	处理事件
		void Event();
		//!	更新各种状态
		void Update();
		//!	渲染
		void Draw();
		//! 绘制矩形
		void DrawRect();
	};
}

#endif	// __Dungeon_Game__