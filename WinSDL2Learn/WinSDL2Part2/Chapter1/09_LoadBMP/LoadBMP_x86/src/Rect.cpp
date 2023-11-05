#include "Rect.h"

namespace Dungeon
{
	Rect::Rect() :mRectData(nullptr)
	{
		//动态申请内存
		this->mRectData = (RectData *)malloc(sizeof(RectData));
		if (mRectData)
		{
			mRectData->color = 0xffffffff;//初始颜色是白色
			mRectData->start.x = 0;
			mRectData->start.y = 0;
			mRectData->end.x = 0;
			mRectData->end.y = 0;
			mRectData->winWidth = 0;
			mRectData->winHeight = 0;
			mRectData->move = SDL_FALSE;
			mRectData->point.x = 0;
			mRectData->point.y = 0;
			mRectData->speedX = 15.5;//X移动速度
			mRectData->speedY = 15.5;//X移动速度
		}
		else
		{
			SDL_Log("Can not create mRectData");
		}
	}

	Rect::~Rect()
	{
		Destory();
	}


	DisplayObject *Rect::Create(int color, int x1, int y1, int x2, int y2, int w, int h)
	{
		if (!mRectData)
		{
			SDL_Log("Rect::Create():: mRectData is null");
			return nullptr;
		}
		mRectData->color = color;
		mRectData->start.x = x1;
		mRectData->start.y = y1;
		mRectData->end.x = x2;
		mRectData->end.y = y2;
		mRectData->winWidth = w;
		mRectData->winHeight = h;

		//把显示对象委托给DisplayObject
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//设置显示对象
		OnCallbackData *callback = displayObject->GetOnCallback();
		if (callback)
		{
			callback->OnDraw = &OnDrawCallback;//设置绘制回调
			callback->OnMouseDown = &OnMouseDownCallback;
			callback->OnMouseUp = &OnMouseUpCallback;
			callback->OnMouseMove = &OnMouseMoveCallback;
			callback->OnDestory = &OnDestoryCallback;//设置释放内存回调
		}
		return displayObject;
	}

	void Rect::OnDrawCallback(DisplayObject *self, SDL_Surface *winSurface, Resource *resource)
	{
		Rect *rect = (Rect *)self->GetSubClass();
		if (rect)
		{
			rect->Draw(winSurface);
		}
	}

	void Rect::OnMouseDownCallback(DisplayObject *self, SDL_Event *event)
	{
		Rect *rect = (Rect *)self->GetSubClass();
		if (rect)
		{
			rect->MouseButtonDown(event);
		}
	}

	void Rect::OnMouseUpCallback(DisplayObject *self, SDL_Event *event)
	{
		Rect *rect = (Rect *)self->GetSubClass();
		if (rect)
		{
			rect->MouseButtonUp(event);
		}
	}

	void Rect::OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{
		Rect *rect = (Rect *)self->GetSubClass();
		if (rect)
		{
			rect->MouseMove(event);
		}
	}

	void Rect::MouseButtonDown(SDL_Event *event)
	{
		if (!mRectData)
		{
			return;
		}
		SDL_FPoint point = { event->button.x,event->button.y };
		float x = mRectData->start.x;
		float y = mRectData->start.y;
		float w = mRectData->end.x - mRectData->start.x;
		float h = mRectData->end.y - mRectData->start.y;
		SDL_FRect rect = { x,y,w,h };
		if (SDL_PointInFRect(&point, &rect))
		{
			mRectData->move = SDL_TRUE;
			mRectData->point.x = point.x;
			mRectData->point.y = point.y;
		}
	}

	void Rect::MouseButtonUp(SDL_Event *event)
	{
		if (!mRectData)
		{
			return;
		}
		mRectData->move = SDL_FALSE;
	}

