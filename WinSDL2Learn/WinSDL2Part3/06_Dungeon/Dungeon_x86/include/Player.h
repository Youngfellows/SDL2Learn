#ifndef __Dungeon_Player__
#define __Dungeon_Player__

#include <GameObject.h>

namespace Dungeon
{
	/*
	* 游戏对象: 玩家
	*/
	class Player : public GameObject
	{
	public:
		//! 构造函数
		Player(class Game *game);
	};
}

#endif	// __Dungeon_Player__