#include "Resource.h"


namespace Dungeon
{
	Resource::Resource() :
		mCursorTexture(nullptr), mCursorSurface(nullptr), mCursor(nullptr),
		mBackgroundTexture(nullptr)
	{
	}

	Resource::~Resource()
	{
		Unload();
	}

	SDL_bool Resource::LoadCursor(const char *file, SDL_Renderer *renderer)
	{
		mCursorSurface = IMG_Load(file);
		if (!mCursorSurface)
		{
			SDL_Log("Can not load cursor: %s", SDL_GetError());
			return SDL_FALSE;
		}
		mCursor = SDL_CreateColorCursor(mCursorSurface, 0, 0);
		if (!mCursor)
		{
			SDL_Log("Can not create cursor: %s", SDL_GetError());
			return SDL_FALSE;
		}
		mCursorTexture = SDL_CreateTextureFromSurface(renderer, mCursorSurface);
		if (!mCursorTexture)
		{
			SDL_Log("Can not create cursor texture: %s", SDL_GetError());
			return SDL_FALSE;
		}

		return SDL_TRUE;
	}

	SDL_bool Resource::LoadBackground(const char *file, SDL_Renderer *renderer)
	{
		mBackgroundTexture = IMG_LoadTexture(renderer, file);
		if (!mBackgroundTexture)
		{
			SDL_Log("Can not load background image: %s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_Surface *Resource::GetCursorSurface()
	{
		return this->mCursorSurface;
	}

	SDL_Cursor *Resource::GetCursor()
	{
		return this->mCursor;
	}

	SDL_Texture *Resource::GetCursorTexture()
	{
		return this->mCursorTexture;
	}

	SDL_Texture *Resource::GetBackgroundTexture()
	{
		return this->mBackgroundTexture;
	}

	void Resource::Unload()
	{
		if (mBackgroundTexture)
		{
			SDL_DestroyTexture(mBackgroundTexture);
			mBackgroundTexture = nullptr;
		}
		if (mCursorTexture)
		{
			SDL_DestroyTexture(mCursorTexture);
			mCursorTexture = nullptr;
		}
		if (mCursor)
		{
			SDL_FreeCursor(mCursor);
			mCursor = nullptr;
		}
		if (mCursorSurface)
		{
			SDL_FreeSurface(mCursorSurface);
			mCursorSurface = nullptr;
		}
	}
}