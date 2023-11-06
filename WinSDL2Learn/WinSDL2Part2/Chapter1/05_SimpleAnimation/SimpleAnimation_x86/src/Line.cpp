#include "Line.h"


namespace Dungeon
{
	Line::Line() :mLineData(nullptr)
	{
		//动态申请内存
		this->mLineData = (LineData *)malloc(sizeof(LineData));
		if (mLineData)
		{
			mLineData->color = 0xffffffff;//初始颜色是白色
			mLineData->start.x = 0;
			mLineData->start.y = 0;
			mLineData->end.x = 0;
			mLineData->end.y = 0;
			mLineData->winWidth = 0;
			mLineData->winHeight = 0;
		}
		else
		{
			SDL_Log("Can not create mLineData");
		}
	}

	Line::~Line()
	{
		Destory();
	}

	/*
	* 两点之间直线方程: y=k*x+b;
	* 直线的斜率:
	* k=&x/&y=(y2-y1)/(x2-x1)
	*	代入A(100,50)或者B(200,80)得
	* k=(80-50)/(200-100)
	*  =3/10
	*
	* 直线在y轴的截距:
	* b=y-k*x,代入A(100,50)或者B(200,80)得
	* b=50-(3/10)*100
	*  =20
	*
	* 因此直线方程: y = k*x+b = (3/10)*x+20;
	*
	* 宽高为w*h的图片直线上两点之间任意点与像素索引的对应关系:
	* A(100,50)->50*w+100
	* B(200,80)->80*w+200
	* 因此在 100<=x<=200直线上求出像素数据索引即可,
	* C(x,y)点像素索引为: y*w+x=(kx+b)*w+x=((3/10)*x+20)*w+x;
	*/
	DisplayObject *Line::Create(int color, int x1, int y1, int x2, int y2, int w, int h)
	{
		if (!mLineData)
		{
			SDL_Log("Line::Create():: mLineData is null");
			return nullptr;
		}
		mLineData->color = color;
		mLineData->start.x = x1;
		mLineData->start.y = y1;
		mLineData->end.x = x2;
		mLineData->end.y = y2;
		mLineData->winWidth = w;
		mLineData->winHeight = h;
		mLineData->k = (float)(y2 - y1) / (float)(x2 - x1);//求斜率
		mLineData->b = y1 - mLineData->k * x1;//代入(x1,y1)求截距
		SDL_Log("Line::Create():: y=%f*x+%f", mLineData->k, mLineData->b);

		//把显示对象委托给DisplayObject
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//设置显示对象
		OnCallbackData *callback = displayObject->GetOnCallback();
		if (callback)
		{
			callback->OnDraw = &OnDrawCallback;//设置绘制回调
			callback->OnDestory = &OnDestoryCallback;//设置释放内存回调
		}
		return displayObject;
	}

	void Line::OnDrawCallback(DisplayObject *self, SDL_Surface *winSurface, Resource *resource)
	{
		Line *line = (Line *)self->GetSubClass();
		if (line)
		{
			line->Draw(winSurface);
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

	void Line::Draw(SDL_Surface *winSurface)
	{
		if (!mLineData)
		{
			return;
		}
		//设置点A(x1,y1)到点B(x,y2)直线上像素数据
		//index=y*w+x=(kx+b)*w+x=((3/10)*x+20)*w+x;
		for (int x = mLineData->start.x; x <= mLineData->end.x; x++)
		{
			long index = (mLineData->k * x + mLineData->b) * mLineData->winWidth + x;
			//long index = mLineData->k * x + mLineData->b;
			//SDL_Log("Line::Draw():: index:%ld", index);
			((Uint32 *)(winSurface->pixels))[index] = mLineData->color;
		}
	}


	void Line::Destory()
	{
		if (mLineData)
		{
			free(mLineData);
			mLineData = nullptr;
			SDL_Log(" Line::Destory()::");
		}
	}
}