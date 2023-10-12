#include "DisplayObject.h"

namespace Dungeon
{

	DisplayObject::DisplayObject() :subClass(nullptr), OnDraw(nullptr), OnMouseMove(nullptr), OnDestory(nullptr)
	{
	}

	DisplayObject::~DisplayObject()
	{
	}

	SDL_bool DisplayObject::Create(OnDrawCallback onDrawCallback, OnMouseMoveCallback onMouseMoveCallback, OnDestoryCallback onDestoryCallback)
	{
		if (!onDrawCallback || !onMouseMoveCallback || !onDestoryCallback)
		{
			return SDL_FALSE;
		}
		this->OnDraw = onDrawCallback;
		this->OnMouseMove = onMouseMoveCallback;
		this->OnDestory = onDestoryCallback;
		return SDL_TRUE;
	}
	void DisplayObject::Draw(Resource *resource, SDL_Renderer *renderer)
	{
		if (OnDraw)
		{
			OnDraw(this, resource, renderer);//调用回调函数onDrawCallback
		}
	}

	void DisplayObject::MouseMove(SDL_Event *event)
	{
		if (OnMouseMove)
		{
			OnMouseMove(this, event);//调用回调函数onMouseMoveCallback
		}
	}

	void DisplayObject::Destory()
	{
		if (OnDestory)
		{
			OnDestory(this);//调用回调函数onDestoryCallback
		}
	}
}