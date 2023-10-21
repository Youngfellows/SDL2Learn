#ifndef _DUNGEON_MINE_H_
#define _DUNGEON_MINE_H_

#include <cstdlib>
#include <ctime>
#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	/*
	* 地雷数据
	*/
	typedef struct MineData
	{
		SDL_FRect *dest;//显示位置
		SDL_bool visible;//是否可见
	};

	/*
	* 雷场数据
	*/
	typedef struct MinefieldData
	{
		SDL_FRect *boundry;//雷场边界
		MineData **mines;//要显示的雷个数
		int amount;//扫掉的雷个数
		int size;//累总数
	}MinefieldData;
}

namespace Dungeon
{
	class Mine
	{
	private:
		MinefieldData *mMinefieldData;

	public:
		Mine();
		~Mine();
		DisplayObject *Create(float x, float y, float w, float h, int size,
			float mineWidth, float mineHeight);
		static void OnDrawCallback(DisplayObject *self, Resource *resource,
			SDL_Renderer *renderer);//绘制回调
		static void OnDestoryCallback(DisplayObject *self);
		static void OnPlayerMoveCallback(void *position);//玩家移动回调

	private:
		void CreateMins();//创建地雷
	};

}

#endif // !_DUNGEON_MINE_H_

