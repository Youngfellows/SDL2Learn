#ifndef _DUNGEON_TEXT_H_
#define _DUNGEON_TEXT_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	typedef struct TextData
	{
		TTF_Font *font;//字体
		char *file;//字体文件
		char *value;//文本
		int ptsize;//字体大小
		uint32_t color;//字体颜色
		SDL_Surface *textSurface;
		SDL_FRect *dest;//文本显示区域
		OnTextClickCallback OnTextClick;//文本点击事件回调的函数指针
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
			int ptsize, uint32_t color, float x, float y, OnTextClickCallback onTextClickCllback);
		void TextSet(const char *value);
		TextData *GetTextData();
		static void OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void OnMouseDownCallback(DisplayObject *self, SDL_Event *event);
		static void OnDestoryCallback(DisplayObject *self);
	};
}

#endif // !_DUNGEON_TEXT_H_

