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

	public:
		Resource();
		~Resource();
		SDL_bool Load(SDL_Window *window);
		SDL_bool LoadWinSurface(SDL_Window *window);
		SDL_Surface *GetWinSurface();
		void Destory();
	};
}
#endif // !_DUNGEON_RESOURCE_H_


