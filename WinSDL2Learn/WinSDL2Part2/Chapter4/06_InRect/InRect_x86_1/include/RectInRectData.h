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
		SDL_FRect *border;//�߽����
		SliderData *slider;//�ڲ�����
	}RectInRectData;
}

#endif // !_DUNGEON_RECTINRECTDATA_H_
