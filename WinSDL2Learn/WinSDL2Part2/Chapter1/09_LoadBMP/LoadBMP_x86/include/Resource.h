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
		SDL_Surface *mWinSurface;
		SDL_Surface *mCatSurface;
		SDL_Surface *mSDLLogoSurface;

	public:
		Resource();
		~Resource();
		SDL_bool Load(SDL_Window *window);
		SDL_bool LoadWinSurface(SDL_Window *window);
		SDL_bool LoadCatSurface();
		SDL_bool LoadSDLLogoSurface();
		SDL_Surface *GetWinSurface();
		SDL_Surface *GetCatSurface();
		SDL_Surface *GetSDLLogoSurface();
		void Destory();
	};
}
#endif // !_DUNGEON_RESOURCE_H_


