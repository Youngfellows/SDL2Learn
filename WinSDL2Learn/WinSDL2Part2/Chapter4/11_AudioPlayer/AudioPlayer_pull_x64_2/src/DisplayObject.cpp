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
			OnCallback->OnMouseDown = nullptr;
			OnCallback->OnMouseUp = nullptr;
			OnCallback->OnDestory = nullptr;
		}
	}

	DisplayObject::~DisplayObject()
	{
		SDL_Log("DisplayObject::~DisplayObject");
		Destory();
	}

	void *DisplayObject::GetSubClass()
	{
		return this->subClass;
	}

	void DisplayObject::SetSubClass(void *subClazz)
	{
		this->subClass = subClazz;
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
				// 注意一定要传递
				OnCallback->OnDraw(this, resource, renderer);
			}
		}
	}

	void DisplayObject::Draw2(Resource *resource, SDL_Renderer *renderer)
	{
		if (OnCallback)
		{
			if (OnCallback->OnDraw2)
			{
				// 注意一定要传递subClass
				OnCallback->OnDraw2(subClass, resource, renderer);
			}
		}
	}

	void DisplayObject::MouseDown(SDL_Event *event)
	{
		if (OnCallback)
		{
			if (OnCallback->OnMouseDown)
			{
				SDL_Log("DisplayObject::MouseDown 1 this:%p", this);
				OnCallback->OnMouseDown(this, event);
				SDL_Log("DisplayObject::MouseDown 2 this:%p", this);
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
		SDL_Log("DisplayObject:: Destory");
		if (OnCallback)
		{
			if (OnCallback->OnDestory)
			{
				OnCallback->OnDestory(this);
			}
			free(OnCallback);
			OnCallback = nullptr;
			SDL_Log("DisplayObject:: Destory free memory");
		}
	}
}