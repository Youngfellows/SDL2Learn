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
	//函数指针,文本点击事件回调
	typedef void (*OnTextClickCallback)(DisplayObject *self);

	//边距
	typedef struct TextPadding
	{
		float left;
		float right;
		float top;
		float bottom;
	}TextPadding;

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
		TextPadding *padding;//边距
		uint32_t bgColor;//背景
		SDL_FRect *background;//背景
		SDL_FPoint *point;//位置
		SDL_bool move;//是否可移动
		TextClickData *textClickData;//回调函数数据
		DisplayObject *destObj;//保存回调回去需要获取的对象的指针
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
			int ptsize, uint32_t color, float x, float y, uint32_t bgColor,
			float left, float right, float top, float bottom,
			DisplayObject *destDisObj, int size, initializer_list<OnTextClickCallback> ls);
		void TextSet(const char *value);
		static void OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer);
		static void OnMouseDownCallback(DisplayObject *self, SDL_Event *event);
		static void OnMouseUpCallback(DisplayObject *self, SDL_Event *event);
		static void OnMouseMoveCallback(DisplayObject *self, SDL_Event *event);
		static void OnDestoryCallback(DisplayObject *self);

	private:
		TextData *GetTextData();
		void Draw(Resource *resource, SDL_Renderer *renderer);
		void MouseButtonDown(SDL_Event *event);
		void MouseButtonUp(SDL_Event *event);
		void MouseMove(SDL_Event *event);
		void Destory();
		void Free(void *data);
	};
}
#endif // !_DUNGEON_TEXT_H_

