#include "DisplayObject.h"

namespace Dungeon
{
	DisplayObject::DisplayObject() :mDest(nullptr), OnDraw(nullptr), OnMouseMove(nullptr)
	{

	}

	DisplayObject::~DisplayObject()
	{

	}

	SDL_bool DisplayObject::DisplayObject_Create(float x, float y, float w, float h,
		DisplayObject_OnDrawCallback onDrawCallback,
		DisplayObject_OnMouseMoveCallback onMouseMoveCallback)
	{
		this->OnDraw = onDrawCallback;//设置回调函数OnDraw
		this->OnMouseMove = onMouseMoveCallback;//设置回调函数OnMouseMove
		this->mDest = (struct SDL_FRect *)malloc(sizeof(struct SDL_FRect));
		if (!mDest)
		{
			return SDL_FALSE;
		}
		mDest->x = x;
		mDest->y = y;
		mDest->w = w;
		mDest->h = h;

		return SDL_TRUE;
	}

	void DisplayObject::DisplayObject_Draw(Resource *resource, SDL_Renderer *renderer)
	{
		if (OnDraw)
		{
			OnDraw(this, resource, renderer);//调用回调函数OnDraw
		}
	}

	void DisplayObject::DisplayObject_OnMouseMove(SDL_Event *event)
	{
		if (OnMouseMove)
		{
			OnMouseMove(this, event);//调用回调函数OnMouseMove
		}
	}

	void DisplayObject::DisplayObject_Destory()
	{
		if (mDest)
		{
			free(mDest);
		}
	}
}