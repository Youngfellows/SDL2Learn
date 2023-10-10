#include "Cursor.h"


namespace Dungeon
{
	Cursor::Cursor()
	{

	}

	Cursor::~Cursor()
	{

	}

	DisplayObject *Cursor::Cursor_Create(float x, float y, float w, float h)
	{
		DisplayObject *displayObject = new DisplayObject();
		if (displayObject->DisplayObject_Create(x, y, w, h,
			&Cursor_OnDraw, &Cursor_OnMouseMove))
		{
			return displayObject;
		}
		return nullptr;
	}

	/*
	* ���ַ�ʽ���ܸ�ֵdisplayObject,ֻ�Ǿֲ�����
	*/
	SDL_bool Cursor::Cursor_Create(DisplayObject *displayObject, float x, float y, float w, float h)
	{
		displayObject = new DisplayObject();
		if (displayObject->DisplayObject_Create(x, y, w, h,
			&Cursor_OnDraw, &Cursor_OnMouseMove))
		{
			return SDL_TRUE;
		}
		return SDL_TRUE;
	}

	void Cursor::Cursor_Destory(DisplayObject *displayObject)
	{
		displayObject->DisplayObject_Destory();
	}

	/*
	* ʵ�ֻص�����OnDraw
	*/
	void Cursor::Cursor_OnDraw(DisplayObject *displayObject, Resource *resource, SDL_Renderer *renderer)
	{
		SDL_RenderCopyF(renderer, resource->Resource_GetCursorTexture(), nullptr, displayObject->mDest);
	}


	/*
	* ʵ�ֻص�����OnMouseMove
	*/
	void Cursor::Cursor_OnMouseMove(DisplayObject *displayObject, SDL_Event *event)
	{
		displayObject->mDest->x = (float)event->motion.x;
		displayObject->mDest->y = (float)event->motion.y;
	}
}