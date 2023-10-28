#include "Resource.h"

namespace Dungeon
{

	Resource::Resource()
	{
	}

	Resource::~Resource()
	{
	}

	SDL_bool Resource::Load(SDL_Renderer *renderer)
	{
		return SDL_TRUE;
	}

	void Resource::Unload()
	{

	}
}