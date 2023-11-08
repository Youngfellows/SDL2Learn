#include "Cursor.h"

namespace Dungeon
{
	Cursor::Cursor() :mCursorData(nullptr)
	{

	}

	Cursor::~Cursor()
	{
	}

	DisplayObject *Cursor::Create(float x, float y, float w, float h)
	{
		//动态申请内存
		this->mCursorData = (CursorData *)malloc(sizeof(CursorData));
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

		//创建要显示对象
		DisplayObject *displayObject = new DisplayObject();
		//设置回调函数
		if (!displayObject->Create(&OnDrawCallback, &OnMouseMoveCallback, &OnDestoryCallback))
		{
			return nullptr;
		}
		displayObject->subClass = this;//设置要显示数据
		return displayObject;
	}

	void Cursor::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		Cursor *cursor = (Cursor *)self->subClass;
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;
			if (data)
			{
				//绘制光标
				SDL_RenderCopyF(renderer, resource->GetCursorTexture(), nullptr, data->dest);
			}
		}
	}
	void Cursor::OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{
		Cursor *cursor = (Cursor *)self->subClass;
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

	void Cursor::OnDestoryCallback(DisplayObject *self)
	{
		Cursor *cursor = (Cursor *)self->subClass;
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;
			free(data->dest);
			free(data);
		}
	}
}