#ifndef _DUNGEON_EYEBALLDATA_H_
#define _DUNGEON_EYEBALLDATA_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	/*
	* �������ݽṹ��
	*/
	typedef struct EyeballData
	{
		float eyeRadius;//����뾶
		SDL_FPoint *eyeCenter;//�۾�����λ��
		SDL_Rect *eyeballSrcRect;//����ͼƬ����(10*10)
		SDL_FRect *eyeballDestRect;//��������ľ���
		SDL_Rect *eyeSrcRect;//�۾�ͼƬ����(40*40)
		SDL_FRect *eyeDestRect;//�����۾�����
	} EyeballData;
}

#endif // !_DUNGEON_EYEBALLDATA_H_

