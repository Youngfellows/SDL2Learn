#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"
#include "Resource.h"

namespace Dungeon
{
	class DisplayObject
	{
	public:
		void *subClassData;//���ݶ���ָ��

	private:
		typedef void (*DisplayObject_OnDrawCallback)(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		typedef void (*DisplayObject_OnMouseMoveCallback)(DisplayObject *self, SDL_Event *event);
		DisplayObject_OnDrawCallback OnDraw;//����OnDraw�ص�����,ʹ�ú���ָ��
		DisplayObject_OnMouseMoveCallback OnMouseMove;//����OnMouseMove�ص�����,ʹ�ú���ָ��

	public:
		DisplayObject();
		~DisplayObject();
		void DisplayObject_Create(DisplayObject_OnDrawCallback onDrawCallback,
			DisplayObject_OnMouseMoveCallback onMouseMoveCallback);
		void DisplayObject_Draw(Resource *resource, SDL_Renderer *renderer);
		void DisplayObject_OnMouseMove(SDL_Event *event);
		void DisplayObject_Destory();
	};
}

#endif // !_DUNGEON_DISPLAYOBJECT_H_

