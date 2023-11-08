#include "DisplayObject.h"


namespace Dungeon
{

	DisplayObject::DisplayObject() :mSubClassData(nullptr),
		OnDraw(nullptr), OnMoveMove(nullptr), OnDestory(nullptr)
	{
	}

	DisplayObject::~DisplayObject()
	{

	}

	/*
	* 设置回调函数
	*/
	SDL_bool DisplayObject::DisplayObject_Create(DisplayObject_OnDrawCallback onDrawCallback,
		DisplayObject_OnMouseMoveCallback onMouseMoveCallback,
		DisplayObject_DestoryCallback onDestoryCallback)
	{
		if (!onDrawCallback || !onMouseMoveCallback || !onDestoryCallback)
		{
			return SDL_FALSE;
		}
		this->OnDraw = onDrawCallback;
		this->OnMoveMove = onMouseMoveCallback;
		this->OnDestory = onDestoryCallback;
		return SDL_TRUE;
	}

	void DisplayObject::DisplayObject_Draw(Resource *resource, SDL_Renderer *renderer)
	{
		if (OnDraw)
		{
			OnDraw(this, resource, renderer);//调用回调函数OnDraw
		}
	}

	void DisplayObject::DisplayObject_OnMouseMove(SDL_Event *event)
	{
		if (OnMoveMove)
		{
			OnMoveMove(this, event);//调用回调函数OnMoveMove
		}
	}

	void DisplayObject::DisplayObject_Destory()
	{
		if (OnDestory)
		{
			OnDestory(this);//调用回调函数OnDestory
		}
	}
}