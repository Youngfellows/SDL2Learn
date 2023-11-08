#include "DisplayObject.h"


namespace Dungeon
{

	DisplayObject::DisplayObject() :subClass(nullptr), OnDraw(nullptr), OnDestroy(nullptr)
	{
	}

	DisplayObject::~DisplayObject()
	{
	}

	SDL_bool DisplayObject::Create(OnDrawCallback onDrawCallback,
		OnTextSetCallback onTextSetCallback,
		OnDestroyCallback onDestroyCallback)
	{
		if (!onDrawCallback
			|| !onTextSetCallback
			|| !onDestroyCallback)
		{
			return SDL_FALSE;
		}
		this->OnDraw = onDrawCallback;
		this->OnTextSet = onTextSetCallback;
		this->OnDestroy = onDestroyCallback;
		return SDL_TRUE;
	}


	void DisplayObject::Draw(SDL_Renderer *renderer)
	{
		if (OnDraw)
		{
			OnDraw(this, renderer);//调用回调函数onDrawCallback
		}
	}

	void DisplayObject::Destroy()
	{
		if (OnDestroy)
		{
			OnDestroy(this);//调用回调函数onDestroyCallback
		}
	}

	void DisplayObject::TextSet(const char *value)
	{
		if (OnTextSet)
		{
			OnTextSet(this, value);//调用回调函数onTextSetCallback
		}
	}
}