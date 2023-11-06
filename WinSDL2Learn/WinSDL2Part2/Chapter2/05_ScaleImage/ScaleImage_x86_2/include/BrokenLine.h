#ifndef _DUNGEON_BROKEN_LINE_H_
#define _DUNGEON_BROKEN_LINE_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include <iostream>

//using namespace std;

namespace Dungeon
{
	typedef struct BrokenLineData
	{
		int color;
		int size;//绘制点数目
		SDL_FPoint *points;//绘制点列表
	}BrokenLineData;
}

namespace Dungeon
{
	class BrokenLine
	{
	private:
		BrokenLineData mBrokenLineData;

	public:
		BrokenLine();
		~BrokenLine();
		DisplayObject *Create(int color, int size, std::initializer_list<SDL_FPoint> pointList);
		static void OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void OnDestoryCallback(DisplayObject *self);

	private:
		void DrawBrokenLine(SDL_Renderer *renderer);
		void Destory();
	};
}

#endif // !_DUNGEON_BROKEN_LINE_H_
