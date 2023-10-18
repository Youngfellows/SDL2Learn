#ifndef _DUNGEON_MOVABLE_RECTANGLE_H_
#define _DUNGEON_MOVABLE_RECTANGLE_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"

namespace Dungeon
{
	typedef struct RectangleData
	{
		SDL_FRect *dest;//要绘制的目标矩形位置
		int color;//矩形颜色
		int borderColor;//边框颜色
		int borderSize;//边框大小
	}RectangleData;
}

namespace Dungeon
{
	/*
	* 可移动矩形
	*/
	class MovableRectangle
	{
	private:
		RectangleData *mRectangleData;

	public:
		MovableRectangle();
		~MovableRectangle();
		DisplayObject *Create(float x, float y, float w, float h,
			int color, int borderColor, int borderSize);
		static void OnDrawCallback(DisplayObject *self, SDL_Renderer *renderer);
		static void OnDrawCallback2(void *userdata, SDL_Renderer *renderer);
		static void OnMouseMoveCallback(DisplayObject *self, SDL_Event *event);
		static void OnScanCodeLeftDownCallback(DisplayObject *self);
		static void OnScanCodeRightDownCallback(DisplayObject *self);
		static void OnDestoryCallback(DisplayObject *self);
		RectangleData *GetRectangleData();
	};
}
#endif // !_DUNGEON_MOVABLE_RECTANGLE_H_

