#include "Ball.h"


namespace Dungeon
{
	Ball::Ball() :mAngle(0), mRotateSpeed(0)
	{

	}

	Ball::~Ball()
	{

	}

	void Ball::Ball_Create(int x, int y, double rotateSpeed)
	{
		this->mDest.x = x;
		this->mDest.y = y;
		this->mDest.w = 30;
		this->mDest.h = 30;
		this->mAngle = 0;
		this->mRotateSpeed = rotateSpeed;
	}

	void Ball::Ball_Draw(SDL_Renderer *renderer,Resource *resource)
	{
		this->mAngle += this->mRotateSpeed;
		if (resource)
		{
			SDL_RenderCopyEx(renderer,
				resource->Resource_GetBallTexture(),
				NULL,
				&(this->mDest),
				this->mAngle,
				NULL,
				SDL_FLIP_NONE);
		}

	}

	void Ball::Ball_Destory()
	{

	}
}