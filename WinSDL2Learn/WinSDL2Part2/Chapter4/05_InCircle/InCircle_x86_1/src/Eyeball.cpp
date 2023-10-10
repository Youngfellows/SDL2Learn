#include "Eyeball.h"
#include "Config.h"

namespace Dungeon
{
	Eyeball::Eyeball()
	{

	}

	DisplayObject *Eyeball::Eyeball_Create(float centerX, float centerY)
	{
		EyeballData *data = (EyeballData *)malloc(sizeof(EyeballData));//��̬�����ڴ�
		if (!data)
		{
			return nullptr;
		}

		data->eyeRadius = EYEBALL_RADIUS;//����뾶
		data->eyeCenter = (SDL_FPoint *)malloc(sizeof(SDL_FPoint));//�۾�����λ��
		if (!data->eyeCenter)
		{
			return nullptr;
		}
		data->eyeCenter->x = centerX;
		data->eyeCenter->y = centerY;

		data->eyeballSrcRect = (SDL_Rect *)malloc(sizeof(SDL_Rect));//����ͼƬ����(10*10)
		if (!data->eyeballSrcRect)
		{
			return nullptr;
		}
		data->eyeballSrcRect->x = EYEBALL_SRC_RECT_X;
		data->eyeballSrcRect->y = EYEBALL_SRC_RECT_Y;
		data->eyeballSrcRect->w = EYEBALL_SRC_RECT_WIDTH;
		data->eyeballSrcRect->h = EYEBALL_SRC_RECT_HEIGHT;

		data->eyeballDestRect = (SDL_FRect *)malloc(sizeof(SDL_FRect));//Ҫ��������ͼƬ����
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

		data->eyeSrcRect = (SDL_Rect *)malloc(sizeof(SDL_Rect));//�۾�ͼƬ����(40*40)
		if (!data->eyeSrcRect)
		{

			return nullptr;
		}
		data->eyeSrcRect->x = EYE_SRC_RECT_X;
		data->eyeSrcRect->y = EYE_SRC_RECT_Y;
		data->eyeSrcRect->w = EYE_SRC_RECT_WIDTH;
		data->eyeSrcRect->h = EYE_SRC_RECT_HEIGHT;

		data->eyeDestRect = (SDL_FRect *)malloc(sizeof(SDL_FRect));//Ҫ�����۾�ͼƬ����
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

		//����Ҫ��ʾ�Ķ���
		DisplayObject *displayObject = new DisplayObject();
		displayObject->DisplayObject_Create(&Eyeball_CursorOnDraw, &Eyeball_CursorOnMouseMove);
		displayObject->subClassData = data;//Ϊ���ƶ���ֵ
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
	* OnDraw�ص����������۾�+����
	*/
	void Eyeball::Eyeball_CursorOnDraw(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		EyeballData *data = (EyeballData *)self->subClassData;
		if (data)
		{
			SDL_RenderCopyF(renderer, resource->Resource_GetEyeTexture(), data->eyeSrcRect, data->eyeDestRect);//�����۾�
			SDL_RenderCopyF(renderer, resource->Resource_GetEyeTexture(), data->eyeballSrcRect, data->eyeballDestRect);//��������
		}
	}

	/*
	* OnMouseMove�ص�������������λ��
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