#ifndef  _DUNGEON_RESOURCE_H_
#define _DUNGEON_RESOURCE_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace Dungeon
{
	class Resource
	{
	private:
		SDL_Texture *mWalkTexture;

	public:
		Resource();
		~Resource();
		SDL_bool Load(SDL_Renderer *renderer);
		SDL_Texture *GetWalkTexture();
		void Destory();
	};
}
#endif // ! _DUNGEON_RESOURCE_H_
