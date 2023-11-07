#include "Resource.h"
#include "Config.h"
#include "SDL2/SDL_image.h"

namespace Dungeon
{

	Resource::Resource() :
		mWinSurface(nullptr),
		mCatSurface(nullptr),
		mSasaSurface(nullptr),
		mYayaSurface(nullptr)
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
		if (!LoadSasaSurface())
		{
			return SDL_FALSE;
		}
		if (!LoadYayaSurface())
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

	SDL_bool Resource::LoadSasaSurface()
	{
		// 读取图片存为surface形式
		//this->mSasaSurface = SDL_LoadBMP(CAT_PHOTO_BMP_FILE);
		this->mSasaSurface = IMG_Load(GIRL_SASA_PHOTO_FILE);
		if (!mSasaSurface)
		{
			SDL_Log("Can not get sasa surface: %s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_bool Resource::LoadYayaSurface()
	{
		// 读取图片存为surface形式
		//this->mSasaSurface = SDL_LoadBMP(CAT_PHOTO_BMP_FILE);
		this->mYayaSurface = IMG_Load(GIRL_YAYA_PHOTO_FILE);
		if (!mYayaSurface)
		{
			SDL_Log("Can not get yaya surface: %s", SDL_GetError());
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

	SDL_Surface *Resource::GetSasaSurface()
	{
		return this->mSasaSurface;
	}

	SDL_Surface *Resource::GetYayaSurface()
	{
		return this->mYayaSurface;
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

		if (mSasaSurface)
		{
			SDL_FreeSurface(mSasaSurface);
			mSasaSurface = nullptr;
		}

		if (mYayaSurface)
		{
			SDL_FreeSurface(mYayaSurface);
			mYayaSurface = nullptr;
		}
	}
}