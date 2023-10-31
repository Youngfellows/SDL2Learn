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
		static void OnMouseMoveCallback(DisplayObject *self, SDL_Event *event);
		static void OnScanCodeLeftDown(DisplayObject *self);
		static void OnScanCodeRightDown(DisplayObject *self);
	};
}

namespace Dungeon
{
	MovableRectangle::MovableRectangle() :mRectangleData(nullptr)
	{
		//动态申请内存
		this->mRectangleData = (RectangleData *)malloc(sizeof(RectangleData));
		if (!mRectangleData)
		{
			SDL_Log("Can not create mRectangleData");
		}
	}

	MovableRectangle::~MovableRectangle()
	{

	}

	DisplayObject *MovableRectangle::Create(float x, float y, float w, float h,
		int color, int borderColor, int borderSize)
	{
		if (!mRectangleData)
		{
			return nullptr;
		}
		//动态申请内存
		mRectangleData->dest = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mRectangleData->dest)
		{
			return nullptr;
		}
		mRectangleData->dest->x = x;
		mRectangleData->dest->y = y;
		mRectangleData->dest->w = w;
		mRectangleData->dest->h = h;
		mRectangleData->color = color;
		mRectangleData->borderColor = borderColor;
		mRectangleData->borderSize = borderSize;

		//创建要显示对象代理类
		DisplayObject *displayObject = new DisplayObject();

		return displayObject;
	}

	void MovableRectangle::OnDrawCallback(DisplayObject *self, SDL_Renderer *renderer)
	{

	}

	void MovableRectangle::OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{

	}

	void MovableRectangle::OnScanCodeLeftDown(DisplayObject *self)
	{

	}

	void MovableRectangle::OnScanCodeRightDown(DisplayObject *self)
	{

	}
}

#endif // !_DUNGEON_MOVABLE_RECTANGLE_H_

