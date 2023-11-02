#ifndef _DUNGEON_NO_SIGNAL_H_
#define _DUNGEON_NO_SIGNAL_H_

#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include <ctime>
#include <iostream>

namespace Dungeon
{
	typedef struct ScreenData
	{
		int width;//屏幕宽
		int height;//屏幕高
	}ScreenData;

	class NoSignal
	{
	private:
		ScreenData *mScreenData;//屏幕数据

	public:
		NoSignal();
		~NoSignal();
		DisplayObject *Create(int w, int h);
		static void OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void OnDestoryCallback(DisplayObject *self);

	private:
		void Draw(SDL_Renderer *renderer);
		void DrawScreen(SDL_Renderer *renderer);
		void Destory();
	};
}

#endif // !_DUNGEON_NO_SIGNAL_H_
