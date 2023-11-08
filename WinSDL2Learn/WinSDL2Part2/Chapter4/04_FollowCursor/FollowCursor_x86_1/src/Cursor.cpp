#include "Cursor.h"


namespace Dungeon
{
	Cursor::Cursor() :mCursorData(nullptr)
	{
	}

	Cursor::~Cursor()
	{

	}

	DisplayObject *Cursor::Cursor_Create(float x, float y, float w, float h)
	{
		//动态申请内存
		mCursorData = (CursorData *)malloc(sizeof(CursorData));
		if (!mCursorData)
		{
			return nullptr;
		}
		mCursorData->dest = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mCursorData->dest)
		{
			return nullptr;
		}
		mCursorData->dest->x = x;
		mCursorData->dest->y = y;
		mCursorData->dest->w = w;
		mCursorData->dest->h = h;
		DisplayObject *displayObject = new DisplayObject();
		if (!displayObject->DisplayObject_Create(
			&Cursor_OnDrawCallback,
			&Cursor_OnMouseMoveCallback,
			&Cursor_OnDestoryCallback))
		{
			return nullptr;
		}
		displayObject->subClass = this;//设置要显示对象

		return displayObject;
	}

	void Cursor::Cursor_OnDestoryCallback(DisplayObject *self)
	{
		Cursor *cursor = (Cursor *)self->subClass;
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;
			if (data)
			{
				free(data->dest);
				free(data);
			}
		}
	}

	/*
	* 回调函数OnDraw
	*/
	void Cursor::Cursor_OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		Cursor *cursor = (Cursor *)self->subClass;
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;
			if (data)
			{
				SDL_RenderCopyF(renderer, resource->Resource_GetCursorTexture(), nullptr, data->dest);
			}
		}
	}


	/*
	* 回调函数OnMouseMove
	*/
	void Cursor::Cursor_OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{
		Cursor *cursor = (Cursor *)self->subClass;
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;
			if (data)
			{
				data->dest->x = (float)event->motion.x;
				data->dest->y = (float)event->motion.y;
			}
		}
	}
}