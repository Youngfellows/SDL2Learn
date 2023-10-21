#include "Cursor.h"

namespace Dungeon
{
	Cursor::Cursor() :mCursorData(nullptr)
	{

	}

	Cursor::~Cursor()
	{
		CursorData *data = mCursorData;
		if (data)
		{
			free(data->dest);
			free(data);
			data = nullptr;
		}
	}

	DisplayObject *Cursor::Create(float x, float y, float w, float h)
	{
		//动态申请内存
		this->mCursorData = (CursorData *)malloc(sizeof(CursorData));
		if (!mCursorData)
		{
			//SDL_Log("Can not create cursor data in memory");
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

		//设置要显示的对象
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//设置要显示数据
		OnCallbackData *onCallback = displayObject->GetOnCallback();//设置回调函数
		if (onCallback)
		{
			onCallback->OnDraw = &OnDrawCallback;
			onCallback->OnMouseMove = &OnMouseMoveCallback;
			onCallback->OnDestory = &OnDestoryCallback;
		}
		return displayObject;
	}

	void Cursor::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		Cursor *cursor = (Cursor *)self->GetSubClass();//获取显示对象
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;
			if (data)
			{
				if (resource)
				{
					//显示光标
					SDL_RenderCopyF(renderer, resource->GetCursorTexture(), nullptr, data->dest);
				}
			}
		}
	}

	void Cursor::OnDestoryCallback(DisplayObject *self)
	{
		Cursor *cursor = (Cursor *)self->GetSubClass();//获取显示对象
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;
			if (data)
			{
				free(data->dest);
				free(data);
				data = nullptr;
			}
		}
	}

	void Cursor::OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{
		Cursor *cursor = (Cursor *)self->GetSubClass();//获取显示对象
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;
			if (data)
			{
				//更新光标位置
				data->dest->x = event->motion.x;
				data->dest->y = event->motion.y;
			}
		}
	}
}