#ifndef _DUNGEON_RESOURCE_H_
#define _DUNGEON_RESOURCE_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace Dungeon
{
	class Resource
	{
	private:
		SDL_Surface *mCursorSurface;
		SDL_Cursor *mCursor;
		SDL_Texture *mCursorTexture;

	public:
		Resource();
		~Resource();
		SDL_bool Load(SDL_Renderer *renderer);
		SDL_Surface *GetCursorSurface();
		SDL_Cursor *GetCursor();
		SDL_Texture *GetCursorTexture();
	};
}

#endif // !_DUNGEON_RESOURCE_H_
