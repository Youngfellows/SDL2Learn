#ifndef _DUNGEON_GROUND_H_
#define _DUNGEON_GROUND_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	//场地
	typedef struct GroundData
	{
		float x;//场地开始绘制的X位置
		float y;//场地开始绘制的Y位置
		float width;//场地宽
		float height;//场地高
		int xSize;//x方向绘制数量
		int ySize;//y方向绘制数量
		SDL_Texture *groundTexture;//要绘制的资源
	}GroundData;
}

namespace Dungeon
{
	class Ground
	{
	private:
		GroundData *mGroundData;

	public:
		Ground();
		~Ground();
		DisplayObject *Create(float x, float y, float w, float h, int xSize, int ySize, SDL_Texture *texture);
		static void OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void OnDestoryCallback(DisplayObject *self);

	private:
		void Draw(SDL_Renderer *renderer);
		void Destory();
	};
}
#endif // !_DUNGEON_GROUND_H_

