#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"
#include "Resource.h"

namespace Dungeon
{
	class DisplayObject;//先声明类

	//函数指针,定义回调函数
	typedef void (*OnDrawCallback)(DisplayObject *self, SDL_Surface *winSurface, Resource *resource);//绘制
	typedef void (*OnMouseMoveCallback)(DisplayObject *self, SDL_Event *event);//光标移动
	typedef void (*OnMouseDownCallback)(DisplayObject *self, SDL_Event *event);//鼠标键按下
	typedef void (*OnMouseUpCallback)(DisplayObject *self, SDL_Event *event);//鼠标键按下
	typedef void (*OnDestoryCallback)(DisplayObject *self);//释放资源

	//回调函数接口结构体
	typedef struct OnCallbackData
	{
		OnDrawCallback OnDraw;
		OnMouseMoveCallback OnMouseMove;
		OnMouseDownCallback OnMouseDown;
		OnMouseUpCallback OnMouseUp;
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
		void Draw(SDL_Surface *winSurface, Resource *resource);//绘制
		void MouseMove(SDL_Event *event);//光标移动
		void MouseDown(SDL_Event *event);//鼠标键按下
		void MouseUp(SDL_Event *event);//鼠标键按下
		void Destory();//释放资源
	};
}

#endif // !_DUNGEON_DISPLAYOBJECT_H_
