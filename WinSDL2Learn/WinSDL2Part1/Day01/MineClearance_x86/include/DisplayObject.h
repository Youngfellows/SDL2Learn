#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"
#include "Resource.h"

namespace Dungeon
{
	class DisplayObject;//先声明类

	//函数指针,定义回调函数
	typedef void (*OnDrawCallback)(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);//绘制
	typedef void (*OnMouseMoveCallback)(DisplayObject *self, SDL_Event *event);//光标移动
	typedef void (*OnMouseDownCallback)(DisplayObject *self, SDL_Event *event);//鼠标键按下
	typedef void (*OnMouseUpCallback)(DisplayObject *self, SDL_Event *event);//鼠标键松开
	typedef void (*OnMouseWheelCallback)(DisplayObject *self, SDL_Event *event);//鼠标滚轮事件
	typedef void (*OnScanCodeLeftKeyDownCallback)(DisplayObject *self);//按下方向左键
	typedef void (*OnScanCodeRightKeyDownCallback)(DisplayObject *self);//按下方向右键
	typedef void (*OnScanCodeLeftKeyUpCallback)(DisplayObject *self);//松开方向左键
	typedef void (*OnScanCodeRightKeyUpCallback)(DisplayObject *self);//松开方向右键
	typedef void (*OnScanCodeUpKeyDownCallback)(DisplayObject *self);//按下方向上键
	typedef void (*OnScanCodeDownKeyDownCallback)(DisplayObject *self);//按下方向下键
	typedef void (*OnScanCodeUpKeyUpCallback)(DisplayObject *self);//松开方向上键
	typedef void (*OnScanCodeDownKeyUpCallback)(DisplayObject *self);//松开方向下键

	typedef void (*OnDestoryCallback)(DisplayObject *self);//释放资源

	//绘制,还可以采用传递void *方式定义接口,一点都不耦合
	typedef void (*OnDrawCallback2)(void *userdata, Resource *resource, SDL_Renderer *renderer);


	//回调函数接口结构体
	typedef struct OnCallbackData
	{
		OnDrawCallback OnDraw;
		OnDrawCallback2 OnDraw2;
		OnMouseMoveCallback OnMouseMove;
		OnMouseDownCallback OnMouseDown;
		OnMouseUpCallback OnMouseUp;
		OnMouseWheelCallback OnMouseWheel;
		OnScanCodeLeftKeyDownCallback OnScanCodeLeftKeyDown;
		OnScanCodeRightKeyDownCallback OnScanCodeRightKeyDown;
		OnScanCodeLeftKeyUpCallback OnScanCodeLeftKeyUp;
		OnScanCodeRightKeyUpCallback OnScanCodeRightKeyUp;
		OnScanCodeUpKeyDownCallback OnScanCodeUpKeyDown;
		OnScanCodeDownKeyDownCallback OnScanCodeDownKeyDown;
		OnScanCodeUpKeyUpCallback OnScanCodeUpKeyUp;
		OnScanCodeDownKeyUpCallback OnScanCodeDownKeyUp;
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
		void Draw(Resource *resource, SDL_Renderer *renderer);//绘制
		void Draw2(Resource *resource, SDL_Renderer *renderer);//绘制
		void MouseMove(SDL_Event *event);//光标移动
		void MouseDown(SDL_Event *event);//鼠标键按下
		void MouseUp(SDL_Event *event);//鼠标键松开
		void MouseWheelScroll(SDL_Event *event);//鼠标滚轮滚动
		void ScanCodeLeftKeyDown();//按下方向左键
		void ScanCodeRightKeyDown();//按下方向右键
		void ScanCodeLeftKeyUp();//松开方向左键
		void ScanCodeRightKeyUp();//松开方向右键
		void ScanCodeUpKeyDown();//按下方向上键
		void ScanCodeDownKeyDown();//按下方向下键
		void ScanCodeUpKeyUp();//松开方向上键
		void ScanCodeDownKeyUp();//松开方向下键
		void Destory();//释放资源
	};
}

#endif // !_DUNGEON_DISPLAYOBJECT_H_
