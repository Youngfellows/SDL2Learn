#ifndef _DUNGEON_RECTANGLE_H_
#define _DUNGEON_RECTANGLE_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"

namespace Dungeon
{
	//函数指针,矩形被点击的回调函数
	typedef void (*OnRectangleClickCallback)(DisplayObject *self);

	typedef struct RectangleData
	{
		SDL_FRect *dest;//要绘制的目标矩形位置
		SDL_FPoint *point;//上一次按下点位置
		SDL_bool move;//是否可移动
		int color;//矩形颜色
		int borderColor;//边框颜色
		int borderSize;//边框大小
		DisplayObject *destObj;
		OnRectangleClickCallback OnClick;//被点击的回调
	}RectangleData;

}

namespace Dungeon
{
	/*
	* 可以点击的矩形
	*/
	class Rectangle
	{
	private:
		RectangleData *mRectangleData;

	public:
		Rectangle();
		~Rectangle();
		DisplayObject *Create(float x, float y, float w, float h,
			int color, int borderColor, int borderSize,
			DisplayObject *destObj, OnRectangleClickCallback onClickCallback);
		static void OnDrawCallback(DisplayObject *self, SDL_Surface *winSurface,Resource *resource);
		static void OnMouseMoveCallback(DisplayObject *self, SDL_Event *event);
		static void OnMouseDownCallback(DisplayObject *self, SDL_Event *event);
		static void OnMouseUpCallback(DisplayObject *self, SDL_Event *event);
		static void OnDestoryCallback(DisplayObject *self);
		void move();

	private:
		void Destory();
		void Draw(SDL_Surface *winSurace, Resource *resource);
		void MouseMove(SDL_Event *event);
		void MouseDown(SDL_Event *event);
		void MouseUp(SDL_Event *event);
	};
}

#endif // !_DUNGEON_MOVABLE_RECTANGLE_H_

