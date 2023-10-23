#ifndef _DUNGEON_TEXT_H_
#define _DUNGEON_TEXT_H_

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "DisplayObject.h"
#include "Resource.h"

using namespace std;

namespace Dungeon
{
	//点击事件回调函数列表
	typedef struct TextClickData
	{
		int size;
		OnTextClickCallback *OnTextClicks;//文本点击事件回调的函数指针
	}TextClickData;

	typedef struct TextData
	{
		TTF_Font *font;//字体
		char *file;//字体文件
		char *value;//文本
		int ptsize;//字体大小
		uint32_t color;//字体颜色
		SDL_Surface *textSurface;
		SDL_FRect *dest;//文本显示区域
		TextClickData *textClickData;//回调函数数据
	}TextData;
}

namespace Dungeon
{
	class Text
	{
	private:
		TextData *mTextData;

	public:
		Text();
		~Text();
		DisplayObject *Create(const char *file, const char *value,
			int ptsize, uint32_t color, float x, float y,
			int size, initializer_list<OnTextClickCallback> ls);
		void TextSet(const char *value);
		TextData *GetTextData();
		static void OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void OnMouseDownCallback(DisplayObject *self, SDL_Event *event);
		static void OnDestoryCallback(DisplayObject *self);
	};
}

#endif // !_DUNGEON_TEXT_H_

