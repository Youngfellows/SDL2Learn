#include "Resource.h"

#include "Config.h"

namespace Dungeon
{

	Resource::Resource() :mCursorSurface(nullptr), mCursor(nullptr), mCursorTexture(nullptr)
	{
	}

	Resource::~Resource()
	{

	}

	SDL_bool Resource::Create(SDL_Renderer *renderer)
	{
		this->mCursorSurface = IMG_Load(CURSOR_FILE_NAME);
		if (!mCursorSurface)
		{
			SDL_Log("Can not load cursor: %s", SDL_GetError());
			return SDL_FALSE;
		}
		this->mCursor = SDL_CreateColorCursor(mCursorSurface, 0, 0);
		if (!mCursor)
		{
			SDL_Log("Can not create cursor: %s", SDL_GetError());
			return SDL_FALSE;
		}
		this->mCursorTexture = SDL_CreateTextureFromSurface(renderer, mCursorSurface);
		if (!mCursorTexture)
		{
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

	void Resource::Destory()
	{
		if (mCursorTexture)
		{
			SDL_DestroyTexture(mCursorTexture);
		}
		if (mCursor)
		{
			SDL_FreeCursor(mCursor);
		}
		if (mCursorSurface)
		{
			SDL_FreeSurface(mCursorSurface);
		}
	}
}