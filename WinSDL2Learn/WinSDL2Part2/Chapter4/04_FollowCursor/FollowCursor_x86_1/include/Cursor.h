#ifndef _DUNGEON_CURSOR_H_
#define _DUNGEON_CURSOR_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"
#include "CursorData.h"

namespace Dungeon
{
	class Cursor
	{
	private:
		CursorData *mCursorData;

	public:
		Cursor();
		~Cursor();
		DisplayObject *Cursor_Create(float x, float y, float w, float h);
		SDL_bool Cursor_Create(DisplayObject *displayObject, float x, float y, float w, float h);
		static void Cursor_OnDestoryCallback(DisplayObject *self);
		static void Cursor_OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void Cursor_OnMouseMoveCallback(DisplayObject *self, SDL_Event *event);
	};
}

#endif // ! _DUNGEON_CURSOR_H_

