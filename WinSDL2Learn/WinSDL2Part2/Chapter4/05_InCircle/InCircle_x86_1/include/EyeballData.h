#ifndef _DUNGEON_EYEBALLDATA_H_
#define _DUNGEON_EYEBALLDATA_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	/*
	* 眼球数据结构体
	*/
	typedef struct EyeballData
	{
		float eyeRadius;//眼球半径
		SDL_FPoint *eyeCenter;//眼睛中心位置
		SDL_Rect *eyeballSrcRect;//眼球图片矩形(10*10)
		SDL_FRect *eyeballDestRect;//绘制眼球的矩形
		SDL_Rect *eyeSrcRect;//眼睛图片矩形(40*40)
		SDL_FRect *eyeDestRect;//绘制眼睛矩形
	} EyeballData;
}

#endif // !_DUNGEON_EYEBALLDATA_H_

