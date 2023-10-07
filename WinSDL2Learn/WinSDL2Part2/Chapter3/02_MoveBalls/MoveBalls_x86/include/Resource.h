#ifndef _DUNGEON_RESOURCE_H_
#define _DUNGEON_RESOURCE_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace Dungeon
{
	class Resource
	{
	private:
		SDL_Texture *mBallTexture;

	public:
		Resource();
		~Resource();
		bool Resource_Load(SDL_Renderer *renderer);
		SDL_Texture *Resource_GetBallTexture();
		void Resource_Unload();
	};
}

#endif // !_DUNGEON_DRAWBALL_RESOURCE_H_
