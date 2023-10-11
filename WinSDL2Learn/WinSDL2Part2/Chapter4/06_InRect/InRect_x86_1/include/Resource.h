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
		SDL_bool Resource_Load(SDL_Renderer *renderer);
		SDL_Surface *Resource_GetCursorSurface();
		SDL_Cursor *Resource_GetCursor();
		SDL_Texture *Resource_GetCursorTexture();
	};
}

#endif // !_DUNGEON_RESOURCE_H_
