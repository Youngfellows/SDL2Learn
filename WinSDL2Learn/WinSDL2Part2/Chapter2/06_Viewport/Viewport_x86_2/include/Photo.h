#ifndef  _DUNGEON_PHOTO_H_
#define _DUNGEON_PHOTO_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"

namespace Dungeon
{
	//函数指针,定义点击回调
	typedef void (*OnPhotoClickCallback)();

	typedef struct PhotoData
	{
		SDL_FRect *dest;//显示位置
		SDL_Texture *texture;//显示资源
		OnPhotoClickCallback OnClick;//定义点击回调
		SDL_bool move;//是否可移动
		SDL_FPoint *point;//位置坐标
		SDL_bool rotateAnim;//是否旋转动画
		SDL_bool scaleAnim;//是否缩放动画
		float angle;//旋转角度
		float valueX;//x坐标
		SDL_bool delay;//动画是否延迟执行
		int delayTime;//动画执行时间
	} PhotoData;
}

namespace Dungeon
{
	class Photo
	{
	private:
		PhotoData *mPhotoData;

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
		void Rotate();
		void Scale();
		void SetDelay(int delayTime);
		static int SDLCALL ThreadCallback(void *userdata);

	private:
		void Draw(SDL_Renderer *renderer);
		void MouseButtonDown(SDL_Event *event);
		void MouseButtonUp(SDL_Event *event);
		void MouseMove(SDL_Event *event);
		void Destory();
	};
}

#endif // ! _DUNGEON_PHOTO_H_

