#include "Resource.h"


namespace Dungeon
{
#define CURSOR_FILE_NAME "./resources/cursor.png"

	Resource::Resource() :mCursorSurface(nullptr), mCursor(nullptr), mCursorTexture(nullptr)
	{
	}

	SDL_bool Resource::Resource_Load(SDL_Renderer *renderer)
	{
		mCursorSurface = IMG_Load(CURSOR_FILE_NAME);
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
			SDL_Log("Can not create texture: %s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_Surface *Resource::Resource_GetCursorSurface()
	{
		return this->mCursorSurface;
	}

	SDL_Cursor *Resource::Resource_GetCursor()
	{
		return this->mCursor;
	}

	SDL_Texture *Resource::Resource_GetCursorTexture()
	{
		return this->mCursorTexture;
	}

	Resource::~Resource()
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