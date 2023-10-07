#include "Resource.h"

namespace Dungeon
{
#define BALL_FILE_NAME "./resources/ball.png"

	Resource::Resource() :mBallTexture(nullptr)
	{

	}

	Resource::~Resource()
	{

	}

	bool Resource::Resource_Load(SDL_Renderer *renderer)
	{
		mBallTexture = IMG_LoadTexture(renderer, BALL_FILE_NAME);
		if (!mBallTexture)
		{
			SDL_Log("Can not load image: %s", SDL_GetError());
			return false;
		}
		return true;
	}

	SDL_Texture *Resource::Resource_GetBallTexture()
	{
		return mBallTexture;
	}

	void Resource::Resource_Unload()
	{
		SDL_DestroyTexture(mBallTexture);
	}
}