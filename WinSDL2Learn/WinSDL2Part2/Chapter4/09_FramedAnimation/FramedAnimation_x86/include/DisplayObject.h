#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"
#include "Resource.h"

namespace Dungeon
{
	class DisplayObject
	{
	public:
		void *subClass;//显示的对象,相当于泛型

	private:
		typedef void (*OnDrawCallback)(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		typedef void (*OnDestroyCallback)(DisplayObject *self);
		typedef void (*OnScanCodeLeftCallback)(DisplayObject *self);//点击方向左键回调
		typedef void (*OnScanCodeRightCallback)(DisplayObject *self);//点击方向右键回调
		typedef void (*OnKeyUpCallback)(DisplayObject *self);//按键抬起回调
		OnDrawCallback OnDraw;
		OnDestroyCallback OnDestroy;
		OnScanCodeLeftCallback OnScanCodeLeft;
		OnScanCodeRightCallback OnScanCodeRight;
		OnKeyUpCallback OnKeyUp;

	public:
		DisplayObject();
		~DisplayObject();
		SDL_bool Create(OnDrawCallback onDrawCallback,
			OnScanCodeLeftCallback OnScanCodeLeft,
			OnScanCodeRightCallback onScanCodeRightCallback,
			OnKeyUpCallback onKeyUpCallback,
			OnDestroyCallback onDestroyCallback);
		void Draw(Resource *resource, SDL_Renderer *renderer);
		void Destroy();
		void ScanCodeLeft();
		void ScanCodeRight();
		void KeyUp();
	};
}
#endif // !_DUNGEON_DISPLAYOBJECT_H_

