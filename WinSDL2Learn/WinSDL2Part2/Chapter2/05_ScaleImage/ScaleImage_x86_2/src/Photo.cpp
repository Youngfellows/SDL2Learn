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
			mPhotoData->texture = nullptr;
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
		SDL_Texture *texture, OnPhotoClickCallback clickCallback)
	{
		if (!mPhotoData)
		{
			SDL_Log("Photo::Create():: mPhotoData is null");
			return nullptr;
		}
		mPhotoData->texture = texture;
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

	void Photo::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		Photo *photo = (Photo *)self->GetSubClass();
		if (photo)
		{
			photo->Draw(renderer);//绘制图片
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

	void Photo::Draw(SDL_Renderer *renderer)
	{
		if (!mPhotoData)
		{
			SDL_Log("Photo::Draw():: mPhotoData is null");
			return;
		}
		if (!mPhotoData->texture)
		{
			SDL_Log("Photo::Draw():: mPhotoData->texture is null");
			return;
		}

		if (mPhotoData->anim)
		{
			mPhotoData->angle += 4.5;//更新旋转角度
		}

		//绘制图片
		//SDL_RenderCopyF(renderer, mPhotoData->texture, nullptr, mPhotoData->dest);
		SDL_RenderCopyExF(renderer, mPhotoData->texture, nullptr, mPhotoData->dest,
			mPhotoData->angle, nullptr, SDL_FLIP_NONE);//绘制图片
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
