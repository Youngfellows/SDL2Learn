#ifndef _DUNGEON_CURSORDATA_H_
#define _DUNGEON_CURSORDATA_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	typedef struct CursorData
	{
		SDL_FRect *dest;
	} CursorData;
}

#endif // !_DUNGEON_CURSORDATA_H_

