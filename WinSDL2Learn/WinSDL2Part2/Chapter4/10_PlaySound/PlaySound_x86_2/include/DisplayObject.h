#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	class  DisplayObject
	{
	public:
		void *subClass;//Ҫ��ʾ��,�൱�ڷ���

	private:
		typedef void (*OnDrawCallback)(DisplayObject *self, SDL_Renderer *renderer);
		typedef void (*OnTextSetCallback)(DisplayObject *self, const char *value);
		typedef void (*OnDestroyCallback)(DisplayObject *self);
		OnDrawCallback OnDraw;//�ص�����OnDraw,ʹ�ú���ָ��
		OnDestroyCallback OnDestroy;//�ص�����OnDestroy,ʹ�ú���ָ��
		OnTextSetCallback OnTextSet;//�ص�����OnTextSet,ʹ�ú���ָ��

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

