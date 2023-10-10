#ifndef  _DUNGEON_RESOURCE_H_
#define _DUNGEON_RESOURCE_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace Dungeon
{
	class Resource
	{
	private:
		SDL_Texture *mEyeTexture;

	public:
		Resource();
		~Resource();
		SDL_bool Resource_Load(SDL_Renderer *renderer);
		SDL_Texture *Resource_GetEyeTexture();
		void Resource_Unload();
	};
}

#endif // ! _DUNGEON_RESOURCE_H_

