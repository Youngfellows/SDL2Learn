#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	class  DisplayObject
	{
	public:
		void *subClass;//要显示类,相当于泛型

	private:
		typedef void (*OnDrawCallback)(DisplayObject *self, SDL_Renderer *renderer);
		typedef void (*OnTextSetCallback)(DisplayObject *self, const char *value);
		typedef void (*OnDestroyCallback)(DisplayObject *self);
		OnDrawCallback OnDraw;//回调函数OnDraw,使用函数指针
		OnDestroyCallback OnDestroy;//回调函数OnDestroy,使用函数指针
		OnTextSetCallback OnTextSet;//回调函数OnTextSet,使用函数指针

	public:
		DisplayObject();
		~DisplayObject();
		SDL_bool Create(OnDrawCallback onDrawCallback,
			OnTextSetCallback onTextSetCallback,
			OnDestroyCallback onDestroyCallback);
		void Draw(SDL_Renderer *renderer);
		void Destroy();
		void TextSet(const char *value);
	};

}
#endif // !_DUNGEON_DISPLAYOBJECT_H_

