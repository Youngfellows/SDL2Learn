#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"
#include "Resource.h"

namespace Dungeon
{
	class DisplayObject
	{
	private:
		typedef void (*DisplayObject_OnDrawCallback)(DisplayObject *displayObject, Resource *resource, SDL_Renderer *renderer);
		typedef void (*DisplayObject_OnMouseMoveCallback)(DisplayObject *displayObject, SDL_Event *event);
		DisplayObject_OnDrawCallback OnDraw;//����ָ��,��Ϊ�ص�����
		DisplayObject_OnMouseMoveCallback OnMouseMove;//����ָ��,��Ϊ�ص�����

	public:
		SDL_FRect *mDest;

	public:
		DisplayObject();
		~DisplayObject();
		SDL_bool DisplayObject_Create(float x, float y, float w, float h,
			DisplayObject_OnDrawCallback onDrawCallback,
			DisplayObject_OnMouseMoveCallback onMouseMoveCallback);
		void DisplayObject_Draw(Resource *resource, SDL_Renderer *renderer);
		void DisplayObject_OnMouseMove(SDL_Event *event);
		void DisplayObject_Destory();
	};
}

#endif // ! _DUNGEON_DISPLAYOBJECTCALLBACK_H_