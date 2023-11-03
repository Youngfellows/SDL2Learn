#include "Bubble.h"
#include <cstdlib>
#include <ctime>
#include "Config.h"

namespace Dungeon
{
	Bubble::Bubble(Resource *resource, Uint32 color, SDL_FRect border)
	{
		//srand(time(0));//一定不能设置随机数种子,否则可能只有一个图形
		this->mBubbleData = (BubbleData *)malloc(sizeof(BubbleData));
		if (mBubbleData)
		{
			mBubbleData->color = color;
			mBubbleData->border = { border.x,border.y,border.w,border.h };
			mBubbleData->x = border.x + border.w / 2;
			mBubbleData->y = border.y + border.h / 2;
			mBubbleData->speedX = (float)(rand() % 10000) / 10000 - 0.5f; // -0.5 ~ 0.5
			mBubbleData->speedY = (float)(rand() % 10000) / 10000 - 0.5f;
			mBubbleData->dest.x = mBubbleData->x;
			mBubbleData->dest.y = mBubbleData->y;
			mBubbleData->dest.w = BUBBLE_WIDTH;
			mBubbleData->dest.h = BUBBLE_HEIGHT;
			mBubbleData->angel = rand() % 360;
			int index = rand() % 2;
			SDL_Texture *photo = resource->GetGirlTexture();
			if (index == 1)
			{
				photo = resource->GetCatTexture();
			}
			mBubbleData->photo = photo;
			mBubbleData->move = SDL_FALSE;
			SDL_Log("Bubble::Bubble():: border:%p", &mBubbleData->border);
			SDL_Log("Bubble::Bubble():: x:%f,y:%f,color:%d", mBubbleData->x, mBubbleData->y, mBubbleData->color);
			SDL_Log("Bubble::Bubble():: speedX:%f,speedY:%f", mBubbleData->speedX, mBubbleData->speedY);
		}
		else
		{
			SDL_Log("Bubble::Bubble():: Create mBubbleData error");
		}
	}

	void Bubble::Draw(Resource *resource, SDL_Renderer *renderer)
	{
		if (!mBubbleData)
		{
			return;
		}
		/*if (!mBubbleData->move)
		{
			mBubbleData->x += mBubbleData->speedX;
			mBubbleData->y += mBubbleData->speedY;
		}*/
		mBubbleData->x += mBubbleData->speedX;
		mBubbleData->y += mBubbleData->speedY;

		mBubbleData->angel += 0.5;
		if (mBubbleData->x > mBubbleData->border.w + mBubbleData->border.x - WIDTH_HEIGHT)
		{
			mBubbleData->speedX = -abs(mBubbleData->speedX);//改变x方向
			mBubbleData->x = mBubbleData->border.w + mBubbleData->border.x - WIDTH_HEIGHT;
		}
		if (mBubbleData->x < mBubbleData->border.x)
		{
			mBubbleData->speedX = abs(mBubbleData->speedX);//改变x方向
			mBubbleData->x = mBubbleData->border.x;
		}
		if (mBubbleData->y > mBubbleData->border.h + mBubbleData->border.y - WIDTH_HEIGHT)
		{
			mBubbleData->speedY = -abs(mBubbleData->speedY);//改变y方向
			mBubbleData->y = mBubbleData->border.h + mBubbleData->border.y - WIDTH_HEIGHT;
		}
		if (mBubbleData->y < mBubbleData->border.y)
		{
			mBubbleData->speedY = abs(mBubbleData->speedY);//改变y方向
			mBubbleData->y = mBubbleData->border.y;
		}
		//0xffffffff ARGB
		SDL_Color color = {
		(mBubbleData->color & 0x00FF0000) >> 16,//R
		(mBubbleData->color & 0x0000FF00) >> 8,//G
		(mBubbleData->color & 0x000000FF) >> 0,//B
		(mBubbleData->color & 0xFF000000) >> 24,//A
		};
		//SDL_Color color = { 255,0,0,255 };
		/*	SDL_Log("Point::Draw():: 2,x:%f,y:%f,(%d,%d,%d,%d)", mPointData->x, mPointData->y,
		color.r, color.g, color.b, color.a);*/
		//SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		//SDL_RenderDrawPointF(renderer, mPointData->x, mPointData->y);//绘制点


		//SDL_FRect rect = { mBubbleData->x, mBubbleData->y ,WIDTH_HEIGHT,WIDTH_HEIGHT };
		//SDL_RenderFillRectF(renderer, &rect);//绘制矩形
		//SDL_RenderCopyF(renderer, resource->GetGirlTexture(), nullptr, &rect);
		//SDL_RenderCopyExF(renderer, mBubbleData->photo, nullptr, &rect, mBubbleData->angel, nullptr, SDL_FLIP_NONE);

		mBubbleData->dest.x = mBubbleData->x;
		mBubbleData->dest.y = mBubbleData->y;
		SDL_RenderCopyExF(renderer, mBubbleData->photo, nullptr, &mBubbleData->dest, mBubbleData->angel, nullptr, SDL_FLIP_NONE);
	}

	void Bubble::SetMouseMove(SDL_bool move)
	{
		if (!mBubbleData)
		{
			return;
		}
		mBubbleData->move = move;
	}

	void Bubble::MouseMove(SDL_FPoint point)
	{
		if (!mBubbleData)
		{
			return;
		}
		mBubbleData->x += point.x;
		mBubbleData->y += point.y;

		//移动鼠标时更新各个泡泡的位置
		mBubbleData->dest.x = mBubbleData->x;
		mBubbleData->dest.y = mBubbleData->y;

		//更新边界,限定边界
		mBubbleData->border.x += point.x;
		mBubbleData->border.y += point.y;
		if (mBubbleData->border.x < 0)
		{
			mBubbleData->border.x = 0;
		}
		if (mBubbleData->border.x > WINDOW_WIDTH - mBubbleData->border.w)
		{
			mBubbleData->border.x = WINDOW_WIDTH - mBubbleData->border.w;
		}

		if (mBubbleData->border.y < 0)
		{
			mBubbleData->border.y = 0;
		}
		if (mBubbleData->border.y > WINDOW_HEIGHT - mBubbleData->border.h)
		{
			mBubbleData->border.y = WINDOW_HEIGHT - mBubbleData->border.h;
		}
	}

	Bubble::~Bubble()
	{
		SDL_Log("Bubble::~Bubble():: pppppppppppppppppppppppp");
		if (mBubbleData)
		{
			free(mBubbleData);
			mBubbleData = nullptr;
		}
	}
}