#ifndef  _DUNGEON_PHOTO_H_
#define _DUNGEON_PHOTO_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"

namespace Dungeon
{
	//函数指针,定义点击回调
	typedef void (*OnPhotoClickCallback)();

	typedef struct PhontData
	{
		SDL_FRect *dest;//显示位置
		SDL_Texture *texture;//显示资源
		OnPhotoClickCallback OnClick;//定义点击回调
		SDL_bool move;//是否可移动
		SDL_FPoint *point;//位置坐标
	} PhotoData;
}

namespace Dungeon
{
	class Photo
	{
	private:
		PhontData *mPhotoData;

	public:
		Photo();
		~Photo();
		DisplayObject *Create(float x, float y, float w, float h,
			SDL_Texture *texture, OnPhotoClickCallback clickCallback);
		static void OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void OnMouseDownCallback(DisplayObject *self, SDL_Event *event);
		static void OnMouseUpCallback(DisplayObject *self, SDL_Event *event);
		static void OnMouseMoveCallback(DisplayObject *self, SDL_Event *event);
		static void OnDestoryCallback(DisplayObject *self);

	private:
		void Draw(SDL_Renderer *renderer);
		void MouseButtonDown(SDL_Event *event);
		void MouseButtonUp(SDL_Event *event);
		void MouseMove(SDL_Event *event);
		void Destory();
	};
}

#endif // ! _DUNGEON_PHOTO_H_