	void Rect::MouseMove(SDL_Event *event)
	{
		if (!mRectData)
		{
			return;
		}
		SDL_bool move = mRectData->move;
		SDL_FPoint curPoint = { event->motion.x ,event->motion.y };

		float w = mRectData->end.x - mRectData->start.x;//矩形宽
		float h = mRectData->end.y - mRectData->start.y;//矩形高

		// 可拖动
		if (move)
		{
			float dx = curPoint.x - mRectData->point.x;
			float dy = curPoint.y - mRectData->point.y;
			//SDL_Log("Rectangle::MouseMove():: Drag Inner Rectangle,dx:%f,dy:%f", dx, dy);

			mRectData->start.x += dx;//更新矩形位置
			mRectData->start.y += dy;

			mRectData->point.x = curPoint.x;//更新点坐标
			mRectData->point.y = curPoint.y;

			//限定可拖动边界
			if (mRectData->start.x < 0)
			{
				mRectData->start.x = 0;//限定左边界
			}
			if (mRectData->start.x > mRectData->winWidth - w)
			{
				mRectData->start.x = mRectData->winWidth - w;//限定右边界
			}
			if (mRectData->start.y < 0)
			{
				mRectData->start.y = 0;//限定上边界
			}
			if (mRectData->start.y > mRectData->winHeight - h)
			{
				mRectData->start.y = mRectData->winHeight - h;//限定下边界
			}

			//更新矩形终点位置
			mRectData->end.x = mRectData->start.x + w;
			mRectData->end.y = mRectData->start.y + h;
		}
	}

	void Rect::Move()
	{
		if (!mRectData)
		{
			return;
		}

		float w = mRectData->end.x - mRectData->start.x;//矩形宽
		float h = mRectData->end.y - mRectData->start.y;//矩形高

		// 移动	
		mRectData->start.x += mRectData->speedX;//更新矩形位置
		mRectData->start.y += mRectData->speedY;

		//限定可拖动边界
		if (mRectData->start.x < 0)
		{
			mRectData->start.x = 0;//限定左边界
			mRectData->speedX = abs((int)mRectData->speedX);
		}
		if (mRectData->start.x > mRectData->winWidth - w)
		{
			mRectData->start.x = mRectData->winWidth - w;//限定右边界
			mRectData->speedX = -abs((int)mRectData->speedX);
		}
		if (mRectData->start.y < 0)
		{
			mRectData->start.y = 0;//限定上边界
			mRectData->speedY = abs((int)mRectData->speedY);
		}
		if (mRectData->start.y > mRectData->winHeight - h)
		{
			mRectData->start.y = mRectData->winHeight - h;//限定下边界
			mRectData->speedY = -abs((int)mRectData->speedY);
		}

		//更新矩形终点位置
		mRectData->end.x = mRectData->start.x + w;
		mRectData->end.y = mRectData->start.y + h;
	}

	void Rect::OnDestoryCallback(DisplayObject *self)
	{

		Rect *rect = (Rect *)self->GetSubClass();
		if (rect)
		{
			rect->Destory();
		}
	}

	/*
	* 按像素点绘制矩形,效率不高
	*/
	void Rect::Draw(SDL_Surface *winSurface)
	{
		if (!mRectData)
		{
			return;
		}
		//绘制矩形,设置像素点颜色值
		for (int y = mRectData->start.y; y < mRectData->end.y; y++)
		{
			//SDL_Log("Line::Draw():: 111111111111111111111,y:%d", y);
			//一行一行的绘制
			for (int x = mRectData->start.x; x <= mRectData->end.x; x++)
			{
				long index = mRectData->winWidth * y + x;
				//SDL_Log("Line::Draw():: index:%ld", index);
				((Uint32 *)(winSurface->pixels))[index] = mRectData->color;
			}
		}
	}


	void Rect::Destory()
	{
		if (mRectData)
		{
			free(mRectData);
			mRectData = nullptr;
			SDL_Log(" Rect::Destory()::");
		}
	}
}