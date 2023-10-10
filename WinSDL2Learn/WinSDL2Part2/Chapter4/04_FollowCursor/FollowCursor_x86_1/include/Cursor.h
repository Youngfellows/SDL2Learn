#ifndef _DUNGEON_CURSOR_H_
#define _DUNGEON_CURSOR_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	class Cursor
	{
	public:
		Cursor();
		~Cursor();
		DisplayObject *Cursor_Create(float x, float y, float w, float h);
		SDL_bool Cursor_Create(DisplayObject *displayObject, float x, float y, float w, float h);
		void Cursor_Destory(DisplayObject *displayObject);
		static void Cursor_OnDraw(DisplayObject *displayObject, Resource *resource, SDL_Renderer *renderer);
		static void Cursor_OnMouseMove(DisplayObject *displayObject, SDL_Event *event);
	};
}

#endif // ! _DUNGEON_CURSOR_H_

