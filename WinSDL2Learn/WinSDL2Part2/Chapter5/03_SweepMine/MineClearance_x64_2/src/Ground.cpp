#include "Ground.h"

namespace Dungeon
{
	Ground::Ground() :mGroundData(nullptr)
	{
		//动态申请内存
		this->mGroundData = (GroundData *)malloc(sizeof(GroundData));
		if (mGroundData)
		{
			mGroundData->x = 0;
			mGroundData->y = 0;
			mGroundData->width = 0;
			mGroundData->height = 0;
			mGroundData->xSize = 0;
			mGroundData->ySize = 0;
			mGroundData->groundTexture = nullptr;
		}
		else
		{
			SDL_Log("Can not create mGroundData");
		}
	}

	Ground::~Ground()
	{
		Destory();
	}

	DisplayObject *Ground::Create(float x, float y, float w, float h, int xSize, int ySize, SDL_Texture *texture)
	{
		if (!mGroundData)
		{
			SDL_Log("Ground::Create():: mGroundData is null");
			return nullptr;
		}
		mGroundData->x = x;
		mGroundData->y = y;
		mGroundData->width = w;
		mGroundData->height = h;
		mGroundData->xSize = xSize;
		mGroundData->ySize = ySize;
		mGroundData->groundTexture = texture;


		//设置显示对象委托
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//设置显示对象
		OnCallbackData *callback = displayObject->GetOnCallback();//设置回调函数
		if (callback)
		{
			callback->OnDraw = &OnDrawCallback;
			callback->OnDestory = &OnDestoryCallback;
		}
		return displayObject;
	}

	void Ground::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		Ground *ground = (Ground *)self->GetSubClass();
		if (ground)
		{
			ground->Draw(renderer);
		}
	}

	void Ground::OnDestoryCallback(DisplayObject *self)
	{
		Ground *ground = (Ground *)self->GetSubClass();
		if (ground)
		{
			ground->Destory();
		}
	}

	void Ground::Draw(SDL_Renderer *renderer)
	{
		if (!mGroundData)
		{
			SDL_Log("Ground::Draw():: mGroundData is null");
			return;
		}

		//绘制砖块
		int xSize = mGroundData->xSize;
		int ySize = mGroundData->ySize;
		float tileX = mGroundData->width / xSize;//每1个砖块的宽
		float tileY = mGroundData->height / ySize;//每1个砖块的高
		/*SDL_Log("Ground::Draw():: xSize:%d,ySize:%d", xSize, ySize);
		SDL_Log("Ground::Draw():: tileX:%f,tileX:%f", tileX, tileY);*/


		for (int j = 0; j < ySize; j++)
		{
			for (int i = 0; i < xSize; i++)
			{
				//计算每个砖块的绘制位置
				float x = mGroundData->x + i * tileX;//每一个砖块的起始位置x坐标
				float y = mGroundData->y + j * tileY;//每一个砖块的起始位置y坐标
				SDL_FRect destRect = { x,y,tileX ,tileY };
				/*SDL_Log("Ground::Draw():: i:%d,j:%d,rect(%f,%f,%f,%f)",
					i, j, destRect.x, destRect.y, destRect.w, destRect.h);*/
				SDL_RenderCopyF(renderer, mGroundData->groundTexture, nullptr, &destRect);
			}
		}
	}

	void Ground::Destory()
	{
		if (mGroundData)
		{
			free(mGroundData);
			mGroundData = nullptr;
		}
	}
}