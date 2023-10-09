#include "Cursor.h"
#include <iostream>


namespace Game
{
	using namespace std;

	//初始化静态成员属性
	int Cursor::radius = 88;
	FRect *Cursor::srcRect = new FRect();

	Cursor::Cursor()
	{
		srcRect->x = 11;
		srcRect->y = 22;
		srcRect->w = 33;
		srcRect->h = 44;
	}

	Cursor::~Cursor()
	{

	}

	DisplayObject *Cursor::Cursor_Create(float x, float y, float w, float h)
	{
		DisplayObject *displayObject = new DisplayObject();
		displayObject->DisplayObject_Create(x, y, w, h,
			&Cursor_OnDraw, &Cursor_OnMouseMove);
		return displayObject;
	}

	void Cursor::Cursor_Destory(DisplayObject *displayObject)
	{
		displayObject->DisplayObject_Destory();
	}

	/*
	* 回调函数
	*/
	void Cursor::Cursor_OnDraw(DisplayObject *displayObject, struct Renderer *renderer)
	{
		cout << "Cursor::Cursor_OnDraw():: call ..." << endl;
		FRect *dest = displayObject->dest;
		float x = dest->x;
		float y = dest->y;
		float w = dest->w;
		float h = dest->h;

		cout << "Cursor::Cursor_OnDraw():: dest(x:" << x << ",y:" << y << ",w:" << w << ",h:" << h << ")" << endl;

		int color = renderer->color;
		cout << "Cursor::Cursor_OnDraw():: renderer color:" << color << endl << endl;
	}

	/*
	* 回调函数
	*/
	void Cursor::Cursor_OnMouseMove(DisplayObject *displayObject, struct Event *event)
	{
		cout << "Cursor::Cursor_OnMouseMove() call ..." << endl;
		FRect *dest = displayObject->dest;
		float x = dest->x;
		float y = dest->y;
		float w = dest->w;
		float h = dest->h;

		cout << "Cursor::Cursor_OnMouseMove():: dest(x:" << x << ",y:" << y << ",w:" << w << ",h:" << h << ")" << endl;

		Motion motion = event->motion;
		float motionX = motion.x;
		float motionY = motion.y;
		cout << "Cursor::Cursor_OnMouseMove():: motion(x:" << motionX << ",y:" << motionY << ")" << endl;

		cout << "radius:" << radius << endl;
		cout << "radius:" << Cursor::radius << endl;

		float pX = srcRect->x;
		float pY = srcRect->y;
		float pW = srcRect->w;
		float pH = srcRect->h;
		cout << "Cursor::Cursor_OnMouseMove():: srcRect(x:" << pX << ",y:" << pY << ",w:" << pW << ",h:" << pH << ")" << endl << endl;
	}
}