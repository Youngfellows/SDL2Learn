#ifndef  _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"
#include "Resource.h"

namespace Dungeon
{
	class  DisplayObject
	{
	public:
		void *subClass;//Ҫ���ƶ���,�൱�ڷ���,��չ�Ժ�

	private:
		//����ص�����->ʹ�ú���ָ��
		typedef void (*OnDrawCallback)(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		typedef void (*OnMouseMoveCallback)(DisplayObject *self, SDL_Event *event);
		typedef void (*OnDestoryCallback)(DisplayObject *self);
		OnDrawCallback OnDraw;
		OnMouseMoveCallback OnMouseMove;
		OnDestoryCallback OnDestory;

	public:
		DisplayObject();
		~DisplayObject();
		SDL_bool Create(OnDrawCallback onDrawCallback, OnMouseMoveCallback onMouseMoveCallback, OnDestoryCallback onDestoryCallback);
		void Draw(Resource *resource, SDL_Renderer *renderer);
		void MouseMove(SDL_Event *event);
		void Destory();
	};
}

#endif // ! _DUNGEON_DISPLAYOBJECT_H_

