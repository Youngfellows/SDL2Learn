#ifndef _GAME_DISPLAYOBJECT_H_
#define _GAME_DISPLAYOBJECT_H_

#include "FRect.h"
#include "Renderer.h"
#include "Event.h"

namespace Game
{
	class DisplayObject
	{
	public:
		typedef void (*DisplayObject_OnMouseMoveCallback)(DisplayObject *displayObject, Event *event);
		typedef void(*DisplayObject_OnDrawCallback)(DisplayObject *displayObject, Renderer *renderer);
		//void (*onDraw)(DisplayObject *displayObject, struct Renderer *renderer);//回调函数
		//void (*onMouseMove)(DisplayObject *displayObject, struct Event *event);//回调函数

		DisplayObject_OnMouseMoveCallback onMouseMove;
		DisplayObject_OnDrawCallback onDraw;

	public:
		FRect *dest;

	public:
		DisplayObject();
		~DisplayObject();
		bool DisplayObject_Create(float x, float y, float w, float h,
			DisplayObject_OnDrawCallback onDrawCallback,
			DisplayObject_OnMouseMoveCallback onMouseMoveCallback);
		void DisplayObject_Draw(struct Renderer *renderer);
		void DisplayObject_OnMouseMove(struct Event *event);
		void DisplayObject_Destory();
	};
}

#endif // !_GAME_DISPLAYOBJECT_H_

