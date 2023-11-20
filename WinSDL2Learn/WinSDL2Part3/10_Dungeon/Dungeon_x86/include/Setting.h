#ifndef _DUNGEON_SETTING_H_
#define _DUNGEON_SETTING_H_

#include <string>

namespace Dungeon
{
#define	WINDOW_TITLE "Dungeon"

	namespace Window
	{
		const int WINDOW_WIDTH = 640;//窗口宽
		const int WINDOW_HEIGHT = 480;//窗口高
	}

	namespace Resources
	{
		const std::string PNG_CHARA07_FILE_NAME = "./resources/sprites/chrA07.png";
		const std::string PNG_GROUND_FILE_NAME = "./resources/sprites/ground.png";
		const std::string PNG_WALL_FILE_NAME = "./resources/sprites/wall.png";
	}

	//角色
	namespace Role
	{
		const std::string PLAYER = "player";//玩家
		const std::string GROUND = "ground";//背景
		const std::string WALL = "wall";//墙壁
	}
}

#endif // ! _DUNGEON_SETTING_H_
