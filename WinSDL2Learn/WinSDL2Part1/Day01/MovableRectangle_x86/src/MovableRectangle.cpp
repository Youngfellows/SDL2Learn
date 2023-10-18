#include "MovableRectangle.h"

namespace Dungeon
{
	MovableRectangle::MovableRectangle() :mRectangleData(nullptr)
	{

	}

	MovableRectangle::~MovableRectangle()
	{
		SDL_Log("~MovableRectangle()");
		if (mRectangleData)
		{
			free(mRectangleData->dest);
			free(mRectangleData);
			SDL_Log("~MovableRectangle() free memory");
			mRectangleData = nullptr;
		}
	}

	DisplayObject *MovableRectangle::Create(float x, float y, float w, float h,
		int color, int borderColor, int borderSize)
	{
		//动态申请内存
		this->mRectangleData = (RectangleData *)malloc(sizeof(RectangleData));
		if (!mRectangleData)
		{
			SDL_Log("Can not create mRectangleData");
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
		if (displayObject)
		{
			SDL_Log("Create SetSubClass");
			displayObject->SetSubClass(this);//设置要显示代理对象
			//displayObject->subClass = (void *)this;
		}

		//设置回调函数
		OnCallbackData *callbackData = displayObject->GetOnCallback();
		if (callbackData)
		{
			callbackData->OnDraw = &OnDrawCallback;
			callbackData->OnMouseMove = &OnMouseMoveCallback;
			callbackData->OnScanCodeLeftKeyDown = &OnScanCodeLeftDownCallback;
			callbackData->OnScanCodeRightKeyDown = &OnScanCodeRightDownCallback;
			callbackData->OnDestory = &OnDestoryCallback;
		}
		return displayObject;
	}

	RectangleData *MovableRectangle::GetRectangleData()
	{
		return this->mRectangleData;
	}

	void MovableRectangle::OnDrawCallback(DisplayObject *self, SDL_Renderer *renderer)
	{
		MovableRectangle *rect = (MovableRectangle *)self->GetSubClass();//注意,一定要获取subClass
		if (rect)
		{
			RectangleData *data = rect->mRectangleData;
			//RectangleData *data = rect->GetRectangleData();
			if (data)
			{
				//绘制边框,ARGB格式颜色0xff00ffff
				Uint8 bRed = (data->borderColor & 0x00ff0000) >> 16;
				Uint8 bGreen = (data->borderColor & 0x0000ff00) >> 8;
				Uint8 bBlue = data->borderColor & 0x000000ff;
				Uint8 bAlpha = (data->borderColor & 0xff000000) >> 24;
				SDL_SetRenderDrawColor(renderer, bRed, bGreen, bBlue, bAlpha);
				SDL_RenderFillRectF(renderer, data->dest);

				//暂时不知道如何设置线宽,采用叠加的方式来实现了
				//绘制矩形,ARGB格式颜色0xff00ffff 
				Uint8 red = (data->color & 0x00ff0000) >> 16;
				Uint8 green = (data->color & 0x0000ff00) >> 8;
				Uint8 blue = data->color & 0x000000ff;
				Uint8 alpha = (data->color & 0xff000000) >> 24;

				float x = data->dest->x + data->borderSize;
				float y = data->dest->y + data->borderSize;
				float w = data->dest->w - 2 * data->borderSize;
				float h = data->dest->h - 2 * data->borderSize;

				SDL_FRect rect = { x,y,w,h };
				SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
				SDL_RenderFillRectF(renderer, &rect);
			}
		}
	}

	void MovableRectangle::OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{

	}

	void MovableRectangle::OnScanCodeLeftDownCallback(DisplayObject *self)
	{

	}

	void MovableRectangle::OnScanCodeRightDownCallback(DisplayObject *self)
	{

	}

	void MovableRectangle::OnDestoryCallback(DisplayObject *self)
	{
		SDL_Log("MovableRectangle::OnDestoryCallback");
		MovableRectangle *rect = (MovableRectangle *)self->GetSubClass();
		if (rect)
		{
			RectangleData *data = rect->mRectangleData;
			if (data)
			{
				free(data->dest);
				free(data);
				data = nullptr;
				SDL_Log("MovableRectangle::OnDestoryCallback:: free memory");
			}
		}
	}
}