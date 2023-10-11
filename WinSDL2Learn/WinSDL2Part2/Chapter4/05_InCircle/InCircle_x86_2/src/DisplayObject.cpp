#include "DisplayObject.h"


namespace Dungeon
{
	DisplayObject::DisplayObject(Eyeball *eyeball) :mEyeball(eyeball)
	{

	}

	void DisplayObject::DisplayObject_Draw(Resource *resource, SDL_Renderer *renderer)
	{
		if (mEyeball)
		{
			mEyeball->Eyeball_CursorOnDraw(resource, renderer);
		}

	}

	void DisplayObject::DisplayObject_OnMouseMove(SDL_Event *event)
	{
		if (mEyeball != nullptr)
		{
			mEyeball->Eyeball_CursorOnMouseMove(event);
		}
	}

	void DisplayObject::DisplayObject_Destory()
	{
		if (mEyeball)
		{
			mEyeball->Eyeball_Destory();
		}
	}

	DisplayObject::~DisplayObject()
	{

	}
}