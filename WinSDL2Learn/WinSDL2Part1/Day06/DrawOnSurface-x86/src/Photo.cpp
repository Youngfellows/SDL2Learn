#include "Photo.h"

#include "Config.h"

namespace Dungeon
{
	Photo::Photo() :mPhotoData(nullptr)
	{
		//动态申请内存
		this->mPhotoData = (PhontData *)malloc(sizeof(PhontData));
		if (mPhotoData)
		{
			mPhotoData->anim = SDL_FALSE;
			mPhotoData->angle = 0;
			mPhotoData->OnClick = nullptr;
			mPhotoData->picSurface = nullptr;
			mPhotoData->dest = (SDL_FRect *)malloc(sizeof(SDL_FRect));
			if (mPhotoData->dest)
			{
				mPhotoData->dest->x = 0;
				mPhotoData->dest->y = 0;
				mPhotoData->dest->w = 0;
				mPhotoData->dest->h = 0;
			}
			else
			{
				SDL_Log("Create mPhotoData->dest error");
			}
			mPhotoData->move = SDL_FALSE;
			mPhotoData->point = (SDL_FPoint *)malloc(sizeof(SDL_FPoint));
			if (mPhotoData->point)
			{
				mPhotoData->point->x = 0;
				mPhotoData->point->y = 0;
			}
			else
			{
				SDL_Log("Create mPhotoData->point error");
			}
		}
		else
		{
			SDL_Log("Create mPhotoData error");
		}
	}

	Photo::~Photo()
	{
	}

	DisplayObject *Photo::Create(float x, float y, float w, float h,
		SDL_Surface *picSurface, OnPhotoClickCallback clickCallback)
	{
		if (!mPhotoData)
		{
			SDL_Log("Photo::Create():: mPhotoData is null");
			return nullptr;
		}
		mPhotoData->picSurface = picSurface;
		mPhotoData->OnClick = clickCallback;
		if (!mPhotoData->dest)
		{
			SDL_Log("Photo::Create():: mPhotoData->dest is null");
			return nullptr;
		}
		mPhotoData->dest->x = x;
		mPhotoData->dest->y = y;
		mPhotoData->dest->w = w;
		mPhotoData->dest->h = h;

		//创建要显示对象代理
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//设置要显示对象
		OnCallbackData *callback = displayObject->GetOnCallback();//设置回调函数
		if (callback)
		{
			callback->OnDraw = &OnDrawCallback;
			callback->OnMouseDown = &OnMouseDownCallback;
			callback->OnMouseMove = &OnMouseMoveCallback;
			callback->OnMouseUp = &OnMouseUpCallback;
			callback->OnDestory = &OnDestoryCallback;
		}
		return displayObject;
	}

	void Photo::OnDrawCallback(DisplayObject *self, SDL_Surface *winSurface, Resource *resource)
	{
		Photo *photo = (Photo *)self->GetSubClass();
		if (photo)
		{
			photo->Draw(winSurface);//绘制图片
		}
	}

	void Photo::OnMouseDownCallback(DisplayObject *self, SDL_Event *event)
	{
		Photo *photo = (Photo *)self->GetSubClass();
		if (photo)
		{
			photo->MouseButtonDown(event);
		}
	}

	void Photo::OnMouseUpCallback(DisplayObject *self, SDL_Event *event)
	{
		Photo *photo = (Photo *)self->GetSubClass();
		if (photo)
		{
			photo->MouseButtonUp(event);
		}
	}

	void Photo::OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{
		Photo *photo = (Photo *)self->GetSubClass();
		if (photo)
		{
			photo->MouseMove(event);
		}
	}

	void Photo::OnDestoryCallback(DisplayObject *self)
	{
		Photo *photo = (Photo *)self->GetSubClass();
		if (photo)
		{
			photo->Destory();
		}
	}

	void Photo::Rotate()
	{
		if (!mPhotoData)
		{
			SDL_Log("Photo::Rotate():: mPhotoData is null");
			return;
		}
		mPhotoData->anim = SDL_TRUE;
	}

	/*
	* 绘制图片: 使用Surface
	*/
	void Photo::Draw(SDL_Surface *winSurface)
	{
		if (!mPhotoData)
		{
			SDL_Log("Photo::Draw():: mPhotoData is null");
			return;
		}
		if (!mPhotoData->picSurface)
		{
			SDL_Log("Photo::Draw():: mPhotoData->texture is null");
			return;
		}

		if (mPhotoData->anim)
		{
			mPhotoData->angle += 4.5;//更新旋转角度
		}

		//绘制图片
		SDL_Rect src = { 0,0,
			mPhotoData->picSurface->w,
			mPhotoData->picSurface->h };

		SDL_Rect dest = {
		(int)mPhotoData->dest->x,
		(int)mPhotoData->dest->y,
		(int)mPhotoData->dest->w,
		(int)mPhotoData->dest->h
		};

		//使用Surface绘制图片有弊端,不能缩放图片,是完整的全像素绘制

		//把整张图片绘制出来,从(0,0)开始绘制
		//SDL_BlitSurface(mPhotoData->picSurface, &src, winSurface, &src);
		//其实是绘制了整张图片,但是只显示图片的局部dest,相当于截取部分显示
		//SDL_BlitSurface(mPhotoData->picSurface, &dest, winSurface, &dest);

		//把整张图片绘制出来,从(dest->x,dest->y)开始绘制,也就是只有拖动dest部分可以更改绘制位置
		SDL_BlitSurface(mPhotoData->picSurface, &src, winSurface, &dest);
	}

	void Photo::MouseButtonDown(SDL_Event *event)
	{
		if (!mPhotoData)
		{
			return;
		}
		SDL_FPoint point = { event->button.x ,event->button.y };
		if (SDL_PointInFRect(&point, mPhotoData->dest))
		{
			mPhotoData->move = SDL_TRUE;
			//更新位置
			mPhotoData->point->x = point.x;
			mPhotoData->point->y = point.y;
			if (mPhotoData->OnClick)
			{
				mPhotoData->OnClick();
			}
		}
	}

	void Photo::MouseButtonUp(SDL_Event *event)
	{
		if (!mPhotoData)
		{
			return;
		}
		mPhotoData->move = SDL_FALSE;
		mPhotoData->anim = SDL_FALSE;
	}

	void Photo::MouseMove(SDL_Event *event)
	{
		if (!mPhotoData)
		{
			return;
		}
		SDL_bool move = mPhotoData->move;
		SDL_FPoint *point = mPhotoData->point;
		SDL_FPoint curPoint = { event->motion.x ,event->motion.y };
		SDL_FRect *inner = mPhotoData->dest;
		SDL_Log("Photo::MouseMove:: point(%f,%f),curPoint(%f,%f),move:%d",
			point->x, point->y, curPoint.x, curPoint.y, move);

		// 可拖动
		if (move)
		{
			float dx = curPoint.x - point->x;
			float dy = curPoint.y - point->y;
			SDL_Log("Photo::MouseMove:::: Drag Inner Rectangle,dx:%f,dy:%f", dx, dy);

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

	void Photo::Destory()
	{
		//释放内存资源
		if (mPhotoData)
		{
			if (mPhotoData->point)
			{
				free(mPhotoData->point);
			}
			if (mPhotoData->dest)
			{
				free(mPhotoData->dest);
			}
			free(mPhotoData);
			mPhotoData = nullptr;
		}
	}
}
