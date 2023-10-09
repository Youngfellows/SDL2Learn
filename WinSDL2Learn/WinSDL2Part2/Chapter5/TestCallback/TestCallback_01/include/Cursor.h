#ifndef _GAME_CURSOR_H_
#define _GAME_CURSOR_H_

#include "DisplayObject.h"

namespace Game
{
	class DisplayObject;

	class Cursor
	{
	private:
		static int radius;//只能访问静态成员
		static FRect *srcRect;

	public:
		Cursor();
		~Cursor();
		DisplayObject *Cursor_Create(float x, float y, float w, float h);
		void Cursor_Destory(DisplayObject *displayObject);
		static void Cursor_OnDraw(DisplayObject *displayObject, struct Renderer *renderer);//回调函数
		static void Cursor_OnMouseMove(DisplayObject *displayObject, struct Event *event);//回调函数
	};

}

#endif // !_GAME_CURSOR_H_

