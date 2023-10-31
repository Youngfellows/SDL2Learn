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
		SDL_Renderer *mRenderer;

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
		SDL_bool CreateComponents();//创建组件
		void DrawComponents();//绘制组件
		void FreeComponents();//释放组件资源
		void MouseMoveEvent(SDL_Event *event);//光标移动事件
		void MouseLeftDownEvent(SDL_Event *event);//鼠标左键按下事件
		void MouseRightDownEvent(SDL_Event *event);//鼠标右键按下事件
		void MouseLeftUpEvent(SDL_Event *event);//鼠标左键松开事件
		void MouseRightUpEvent(SDL_Event *event);//鼠标右键松开事件
		void ScanCodeLeftDownEvent();//按下方向左键
		void ScanCodeRightDownEvent();//按下方向右键
		void ScanCodeLeftUpEvent();//松开方向左键
		void ScanCodeRightUpEvent();//松开方向右键
	};
}
#endif // !_DUNGEON_GAME_H_

