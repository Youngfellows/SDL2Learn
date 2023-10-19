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
		int color, int borderColor, int borderSize, float bWidth, float bHeight)
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
		mRectangleData->enableDrag = SDL_FALSE;

		mRectangleData->point = (SDL_FPoint *)malloc(sizeof(SDL_FPoint));
		if (!mRectangleData->point)
		{
			return nullptr;
		}
		if (mRectangleData->point)
		{
			mRectangleData->point->x = 0;
			mRectangleData->point->y = 0;
		}

		mRectangleData->boundary = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mRectangleData->boundary)
		{
			return nullptr;
		}
		mRectangleData->boundary->x = x;
		mRectangleData->boundary->y = y;
		mRectangleData->boundary->w = bWidth;
		mRectangleData->boundary->h = bHeight;

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
			callbackData->OnDraw2 = &OnDrawCallback2;
			callbackData->OnMouseMove = &OnMouseMoveCallback;
			callbackData->OnMouseLeftDown = &OnMouseLeftDownCallback;
			callbackData->OnMouseLeftUp = &OnMouseLeftUpCallback;
			callbackData->OnScanCodeLeftKeyDown = &OnScanCodeLeftDownCallback;
			callbackData->OnScanCodeLeftKeyUp = &OnScanCodeLeftUpCallback;
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
		//SDL_Log("MovableRectangle::OnDrawCallback");
		MovableRectangle *rect = (MovableRectangle *)self->GetSubClass();//注意,一定要获取subClass
		if (rect)
		{
			RectangleData *data = rect->mRectangleData;
			//RectangleData *data = rect->GetRectangleData();
			if (data)
			{
				// 测试绘制外边框
				SDL_SetRenderDrawColor(renderer, 128, 223, 88, 255);
				SDL_RenderFillRectF(renderer, data->boundary);

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
				//SDL_RenderDrawRectF(renderer, &rect);//带边框的矩形,有个问题,不能设置边框大小

			}
		}
	}


	void MovableRectangle::OnDrawCallback2(void *userdata, SDL_Renderer *renderer)
	{
		//SDL_Log("MovableRectangle::OnDrawCallback2");
		MovableRectangle *rect = (MovableRectangle *)userdata;//注意,一定要获取subClass
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

	void MovableRectangle::OnMouseLeftDownCallback(DisplayObject *self, SDL_Event *event)
	{
		MovableRectangle *rect = (MovableRectangle *)self->GetSubClass();//注意,一定要获取subClass
		if (rect)
		{
			RectangleData *data = rect->mRectangleData;
			//RectangleData *data = rect->GetRectangleData();
			if (data)
			{
				SDL_FPoint point = { event->button.x,event->button.y };
				SDL_FRect *inner = data->dest;
				SDL_Log("Down curPoint(%f,%f)", point.x, point.y);
				if (SDL_PointInFRect(&point, inner))
				{
					SDL_Log("Down In Inner Rectangle");
					data->enableDrag = SDL_TRUE;//可以拖动
					data->point->x = point.x;
					data->point->y = point.y;
				}
			}
		}
	}

	void MovableRectangle::OnMouseLeftUpCallback(DisplayObject *self, SDL_Event *event)
	{
		MovableRectangle *rect = (MovableRectangle *)self->GetSubClass();//注意,一定要获取subClass
		if (rect)
		{
			RectangleData *data = rect->mRectangleData;
			//RectangleData *data = rect->GetRectangleData();
			if (data)
			{
				data->enableDrag = SDL_FALSE;//不可以拖动

			}
		}
	}

	void MovableRectangle::OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{
		MovableRectangle *rect = (MovableRectangle *)self->GetSubClass();//注意,一定要获取subClass
		if (rect)
		{
			RectangleData *data = rect->mRectangleData;
			//RectangleData *data = rect->GetRectangleData();
			if (data)
			{
				//判断是否托动矩形,更新矩形位置
				SDL_FPoint curPoint = { event->motion.x,event->motion.y };
				/*SDL_FPoint curPoint2 = { event->button.x,event->button.y };
				SDL_Log("Drag Inner Rectangle,curPoint(%f,%f),curPoint2(%f,%f)",
					curPoint.x, curPoint.y, curPoint2.x, curPoint2.y);*/

				SDL_FRect *inner = data->dest;
				SDL_FPoint *point = data->point;
				if (SDL_PointInFRect(&curPoint, inner))
				{
					SDL_Log("Drag Inner Rectangle,point(%f,%f),curPoint(%f,%f)",
						point->x, point->y, curPoint.x, curPoint.y);

					float dx = curPoint.x - point->x;
					float dy = curPoint.y - point->y;
					SDL_Log("Drag Inner Rectangle,dx:%f,dy:%f,enableDrag:%d", dx, dy, data->enableDrag);

					// 可拖动
					SDL_bool enableDrag = data->enableDrag;
					if (enableDrag)
					{
						inner->x += dx;//更新矩形位置
						inner->y += dy;

						point->x = curPoint.x;//更新点坐标
						point->y = curPoint.y;

						//限定可拖动边界
						if (inner->x < data->boundary->x)
						{
							inner->x = data->boundary->x;//限定左边界
						}
						if (inner->x > data->boundary->x + (data->boundary->w - inner->w))
						{
							inner->x = data->boundary->x + (data->boundary->w - inner->w);//限定右边界
						}
						if (inner->y < data->boundary->y)
						{
							inner->y = data->boundary->y;//限定左边界
						}
						if (inner->y > data->boundary->y + (data->boundary->h - inner->h))
						{
							inner->y = data->boundary->y + (data->boundary->h - inner->h);//限定右边界
						}
					}
				}
			}
		}
	}

	void MovableRectangle::OnScanCodeLeftDownCallback(DisplayObject *self)
	{
		MovableRectangle *rect = (MovableRectangle *)self->GetSubClass();//注意,一定要获取subClass
		if (rect)
		{
			RectangleData *data = rect->mRectangleData;
			//RectangleData *data = rect->GetRectangleData();
			if (data)
			{

			}
		}
	}

	void MovableRectangle::OnScanCodeLeftUpCallback(DisplayObject *self)
	{
		MovableRectangle *rect = (MovableRectangle *)self->GetSubClass();//注意,一定要获取subClass
		if (rect)
		{
			RectangleData *data = rect->mRectangleData;
			//RectangleData *data = rect->GetRectangleData();
			if (data)
			{

			}
		}
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
				free(data->boundary);
				free(data->point);
				free(data->dest);
				free(data);
				data = nullptr;
				SDL_Log("MovableRectangle::OnDestoryCallback:: free memory");
			}
		}
	}
}