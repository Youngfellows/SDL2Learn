#ifndef _DUNGEON_EVENT_LISTENER_H_
#define _DUNGEON_EVENT_LISTENER_H_

#include "DisplayObject.h"

namespace Dungeon
{
	/*
	* 1. 注册的事件监听回调、
	* 2. 如果需要调用其他对象的函数,需要在回调中传参该对象
	*/
	class EventListener
	{
	private:

	public:
		EventListener();
		~EventListener();
		static void OnClickRect(DisplayObject *self);//点击矩形的回调
		static void OnClickCat();//点击矩形的回调
		static void OnClickGirl();//点击矩形的回调
		static void OnClickText1(DisplayObject *self);//点击文本1
		static void OnClickText2(DisplayObject *self);//点击文本2
	};

}
#endif // !_DUNGEON_EVENT_LISTENER_H_

