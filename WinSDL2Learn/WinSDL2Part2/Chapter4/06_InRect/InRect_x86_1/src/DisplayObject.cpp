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
	* ���ûص�����
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
			OnDraw(this, resource, renderer);//���ûص�����OnDraw
		}
	}

	void DisplayObject::DisplayObject_OnMouseMove(SDL_Event *event)
	{
		if (OnMoveMove)
		{
			OnMoveMove(this, event);//���ûص�����OnMoveMove
		}
	}

	void DisplayObject::DisplayObject_Destory()
	{
		if (OnDestory)
		{
			OnDestory(this);//���ûص�����OnDestory
		}
	}
}