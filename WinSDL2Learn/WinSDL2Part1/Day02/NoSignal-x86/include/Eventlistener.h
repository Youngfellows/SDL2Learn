#ifndef _DUNGEON_EVENT_LISTENER_H_
#define _DUNGEON_EVENT_LISTENER_H_

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
		static void OnClickRect();//点击矩形的回调
	};

}
#endif // !_DUNGEON_EVENT_LISTENER_H_

