#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	class DisplayObject;//先声明类

	//函数指针,定义回调函数
	typedef void (*OnDrawCallback)(DisplayObject *self, SDL_Renderer *renderer);//绘制
	typedef void (*OnMouseMoveCallback)(DisplayObject *self, SDL_Event *event);//光标移动
	typedef void (*OnMouseLeftDownCallback)(DisplayObject *self, SDL_Event *event);//鼠标左键按下
	typedef void (*OnMouseRightDownCallback)(DisplayObject *slef, SDL_Event *event);//鼠标右键按下
	typedef void (*OnMouseLeftUpCallback)(DisplayObject *self, SDL_Event *event);//鼠标左键松开
	typedef void (*OnMouseRightUpCallback)(DisplayObject *self, SDL_Event *event);//鼠标右键松开
	typedef void (*OnScanCodeLeftKeyDownCallback)(DisplayObject *self);//按下方向左键
	typedef void (*OnScanCodeRightKeyDownCallback)(DisplayObject *self);//按下方向右键
	typedef void (*OnScanCodeLeftKeyUpCallback)(DisplayObject *self);//松开方向左键
	typedef void (*OnScanCodeRightKeyUpCallback)(DisplayObject *self);//松开方向右键
	typedef void (*OnDestoryCallback)(DisplayObject *self);//释放资源

	//回调函数接口结构体
	typedef struct OnCallbackData
	{
		OnDrawCallback OnDraw;
		OnMouseMoveCallback OnMouseMove;
		OnMouseLeftDownCallback OnMouseLeftDown;
		OnMouseRightDownCallback OnMouseRightDown;
		OnMouseLeftUpCallback OnMouseLeftUp;
		OnMouseRightUpCallback OnMouseRightUp;
		OnScanCodeLeftKeyDownCallback OnScanCodeLeftKeyDown;
		OnScanCodeRightKeyDownCallback OnScanCodeRightKeyDown;
		OnScanCodeLeftKeyUpCallback OnScanCodeLeftKeyUp;
		OnScanCodeRightKeyUpCallback OnScanCodeRightKeyUp;
		OnDestoryCallback OnDestory;
	}OnCallbackData;

	class DisplayObject
	{
	private:
		void *subClass;//要显示对象实体,相当于泛型
		OnCallbackData *OnCallback;//函数回调

	public:
		DisplayObject();
		~DisplayObject();
		void *GetSubClass();
		void SetSubClass(void *subClass);//设置显示对象
		OnCallbackData *GetOnCallback();//回去回调函数结构体
		void Draw(DisplayObject *self, SDL_Renderer *renderer);//绘制
		void MouseMove(DisplayObject *self, SDL_Event *event);//光标移动
		void MouseLeftDown(DisplayObject *self, SDL_Event *event);//鼠标左键按下
		void MouseRightDown(DisplayObject *slef, SDL_Event *event);//鼠标右键按下
		void MouseLeftUp(DisplayObject *self, SDL_Event *event);//鼠标左键松开
		void MouseRightUp(DisplayObject *self, SDL_Event *event);//鼠标右键松开
		void ScanCodeLeftKeyDown(DisplayObject *self);//按下方向左键
		void ScanCodeRightKeyDown(DisplayObject *self);//按下方向右键
		void ScanCodeLeftKeyUp(DisplayObject *self);//松开方向左键
		void ScanCodeRightKeyUp(DisplayObject *self);//松开方向右键
		void Destory();//释放资源
	};
}

#endif // !_DUNGEON_DISPLAYOBJECT_H_
