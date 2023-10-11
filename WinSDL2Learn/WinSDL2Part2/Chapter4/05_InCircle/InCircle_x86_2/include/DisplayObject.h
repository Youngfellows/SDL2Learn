#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"
#include "Resource.h"
#include "Eyeball.h"

namespace Dungeon
{
	class Eyeball;//��������,�����ٶ���

	class DisplayObject
	{
	private:
		Eyeball *mEyeball;//��Ҫ���Ƶľ������

	public:
		DisplayObject(Eyeball *eyeball);
		~DisplayObject();
		void DisplayObject_Draw(Resource *resource, SDL_Renderer *renderer);
		void DisplayObject_OnMouseMove(SDL_Event *event);
		void DisplayObject_Destory();
	};
}

#endif // !_DUNGEON_DISPLAYOBJECT_H_

