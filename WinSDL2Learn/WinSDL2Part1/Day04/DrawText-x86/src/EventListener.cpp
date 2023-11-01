#include "EventListener.h"

#include "SDL2/SDL.h"

namespace Dungeon
{
	EventListener::EventListener()
	{
	}

	EventListener::~EventListener()
	{
	}

	void EventListener::OnClickRect()
	{
		SDL_Log("EventListener::OnClickRect():: click the rectangle");
	}

	void EventListener::OnClickCat()
	{
		SDL_Log("EventListener::OnClickCat():: click the cat");
	}

	void EventListener::OnClickGirl()
	{
		SDL_Log("EventListener::OnClickGirl():: click the girl");
	}
}