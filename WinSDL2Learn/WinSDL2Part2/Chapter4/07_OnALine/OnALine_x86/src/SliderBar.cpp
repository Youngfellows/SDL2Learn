#include "SliderBar.h"


namespace Dungeon
{
	SliderBar::SliderBar() :mSliderBarData(nullptr)
	{
	}

	SliderBar::~SliderBar()
	{

	}

	DisplayObject *SliderBar::Create(float borderX, float borderY, float borderW, float borderH,
		float sliderW, float sliderH)
	{
		//��̬�����ڴ�
		this->mSliderBarData = (SliderBarData *)malloc(sizeof(SliderBarData));
		if (!mSliderBarData)
		{
			return nullptr;
		}
		mSliderBarData->border = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mSliderBarData->border)
		{
			return nullptr;
		}
		mSliderBarData->border->x = borderX;
		mSliderBarData->border->y = borderY;
		mSliderBarData->border->w = borderW;
		mSliderBarData->border->h = borderH;

		mSliderBarData->sliderData = (SliderData *)malloc(sizeof(SliderData));
		if (!mSliderBarData->sliderData)
		{
			return nullptr;
		}
		mSliderBarData->sliderData->sliderDest = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mSliderBarData->sliderData->sliderDest)
		{
			return nullptr;
		}
		mSliderBarData->sliderData->sliderDest->x = borderX;
		mSliderBarData->sliderData->sliderDest->y = borderY;
		mSliderBarData->sliderData->sliderDest->w = sliderW;
		mSliderBarData->sliderData->sliderDest->h = sliderH;

		mSliderBarData->sliderData->sliderPoint = (SDL_FPoint *)malloc(sizeof(SDL_FPoint));
		if (!mSliderBarData->sliderData->sliderPoint)
		{
			return nullptr;
		}
		mSliderBarData->sliderData->sliderPoint->x = 0;
		mSliderBarData->sliderData->sliderPoint->y = 0;

		//����Ҫ��ʾ����
		DisplayObject *displayObject = new DisplayObject();
		displayObject->subClass = this;//����Ҫ��ʾ����
		//���ûص�����
		if (!displayObject->Create(&OnDrawCallback, &OnMouseMoveCallback, &OnDestoryCallback))
		{
			return nullptr;
		}

		return displayObject;
	}

	/*
	* �ص�����OnDraw
	*/
	void SliderBar::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		SliderBar *slidarBar = (SliderBar *)self->subClass;
		if (slidarBar)
		{
			SliderBarData *data = slidarBar->mSliderBarData;
			if (data)
			{
				//���Ʊ߿�
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderDrawRectF(renderer, data->border);

				//���ƻ���
				SliderData *slidarData = data->sliderData;
				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
				SDL_RenderDrawRectF(renderer, slidarData->sliderDest);
			}
		}
	}

	/*
	* �ص�����OnMouseMove
	*/
	void SliderBar::OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{
		SliderBar *slidarBar = (SliderBar *)self->subClass;
		if (slidarBar)
		{
			SliderBarData *data = slidarBar->mSliderBarData;
			if (data)
			{
				//���»���λ��
				SDL_FRect *border = data->border;
				SliderData *slidarData = data->sliderData;
				SDL_FPoint *point = slidarData->sliderPoint;
				SDL_FRect *sliderDest = slidarData->sliderDest;

				point->x = event->motion.x;
				point->y = event->motion.y;

				/*if (SDL_PointInFRect(point,sliderDest))
				{
				
				}*/
				if (point->x < border->x)
				{
					point->x = border->x;
				}
				if (point->x > border->x + border->w - sliderDest->w)
				{
					point->x = border->x + border->w - sliderDest->w;
				}
				sliderDest->x = point->x;
			}
		}
	}


	/*
	* �ص�����OnDestory
	*/
	void SliderBar::OnDestoryCallback(DisplayObject *self)
	{
		SliderBar *slidarBar = (SliderBar *)self->subClass;
		if (slidarBar)
		{
			SliderBarData *data = slidarBar->mSliderBarData;
			if (data)
			{
				SDL_FRect *border = data->border;
				SliderData *slidarData = data->sliderData;
				SDL_FPoint *point = slidarData->sliderPoint;
				SDL_FRect *sliderDest = slidarData->sliderDest;
				free(point);
				free(sliderDest);
				free(slidarData);
				free(border);
				free(data);
			}
		}
	}
}