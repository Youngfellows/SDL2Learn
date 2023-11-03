#include "StarlitSky.h"

namespace Dungeon
{
	StarlitSky::StarlitSky() :mStarlitData(nullptr)
	{
		//动态申请内存
		this->mStarlitData = (StarlitSkyData *)malloc(sizeof(StarlitSkyData));
		if (mStarlitData)
		{
			mStarlitData->size = 0;
			mStarlitData->color = 0;
			mStarlitData->bgColor = 0;
			mStarlitData->bubbles = new std::vector<Bubble *>;
			mStarlitData->move = SDL_FALSE;
			mStarlitData->point.x = 0;
			mStarlitData->point.y = 0;
			mStarlitData->texture = nullptr;
			mStarlitData->dest = (SDL_FRect *)malloc(sizeof(SDL_FRect));
			if (mStarlitData->dest)
			{
				mStarlitData->dest->x = 0;
				mStarlitData->dest->y = 0;
				mStarlitData->dest->w = 0;
				mStarlitData->dest->h = 0;
			}
			else
			{
				SDL_Log("Create mStarlitData->dest error");
			}
		}
		else
		{
			SDL_Log("Create mStarlitData error");
		}
	}

	StarlitSky::~StarlitSky()
	{
		SDL_Log("StarlitSky::~StarlitSky()::");
		Destory();
	}

