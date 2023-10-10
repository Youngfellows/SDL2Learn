#include "Resource.h"


namespace Dungeon
{
#define EYE_FILE_NAME "./resources/eye.png"

	Resource::Resource() :mEyeTexture(nullptr)
	{
	}

	SDL_bool Resource::Resource_Load(SDL_Renderer *renderer)
	{
		mEyeTexture = IMG_LoadTexture(renderer, EYE_FILE_NAME);
		if (!mEyeTexture)
		{
			SDL_Log("Can not load texture: %s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_Texture *Resource::Resource_GetEyeTexture()
	{
		return mEyeTexture;
	}

	void Resource::Resource_Unload()
	{
		if (mEyeTexture != nullptr)
		{
			SDL_DestroyTexture(mEyeTexture);
		}
	}

	Resource::~Resource()
	{
	}
}