#include "WalkAnimation.h"


namespace Dungeon
{
	WalkAnimation::WalkAnimation() :mWalkAnimationData(nullptr)
	{
	}

	WalkAnimation::~WalkAnimation()
	{
	}

	DisplayObject *WalkAnimation::Create()
	{
		//动态申请内存
		this->mWalkAnimationData = (WalkAnimationData *)malloc(sizeof(WalkAnimationData));
		if (!mWalkAnimationData)
		{
			return nullptr;
		}
		mWalkAnimationData->dest = (SDL_FRect *)malloc(sizeof(SDL_Rect));
		if (!mWalkAnimationData->dest)
		{
			return nullptr;
		}
		mWalkAnimationData->dest->x = 0;
		mWalkAnimationData->dest->y = 0;
		mWalkAnimationData->dest->w = ANIMATION_WIDTH;
		mWalkAnimationData->dest->h = ANIMATION_HEIGHT;

		mWalkAnimationData->currentFrameIndex = 6;
		mWalkAnimationData->globalFramesCount = 0;
		mWalkAnimationData->walking = SDL_FALSE;
		mWalkAnimationData->speed = ANIMATION_SPEED;
		for (int i = 0; i < ANIMATION_FRAMES; i++)
		{
			mWalkAnimationData->frames[i].x = i * ANIMATION_WIDTH;
			mWalkAnimationData->frames[i].y = 0;
			mWalkAnimationData->frames[i].w = ANIMATION_WIDTH;
			mWalkAnimationData->frames[i].h = ANIMATION_HEIGHT;
		}

		//创建显示对象
		DisplayObject *displayObject = new DisplayObject();
		displayObject->subClass = this;//设置要显示数据
		//设置回调函数
		if (!displayObject->Create(&OnDraw,
			&OnScanCodeLeft,
			&OnScanCodeRight,
			&OnKeyUp,
			&OnDestroy
		))
		{
			return nullptr;
		}

		return displayObject;
	}


	WalkAnimationData *WalkAnimation::GetWalkAnimationData()
	{
		return this->mWalkAnimationData;
	}

	void WalkAnimation::OnDraw(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{

		WalkAnimation *walkAnimation = (WalkAnimation *)self->subClass;
		if (walkAnimation)
		{
			WalkAnimationData *data = walkAnimation->GetWalkAnimationData();
			SDL_Log("OnDrad:: globalFramesCount:%d,walking:%d,currentFrameIndex:%d", data->globalFramesCount,
				data->walking, data->currentFrameIndex);
			if (data)
			{
				//绘制动画
				SDL_RenderCopyExF(renderer, resource->GetWalkTexture(),
					&data->frames[data->currentFrameIndex], data->dest,
					0, nullptr, data->frameFlip);

				data->globalFramesCount++;
				if (data->walking)
				{
					if (data->globalFramesCount % 10 == 0)
					{
						//移动动画
						data->dest->x += data->speed;
						data->currentFrameIndex++;
						if (data->currentFrameIndex == 5)
						{
							data->currentFrameIndex = 0;
						}
					}
				}
			}
		}
	}

	void WalkAnimation::OnScanCodeLeft(DisplayObject *self)
	{
		WalkAnimation *walkAnimation = (WalkAnimation *)self->subClass;
		if (walkAnimation)
		{
			WalkAnimationData *data = walkAnimation->GetWalkAnimationData();
			if (data)
			{
				if (!IsWalking(self))
				{
					if (data->speed > 0)
					{
						data->speed *= -1;
					}
					data->frameFlip = SDL_FLIP_HORIZONTAL;
					GotoAndPlay(self, 0);
				}
			}
		}
	}

	void WalkAnimation::OnScanCodeRight(DisplayObject *self)
	{
		WalkAnimation *walkAnimation = (WalkAnimation *)self->subClass;
		if (walkAnimation)
		{
			WalkAnimationData *data = walkAnimation->GetWalkAnimationData();
			if (data)
			{
				if (data->speed < 0)
				{
					data->speed *= -1;
				}
				data->frameFlip = SDL_FLIP_NONE;
				GotoAndPlay(self, 0);
			}
		}
	}

	void WalkAnimation::OnKeyUp(DisplayObject *self)
	{
		WalkAnimation *walkAnimation = (WalkAnimation *)self->subClass;
		if (walkAnimation)
		{
			WalkAnimationData *data = walkAnimation->GetWalkAnimationData();
			if (data)
			{
				GotoAndStop(self, 6);
			}
		}
	}

	void WalkAnimation::OnDestroy(DisplayObject *self)
	{
		WalkAnimation *walkAnimation = (WalkAnimation *)self->subClass;
		if (walkAnimation)
		{
			WalkAnimationData *data = walkAnimation->GetWalkAnimationData();
			if (data)
			{
				free(data->dest);
				free(data);
			}
		}
	}

	SDL_bool WalkAnimation::IsWalking(DisplayObject *self)
	{
		WalkAnimation *walkAnimation = (WalkAnimation *)self->subClass;
		if (walkAnimation)
		{
			WalkAnimationData *data = walkAnimation->GetWalkAnimationData();
			if (data)
			{
				return data->walking;
			}
		}
		return SDL_FALSE;
	}

	void WalkAnimation::GotoAndPlay(DisplayObject *self, int frameIndex)
	{
		WalkAnimation *walkAnimation = (WalkAnimation *)self->subClass;
		if (walkAnimation)
		{
			WalkAnimationData *data = walkAnimation->GetWalkAnimationData();
			if (data)
			{
				data->walking = SDL_TRUE;
				data->currentFrameIndex = frameIndex;
				SDL_Log("GotoAndPlay: START,walking:%d,currentFrameIndex:%d", data->walking, data->currentFrameIndex);
			}
		}
	}

	void WalkAnimation::GotoAndStop(DisplayObject *self, int frameIndex)
	{
		WalkAnimation *walkAnimation = (WalkAnimation *)self->subClass;
		if (walkAnimation)
		{
			WalkAnimationData *data = walkAnimation->GetWalkAnimationData();
			if (data)
			{
				data->walking = SDL_FALSE;
				data->currentFrameIndex = frameIndex;
				SDL_Log("GotoAndStop: STOP, walking:%d,currentFrameIndex:%d", data->walking, data->currentFrameIndex);
			}
		}
	}
}

