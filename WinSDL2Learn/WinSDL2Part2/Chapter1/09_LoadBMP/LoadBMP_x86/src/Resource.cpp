#include "Resource.h"
#include "Config.h"
#include "SDL_Logo.h"

namespace Dungeon
{

	Resource::Resource() :
		mWinSurface(nullptr),
		mCatSurface(nullptr),
		mSDLLogoSurface(nullptr)
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
		if (!LoadSDLLogoSurface())
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

	/*
	* 加载图片二进制数据到Surface
	*/
	SDL_bool Resource::LoadSDLLogoSurface()
	{
		this->mSDLLogoSurface = SDL_LoadBMP_RW(
			SDL_RWFromConstMem(SDLLogoData, sizeof(SDLLogoData)),
			1
		);
		if (!mSDLLogoSurface)
		{
			SDL_Log("Can not get sdl logo surface: %s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_Surface *Resource::GetSDLLogoSurface()
	{
		return this->mSDLLogoSurface;
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

		if (mSDLLogoSurface)
		{
			SDL_FreeSurface(mSDLLogoSurface);
			mSDLLogoSurface = nullptr;
		}
	}
}