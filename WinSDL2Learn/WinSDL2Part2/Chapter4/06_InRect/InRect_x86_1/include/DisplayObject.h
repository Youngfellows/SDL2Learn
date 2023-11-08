#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"
#include "Resource.h"

namespace Dungeon
{
	class DisplayObject
	{
	public:
		void *mSubClassData;//要显示的对象指针,相当于泛型

	private:
		typedef void (*DisplayObject_OnDrawCallback)(DisplayObject *self,
			Resource *resource, SDL_Renderer *renderer);
		typedef void (*DisplayObject_OnMouseMoveCallback)(DisplayObject *self, SDL_Event *event);
		typedef void(*DisplayObject_DestoryCallback)(DisplayObject *self);
		DisplayObject_OnDrawCallback OnDraw;//回调函数OnDraw
		DisplayObject_OnMouseMoveCallback OnMoveMove;//回调函数OnMoveMove
		DisplayObject_DestoryCallback OnDestory;//回调函数OnDestory

	public:
		DisplayObject();
		~DisplayObject();
		SDL_bool DisplayObject_Create(DisplayObject_OnDrawCallback onDrawCallback,
			DisplayObject_OnMouseMoveCallback onMouseMoveCallback,
			DisplayObject_DestoryCallback onDestoryCallback);
		void DisplayObject_Draw(Resource *resource, SDL_Renderer *renderer);
		void DisplayObject_OnMouseMove(SDL_Event *event);
		void DisplayObject_Destory();
	};
}
#endif // !_DUNGEON_DISPLAYOBJECT_H_

