#ifndef _DUNGEON_EYEBALL_H_
#define _DUNGEON_EYEBALL_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"
#include "EyeballData.h"

namespace Dungeon
{
	class Eyeball
	{
	private:

	public:
		Eyeball();
		~Eyeball();
		DisplayObject *Eyeball_Create(float centerX, float centerY);
		void Eyeball_Destory(DisplayObject *self);
		static void Eyeball_CursorOnDraw(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void Eyeball_CursorOnMouseMove(DisplayObject *self, SDL_Event *event);
	};
}

#endif // !_DUNGEON_EYEBALL_H_

