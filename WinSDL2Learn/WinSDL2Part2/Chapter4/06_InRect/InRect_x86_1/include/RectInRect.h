#ifndef _DUNGEON_RECTINRECT_H_
#define _DUNGEON_RECTINRECT_H_

#include "SDL2/SDL.h"
#include "RectInRectData.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	class RectInRect
	{
	private:
		RectInRectData *mRectInRectData;

	public:
		RectInRect();
		~RectInRect();
		DisplayObject *RectInRect_Create(float x, float y);
		static void RectInRect_DrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void RectInRect_MouseMoveCallback(DisplayObject *self, SDL_Event *event);
		static void RectInRect_DestoryCallback(DisplayObject *self);
	};

}
#endif // !_DUNGEON_RECTINRECT_H_
