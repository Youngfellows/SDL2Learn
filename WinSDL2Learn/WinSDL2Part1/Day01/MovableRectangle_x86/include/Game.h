#ifndef _DUNGEON_GAME_H_
#define _DUNGEON_GAME_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"

namespace Dungeon
{
	class Game
	{
	private:
		SDL_Window *mWindow;//Window窗口
		bool mIsRunning;
		SDL_Renderer *mRenderer;
		DisplayObject *mMovableRectangle;//可以的矩形组件

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
		void MouseDownEvent(SDL_Event *event);//鼠标键按下事件
		void MouseUpEvent(SDL_Event *event);//鼠标键松开事件
		void KeyDownEvent(SDL_Event *event);//处理按键按下事件
		void KeyUpEvent(SDL_Event *event);//处理按键松开事件
		void ScanCodeLeftDownEvent();//按下方向左键
		void ScanCodeRightDownEvent();//按下方向右键
		void ScanCodeLeftUpEvent();//松开方向左键
		void ScanCodeRightUpEvent();//松开方向右键
	};
}
#endif // !_DUNGEON_GAME_H_

