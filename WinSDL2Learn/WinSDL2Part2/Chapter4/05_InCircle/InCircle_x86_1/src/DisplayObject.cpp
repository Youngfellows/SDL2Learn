#include "DisplayObject.h"


namespace Dungeon
{
	DisplayObject::DisplayObject() :subClassData(nullptr), OnDraw(nullptr), OnMouseMove(nullptr)
	{
	}

	void DisplayObject::DisplayObject_Create(DisplayObject_OnDrawCallback onDrawCallback,
		DisplayObject_OnMouseMoveCallback onMouseMoveCallback)
	{
		this->OnDraw = onDrawCallback;//设置OnDraw回调函数
		this->OnMouseMove = onMouseMoveCallback;//设置OnMouseMove回调函数
	}

	void DisplayObject::DisplayObject_Draw(Resource *resource, SDL_Renderer *renderer)
	{
		if (OnDraw != nullptr)
		{
			OnDraw(this, resource, renderer);//调用OnDraw回调函数
		}
	}

	void DisplayObject::DisplayObject_OnMouseMove(SDL_Event *event)
	{
		if (OnMouseMove)
		{
			OnMouseMove(this, event);//调用OnMouseMove回调函数
		}
	}

	void DisplayObject::DisplayObject_Destory()
	{

	}

	DisplayObject::~DisplayObject()
	{
	}
}