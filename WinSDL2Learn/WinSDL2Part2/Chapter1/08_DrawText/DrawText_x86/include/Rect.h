#ifndef _DUNGEON_RECT_H_
#define _DUNGEON_RECT_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	typedef struct RectData
	{
		int color;//颜色
		SDL_Point start;//开始位置
		SDL_Point end;//结束位置
		int winWidth;//窗口宽
		int winHeight;//窗口高
		SDL_bool move;//是否可移动
		SDL_FPoint point;
		float speedX;
		float speedY;
	}RectData;
}

namespace Dungeon
{
	class Rect
	{
	private:
		RectData *mRectData;

	public:
		Rect();
		~Rect();
		DisplayObject *Create(int color, int x1, int y1, int x2, int y2, int w, int h);
		static void OnDrawCallback(DisplayObject *self, SDL_Surface *winSurface, Resource *resource);
		static void OnMouseDownCallback(DisplayObject *self, SDL_Event *event);
		static void OnMouseUpCallback(DisplayObject *self, SDL_Event *event);
		static void OnMouseMoveCallback(DisplayObject *self, SDL_Event *event);
		static void OnDestoryCallback(DisplayObject *self);
		void Move();

	private:
		void Draw(SDL_Surface *winSurface);
		void MouseButtonDown(SDL_Event *event);
		void MouseButtonUp(SDL_Event *event);
		void MouseMove(SDL_Event *event);
		void Destory();
	};
}

#endif // !_DUNGEON_RECT_H_

