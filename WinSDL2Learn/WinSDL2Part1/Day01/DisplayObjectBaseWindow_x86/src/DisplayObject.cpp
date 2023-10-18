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
			OnCallback->OnMouseLeftDown = nullptr;
			OnCallback->OnMouseRightDown = nullptr;
			OnCallback->OnMouseLeftUp = nullptr;
			OnCallback->OnMouseRightUp = nullptr;
			OnCallback->OnScanCodeLeftKeyDown = nullptr;
			OnCallback->OnScanCodeRightKeyDown = nullptr;
			OnCallback->OnScanCodeLeftKeyUp = nullptr;
			OnCallback->OnScanCodeRightKeyUp = nullptr;
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

	void DisplayObject::Draw(DisplayObject *self, SDL_Renderer *renderer)
	{
		if (OnCallback)
		{
			if (OnCallback->OnDraw)
			{
				OnCallback->OnDraw(this, renderer);
			}
		}
	}

	void DisplayObject::MouseMove(DisplayObject *self, SDL_Event *event)
	{
		if (OnCallback)
		{
			if (OnCallback->OnMouseMove)
			{
				OnCallback->OnMouseMove(this, event);
			}
		}
	}

	void DisplayObject::MouseLeftDown(DisplayObject *self, SDL_Event *event)
	{
		if (OnCallback)
		{
			if (OnCallback->OnMouseLeftDown)
			{
				OnCallback->OnMouseLeftDown(this, event);
			}
		}
	}

	void DisplayObject::MouseRightDown(DisplayObject *slef, SDL_Event *event)
	{
		if (OnCallback)
		{
			if (OnCallback->OnMouseRightDown)
			{
				OnCallback->OnMouseRightDown(this, event);
			}
		}
	}

	void DisplayObject::MouseLeftUp(DisplayObject *self, SDL_Event *event)
	{
		if (OnCallback)
		{
			if (OnCallback->OnMouseLeftUp)
			{
				OnCallback->OnMouseLeftUp(this, event);
			}
		}
	}

	void DisplayObject::MouseRightUp(DisplayObject *self, SDL_Event *event)
	{
		if (OnCallback)
		{
			if (OnCallback->OnMouseRightUp)
			{
				OnCallback->OnMouseRightUp(this, event);
			}
		}
	}

	void DisplayObject::ScanCodeLeftKeyDown(DisplayObject *self)
	{
		if (OnCallback)
		{
			if (OnCallback->OnScanCodeLeftKeyDown)
			{
				OnCallback->OnScanCodeLeftKeyDown(this);
			}
		}
	}

	void DisplayObject::ScanCodeRightKeyDown(DisplayObject *self)
	{
		if (OnCallback)
		{
			if (OnCallback->OnScanCodeRightKeyDown)
			{
				OnCallback->OnScanCodeRightKeyDown(this);
			}
		}
	}

	void DisplayObject::ScanCodeLeftKeyUp(DisplayObject *self)
	{
		if (OnCallback)
		{
			if (OnCallback->OnScanCodeLeftKeyUp)
			{
				OnCallback->OnScanCodeLeftKeyUp(this);
			}
		}
	}

	void DisplayObject::ScanCodeRightKeyUp(DisplayObject *self)
	{
		if (OnCallback)
		{
			if (OnCallback->OnScanCodeRightKeyUp)
			{
				OnCallback->OnScanCodeRightKeyUp(this);
			}
		}
	}

	void DisplayObject::Destory()
	{
		SDL_Log("Destory");
		if (OnCallback)
		{
			if (OnCallback->OnDestory)
			{
				OnCallback->OnDestory(this);
			}
			free(OnCallback);
			SDL_Log("Destory free memory");
		}
	}
}