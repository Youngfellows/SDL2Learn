#ifndef _DUNGEON_RECTSHAPE_H_
#define _DUNGEON_RECTSHAPE_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	class RectShape
	{
	private:
		SDL_Rect mDest;
		uint32_t mColor;
		SDL_FPoint mDragStartPoint;
		SDL_FPoint mDragStartMousePoint;
		bool dragEnabled;
	
	public:
		RectShape *mPre;
		RectShape *mNext;

	public:
		RectShape(float x, float y, float w, float h, uint32_t color);
		~RectShape();
		void RectShape_Draw(SDL_Renderer *renderer);
		SDL_bool RectShape_OnMouseEvent(SDL_Event *event);
		void RectShape_Destory();
	};
}
#endif // !_DUNGEON_RECTSHAPE_H_
