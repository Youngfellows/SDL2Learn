#ifndef _DUNGEON_GAME_H_
#define _DUNGEON_GAME_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	class Game
	{
	private:
		SDL_Window *mWindow;//Window窗口
		bool mIsRunning;
		SDL_Renderer *mRenderer;
		Resource *mResource;//资源
		DisplayObject *mMovableRectangle;//可以的矩形组件
		DisplayObject *mCursor;//光标

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
		void MouseWheelEvent(SDL_Event *event);//鼠标滚轮事件
		void KeyDownEvent(SDL_Event *event);//处理按键按下事件
		void KeyUpEvent(SDL_Event *event);//处理按键松开事件
		void ScanCodeLeftKeyDownEvent();//按下方向左键
		void ScanCodeRightKeyDownEvent();//按下方向右键
		void ScanCodeLeftKeyUpEvent();//松开方向左键
		void ScanCodeRightKeyUpEvent();//松开方向右键
		void ScanCodeUpKeyDownEvent();//按下方向上键
		void ScanCodeDownKeyDownEvent();//按下方向下键
		void ScanCodeUpKeyUpEvent();//松开方向上键
		void ScanCodeDownKeyUpEvent();//松开方向下键
	};
}
#endif // !_DUNGEON_GAME_H_

