#ifndef _DUNGEON_CURSOR_H_
#define _DUNGEON_CURSOR_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	class Cursor
	{
	private:
		Resource *mResource;
		DisplayObject *mDisplayObject;

	public:
		Cursor(Resource *resource);
		~Cursor();
		SDL_bool Cursor_Create(float x, float y, float w, float h);
		void Cursor_Destory();

	public:
		void Cursor_OnDraw(SDL_Renderer *renderer);
		void Cursor_OnMouseMove(SDL_Event *event);
	};
}


#endif // ! _DUNGEON_CURSOR_H_

