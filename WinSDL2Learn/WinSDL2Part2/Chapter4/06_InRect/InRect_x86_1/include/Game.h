#ifndef _DUNGEON_GAME_H_
#define _DUNGEON_GAME_H_

#include <SDL2/SDL.h>
#include "Resource.h"
#include "DisplayObject.h"

namespace Dungeon
{
	class Game
	{
	private:
		SDL_Window *mWindow;//!< 先声明 *mWindow，窗口
		bool mIsRunning;//!< 运行状态
		SDL_Renderer *mRenderer;
		Resource *mResource;
		DisplayObject *mCursor;//光标
		DisplayObject *mRectInRect;//内部矩形

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

		//! 创建组件
		SDL_bool CreateComponents();

		//! 释放组件资源
		void FreeComponents();

		//! 处理鼠标移动事件
		void ProcessMouseMoveEvent(SDL_Event *event);
	};
}

#endif // !_DUNGEON_GAME_H_

