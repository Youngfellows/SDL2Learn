#include "Resource.h"
#include "Config.h"

namespace Dungeon
{
	Resource::Resource() :
		mCursorTexture(nullptr), mCursorSurface(nullptr), mCursor(nullptr),
		mBackgroundTexture(nullptr), mPlayerTexture(nullptr), mMineTexture(nullptr)
	{
	}

	Resource::~Resource()
	{
		Unload();
	}

	SDL_bool  Resource::load(SDL_Renderer *renderer)
	{
		// 加载光标资源
		if (!LoadCursor(CURSOR_FILE_NAME, renderer))
		{
			return SDL_FALSE;
		}
		//加载背景图
		if (!LoadBackground(BACKGROUND_FILE_NAME, renderer))
		{
			return SDL_FALSE;
		}
		//加载玩家
		if (!LoadPlayer(PLAYER_FILE_NAME, renderer))
		{
			return SDL_FALSE;
		}
		//加载雷
		if (!LoadMine(MINE_FILE_NAME, renderer))
		{
			return SDL_FALSE;
		}
		return SDL_TRUE;
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

	SDL_bool Resource::LoadPlayer(const char *file, SDL_Renderer *renderer)
	{
		mPlayerTexture = IMG_LoadTexture(renderer, file);
		if (!mPlayerTexture)
		{
			SDL_Log("Can not load player image: %s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	SDL_bool Resource::LoadMine(const char *file, SDL_Renderer *renderer)
	{
		SDL_Surface *mineSurface = SDL_LoadBMP(file);
		if (!mineSurface)
		{
			SDL_Log("Can not load mine image: %s", SDL_GetError());
			return SDL_FALSE;
		}
		//mMineTexture = IMG_LoadTexture(renderer, file);
		mMineTexture = SDL_CreateTextureFromSurface(renderer, mineSurface);
		SDL_FreeSurface(mineSurface);
		if (!mMineTexture)
		{
			SDL_Log("Can not create mine texture: %s", SDL_GetError());
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

	SDL_Texture *Resource::GetPlayerTexture()
	{
		return this->mPlayerTexture;
	}

	SDL_Texture *Resource::GetMineTexture()
	{
		return this->mMineTexture;
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
		if (mPlayerTexture)
		{
			SDL_DestroyTexture(mPlayerTexture);
			mPlayerTexture = nullptr;
		}
		if (mMineTexture)
		{
			SDL_DestroyTexture(mMineTexture);
			mMineTexture = nullptr;
		}
	}
}