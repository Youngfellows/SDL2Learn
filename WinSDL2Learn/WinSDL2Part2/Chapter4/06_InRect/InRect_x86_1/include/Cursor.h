#ifndef _DUNGEON_CURSOR_H_
#define _DUNGEON_CURSOR_H_

#include "SDL2/SDL.h"
#include "Resource.h"
#include "CursorData.h"
#include "DisplayObject.h"

namespace Dungeon
{
	/*
	* 鼠标光标类
	*/
	class Cursor
	{
	private:
		CursorData *mCursorData;

	public:
		Cursor();
		~Cursor();
		DisplayObject *Cursor_Create(float x, float y, float w, float h);
		static void Cursor_DestoryCallback(DisplayObject *self);
		static void Cursor_OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void Cursor_OnMouseMoveCallback(DisplayObject *self, SDL_Event *event);

	private:
		CursorData *Cursor_GetCursorData();
	};
}

#endif // !_DUNGEON_CURSOR_H_
