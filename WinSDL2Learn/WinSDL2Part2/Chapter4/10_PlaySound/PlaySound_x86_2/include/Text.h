#ifndef  _DUNGEON_TEXT_H_
#define  _DUNGEON_TEXT_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "DisplayObject.h"

namespace Dungeon
{
	//文本数据实体
	typedef struct TextData
	{
		TTF_Font *font;//字体
		char *fontFile;//字体文件
		char *value;//文本
		int ptsize;//字体大小
		uint32_t color;//字体颜色
		SDL_Surface *textSurface;
		SDL_FRect *dest;//文本显示区域
	}TextData;
}

namespace Dungeon
{
	/*
	* 文本类
	*/
	class Text
	{
	private:
		TextData *mTextData;

	public:
		Text();
		~Text();
		DisplayObject *Create(const char *fontFile, const char *value, int ptsize, uint32_t color, float x, float y);
		static void TextSet(DisplayObject *self, const char *value);
		static void DrawCallback(DisplayObject *self, SDL_Renderer *renderer);
		static void DestroyCallback(DisplayObject *self);
		TextData *GetTextData();
	};

}

#endif // ! _DUNGEON_TEXT_H_
