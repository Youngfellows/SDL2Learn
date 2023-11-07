#include "RectShape.h"

namespace Dungeon
{
	RectShape::RectShape(float x, float y, float w, float h, uint32_t color)
		:mColor(color), dragEnabled(false), mPre(nullptr), mNext(nullptr)
	{
		mDest.x = (int)x;
		mDest.y = (int)y;
		mDest.w = (int)w;
		mDest.h = (int)h;
	}

	void RectShape::RectShape_Draw(SDL_Renderer *renderer)
	{
		// 0xffff0000 ARGB
		SDL_SetRenderDrawColor(
			renderer,
			(mColor & 0x00ff0000) >> 16,
			(mColor & 0x0000ff00) >> 8,
			(mColor & 0x000000ff),
			(mColor & 0xff000000) >> 24
		);
		SDL_RenderFillRect(renderer, &mDest);
	}

	SDL_bool RectShape::RectShape_OnMouseEvent(SDL_Event *event)
	{
		SDL_Point currentMousePoint = { event->button.x,event->button.y };
		SDL_Rect destRect = { mDest.x,mDest.y,mDest.w,mDest.h };
		switch (event->type)
		{
		case SDL_MOUSEMOTION:
			if (dragEnabled)
			{
				mDest.x = mDragStartPoint.x + (event->motion.x - mDragStartMousePoint.x);
				mDest.y = mDragStartPoint.y + (event->motion.y - mDragStartMousePoint.y);
				return SDL_TRUE;
			}

			break;
		case SDL_MOUSEBUTTONDOWN:
			if (SDL_PointInRect(&currentMousePoint, &destRect))
			{
				mDragStartPoint.x = mDest.x;
				mDragStartPoint.y = mDest.y;
				mDragStartMousePoint.x = event->button.x;
				mDragStartMousePoint.y = event->button.y;
				dragEnabled = SDL_TRUE;
				return SDL_TRUE;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (SDL_PointInRect(&currentMousePoint, &destRect))
			{
				dragEnabled = false;
				return SDL_TRUE;
			}
			break;
		default:
			break;
		}
		return SDL_FALSE;
	}

	void RectShape::RectShape_Destory()
	{

	}

	RectShape::~RectShape()
	{

	}
}