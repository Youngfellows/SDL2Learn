#ifndef  _DUNGEON_TEXT_H_
#define  _DUNGEON_TEXT_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "DisplayObject.h"

namespace Dungeon
{
	//�ı�����ʵ��
	typedef struct TextData
	{
		TTF_Font *font;//����
		char *fontFile;//�����ļ�
		char *value;//�ı�
		int ptsize;//�����С
		uint32_t color;//������ɫ
		SDL_Surface *textSurface;
		SDL_FRect *dest;//�ı���ʾ����
	}TextData;
}

namespace Dungeon
{
	/*
	* �ı���
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
