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

	void DisplayObject::Draw(SDL_Renderer *renderer)
	{
		if (OnCallback)
		{
			if (OnCallback->OnDraw)
			{
				// 注意一定要传递
				OnCallback->OnDraw(this, renderer);
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

	void DisplayObject::MouseLeftDown(SDL_Event *event)
	{
		if (OnCallback)
		{
			if (OnCallback->OnMouseLeftDown)
			{
				OnCallback->OnMouseLeftDown(this, event);
			}
		}
	}

	void DisplayObject::MouseRightDown(SDL_Event *event)
	{
		if (OnCallback)
		{
			if (OnCallback->OnMouseRightDown)
			{
				OnCallback->OnMouseRightDown(this, event);
			}
		}
	}

	void DisplayObject::MouseLeftUp(SDL_Event *event)
	{
		if (OnCallback)
		{
			if (OnCallback->OnMouseLeftUp)
			{
				OnCallback->OnMouseLeftUp(this, event);
			}
		}
	}

	void DisplayObject::MouseRightUp(SDL_Event *event)
	{
		if (OnCallback)
		{
			if (OnCallback->OnMouseRightUp)
			{
				OnCallback->OnMouseRightUp(this, event);
			}
		}
	}

	void DisplayObject::ScanCodeLeftKeyDown()
	{
		if (OnCallback)
		{
			if (OnCallback->OnScanCodeLeftKeyDown)
			{
				OnCallback->OnScanCodeLeftKeyDown(this);
			}
		}
	}

	void DisplayObject::ScanCodeRightKeyDown()
	{
		if (OnCallback)
		{
			if (OnCallback->OnScanCodeRightKeyDown)
			{
				OnCallback->OnScanCodeRightKeyDown(this);
			}
		}
	}

	void DisplayObject::ScanCodeLeftKeyUp()
	{
		if (OnCallback)
		{
			if (OnCallback->OnScanCodeLeftKeyUp)
			{
				OnCallback->OnScanCodeLeftKeyUp(this);
			}
		}
	}

	void DisplayObject::ScanCodeRightKeyUp()
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