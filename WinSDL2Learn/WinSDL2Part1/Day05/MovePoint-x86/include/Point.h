#ifndef  _DUNGEON_POINT_H_
#define _DUNGEON_POINT_H_

#include "SDL2/SDL.h"
#include "Resource.h"

namespace Dungeon
{
	typedef struct PointData
	{
		Uint32 color;//颜色
		float x;
		float y;
		float speedX;
		float speedY;
		SDL_FRect border;//边界
		float angel;
		SDL_Texture *photo;
	}PointData;
}

namespace Dungeon
{
	class Point
	{
	private:
		const float WIDTH_HEIGHT = 30;

	public:
		PointData *mPointData;

	public:
		Point(Resource *resource, Uint32 color, SDL_FRect border);
		~Point();
		void Draw(Resource *resource, SDL_Renderer *renderer);
	};
}
#endif // ! _DUNGEON_POINT_H_

