#include "EventListener.h"

#include "SDL2/SDL.h"
#include "Photo.h"
#include "Rectangle.h"
#include "Rect.h"

namespace Dungeon
{
	EventListener::EventListener()
	{
	}

	EventListener::~EventListener()
	{
	}

	void EventListener::OnClickRect(DisplayObject *self)
	{
		SDL_Log("EventListener::OnClickRect():: click the rectangle");
	}

	void EventListener::OnClickCat()
	{
		SDL_Log("EventListener::OnClickCat():: click the cat");
	}

	void EventListener::OnClickText1(DisplayObject *self)
	{
		SDL_Log("EventListener::OnClickText1():: click text1");
		Rectangle *rect = (Rectangle *)self->GetSubClass();
		if (rect)
		{
			rect->move();
		}
	}

	void EventListener::OnClickText2(DisplayObject *self)
	{
		SDL_Log("EventListener::OnClickText2():: click text2");
		Rect *rect = (Rect *)self->GetSubClass();
		if (rect)
		{
			rect->Move();
		}
	}
}