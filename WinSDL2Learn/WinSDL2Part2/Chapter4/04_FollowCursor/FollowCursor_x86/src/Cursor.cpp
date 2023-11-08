#include "Cursor.h"

namespace Dungeon
{

	Cursor::Cursor(Resource *resource) :mResource(resource), mDisplayObject(nullptr)
	{

	}

	Cursor::~Cursor()
	{

	}

	/*
	* 实现的回调函数
	*/
	void Cursor::Cursor_OnDraw(SDL_Renderer *renderer)
	{
		SDL_RenderCopyF(renderer, mResource->Resource_GetCursorTexture(), nullptr, mDisplayObject->mDest);
	}

	/*
	* 实现的回调函数
	*/
	void Cursor::Cursor_OnMouseMove(SDL_Event *event)
	{
		mDisplayObject->mDest->x = (float)event->motion.x;
		mDisplayObject->mDest->y = (float)event->motion.y;
	}

	SDL_bool Cursor::Cursor_Create(float x, float y, float w, float h)
	{
		mDisplayObject = new DisplayObject();
		if (!mDisplayObject->DisplayObject_Create(x, y, w, h))
		{
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	void Cursor::Cursor_Destory()
	{
		mDisplayObject->DisplayObject_Destory();
	}
}