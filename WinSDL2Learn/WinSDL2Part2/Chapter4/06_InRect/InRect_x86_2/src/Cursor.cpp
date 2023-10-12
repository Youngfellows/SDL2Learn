#include "Cursor.h"

namespace Dungeon
{
	Cursor::Cursor() :mCursorData(nullptr)
	{

	}

	Cursor::~Cursor()
	{
	}

	CursorData *Cursor::GetCursorData()
	{
		return this->mCursorData;
	}

	SDL_bool Cursor::Create(float x, float y, float w, float h)
	{
		this->mCursorData = (CursorData *)malloc(sizeof(CursorData));//动态申请内存
		if (!mCursorData)
		{
			return SDL_FALSE;
		}
		mCursorData->dest = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mCursorData->dest)
		{
			return SDL_FALSE;
		}
		mCursorData->dest->x = x;
		mCursorData->dest->y = y;
		mCursorData->dest->w = w;
		mCursorData->dest->h = h;
		return  SDL_TRUE;;
	}

	void Cursor::Destory()
	{
		CursorData *data = mCursorData;
		//CursorData *data = GetCursorData();
		if (data)
		{
			if (data->dest)
			{
				free(data->dest);
			}
			free(data);
		}
	}


	void Cursor::OnDraw(Resource *resource, SDL_Renderer *renderer)
	{
		//CursorData *data = mCursorData;
		CursorData *data = GetCursorData();
		if (data)
		{
			//绘制光标
			SDL_RenderCopyF(renderer, resource->GetCursorTexture(), nullptr, data->dest);
		}
	}


	void Cursor::OnMouseMove(SDL_Event *event)
	{
		CursorData *data = mCursorData;
		if (data)
		{
			//更新光标位置
			data->dest->x = event->motion.x;
			data->dest->y = event->motion.y;
		}
	}
}