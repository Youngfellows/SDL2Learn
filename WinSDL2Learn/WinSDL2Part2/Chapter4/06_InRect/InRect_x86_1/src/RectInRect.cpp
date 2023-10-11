#include "RectInRect.h"

#include "Config.h"

namespace Dungeon
{
	RectInRect::RectInRect() :mRectInRectData(nullptr)
	{
	}

	RectInRect::~RectInRect()
	{

	}

	DisplayObject *RectInRect::RectInRect_Create(float x, float y)
	{
		//动态申请内存
		mRectInRectData = (RectInRectData *)malloc(sizeof(RectInRectData));
		if (!mRectInRectData)
		{
			return nullptr;
		}
		mRectInRectData->border = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mRectInRectData->border)
		{
			return nullptr;
		}
		mRectInRectData->border->x = x;
		mRectInRectData->border->y = y;
		mRectInRectData->border->w = BORDER_RECT_WIDTH;
		mRectInRectData->border->h = BORDER_RECT_HEIGHT;

		mRectInRectData->slider = (SliderData *)malloc(sizeof(SliderData));
		if (!mRectInRectData->slider)
		{
			return nullptr;
		}
		mRectInRectData->slider->innerRect = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mRectInRectData->slider->innerRect)
		{
			return nullptr;
		}
		mRectInRectData->slider->innerRect->x = x;
		mRectInRectData->slider->innerRect->y = y;
		mRectInRectData->slider->innerRect->w = SLIDER_RECT_WIDTH;
		mRectInRectData->slider->innerRect->h = SLIDER_RECT_HEIGHT;

		//创建要绘制对象
		DisplayObject *displayObject = new DisplayObject();
		displayObject->mSubClassData = this;//设置要绘制实体
		//设置回调函数
		if (!displayObject->DisplayObject_Create(&RectInRect_DrawCallback,
			&RectInRect_MouseMoveCallback, &RectInRect_DestoryCallback))
		{
			return nullptr;
		}

		return displayObject;
	}

	/*
	* 回调函数OnDrawCallback
	*/
	void RectInRect::RectInRect_DrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		RectInRect *rectInRect = (RectInRect *)self->mSubClassData;
		if (rectInRect)
		{
			RectInRectData *data = rectInRect->mRectInRectData;
			if (data)
			{
				//绘制边框-红色
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderDrawRectF(renderer, data->border);

				//绘制滑块
				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
				SDL_RenderDrawRectF(renderer, data->slider->innerRect);
			}
		}
	}

	/*
	* 回调函数OnMouseMoveCallback
	*/
	void RectInRect::RectInRect_MouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{
		RectInRect *rectInRect = (RectInRect *)self->mSubClassData;
		if (rectInRect)
		{
			RectInRectData *data = rectInRect->mRectInRectData;
			if (data)
			{
				SDL_FRect *border = data->border;
				SliderData *sliderData = data->slider;
				if (sliderData)
				{
					//更新滑块位置
					SDL_FRect *inner = sliderData->innerRect;
					inner->x = event->motion.x;
					inner->y = event->motion.y;

					if (inner->x < border->x) {
						inner->x = border->x;
					}
					if (inner->x > border->x + border->w - inner->w)
					{
						inner->x = border->x + border->w - inner->w;
					}

					if (inner->y < border->y) {
						inner->y = border->y;
					}
					if (inner->y > border->y + border->h - inner->h) {
						inner->y = border->y + border->h - inner->h;
					}
				}
			}
		}
	}

	/*
	* 回调函数DestoryCallback
	*/
	void RectInRect::RectInRect_DestoryCallback(DisplayObject *self)
	{
		RectInRect *rectInRect = (RectInRect *)self->mSubClassData;
		if (rectInRect)
		{
			RectInRectData *data = rectInRect->mRectInRectData;
			if (data)
			{
				free(data->border);
				free(data->slider->innerRect);
				free(data->slider);
				free(data);
			}
		}
	}

}