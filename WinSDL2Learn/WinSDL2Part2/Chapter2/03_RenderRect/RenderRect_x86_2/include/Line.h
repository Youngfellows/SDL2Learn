#ifndef _DUNGEON_LINE_H_
#define _DUNGEON_LINE_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"

namespace Dungeon
{
	typedef struct LineData
	{
		int color;
		SDL_FPoint start;//起始点
		SDL_FPoint end;//结束点
	}LineData;
}

namespace Dungeon
{
	class Line
	{
	private:
		LineData mLineData;

	public:
		Line();
		~Line();
		DisplayObject *Create(int color, SDL_FPoint start, SDL_FPoint end);
		static void OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void OnDestoryCallback(DisplayObject *self);

	private:
		void DrawLine(SDL_Renderer *renderer);
		void Destory();
	};
}


#endif // !_DUNGEON_LINE_H_

