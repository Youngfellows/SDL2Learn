#ifndef _DUNGEON_STARLIT_SKY_H_
#define _DUNGEON_STARLIT_SKY_H_

#include "SDL2/SDL.h"
#include <vector>
#include "Bubble.h"
#include "DisplayObject.h"
#include "Config.h"

namespace Dungeon
{
	typedef struct StarlitSkyData
	{
		SDL_FRect *dest;//绘制区域
		Uint32 color;//绘制点颜色
		Uint32 bgColor;//背景颜色
		Uint32 size;
		std::vector<Bubble *> *bubbles;//绘制点列表
		SDL_bool move;//是否可移动
		SDL_FPoint point;//位置
		SDL_Texture *texture;
		SDL_bool anim;
		float angle;
	}StarlitSkyData;
}

namespace Dungeon
{
	class StarlitSky
	{
	private:
		StarlitSkyData *mStarlitData;

	public:
		StarlitSky();
		~StarlitSky();
		DisplayObject *Create(Resource *resource, Uint32 size, Uint32 color, Uint32 bgColor, float x, float y, float w, float h);
		static void OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void OnMouseDownCallback(DisplayObject *self, SDL_Event *event);
		static void OnMouseUpCallback(DisplayObject *self, SDL_Event *event);
		static void OnMouseMoveCallback(DisplayObject *self, SDL_Event *event);
		static void OnDestoryCallbac(DisplayObject *self);
		void Rotate();

	private:
		void CreatePoints(Resource *resource);
		void DrawPoints(Resource *resource, SDL_Renderer *renderer);
		void DrawBackground(SDL_Renderer *renderer);
		void Draw(Resource *resource, SDL_Renderer *renderer);
		void MouseButtonDown(SDL_Event *event);
		void MouseButtonUp(SDL_Event *event);
		void MouseButtonMove(SDL_Event *event);
		void UpdateBubblePosition(SDL_FPoint point);
		void Destory();
	};
}
#endif // !_DUNGEON_STARLIT_SKY_H_

