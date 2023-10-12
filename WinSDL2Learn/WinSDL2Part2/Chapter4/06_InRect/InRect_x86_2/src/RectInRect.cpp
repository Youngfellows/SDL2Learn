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

	SDL_bool RectInRect::Create(float x, float y)
	{
		//¶¯Ì¬ÉêÇëÄÚ´æ
		mRectInRectData = (RectInRectData *)malloc(sizeof(RectInRectData));
		if (!mRectInRectData)
		{
			return SDL_FALSE;
		}
		mRectInRectData->border = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mRectInRectData->border)
		{
			return SDL_FALSE;
		}
		mRectInRectData->border->x = x;
		mRectInRectData->border->y = y;
		mRectInRectData->border->w = BORDER_RECT_WIDTH;
		mRectInRectData->border->h = BORDER_RECT_HEIGHT;

		mRectInRectData->slider = (SliderData *)malloc(sizeof(SliderData));
		if (!mRectInRectData->slider)
		{
			return SDL_FALSE;
		}
		mRectInRectData->slider->innerRect = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mRectInRectData->slider->innerRect)
		{
			return SDL_FALSE;
		}
		mRectInRectData->slider->innerRect->x = x;
		mRectInRectData->slider->innerRect->y = y;
		mRectInRectData->slider->innerRect->w = SLIDER_RECT_WIDTH;
		mRectInRectData->slider->innerRect->h = SLIDER_RECT_HEIGHT;

		return SDL_TRUE;
	}

	void RectInRect::OnDraw(Resource *resource, SDL_Renderer *renderer)
	{
		RectInRectData *data = mRectInRectData;
		if (data)
		{
			//»æÖÆ±ß¿ò-ºìÉ«
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderDrawRectF(renderer, data->border);

			//»æÖÆ»¬¿é
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			SDL_RenderDrawRectF(renderer, data->slider->innerRect);
		}
	}

	void RectInRect::OnMouseMove(SDL_Event *event)
	{
		RectInRectData *data = mRectInRectData;
		if (data)
		{
			SDL_FRect *border = data->border;
			SliderData *sliderData = data->slider;
			if (sliderData)
			{
				//¸üĞÂ»¬¿éÎ»ÖÃ
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

	void RectInRect::Destory()
	{
		RectInRectData *data = mRectInRectData;
		if (data)
		{
			free(data->border);
			free(data->slider->innerRect);
			free(data->slider);
			free(data);
		}
	}

}