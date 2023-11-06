#include "BrokenLine.h"

namespace Dungeon
{
	BrokenLine::BrokenLine()
	{
		//对象初始化
		mBrokenLineData.color = 0xffffffff;
		mBrokenLineData.size = 0;
		mBrokenLineData.points = nullptr;
	}

	BrokenLine::~BrokenLine()
	{
		Destory();
	}

	DisplayObject *BrokenLine::Create(int color, int size, std::initializer_list<SDL_FPoint> pointList)
	{
		//初始化对象属性,申请内存
		mBrokenLineData.color = color;
		mBrokenLineData.size = size;
		mBrokenLineData.points = (SDL_FPoint *)malloc(sizeof(SDL_FPoint) * size);
		if (!mBrokenLineData.points)
		{
			SDL_Log("Can not create mBrokenLineData.points");
			return nullptr;
		}
		//使用可变参数为列表赋值
		int i = 0;
		std::initializer_list<SDL_FPoint>::iterator iter;//使用迭代器
		for (iter = pointList.begin(); iter != pointList.end(); iter++)
		{
			SDL_FPoint point = *iter;
			*(mBrokenLineData.points + i) = point;//为数组赋值,使用指针形式
			SDL_FPoint point1 = *(mBrokenLineData.points + i);
			//mBrokenLineData.points[i] = point;//为数组赋值,使用索引形式

			//SDL_Log("BrokenLine::Create():: i:%d,FPoint(%f,%f)", i, point1.x, point1.y);
			i++;
		}

		//设置绘制委托对象
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//设置绘制对象
		OnCallbackData *callback = displayObject->GetOnCallback();//设置回调
		if (callback)
		{
			callback->OnDraw = &OnDrawCallback;
			callback->OnDestory = &OnDestoryCallback;
		}
		return displayObject;
	}

	void BrokenLine::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		BrokenLine *brokenLine = (BrokenLine *)self->GetSubClass();
		if (brokenLine)
		{
			brokenLine->DrawBrokenLine(renderer);
		}
	}

	void BrokenLine::OnDestoryCallback(DisplayObject *self)
	{
		BrokenLine *brokenLine = (BrokenLine *)self->GetSubClass();
		if (brokenLine)
		{
			brokenLine->Destory();
		}
	}

	void BrokenLine::DrawBrokenLine(SDL_Renderer *renderer)
	{
		//设置颜色 0xffffffff ARGB
		SDL_Color color = {
		(mBrokenLineData.color & 0x00ff0000) >> 16,//R
		(mBrokenLineData.color & 0x0000ff00) >> 8,//G
		(mBrokenLineData.color & 0x000000ff),//B
		(mBrokenLineData.color & 0xff000000) >> 24,//A
		};
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

		//绘制多点直线,也可以是折线
		//SDL_FPoint start = *(mBrokenLineData.points + 0);
		//SDL_FPoint end = *(mBrokenLineData.points + 1);
		//SDL_Log("BrokenLine::DrawBrokenLine():: start(%f,%f),end(%f,%f)", start.x, start.y, end.x, end.y);
		//SDL_RenderDrawLineF(renderer, start.x, start.y, end.x, end.y);

		//SDL_Log("BrokenLine::DrawBrokenLine():: size:%d", mBrokenLineData.size);
		////如果使用指针只显示一个点
		//SDL_RenderDrawLines(renderer, mBrokenLineData.points, mBrokenLineData.size);
		SDL_RenderDrawLinesF(renderer, mBrokenLineData.points, mBrokenLineData.size);
	}

	void BrokenLine::Destory()
	{
		SDL_Log("BrokenLine::Destory()::");
		if (mBrokenLineData.points)
		{
			free(mBrokenLineData.points);
			mBrokenLineData.points = nullptr;
		}
	}
}