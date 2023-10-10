#include "DisplayObject.h"


namespace Dungeon
{
	DisplayObject::DisplayObject() :subClassData(nullptr), OnDraw(nullptr), OnMouseMove(nullptr)
	{
	}

	void DisplayObject::DisplayObject_Create(DisplayObject_OnDrawCallback onDrawCallback,
		DisplayObject_OnMouseMoveCallback onMouseMoveCallback)
	{
		this->OnDraw = onDrawCallback;//����OnDraw�ص�����
		this->OnMouseMove = onMouseMoveCallback;//����OnMouseMove�ص�����
	}

	void DisplayObject::DisplayObject_Draw(Resource *resource, SDL_Renderer *renderer)
	{
		if (OnDraw != nullptr)
		{
			OnDraw(this, resource, renderer);//����OnDraw�ص�����
		}
	}

	void DisplayObject::DisplayObject_OnMouseMove(SDL_Event *event)
	{
		if (OnMouseMove)
		{
			OnMouseMove(this, event);//����OnMouseMove�ص�����
		}
	}

	void DisplayObject::DisplayObject_Destory()
	{

	}

	DisplayObject::~DisplayObject()
	{
	}
}