#include "Point.h"
#include <cstdlib>
#include <ctime>

namespace Dungeon
{
	Point::Point(Resource *resource,Uint32 color, SDL_FRect border)
	{
		//srand(time(0));//一定不能设置随机数种子,否则可能只有一个图形
		this->mPointData = (PointData *)malloc(sizeof(PointData));
		if (mPointData)
		{
			mPointData->color = color;
			mPointData->border = { border.x,border.y,border.w,border.h };
			mPointData->x = border.x + border.w / 2;
			mPointData->y = border.y + border.h / 2;
			mPointData->speedX = (float)(rand() % 10000) / 10000 - 0.5f; // -0.5 ~ 0.5
			mPointData->speedY = (float)(rand() % 10000) / 10000 - 0.5f;
			mPointData->angel = rand() % 360;
			int index = rand() % 2;
			SDL_Texture *photo = resource->GetGirlTexture();
			if (index == 1)
			{
				photo = resource->GetCatTexture();
			}
			mPointData->photo = photo;
			SDL_Log("Point::Point():: border:%p", &mPointData->border);
			SDL_Log("Point::Point():: x:%f,y:%f,color:%d", mPointData->x, mPointData->y, mPointData->color);
			SDL_Log("Point::Point():: speedX:%f,speedY:%f", mPointData->speedX, mPointData->speedY);
		}
		else
		{
			SDL_Log("Point::Point():: Create mPointData error");
		}
	}

	void Point::Draw(Resource *resource, SDL_Renderer *renderer)
	{
		//SDL_Log("Point::Draw():: 1,x:%f,y:%f", mPointData->x, mPointData->y);
		mPointData->x += mPointData->speedX;
		mPointData->y += mPointData->speedY;
		mPointData->angel += 0.5;
		if (mPointData->x > mPointData->border.w + mPointData->border.x - WIDTH_HEIGHT)
		{
			mPointData->speedX = -abs(mPointData->speedX);//改变x方向
			//SDL_Log("Point::Draw():: 22222,x:%f,y:%f", mPointData->x, mPointData->y);
		}
		if (mPointData->x < mPointData->border.x)
		{
			mPointData->speedX = abs(mPointData->speedX);//改变x方向
			//SDL_Log("Point::Draw():: 33333,x:%f,y:%f", mPointData->x, mPointData->y);
		}
		if (mPointData->y > mPointData->border.h + mPointData->border.y - WIDTH_HEIGHT)
		{
			mPointData->speedY = -abs(mPointData->speedY);//改变y方向
			//SDL_Log("Point::Draw():: 44444,x:%f,y:%f", mPointData->x, mPointData->y);
		}
		if (mPointData->y < mPointData->border.y)
		{
			mPointData->speedY = abs(mPointData->speedY);//改变y方向
			//SDL_Log("Point::Draw():: 55555,x:%f,y:%f", mPointData->x, mPointData->y);
		}
		//0xffffffff ARGB
		SDL_Color color = {
		(mPointData->color & 0x00FF0000) >> 16,//R
		(mPointData->color & 0x0000FF00) >> 8,//G
		(mPointData->color & 0x000000FF) >> 0,//B
		(mPointData->color & 0xFF000000) >> 24,//A
		};
		//SDL_Color color = { 255,0,0,255 };
	/*	SDL_Log("Point::Draw():: 2,x:%f,y:%f,(%d,%d,%d,%d)", mPointData->x, mPointData->y,
			color.r, color.g, color.b, color.a);*/
		//SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		//SDL_RenderDrawPointF(renderer, mPointData->x, mPointData->y);//绘制点

		SDL_FRect rect = { mPointData->x, mPointData->y ,WIDTH_HEIGHT,WIDTH_HEIGHT };
		//SDL_RenderFillRectF(renderer, &rect);//绘制矩形
		//SDL_RenderCopyF(renderer, resource->GetGirlTexture(), nullptr, &rect);
		SDL_RenderCopyExF(renderer, mPointData->photo, nullptr, &rect, mPointData->angel, nullptr, SDL_FLIP_NONE);
	}

	Point::~Point()
	{
		SDL_Log("Point::~Point():: pppppppppppppppppppppppp");
		if (mPointData)
		{
			free(mPointData);
			mPointData = nullptr;
		}
	}
}