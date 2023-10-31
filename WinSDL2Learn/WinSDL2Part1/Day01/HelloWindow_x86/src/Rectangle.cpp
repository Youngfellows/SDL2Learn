#include "Rectangle.h"
#include "Config.h"

namespace Dungeon
{
	Rectangle::Rectangle() :mRectangleData(nullptr)
	{
		//动态申请内存
		this->mRectangleData = (RectangleData *)malloc(sizeof(RectangleData));
		if (mRectangleData)
		{
			mRectangleData->dest = nullptr;
			mRectangleData->OnClick = nullptr;
			mRectangleData->point = nullptr;
		}
		else
		{
			SDL_Log("Can not create mRectangleData");
		}
	}

	Rectangle::~Rectangle()
	{
		SDL_Log("Rectangle::~Rectangle()::");
		Destory();
	}

	DisplayObject *Rectangle::Create(float x, float y, float w, float h,
		int color, int borderColor, int borderSize, OnRectangleClickCallback onClickCallback)
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
		mRectangleData->OnClick = onClickCallback;
		mRectangleData->move = SDL_FALSE;
		mRectangleData->point = (SDL_FPoint *)malloc(sizeof(SDL_FPoint));
		if (!mRectangleData->point)
		{
			return nullptr;
		}

		//创建要显示对象代理类
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//把当前对象设置过去
		OnCallbackData *onCallback = displayObject->GetOnCallback();//设置回调函数
		if (onCallback)
		{
			onCallback->OnDraw = &OnDrawCallback;
			onCallback->OnMouseMove = &OnMouseMoveCallback;
			onCallback->OnMouseDown = &OnMouseDownCallback;
			onCallback->OnMouseUp = &OnMouseUpCallback;
			onCallback->OnDestory = &OnDestoryCallback;
		}
		return displayObject;
	}

	void Rectangle::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		Rectangle *rect = (Rectangle *)self->GetSubClass();
		if (rect)
		{
			rect->Draw(resource, renderer);
		}
	}

	void Rectangle::OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{
		Rectangle *rect = (Rectangle *)self->GetSubClass();
		if (rect)
		{
			rect->MouseMove(event);
		}
	}

	void Rectangle::OnMouseDownCallback(DisplayObject *self, SDL_Event *event)
	{
		Rectangle *rect = (Rectangle *)self->GetSubClass();
		if (rect)
		{
			rect->MouseDown(event);
		}
	}

	void Rectangle::OnMouseUpCallback(DisplayObject *self, SDL_Event *event)
	{
		Rectangle *rect = (Rectangle *)self->GetSubClass();
		if (rect)
		{
			rect->MouseUp(event);
		}
	}

	void Rectangle::OnDestoryCallback(DisplayObject *self)
	{
		Rectangle *rect = (Rectangle *)self->GetSubClass();
		if (rect)
		{
			rect->Destory();//释放内存
		}
	}

	/*
	* 绘制图形
	*/
	void  Rectangle::Draw(Resource *resource, SDL_Renderer *renderer)
	{
		if (!mRectangleData)
		{
			SDL_Log("Rectangle::Draw():: mRectangleData is null");
			return;
		}
		//0xffffffff ARGB
		SDL_Color color = {
			(mRectangleData->color & 0x00ff0000) >> 16,//r
			(mRectangleData->color & 0x0000ff00) >> 8,//g
			(mRectangleData->color & 0x000000ff),//b
			(mRectangleData->color & 0xff000000) >> 24,//a
		};
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderFillRectF(renderer, mRectangleData->dest);
	}

	/*
	* 处理鼠标移动事件
	*/
	void  Rectangle::MouseMove(SDL_Event *event)
	{
		if (!mRectangleData)
		{
			SDL_Log("Rectangle::MouseMove():: mRectangleData is null");
			return;
		}
		SDL_bool move = mRectangleData->move;
		SDL_FPoint *point = mRectangleData->point;
		SDL_FPoint curPoint = { event->motion.x ,event->motion.y };
		SDL_FRect *inner = mRectangleData->dest;
		SDL_Log("Rectangle::MouseMove():: point(%f,%f),curPoint(%f,%f),move:%d",
			point->x, point->y, curPoint.x, curPoint.y, move);

		if (SDL_PointInFRect(&curPoint, inner))
		{
			SDL_Log("Rectangle::MouseMove():: Move Inner Rectangle");
		}

		// 可拖动

		if (move)
		{
			float dx = curPoint.x - point->x;
			float dy = curPoint.y - point->y;
			SDL_Log("Rectangle::MouseMove():: Drag Inner Rectangle,dx:%f,dy:%f", dx, dy);

			inner->x += dx;//更新矩形位置
			inner->y += dy;

			point->x = curPoint.x;//更新点坐标
			point->y = curPoint.y;

			//限定可拖动边界
			if (inner->x < 0)
			{
				inner->x = 0;//限定左边界
			}
			if (inner->x > WINDOW_WIDTH - inner->w)
			{
				inner->x = WINDOW_WIDTH - inner->w;//限定右边界
			}
			if (inner->y < 0)
			{
				inner->y = 0;//限定上边界
			}
			if (inner->y > WINDOW_HEIGHT - inner->h)
			{
				inner->y = WINDOW_HEIGHT - inner->h;//限定下边界
			}
		}
	}

	/*
	* 处理鼠标键按下事件
	*/
	void  Rectangle::MouseDown(SDL_Event *event)
	{
		if (!mRectangleData)
		{
			SDL_Log("Rectangle::MouseDown():: mRectangleData is null");
			return;
		}
		SDL_Log("Rectangle::MouseDown()::");
		SDL_FPoint point = { event->button.x,event->button.y };
		if (SDL_PointInFRect(&point, mRectangleData->dest))
		{
			SDL_Log("Rectangle::MouseDown():: Click");
			mRectangleData->move = SDL_TRUE;//可拖动
			mRectangleData->point->x = point.x;//设置当前按下位置坐标
			mRectangleData->point->y = point.y;
			if (mRectangleData->OnClick)
			{
				mRectangleData->OnClick();//调用回调函数
			}
		}
		else
		{
			mRectangleData->move = SDL_FALSE;//不可拖动
		}
	}

	void Rectangle::MouseUp(SDL_Event *event)
	{
		if (!mRectangleData)
		{
			SDL_Log("Rectangle::MouseUp():: mRectangleData is null");
			return;
		}
		mRectangleData->move = SDL_FALSE;
		SDL_Log("Rectangle::MouseUp()::");
	}

	void Rectangle::Destory()
	{
		SDL_Log("Rectangle::Destory()::");
		//释放内存资源
		if (mRectangleData)
		{
			if (mRectangleData->point)
			{
				free(mRectangleData->point);
			}
			if (mRectangleData->dest)
			{
				free(mRectangleData->dest);
			}
			free(mRectangleData);
		}
	}
}