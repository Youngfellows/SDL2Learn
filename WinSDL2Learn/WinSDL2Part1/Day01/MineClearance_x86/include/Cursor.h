#ifndef _DUNGEON_CURSOR_H_
#define _DUNGEON_CURSOR_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	typedef struct CursorData
	{
		SDL_FRect *dest;
	}CursorData;
}

namespace Dungeon
{
	class Cursor
	{
	private:
		CursorData *mCursorData;

	public:
		Cursor();
		~Cursor();
		DisplayObject *Create(float x, float y, float w, float h);
		static void OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void OnDestoryCallback(DisplayObject *self);
		static void OnMouseMoveCallback(DisplayObject *self, SDL_Event *event);
	};

}
#endif // ! _DUNGEON_CURSOR_H_

