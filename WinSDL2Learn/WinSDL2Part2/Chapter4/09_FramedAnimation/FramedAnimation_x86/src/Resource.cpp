#include "Resource.h"
#include "Config.h"

namespace Dungeon
{
	Resource::Resource() :mWalkTexture(nullptr)
	{
	}

	Resource::~Resource()
	{
	}

	SDL_bool Resource::Load(SDL_Renderer *renderer)
	{
		mWalkTexture = IMG_LoadTexture(renderer, WALK_FILE_NAME);
		if (!mWalkTexture) {
			SDL_Log("Can not load imgage: %s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_Texture *Resource::GetWalkTexture()
	{
		return this->mWalkTexture;
	}

	void Resource::Destory()
	{
		if (mWalkTexture)
		{
			SDL_DestroyTexture(mWalkTexture);
		}
	}

}