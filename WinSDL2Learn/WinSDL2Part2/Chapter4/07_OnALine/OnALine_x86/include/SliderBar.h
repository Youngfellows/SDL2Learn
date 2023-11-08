#ifndef _DUNGEON_SLIDER_H_
#define _DUNGEON_SLIDER_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	//滑块数据
	typedef struct SliderData
	{
		SDL_FPoint *sliderPoint;//滑块触摸位置
		SDL_FRect *sliderDest;//要绘制滑块矩形位置
	}SliderData;

	//滑动条数据
	typedef struct SliderBarData
	{
		SDL_FRect *border;//滑动条边框
		SliderData *sliderData;//滑块数据
	}SliderBarData;
}

namespace Dungeon
{
	class SliderBar
	{
	private:
		SliderBarData *mSliderBarData;//滑动条数据

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

