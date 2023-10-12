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
		SDL_bool Create(float x, float y);
		void OnDraw(Resource *resource, SDL_Renderer *renderer);
		void OnMouseMove(SDL_Event *event);
		void Destory();
	};

}
#endif // !_DUNGEON_RECTINRECT_H_
