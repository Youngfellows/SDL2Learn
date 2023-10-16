#include "DisplayObject.h"


namespace Dungeon
{
	DisplayObject::DisplayObject() :subClass(nullptr), OnDraw(nullptr), OnScanCodeLeft(nullptr),
		OnScanCodeRight(nullptr), OnKeyUp(nullptr)
	{

	}

	DisplayObject::~DisplayObject()
	{
	}

	SDL_bool DisplayObject::Create(OnDrawCallback onDrawCallback,
		OnScanCodeLeftCallback onScanCodeLeftCallback,
		OnScanCodeRightCallback onScanCodeRightCallback,
		OnKeyUpCallback onKeyUpCallback,
		OnDestroyCallback onDestroyCallback)
	{
		if (!onDrawCallback
			|| !onScanCodeLeftCallback
			|| !onScanCodeRightCallback
			|| !onKeyUpCallback
			|| !onDestroyCallback)
		{
			return SDL_FALSE;
		}
		this->OnDraw = onDrawCallback;
		this->OnScanCodeLeft = onScanCodeLeftCallback;
		this->OnScanCodeRight = onScanCodeRightCallback;
		this->OnKeyUp = onKeyUpCallback;
		this->OnDestroy = onDestroyCallback;
		return SDL_TRUE;
	}

	void DisplayObject::Draw(Resource *resource, SDL_Renderer *renderer)
	{
		if (OnDraw)
		{
			OnDraw(this, resource, renderer);
		}
	}

	void DisplayObject::Destroy()
	{
		if (OnDestroy)
		{
			OnDestroy(this);
		}
	}

	void DisplayObject::ScanCodeLeft()
	{
		if (OnScanCodeLeft)
		{
			OnScanCodeLeft(this);
		}
	}

	void DisplayObject::ScanCodeRight()
	{
		if (OnScanCodeRight)
		{
			OnScanCodeRight(this);
		}
	}

	void DisplayObject::KeyUp()
	{
		if (OnKeyUp)
		{
			OnKeyUp(this);
		}
	}
}