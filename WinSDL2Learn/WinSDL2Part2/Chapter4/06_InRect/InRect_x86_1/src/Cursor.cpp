#include "Cursor.h"

namespace Dungeon
{
	Cursor::Cursor() :mCursorData(nullptr)
	{

	}

	Cursor::~Cursor()
	{
	}

	CursorData *Cursor::Cursor_GetCursorData()
	{
		return this->mCursorData;
	}

	DisplayObject *Cursor::Cursor_Create(float x, float y, float w, float h)
	{
		this->mCursorData = (CursorData *)malloc(sizeof(CursorData));//动态申请内存
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

		//创建要显示的对象
		DisplayObject *displayObject = new DisplayObject();

		//为displayObject设置回调函数
		if (!displayObject->DisplayObject_Create(&Cursor_OnDrawCallback,
			&Cursor_OnMouseMoveCallback, &Cursor_DestoryCallback))
		{
			//displayObject->DisplayObject_Destory();
			return nullptr;
		}
		displayObject->mSubClassData = this;//设置显示数据
		return displayObject;
	}

	/*
	* 被调用的回调函数,只能是静态的,不能访问非静态成员,通过传参来访问
	*/
	void Cursor::Cursor_DestoryCallback(DisplayObject *self)
	{
		//释放内存
		Cursor *cursor = (Cursor *)self->mSubClassData;//获取传递的对象
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;

			if (data)
			{
				if (data->dest)
				{
					free(data->dest);
				}
				free(data);
			}
		}
	}

	/*
	* 被调用的回调函数,只能是静态的,不能访问非静态成员,通过传参来访问
	*/
	void Cursor::Cursor_OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		Cursor *cursor = (Cursor *)self->mSubClassData;//获取传递的对象
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;
			//CursorData *data = cursor->Cursor_GetCursorData();
			if (data)
			{
				//绘制光标
				SDL_RenderCopyF(renderer, resource->Resource_GetCursorTexture(), nullptr, data->dest);
			}
		}
	}

	/*
	* 被调用的回调函数,只能是静态的,不能访问非静态成员,通过传参来访问
	*/
	void Cursor::Cursor_OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{
		Cursor *cursor = (Cursor *)self->mSubClassData;//获取传递的对象
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;
			//CursorData *data = cursor->Cursor_GetCursorData();
			if (data)
			{
				//更新光标位置
				data->dest->x = event->motion.x;
				data->dest->y = event->motion.y;
			}
		}
	}
}