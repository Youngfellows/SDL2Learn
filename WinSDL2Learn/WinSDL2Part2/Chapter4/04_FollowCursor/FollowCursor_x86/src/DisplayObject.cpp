#include "DisplayObject.h"


namespace Dungeon
{
	DisplayObject::DisplayObject() :mDest(nullptr)
	{

	}

	DisplayObject::~DisplayObject()
	{

	}

	SDL_bool DisplayObject::DisplayObject_Create(float x, float y, float w, float h)
	{
		mDest = (SDL_FRect *)malloc(sizeof(struct SDL_FRect));
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

	void DisplayObject::DisplayObject_Destory()
	{
		if (mDest != nullptr)
		{
			free(mDest);
			mDest = nullptr;
		}
	}
}