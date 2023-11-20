#ifndef _DUNGEON_SETTING_H_
#define _DUNGEON_SETTING_H_

#include <string>

namespace Dungeon
{
#define	WINDOW_TITLE "Dungeon"

	namespace Window
	{
		const int WINDOW_WIDTH = 600;//窗口宽
		const int WINDOW_HEIGHT = 600;//窗口高
	}

	namespace Resources
	{
		const std::string PNG_CHARA07_FILE_NAME = "./resources/sprites/chrA07.png";
	}

	//角色
	namespace Role
	{
		const std::string PLAYER = "player";//玩家
	}
}

#endif // ! _DUNGEON_SETTING_H_
