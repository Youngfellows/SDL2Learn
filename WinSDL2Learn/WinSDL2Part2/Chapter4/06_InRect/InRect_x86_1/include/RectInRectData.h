#ifndef _DUNGEON_RECTINRECTDATA_H_
#define _DUNGEON_RECTINRECTDATA_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	typedef struct SliderData
	{
		SDL_FRect *innerRect;
	} SliderData;

	typedef struct RectInRectData
	{
		SDL_FRect *border;//边界矩形
		SliderData *slider;//内部滑块
	}RectInRectData;
}

#endif // !_DUNGEON_RECTINRECTDATA_H_
