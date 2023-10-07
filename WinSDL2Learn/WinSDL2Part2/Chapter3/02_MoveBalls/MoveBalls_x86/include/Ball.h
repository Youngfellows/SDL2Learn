#ifndef _DUNGEON_BALL_H_
#define _DUNGEON_BALL_H_

#include "SDL2/SDL.h"
#include "Resource.h"

namespace Dungeon
{
	class Ball
	{
	private:
		SDL_Rect mDest;
		double mAngle;
		double mRotateSpeed;
		float mSpeedX;
		float mSpeedY;

	public:
		Ball();
		~Ball();
		void Ball_Create(int x, int y, double rotateSpeed, float speedX, float speedY);
		void Ball_Draw(SDL_Renderer *renderer, Resource *resource);
		void Ball_Destory();
	};

}


#endif // !_DUNGEON_BALL_H_

