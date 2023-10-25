#include "DisplayObject.h"


namespace Game
{
	DisplayObject::DisplayObject() :dest(nullptr), onDraw(nullptr), onMouseMove(nullptr)
	{
	}

	DisplayObject::~DisplayObject()
	{
	}

	bool DisplayObject::DisplayObject_Create(float x, float y, float w, float h,
		DisplayObject_OnDrawCallback onDrawCallback,
		DisplayObject_OnMouseMoveCallback onMouseMoveCallback)
	{
		this->dest = new FRect();
		dest->x = x;
		dest->y = y;
		dest->w = w;
		dest->h = h;

		this->onDraw = onDrawCallback;
		this->onMouseMove = onMouseMoveCallback;
		return true;
	}

	void DisplayObject::DisplayObject_Draw(struct Renderer *renderer)
	{
		if (onDraw != nullptr)
		{
			onDraw(this, renderer);
		}
	}

	void DisplayObject::DisplayObject_OnMouseMove(struct Event *event)
	{
		if (onMouseMove != nullptr)
		{
			onMouseMove(this, event);
		}
	}

	void DisplayObject::DisplayObject_Destory()
	{
		delete dest;
	}
}