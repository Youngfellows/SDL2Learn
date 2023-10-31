#ifndef _DUNGEON_BACKGROUND_H_
#define _DUNGEON_BACKGROUND_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	typedef struct BackgroundData
	{
		SDL_FRect *dest;//显示区域
		int color;//填充颜色
		float borderSize;//边框大小
		int borderColor;//边框颜色
		SDL_bool isBorder;//是否有边框
	}BackgroundData;
}

namespace Dungeon
{
	/*
	* 游戏背景
	*/
	class Background
	{
	private:
		BackgroundData *mBackgroundData;

	public:
		Background();
		~Background();
		DisplayObject *Create(float x, float y, float w, float h, int color,
			SDL_bool isBorder, int borderColor, float borderSize);
		static void OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void OnDestoryCallback(DisplayObject *self);
	};

}
#endif // !_DUNGEON_BACKGROUND_H_

