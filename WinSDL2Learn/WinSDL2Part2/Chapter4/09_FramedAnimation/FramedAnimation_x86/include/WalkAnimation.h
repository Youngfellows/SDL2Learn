#ifndef _DUNGEON_WALKANIMATION_H_
#define _DUNGEON_WALKANIMATION_H_

#include "SDL2/SDL.h"
#include "Config.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	typedef struct WalkAnimationData
	{
		SDL_FRect *dest;//绘制区域
		int currentFrameIndex;
		uint32_t globalFramesCount;
		SDL_Rect frames[ANIMATION_FRAMES];//动画帧数
		SDL_bool walking;//是否在走
		float speed;//移动位置
		SDL_RendererFlip frameFlip;//是否反向

	}WalkAnimationData;
}

namespace Dungeon
{
	class WalkAnimation
	{
	private:
		WalkAnimationData *mWalkAnimationData;

	public:
		WalkAnimation();
		~WalkAnimation();
		DisplayObject *Create();
		WalkAnimationData *GetWalkAnimationData();
		static void OnDraw(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void OnScanCodeLeft(DisplayObject *self);
		static void OnScanCodeRight(DisplayObject *self);
		static void OnKeyUp(DisplayObject *self);
		static void OnDestroy(DisplayObject *self);

	private:
		static SDL_bool IsWalking(DisplayObject *self);
		static void GotoAndPlay(DisplayObject *self, int frameIndex);
		static void GotoAndStop(DisplayObject *self, int frameIndex);
	};

}
#endif // ! _DUNGEON_WALKANIMATION_H_
