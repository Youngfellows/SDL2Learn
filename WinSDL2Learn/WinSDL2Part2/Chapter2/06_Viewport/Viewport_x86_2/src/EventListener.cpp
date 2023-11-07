#include "EventListener.h"

#include "SDL2/SDL.h"
#include "Photo.h"
#include "StarlitSky.h"

namespace Dungeon
{
	EventListener::EventListener()
	{
	}

	EventListener::~EventListener()
	{
	}

	void EventListener::OnClickRect(DisplayObject *self)
	{
		SDL_Log("EventListener::OnClickRect():: click the rectangle");
		StarlitSky *starlitSky = (StarlitSky *)self->GetSubClass();
		if (starlitSky)
		{
			starlitSky->Rotate();
		}
	}

	void EventListener::OnClickCat()
	{
		SDL_Log("EventListener::OnClickCat():: click the cat");
	}

	void EventListener::OnClickGirl()
	{
		SDL_Log("EventListener::OnClickGirl():: click the girl");
	}

	void EventListener::OnClickText1(DisplayObject *self)
	{
		SDL_Log("EventListener::OnClickText1():: click text1");
		Photo *cat = (Photo *)self->GetSubClass();
		if (cat)
		{
			//cat->Rotate();//开启旋转动画
			cat->Scale();//开启缩放动画
		}
	}

	void EventListener::OnClickText2(DisplayObject *self)
	{
		SDL_Log("EventListener::OnClickText2():: click text2");
		Photo *girl = (Photo *)self->GetSubClass();
		if (girl)
		{
			girl->Rotate();//开启旋转动画
			girl->Scale();//开启缩放动画
		}
	}

	void EventListener::OnClickText3(DisplayObject *self)
	{
		SDL_Log("EventListener::OnClickText2():: click text2");
		Photo *girl = (Photo *)self->GetSubClass();
		if (girl)
		{
			girl->SetDelay(30 * 1000);//设置动画执行时间5秒
			girl->Rotate();//开启旋转动画
			girl->Scale();//开启缩放动画
		}
	}
}