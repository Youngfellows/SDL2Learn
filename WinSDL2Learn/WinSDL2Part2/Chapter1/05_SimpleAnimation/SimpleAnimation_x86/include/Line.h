#ifndef _DUNGEON_LINE_H_
#define _DUNGEON_LINE_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	typedef struct LineData
	{
		int color;//颜色
		SDL_Point start;//开始位置
		SDL_Point end;//结束位置
		int winWidth;//窗口宽
		int winHeight;//窗口高
		float k;//斜率
		float b;//截距
	}LineData;
}

namespace Dungeon
{
	class Line
	{
	private:
		LineData *mLineData;

	public:
		Line();
		~Line();
		DisplayObject *Create(int color, int x1, int y1, int x2, int y2, int w, int h);
		static void OnDrawCallback(DisplayObject *self, SDL_Surface *winSurface, Resource *resource);
		static void OnDestoryCallback(DisplayObject *self);

	private:
		void Draw(SDL_Surface *winSurface);
		void Destory();
	};
}
#endif // !