	DisplayObject *StarlitSky::Create(Resource *resource, Uint32 size, Uint32 color, Uint32 bgColor, float x, float y, float w, float h)
	{
		if (!this->mStarlitData)
		{
			SDL_Log("StarlitSky::Create():: mStarlitData is null");
			return nullptr;
		}
		mStarlitData->size = size;
		mStarlitData->color = color;
		mStarlitData->bgColor = bgColor;
		if (!mStarlitData->dest)
		{
			SDL_Log("StarlitSky::Create():: mStarlitData->dest is null");
			return nullptr;
		}
		mStarlitData->dest->x = x;
		mStarlitData->dest->y = y;
		mStarlitData->dest->w = w;
		mStarlitData->dest->h = h;
		mStarlitData->texture = resource->GetLandscapeTexture();
		CreatePoints(resource);//创建点

		//创建显示代理对象
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);
		OnCallbackData *callback = displayObject->GetOnCallback();
		if (callback)
		{
			callback->OnDraw = &OnDrawCallback;
			callback->OnMouseDown = &OnMouseDownCallback;
			callback->OnMouseUp = &OnMouseUpCallback;
			callback->OnMouseMove = &OnMouseMoveCallback;
			callback->OnDestory = &OnDestoryCallbac;
		}
		return displayObject;
	}

	void StarlitSky::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		StarlitSky *starlitSky = (StarlitSky *)self->GetSubClass();
		if (starlitSky)
		{
			starlitSky->Draw(resource, renderer);
		}
	}

	void StarlitSky::OnMouseDownCallback(DisplayObject *self, SDL_Event *event)
	{
		StarlitSky *starlitSky = (StarlitSky *)self->GetSubClass();
		if (starlitSky)
		{
			starlitSky->MouseButtonDown(event);
		}
	}

	void StarlitSky::OnMouseUpCallback(DisplayObject *self, SDL_Event *event)
	{
		StarlitSky *starlitSky = (StarlitSky *)self->GetSubClass();
		if (starlitSky)
		{
			starlitSky->MouseButtonUp(event);
		}
	}

	void StarlitSky::OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{
		StarlitSky *starlitSky = (StarlitSky *)self->GetSubClass();
		if (starlitSky)
		{
			starlitSky->MouseButtonMove(event);
		}
	}

	void StarlitSky::MouseButtonDown(SDL_Event *event)
	{
		//SDL_Log("StarlitSky::MouseButtonDown():: mouse button down");
		if (!mStarlitData)
		{
			SDL_Log("StarlitSky::MouseButtonDown():: mStarlitData is null");
			return;
		}
		SDL_FPoint point = { event->button.x,event->button.y };
		if (SDL_PointInFRect(&point, mStarlitData->dest))
		{
			SDL_Log("StarlitSky::MouseButtonDown():: In StarlitSky, mouse button down");
			mStarlitData->move = SDL_TRUE;
			mStarlitData->point.x = point.x;
			mStarlitData->point.y = point.y;
		}
	}

	void StarlitSky::MouseButtonUp(SDL_Event *event)
	{
		SDL_Log("StarlitSky::MouseButtonUp():: mouse button up");
		if (!mStarlitData)
		{
			SDL_Log("StarlitSky::MouseButtonUp():: mStarlitData is null");
			return;
		}
		mStarlitData->move = SDL_FALSE;

		std::vector<Bubble *>::iterator it;
		for (it = mStarlitData->bubbles->begin(); it != mStarlitData->bubbles->end(); it++)
		{
			Bubble *bubble = *it;//获取元素
			bubble->SetMouseMove(SDL_FALSE);
		}
	}

	void StarlitSky::MouseButtonMove(SDL_Event *event)
	{
		SDL_Log("StarlitSky::MouseButtonMove():: mouse move");
		if (!mStarlitData)
		{
			SDL_Log("StarlitSky::MouseButtonMove():: mStarlitData is null");
			return;
		}
		SDL_FPoint curPoint = { event->motion.x,event->motion.y };
		SDL_bool move = mStarlitData->move;
		if (move)
		{
			float dx = curPoint.x - mStarlitData->point.x;
			float dy = curPoint.y - mStarlitData->point.y;
			mStarlitData->dest->x += dx;
			mStarlitData->dest->y += dy;
			mStarlitData->point.x = curPoint.x;
			mStarlitData->point.y = curPoint.y;
			//限定边界
			if (mStarlitData->dest->x < 0)
			{
				mStarlitData->dest->x = 0;
			}
			if (mStarlitData->dest->x > WINDOW_WIDTH - mStarlitData->dest->w)
			{
				mStarlitData->dest->x = WINDOW_WIDTH - mStarlitData->dest->w;
			}

			if (mStarlitData->dest->y < 0)
			{
				mStarlitData->dest->y = 0;
			}
			if (mStarlitData->dest->y > WINDOW_HEIGHT - mStarlitData->dest->h)
			{
				mStarlitData->dest->y = WINDOW_HEIGHT - mStarlitData->dest->h;
			}

			//变化的位置
			SDL_FPoint dPoint = { dx,dy };
			UpdateBubblePosition(dPoint);
		}
	}

	void StarlitSky::UpdateBubblePosition(SDL_FPoint point)
	{
		if (!mStarlitData)
		{
			return;
		}
		std::vector<Bubble *>::iterator it;
		for (it = mStarlitData->bubbles->begin(); it != mStarlitData->bubbles->end(); it++)
		{
			Bubble *bubble = *it;//获取元素
			bubble->SetMouseMove(SDL_TRUE);
			bubble->MouseMove(point);
		}
	}

	void StarlitSky::OnDestoryCallbac(DisplayObject *self)
	{
		StarlitSky *starlitSky = (StarlitSky *)self->GetSubClass();
		if (starlitSky)
		{
			starlitSky->Destory();
		}
	}

	void StarlitSky::CreatePoints(Resource *resource)
	{
		if (!mStarlitData)
		{
			return;
		}
		SDL_Log("StarlitSky::CreatePoints():: Start ...");
		for (int i = 0; i < mStarlitData->size; i++)
		{
			SDL_FRect border = { mStarlitData->dest->x ,mStarlitData->dest->y,mStarlitData->dest->w,mStarlitData->dest->h };
			SDL_Log("StarlitSky::CreatePoints():: %d,Start,border{%f,%f,%f,%f}", i, border.x, border.y, border.w, border.h);
			Bubble *bubble = new Bubble(resource, mStarlitData->bgColor, border);
			//SDL_Log("StarlitSky::CreatePoints():: xxxx,mStarlitData->points:%p", mStarlitData->points);
			mStarlitData->bubbles->push_back(bubble);//把点添加到列表中
			SDL_Log("StarlitSky::CreatePoints():: point:%p", bubble);
		}
		SDL_Log("StarlitSky::CreatePoints():: End ...");
	}

	void StarlitSky::DrawPoints(Resource *resource, SDL_Renderer *renderer)
	{
		if (mStarlitData)
		{
			// 1.使用迭代器
			std::vector<Bubble *>::iterator it;
			for (it = mStarlitData->bubbles->begin(); it != mStarlitData->bubbles->end(); it++)
			{
				Bubble *bubble = *it;//获取元素
				bubble->Draw(resource, renderer);//绘制每一个点
			}
		}
	}

	void StarlitSky::DrawBackground(SDL_Renderer *renderer)
	{
		if (mStarlitData)
		{
			if (!mStarlitData->texture)
			{
				//0xffffffff ARGB
				SDL_Color color = {
					(mStarlitData->color & 0x00ff0000) >> 16,//R
					(mStarlitData->color & 0x0000ff00) >> 8,//G
					(mStarlitData->color & 0x000000ff) >> 0,//B
					(mStarlitData->color & 0xff000000) >> 24,//A
				};
				SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);//设置颜色
				SDL_RenderFillRectF(renderer, mStarlitData->dest);//绘制背景
			}
			else
			{
				//绘制背景图
				SDL_RenderCopyF(renderer, mStarlitData->texture, nullptr, mStarlitData->dest);
			}
		}
	}

	void StarlitSky::Draw(Resource *resource, SDL_Renderer *renderer)
	{
		DrawBackground(renderer);//绘制背景
		DrawPoints(resource, renderer);//绘制点
	}

	void StarlitSky::Destory()
	{
		SDL_Log("StarlitSky::~Destory()::");
		if (mStarlitData)
		{
			if (mStarlitData->bubbles)
			{
				std::vector<Bubble *>::iterator it;
				int i = 0;
				for (it = mStarlitData->bubbles->begin(); it != mStarlitData->bubbles->end(); it++)
				{
					Bubble *point = *it;//获取元素
					delete point;
				}
				delete mStarlitData->bubbles;
				mStarlitData->bubbles = nullptr;
			}

			if (mStarlitData->dest)
			{
				free(mStarlitData->dest);
				mStarlitData->dest = nullptr;
			}
			free(mStarlitData);
			mStarlitData = nullptr;
		}
	}
}