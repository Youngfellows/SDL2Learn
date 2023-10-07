#include "Ball.h"
#include "Config.h"


namespace Dungeon
{
	Ball::Ball() :mAngle(0), mRotateSpeed(0)
	{

	}

	Ball::~Ball()
	{

	}

	void Ball::Ball_Create(int x, int y, double rotateSpeed, float speedX, float speedY)
	{
		this->mDest.x = x;
		this->mDest.y = y;
		this->mDest.w = 30;
		this->mDest.h = 30;
		this->mAngle = 0;
		this->mRotateSpeed = rotateSpeed;
		this->mSpeedX = speedX;
		this->mSpeedY = speedY;
	}

	void Ball::Ball_Draw(SDL_Renderer *renderer, Resource *resource)
	{
		this->mAngle += this->mRotateSpeed;
		this->mDest.x += this->mSpeedX;
		this->mDest.y += this->mSpeedY;

		if (((this->mDest.x > WINDOW_WIDTH - this->mDest.w) && this->mSpeedX > 0)
			|| (this->mDest.x < 0 && this->mSpeedX < 0))
		{
			this->mSpeedX *= -1;
		}

		if (((this->mDest.y > WINDOW_HEIGHT - this->mDest.h) && this->mSpeedY > 0)
			|| (this->mDest.y < 0 && this->mSpeedY < 0))
		{
			this->mSpeedY *= -1;
		}

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