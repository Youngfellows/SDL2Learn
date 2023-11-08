#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"
#include "Resource.h"

namespace Dungeon
{
	class DisplayObject
	{
	private:
		typedef void (*DisplayObject_OnDrawCallback)(DisplayObject *self,
			Resource *resource, SDL_Renderer *renderer);
		typedef void (*DisplayObject_OnMouseMoveCallback)(DisplayObject *self,
			SDL_Event *event);
		typedef void(*DisplayObject_OnDestroyCallback)(DisplayObject *self);
		DisplayObject_OnDrawCallback OnDraw;//函数指针,作为回调函数
		DisplayObject_OnMouseMoveCallback OnMouseMove;//函数指针,作为回调函数
		DisplayObject_OnDestroyCallback OnDestroy;//函数指针,作为回调函数

	public:
		void *subClass;//要显示对象

	public:
		DisplayObject();
		~DisplayObject();
		SDL_bool DisplayObject_Create(
			DisplayObject_OnDrawCallback onDrawCallback,
			DisplayObject_OnMouseMoveCallback onMouseMoveCallback,
			DisplayObject_OnDestroyCallback onDestroyCallback);
		void DisplayObject_Draw(Resource *resource, SDL_Renderer *renderer);
		void DisplayObject_OnMouseMove(SDL_Event *event);
		void DisplayObject_Destory();
	};
}

#endif // ! _DUNGEON_DISPLAYOBJECTCALLBACK_H_