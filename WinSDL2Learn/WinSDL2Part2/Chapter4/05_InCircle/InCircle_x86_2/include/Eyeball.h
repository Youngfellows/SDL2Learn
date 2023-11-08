#ifndef _DUNGEON_EYEBALL_H_
#define _DUNGEON_EYEBALL_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"
#include "EyeballData.h"

namespace Dungeon
{
	class DisplayObject;//先声明类,,后面再定义

	class Eyeball
	{
	private:
		EyeballData *mEyeballData;

	public:
		Eyeball();
		~Eyeball();
		DisplayObject *Eyeball_Create(float centerX, float centerY);
		void Eyeball_Destory();
		void Eyeball_CursorOnDraw(Resource *resource, SDL_Renderer *renderer);
		void Eyeball_CursorOnMouseMove(SDL_Event *event);
	};
}

#endif // !_DUNGEON_EYEBALL_H_

