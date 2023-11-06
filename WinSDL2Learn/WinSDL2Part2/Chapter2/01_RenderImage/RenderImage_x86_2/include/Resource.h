#ifndef _DUNGEON_RESOURCE_H_
#define _DUNGEON_RESOURCE_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	/*
	* 加载资源
	*/
	class Resource
	{
	private:
		SDL_Texture *mCatTexture;
		SDL_Texture *mGirlTexture;
		SDL_Texture *mLandscapeTexture;

	public:
		Resource();
		~Resource();
		SDL_bool Load(SDL_Renderer *renderer);
		SDL_bool LoadCatTexture(SDL_Renderer *renderer);
		SDL_bool LoadGirlTexture(SDL_Renderer *renderer);
		SDL_bool LoadLandscapeTexture(SDL_Renderer *renderer);
		SDL_Texture *GetCatTexture();
		SDL_Texture *GetGirlTexture();
		SDL_Texture *GetLandscapeTexture();
		void Destory();
	};
}

#endif // !_DUNGEON_RESOURCE_H_

