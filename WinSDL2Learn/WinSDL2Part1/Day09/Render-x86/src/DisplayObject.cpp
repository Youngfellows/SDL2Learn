#include "DisplayObject.h"

namespace Dungeon
{
	DisplayObject::DisplayObject() :subClass(nullptr), OnCallback(nullptr)
	{
		//动态申请内存
		this->OnCallback = (OnCallbackData *)malloc(sizeof(OnCallbackData));
		if (!OnCallback)
		{
			SDL_Log("Create OnCallbackData failed");
		}
		else
		{
			OnCallback->OnDraw = nullptr;
			OnCallback->OnMouseMove = nullptr;
			OnCallback->OnMouseDown = nullptr;
			OnCallback->OnMouseUp = nullptr;
			OnCallback->OnDestory = nullptr;
		}
	}

	DisplayObject::~DisplayObject()
	{
		SDL_Log("~DisplayObject");
		Destory();
	}

	void *DisplayObject::GetSubClass()
	{
		return this->subClass;
	}

	void DisplayObject::SetSubClass(void *subClass)
	{
		this->subClass = subClass;
	}

	OnCallbackData *DisplayObject::GetOnCallback()
	{
		return this->OnCallback;
	}

	void DisplayObject::Draw(Resource *resource, SDL_Renderer *renderer)
	{
		if (OnCallback)
		{
			if (OnCallback->OnDraw)
			{
				OnCallback->OnDraw(this, resource, renderer);
			}
		}
	}

	void DisplayObject::MouseMove(SDL_Event *event)
	{
		if (OnCallback)
		{
			if (OnCallback->OnMouseMove)
			{
				OnCallback->OnMouseMove(this, event);
			}
		}
	}


	void DisplayObject::MouseDown(SDL_Event *event)
	{
		if (OnCallback)
		{
			if (OnCallback->OnMouseDown)
			{
				OnCallback->OnMouseDown(this, event);
			}
		}
	}

	void DisplayObject::MouseUp(SDL_Event *event)
	{
		if (OnCallback)
		{
			if (OnCallback->OnMouseUp)
			{
				OnCallback->OnMouseUp(this, event);
			}
		}
	}

	void DisplayObject::Destory()
	{
		SDL_Log("DisplayObject::Destory():: ");
		if (OnCallback)
		{
			if (OnCallback->OnDestory)
			{
				OnCallback->OnDestory(this);
			}
			free(OnCallback);
			SDL_Log("DisplayObject::Destory():: free memory");
		}
	}
}