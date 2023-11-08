#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"
#include "Resource.h"
#include "Cursor.h"
#include "RectInRect.h"

namespace Dungeon
{
	class Cursor;//先声明类
	class RectInRect;//先声明类

	/*
	* 这种方式不解耦,依赖关系太强了,没有体现面向对象的特性
	*/
	class DisplayObject
	{
	private:
		Cursor *mCursor;//光标对象
		RectInRect *mRectInRect;//内矩形对象

	public:
		DisplayObject();
		~DisplayObject();
		SDL_bool CreateComponents();
		void Destory();
		void Draw(Resource *resource, SDL_Renderer *renderer);
		void OnMouseMove(SDL_Event *event);

	private:
		void SetCursor(Cursor *cursor);
		void SetRectInRect(RectInRect *rectInRect);
		void DrawCursor(Resource *resource, SDL_Renderer *renderer);
		void CursorOnMouseMove(SDL_Event *event);
		void DrawRectInRect(Resource *resource, SDL_Renderer *renderer);
		void RectInRectOnMouseMove(SDL_Event *event);
	};
}
#endif // !_DUNGEON_DISPLAYOBJECT_H_

