#ifndef _DUNGEON_CURSOR_H_
#define _DUNGEON_CURSOR_H_

#include "SDL2/SDL.h"
#include "Resource.h"
#include "CursorData.h"
#include "DisplayObject.h"

namespace Dungeon
{
	/*
	* 鼠标光标类
	*/
	class Cursor
	{
	private:
		CursorData *mCursorData;

	public:
		Cursor();
		~Cursor();
		SDL_bool Create(float x, float y, float w, float h);
		void Destory();
		void OnDraw(Resource *resource, SDL_Renderer *renderer);
		void OnMouseMove(SDL_Event *event);

	private:
		CursorData *GetCursorData();
	};
}

#endif // !_DUNGEON_CURSOR_H_
