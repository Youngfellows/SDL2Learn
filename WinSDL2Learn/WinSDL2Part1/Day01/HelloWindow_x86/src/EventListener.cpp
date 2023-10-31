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
}