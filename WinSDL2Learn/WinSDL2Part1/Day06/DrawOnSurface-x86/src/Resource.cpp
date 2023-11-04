#include "Resource.h"
#include "Config.h"

namespace Dungeon
{

	Resource::Resource() :
		mWinSurface(nullptr),
		mCatSurface(nullptr)
	{

	}

	Resource::~Resource()
	{
		Destory();
	}

	SDL_bool Resource::Load(SDL_Window *window)
	{
		if (!LoadWinSurface(window))
		{
			return SDL_FALSE;
		}
		if (!LoadCatSurface())
		{
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_bool Resource::LoadWinSurface(SDL_Window *window)
	{
		this->mWinSurface = SDL_GetWindowSurface(window);
		if (!mWinSurface)
		{
			SDL_Log("Can not get window surface: %s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_bool Resource::LoadCatSurface()
	{
		this->mCatSurface = SDL_LoadBMP(CAT_PHOTO_BMP_FILE);
		if (!mCatSurface)
		{
			SDL_Log("Can not get cat surface: %s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_Surface *Resource::GetWinSurface()
	{
		return this->mWinSurface;
	}

	SDL_Surface *Resource::GetCatSurface()
	{
		return this->mCatSurface;
	}

	void Resource::Destory()
	{
		if (mWinSurface)
		{
			SDL_FreeSurface(mWinSurface);
			mWinSurface = nullptr;
		}

		if (mCatSurface)
		{
			SDL_FreeSurface(mCatSurface);
			mCatSurface = nullptr;
		}
	}
}