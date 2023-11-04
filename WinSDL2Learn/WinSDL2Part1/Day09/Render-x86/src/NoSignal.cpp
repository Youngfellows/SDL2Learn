#include "NoSignal.h"

namespace Dungeon
{
	NoSignal::NoSignal() :mScreenData(nullptr)
	{
		//设置随机数种子
		srand(time(0));
		//动态申请内存
		this->mScreenData = (ScreenData *)malloc(sizeof(ScreenData));
		if (mScreenData)
		{
			mScreenData->width = 0;
			mScreenData->height = 0;
		}
		else
		{
			SDL_Log("NoSignal::NoSignal():: Create mScreenData error");
		}

	}

	NoSignal::~NoSignal()
	{
		SDL_Log("NoSignal::~NoSignal()::");
		Destory();
	}

	DisplayObject *NoSignal::Create(int w, int h)
	{
		if (!mScreenData)
		{
			return nullptr;
		}
		mScreenData->width = w;
		mScreenData->height = h;

		//创建要显示对象的代理
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//设置要显示对象
		OnCallbackData *onCallback = displayObject->GetOnCallback();//设置回调
		if (onCallback)
		{
			onCallback->OnDraw = &OnDrawCallback;
			onCallback->OnDestory = &OnDestoryCallback;
		}
		return displayObject;
	}

	void NoSignal::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		NoSignal *noSignal = (NoSignal *)self->GetSubClass();//获取要显示对象
		if (noSignal)
		{
			noSignal->Draw(renderer);
		}
	}

	void NoSignal::OnDestoryCallback(DisplayObject *self)
	{
		NoSignal *noSignal = (NoSignal *)self->GetSubClass();//获取要显示对象
		if (noSignal)
		{
			noSignal->Destory();
		}
	}

	void NoSignal::Draw(SDL_Renderer *renderer)
	{
		DrawScreen(renderer);
	}

	/*
	* 绘制雪花屏幕
	*/
	void NoSignal::DrawScreen(SDL_Renderer *renderer)
	{
		if (!mScreenData)
		{
			SDL_Log(" NoSignal::DrawScreen():: mScreenData is null");
			return;
		}
		for (int x = 0; x < mScreenData->width; x++)
		{
			for (int y = 0; y < mScreenData->height; y++)
			{
				//随机颜色
				SDL_Color color = {
				rand() % 255,//r
				rand() % 255,//g
				rand() % 255,//b
				255//a
				};
				SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);//设置颜色
				SDL_RenderDrawPoint(renderer, x, y);//绘制点
			}
		}
	}

	void NoSignal::Destory()
	{
		SDL_Log("NoSignal::Destory()::");
		if (mScreenData)
		{
			free(mScreenData);
			mScreenData = nullptr;
		}
	}
}
