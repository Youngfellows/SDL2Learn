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

	public:
		Ball();
		~Ball();
		void Ball_Create(int x, int y, double rotateSpeed);
		void Ball_Draw(SDL_Renderer *renderer, Resource *resource);
		void Ball_Destory();
	};

}


#endif // !_DUNGEON_BALL_H_

