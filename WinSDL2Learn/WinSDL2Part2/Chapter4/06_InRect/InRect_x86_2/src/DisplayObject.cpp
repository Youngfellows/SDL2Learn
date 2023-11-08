#include "DisplayObject.h"

#include "Config.h"

namespace Dungeon
{

	DisplayObject::DisplayObject() :mCursor(nullptr), mRectInRect(nullptr)
	{

	}

	DisplayObject::~DisplayObject()
	{

	}

	SDL_bool DisplayObject::CreateComponents()
	{
		//光标
		Cursor *cursor = new Cursor();
		if (!cursor->Create(0, 0, CURSOR_DESTRECT_WIDTH, CURSOR_DESTRECT_HEIGHT))
		{
			return SDL_FALSE;
		}
		SetCursor(cursor);

		//带滑块的内部矩形
		RectInRect *recrInRect = new RectInRect();
		if (!recrInRect->Create(100, 100))
		{
			return SDL_FALSE;
		}
		SetRectInRect(recrInRect);
		return SDL_TRUE;
	}

	void DisplayObject::SetCursor(Cursor *cursor)
	{
		this->mCursor = cursor;
	}

	void DisplayObject::SetRectInRect(RectInRect *rectInRect)
	{
		this->mRectInRect = rectInRect;
	}

	void DisplayObject::DrawCursor(Resource *resource, SDL_Renderer *renderer)
	{
		if (mCursor)
		{
			mCursor->OnDraw(resource, renderer);
		}
	}

	void DisplayObject::CursorOnMouseMove(SDL_Event *event)
	{
		if (mCursor)
		{
			mCursor->OnMouseMove(event);
		}
	}

	void DisplayObject::DrawRectInRect(Resource *resource, SDL_Renderer *renderer)
	{
		if (mRectInRect)
		{
			mRectInRect->OnDraw(resource, renderer);
		}
	}

	void DisplayObject::RectInRectOnMouseMove(SDL_Event *event)
	{
		if (mRectInRect)
		{
			mRectInRect->OnMouseMove(event);
		}
	}

	void DisplayObject::Destory()
	{
		if (mCursor)
		{
			mCursor->Destory();
		}
		if (mRectInRect)
		{
			mRectInRect->Destory();
		}
	}

	void DisplayObject::Draw(Resource *resource, SDL_Renderer *renderer)
	{
		DrawCursor(resource, renderer);
		DrawRectInRect(resource, renderer);
	}

	void DisplayObject::OnMouseMove(SDL_Event *event)
	{
		CursorOnMouseMove(event);
		RectInRectOnMouseMove(event);
	}
}