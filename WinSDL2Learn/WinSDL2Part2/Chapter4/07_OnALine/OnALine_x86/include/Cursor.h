#ifndef _DUNGEON_CURSOR_H_
#define _DUNGEON_CURSOR_H_

#include "SDL2/SDL.h"
#include "Resource.h"
#include "DisplayObject.h"

namespace Dungeon
{
	//光标数据实体
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
		static void OnMouseMoveCallback(DisplayObject *self, SDL_Event *event);
		static void OnDestoryCallback(DisplayObject *self);
	};

}

#endif // !_DUNGEON_CURSOR_H_

