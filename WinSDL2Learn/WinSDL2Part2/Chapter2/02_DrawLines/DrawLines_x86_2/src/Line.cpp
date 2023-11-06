#include "Line.h"


namespace Dungeon
{
	Line::Line()
	{
		//对象初始化
		mLineData = { 0,{0,0},{0,0} };
	}

	Line::~Line()
	{
	}

	DisplayObject *Line::Create(int color, SDL_FPoint start, SDL_FPoint end)
	{
		//初始化对象属性
		mLineData.color = color;
		mLineData.start.x = start.x;
		mLineData.start.y = start.y;
		mLineData.end.x = end.x;
		mLineData.end.y = end.y;

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

	void Line::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		Line *line = (Line *)self->GetSubClass();
		if (line)
		{
			line->DrawLine(renderer);
		}
	}

	void Line::OnDestoryCallback(DisplayObject *self)
	{
		Line *line = (Line *)self->GetSubClass();
		if (line)
		{
			line->Destory();
		}
	}

	void Line::DrawLine(SDL_Renderer *renderer)
	{
		//设置颜色 0xffffffff ARGB
		SDL_Color color = {
		(mLineData.color & 0x00ff0000) >> 16,//R
		(mLineData.color & 0x0000ff00) >> 8,//G
		(mLineData.color & 0x000000ff),//B
		(mLineData.color & 0xff000000) >> 24,//A
		};
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

		//绘制直线
		SDL_RenderDrawLineF(renderer,
			mLineData.start.x, mLineData.start.y,
			mLineData.end.x, mLineData.end.y);
	}

	void Line::Destory()
	{
		SDL_Log("Line::Destory()::");
	}
}