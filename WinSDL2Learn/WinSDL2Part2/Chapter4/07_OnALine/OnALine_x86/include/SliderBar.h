#ifndef _DUNGEON_SLIDER_H_
#define _DUNGEON_SLIDER_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	//��������
	typedef struct SliderData
	{
		SDL_FPoint *sliderPoint;//���鴥��λ��
		SDL_FRect *sliderDest;//Ҫ���ƻ������λ��
	}SliderData;

	//����������
	typedef struct SliderBarData
	{
		SDL_FRect *border;//�������߿�
		SliderData *sliderData;//��������
	}SliderBarData;
}

namespace Dungeon
{
	class SliderBar
	{
	private:
		SliderBarData *mSliderBarData;//����������

	public:
		SliderBar();
		~SliderBar();
		DisplayObject *Create(float borderX, float borderY, float borderW, float borderH,
			float sliderW, float sliderH);
		static void OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void OnMouseMoveCallback(DisplayObject *self, SDL_Event *event);
		static void OnDestoryCallback(DisplayObject *self);
	};
}
#endif // !_DUNGEON_SLIDER_H_

