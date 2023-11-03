#include "Resource.h"


namespace Dungeon
{

	Resource::Resource() :mWinSurface(nullptr)
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

	SDL_Surface *Resource::GetWinSurface()
	{
		return this->mWinSurface;
	}

	void Resource::Destory()
	{
		if (mWinSurface)
		{
			SDL_FreeSurface(mWinSurface);
			mWinSurface = nullptr;
		}
	}
}