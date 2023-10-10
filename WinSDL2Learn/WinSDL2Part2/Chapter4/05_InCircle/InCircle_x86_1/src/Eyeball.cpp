#include "Eyeball.h"
#include "Config.h"

namespace Dungeon
{
	Eyeball::Eyeball()
	{

	}

	DisplayObject *Eyeball::Eyeball_Create(float centerX, float centerY)
	{
		EyeballData *data = (EyeballData *)malloc(sizeof(EyeballData));//动态申请内存
		if (!data)
		{
			return nullptr;
		}

		data->eyeRadius = EYEBALL_RADIUS;//眼球半径
		data->eyeCenter = (SDL_FPoint *)malloc(sizeof(SDL_FPoint));//眼睛中心位置
		if (!data->eyeCenter)
		{
			return nullptr;
		}
		data->eyeCenter->x = centerX;
		data->eyeCenter->y = centerY;

		data->eyeballSrcRect = (SDL_Rect *)malloc(sizeof(SDL_Rect));//眼球图片矩形(10*10)
		if (!data->eyeballSrcRect)
		{
			return nullptr;
		}
		data->eyeballSrcRect->x = EYEBALL_SRC_RECT_X;
		data->eyeballSrcRect->y = EYEBALL_SRC_RECT_Y;
		data->eyeballSrcRect->w = EYEBALL_SRC_RECT_WIDTH;
		data->eyeballSrcRect->h = EYEBALL_SRC_RECT_HEIGHT;

		data->eyeballDestRect = (SDL_FRect *)malloc(sizeof(SDL_FRect));//要绘制眼球图片矩形
		if (!data->eyeballDestRect)
		{
			return nullptr;
		}
		data->eyeballDestRect->x = centerX;
		data->eyeballDestRect->y = centerY;
		/*data->eyeballDestRect->w = data->eyeballSrcRect->w;
		data->eyeballDestRect->h = data->eyeballSrcRect->h;*/
		data->eyeballDestRect->w = EYEBALL_SRC_RECT_WIDTH;
		data->eyeballDestRect->h = EYEBALL_SRC_RECT_HEIGHT;

		data->eyeSrcRect = (SDL_Rect *)malloc(sizeof(SDL_Rect));//眼睛图片矩形(40*40)
		if (!data->eyeSrcRect)
		{

			return nullptr;
		}
		data->eyeSrcRect->x = EYE_SRC_RECT_X;
		data->eyeSrcRect->y = EYE_SRC_RECT_Y;
		data->eyeSrcRect->w = EYE_SRC_RECT_WIDTH;
		data->eyeSrcRect->h = EYE_SRC_RECT_HEIGHT;

		data->eyeDestRect = (SDL_FRect *)malloc(sizeof(SDL_FRect));//要绘制眼睛图片矩形
		if (!data->eyeDestRect)
		{

			return nullptr;
		}

		if (data->eyeCenter)
		{
			data->eyeDestRect->x = data->eyeCenter->x - EYE_SRC_RECT_WIDTH / 2;
			data->eyeDestRect->y = data->eyeCenter->y - EYE_SRC_RECT_HEIGHT / 2;
			data->eyeDestRect->w = EYE_SRC_RECT_WIDTH;
			data->eyeDestRect->h = EYE_SRC_RECT_HEIGHT;
		}

		//创建要显示的对象
		DisplayObject *displayObject = new DisplayObject();
		displayObject->DisplayObject_Create(&Eyeball_CursorOnDraw, &Eyeball_CursorOnMouseMove);
		displayObject->subClassData = data;//为绘制对象赋值
		return displayObject;
	}

	void Eyeball::Eyeball_Destory(DisplayObject *self)
	{
		if (self)
		{
			EyeballData *data = (EyeballData *)self->subClassData;
			if (data)
			{
				if (data->eyeDestRect)
				{
					free(data->eyeDestRect);
				}
				if (data->eyeSrcRect)
				{
					free(data->eyeSrcRect);
				}
				if (data->eyeballDestRect)
				{
					free(data->eyeballDestRect);
				}
				if (data->eyeballSrcRect)
				{
					free(data->eyeballSrcRect);
				}
				free(data);
			}
		}
	}

	/*
	* OnDraw回调函数绘制眼睛+眼球
	*/
	void Eyeball::Eyeball_CursorOnDraw(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		EyeballData *data = (EyeballData *)self->subClassData;
		if (data)
		{
			SDL_RenderCopyF(renderer, resource->Resource_GetEyeTexture(), data->eyeSrcRect, data->eyeDestRect);//绘制眼睛
			SDL_RenderCopyF(renderer, resource->Resource_GetEyeTexture(), data->eyeballSrcRect, data->eyeballDestRect);//绘制眼球
		}
	}

	/*
	* OnMouseMove回调函数更新眼球位置
	*/
	void Eyeball::Eyeball_CursorOnMouseMove(DisplayObject *self, SDL_Event *event)
	{
		EyeballData *data = (EyeballData *)self->subClassData;
		if (data)
		{
			float halfW = data->eyeballDestRect->w / 2;
			float halfH = data->eyeballDestRect->h / 2;
			data->eyeballDestRect->x = event->motion.x - halfW;
			data->eyeballDestRect->y = event->motion.y - halfH;

			float mouseDistanceX = event->motion.x - data->eyeCenter->x;
			float mouseDistanceY = event->motion.y - data->eyeCenter->y;
			float mouseDistance = SDL_sqrtf(mouseDistanceX * mouseDistanceX + mouseDistanceY * mouseDistanceY);
			if (mouseDistance > data->eyeRadius) {
				data->eyeballDestRect->x = data->eyeCenter->x + mouseDistanceX / mouseDistance * data->eyeRadius - halfW;
				data->eyeballDestRect->y = data->eyeCenter->y + mouseDistanceY / mouseDistance * data->eyeRadius - halfH;
			}
		}
	}

	Eyeball::~Eyeball()
	{
	}
}