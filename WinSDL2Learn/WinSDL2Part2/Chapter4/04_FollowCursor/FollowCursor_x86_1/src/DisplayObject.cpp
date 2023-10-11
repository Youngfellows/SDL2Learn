#include "DisplayObject.h"

namespace Dungeon
{
	DisplayObject::DisplayObject() :subClass(nullptr),
		OnDraw(nullptr), OnMouseMove(nullptr), OnDestroy(nullptr)
	{

	}

	DisplayObject::~DisplayObject()
	{

	}

	SDL_bool DisplayObject::DisplayObject_Create(
		DisplayObject_OnDrawCallback onDrawCallback,
		DisplayObject_OnMouseMoveCallback onMouseMoveCallback,
		DisplayObject_OnDestroyCallback onDestroyCallback)
	{
		this->OnDraw = onDrawCallback;//���ûص�����OnDraw
		this->OnMouseMove = onMouseMoveCallback;//���ûص�����OnMouseMove
		this->OnDestroy = onDestroyCallback;//���ûص�����OnDestroy
		if (!OnDraw || !OnMouseMove || !OnDestroy)
		{
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	void DisplayObject::DisplayObject_Draw(Resource *resource, SDL_Renderer *renderer)
	{
		if (OnDraw)
		{
			OnDraw(this, resource, renderer);//���ûص�����OnDraw
		}
	}

	void DisplayObject::DisplayObject_OnMouseMove(SDL_Event *event)
	{
		if (OnMouseMove)
		{
			OnMouseMove(this, event);//���ûص�����OnMouseMove
		}
	}

	void DisplayObject::DisplayObject_Destory()
	{
		if (OnDestroy)
		{
			OnDestroy(this);//���ûص�����OnDestroy
		}
	}
}