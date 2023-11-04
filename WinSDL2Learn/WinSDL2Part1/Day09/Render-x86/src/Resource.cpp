#include "Resource.h"
#include "Config.h"
#include "SDL2/SDL_image.h"

namespace Dungeon
{
	Resource::Resource() :
		mCatTexture(nullptr), 
		mGirlTexture(nullptr),
		mLandscapeTexture(nullptr)
	{

	}

	Resource::~Resource()
	{
		Destory();
	}

	SDL_bool Resource::Load(SDL_Renderer *renderer)
	{
		//加载各个资源
		if (!LoadCatTexture(renderer))
		{
			return SDL_FALSE;
		}
		if (!LoadGirlTexture(renderer))
		{
			return SDL_FALSE;
		}
		if (!LoadLandscapeTexture(renderer))
		{
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_bool  Resource::LoadCatTexture(SDL_Renderer *renderer)
	{
		this->mCatTexture = IMG_LoadTexture(renderer, CAT_PHOTO_FILE);
		if (!mCatTexture)
		{
			SDL_Log("Can not load photo:%s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_bool  Resource::LoadGirlTexture(SDL_Renderer *renderer)
	{
		this->mGirlTexture = IMG_LoadTexture(renderer, GIRL_PHOTO_FILE);
		if (!mGirlTexture)
		{
			SDL_Log("Can not load photo:%s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_bool Resource::LoadLandscapeTexture(SDL_Renderer *renderer)
	{
		this->mLandscapeTexture = IMG_LoadTexture(renderer, LANDSCAPE_PHOTO_FILE);
		if (!mLandscapeTexture)
		{
			SDL_Log("Can not load landscape:%s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_Texture *Resource::GetCatTexture()
	{
		return this->mCatTexture;
	}

	SDL_Texture *Resource::GetGirlTexture()
	{
		return this->mGirlTexture;
	}

	SDL_Texture *Resource::GetLandscapeTexture()
	{
		return this->mLandscapeTexture;
	}

	void Resource::Destory()
	{
		if (mCatTexture)
		{
			SDL_DestroyTexture(mCatTexture);
			mCatTexture = nullptr;
		}
		if (mGirlTexture)
		{
			SDL_DestroyTexture(mGirlTexture);
			mGirlTexture = nullptr;
		}
		if (mLandscapeTexture)
		{
			SDL_DestroyTexture(mLandscapeTexture);
			mLandscapeTexture = nullptr;
		}
	}
}