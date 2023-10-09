#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	class DisplayObject
	{
	public:
		SDL_FRect *mDest;

	public:
		DisplayObject();
		~DisplayObject();
		SDL_bool DisplayObject_Create(float x, float y, float w, float h);
		void DisplayObject_Destory();
	};
}

#endif // ! _DUNGEON_DISPLAYOBJECTCALLBACK_H_