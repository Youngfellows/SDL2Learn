#include "Background.h"


namespace Dungeon
{
	Background::Background() :mBackgroundData(nullptr)
	{

	}

	Background::~Background()
	{

	}

	DisplayObject *Background::Create(float x, float y, float w, float h, int color,
		SDL_bool isBorder, int borderColor, float borderSize)
	{
		//动态申请内存
		this->mBackgroundData = (BackgroundData *)malloc(sizeof(BackgroundData));
		if (!mBackgroundData)
		{
			return nullptr;
		}
		mBackgroundData->dest = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mBackgroundData->dest)
		{
			return nullptr;
		}
		mBackgroundData->dest->x = x;
		mBackgroundData->dest->y = y;
		mBackgroundData->dest->w = w;
		mBackgroundData->dest->h = h;
		mBackgroundData->color = color;
		mBackgroundData->isBorder = isBorder;
		mBackgroundData->borderColor = borderColor;
		mBackgroundData->borderSize = borderSize;

		//创建要显示对象
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//设置要显示对象数据
		OnCallbackData *onCallback = displayObject->GetOnCallback();//设置回调函数
		if (onCallback)
		{
			onCallback->OnDraw = &OnDrawCallback;//只需要处理绘制事件
			onCallback->OnDestory = &OnDestoryCallback;//只需要处理Destory事件
		}
		return displayObject;
	}


	void Background::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		Background *background = (Background *)self->GetSubClass();//获取回调回来的要显示数据
		if (background)
		{
			BackgroundData *data = background->mBackgroundData;//获取背景数据信息
			if (data)
			{
				//绘制边框
				if (data->isBorder)
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

					if (resource)
					{
						// 绘制背景图片
						SDL_RenderCopyF(renderer, resource->GetBackgroundTexture(), nullptr, &rect);
					}
				}
				else
				{
					if (resource)
					{
						// 绘制背景图片
						SDL_RenderCopyF(renderer, resource->GetBackgroundTexture(), nullptr, data->dest);
					}
				}	
			}
		}
	}

	void Background::OnDestoryCallback(DisplayObject *self)
	{
		Background *background = (Background *)self->GetSubClass();//获取回调回来的要显示数据
		if (background)
		{
			BackgroundData *data = background->mBackgroundData;//获取背景数据信息
			if (data)
			{
				//释放内存资源
				free(data->dest);
				free(data);
				data = nullptr;
			}
		}

	}
}