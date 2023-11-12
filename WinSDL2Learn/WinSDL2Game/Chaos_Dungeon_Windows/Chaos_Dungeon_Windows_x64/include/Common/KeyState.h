#ifndef _KEYSTATE_H_
#define _KEYSTATE_H_

enum KeyState
{
	PRESSED,    /** 在这一帧中才按下*/
	PRESSING,   /** 已经按下超过一帧了*/
	RELEASED,   /** 在这一帧中才松开*/
	RELEASING   /** 已经松开超过一帧了*/
};

#endif // !_KEYSTATE_H_

