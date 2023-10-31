#ifndef _DUNGEON_RESOURCE_H_
#define _DUNGEON_RESOURCE_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	class Resource
	{
	private:

	public:
		Resource();
		~Resource();
		SDL_bool Load(SDL_Renderer *renderer);
		void Destory();

	};
}

#endif // !_DUNGEON_RESOURCE_H_

