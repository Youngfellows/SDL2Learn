#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"
#include "Resource.h"
#include "Eyeball.h"

namespace Dungeon
{
	class Eyeball;//先声明类,后面再定义

	class DisplayObject
	{
	private:
		Eyeball *mEyeball;//需要绘制的具体对象

	public:
		DisplayObject(Eyeball *eyeball);
		~DisplayObject();
		void DisplayObject_Draw(Resource *resource, SDL_Renderer *renderer);
		void DisplayObject_OnMouseMove(SDL_Event *event);
		void DisplayObject_Destory();
	};
}

#endif // !_DUNGEON_DISPLAYOBJECT_H_

