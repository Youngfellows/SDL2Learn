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
		SDL_Surface *mSasaSurface;
		SDL_Surface *mYayaSurface;

	public:
		Resource();
		~Resource();
		SDL_bool Load(SDL_Window *window);
		SDL_bool LoadWinSurface(SDL_Window *window);
		SDL_bool LoadCatSurface();
		SDL_bool LoadSasaSurface();
		SDL_bool LoadYayaSurface();
		SDL_Surface *GetWinSurface();
		SDL_Surface *GetCatSurface();
		SDL_Surface *GetSasaSurface();
		SDL_Surface *GetYayaSurface();
		void Destory();
	};
}
#endif // !_DUNGEON_RESOURCE_H_


