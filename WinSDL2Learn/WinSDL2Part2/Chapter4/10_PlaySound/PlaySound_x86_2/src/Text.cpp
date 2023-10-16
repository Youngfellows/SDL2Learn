#include "Text.h"

namespace Dungeon
{
	Text::Text() :mTextData(nullptr)
	{
	}

	Text::~Text()
	{
	}

	TextData *Text::GetTextData()
	{
		return this->mTextData;
	}

	DisplayObject *Text::Create(const char *fontFile, const char *value,
		int ptsize, uint32_t color, float x, float y)
	{
		TTF_Font *font = TTF_OpenFont(fontFile, ptsize);
		if (!font)
		{
			SDL_Log("Can not open font: %s", SDL_GetError());
			return nullptr;
		}

		//��̬�����ڴ�
		this->mTextData = (TextData *)malloc(sizeof(TextData));
		if (!mTextData)
		{
			return nullptr;
		}
		mTextData->font = font;
		//mTextData->fontFile = fontFile;
		mTextData->fontFile = (char *)malloc(sizeof(char) * SDL_strlen(fontFile) + 1);
		if (mTextData->fontFile)
		{
			SDL_strlcpy(mTextData->fontFile, fontFile, SDL_strlen(fontFile) + 1);
		}

		//mTextData->value = value;
		mTextData->value = (char *)malloc(sizeof(char) * SDL_strlen(value) + 1);
		if (mTextData->value)
		{
			SDL_strlcpy(mTextData->value, value, SDL_strlen(value) + 1);
		}

		mTextData->ptsize = ptsize;
		mTextData->color = color;
		mTextData->textSurface = nullptr;

		mTextData->dest = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mTextData->dest)
		{
			return nullptr;
		}
		mTextData->dest->x = x;
		mTextData->dest->y = y;

		//����Ҫ��ʾ����
		DisplayObject *displayObject = new DisplayObject();
		displayObject->subClass = this;//Ϊ����ֵ(�þ���)
		//���ûص�����
		if (!displayObject->Create(
			&DrawCallback,
			&TextSet,
			&DestroyCallback))
		{
			return nullptr;
		}
		TextSet(displayObject, mTextData->value);//�����ı�����
		return displayObject;
	}

	void Text::TextSet(DisplayObject *self, const char *value)
	{
		Text *text = (Text *)self->subClass;
		if (text)
		{
			TextData *textData = text->mTextData;
			if (textData)
			{
				//textData->value = value;//����Ҫ��ʾ�ı�
				textData->value = (char *)malloc(sizeof(char) * SDL_strlen(value) + 1);
				if (textData->value)
				{
					SDL_strlcpy(textData->value, value, SDL_strlen(value) + 1);
				}

				SDL_Color textColor = {
				(textData->color & 0x00ff0000) >> 16,
				(textData->color & 0x0000ff00) >> 8,
				(textData->color & 0x000000ff) ,
				(textData->color & 0xff000000) >> 24,
				};

				if (textData->textSurface)
				{
					SDL_FreeSurface(textData->textSurface);
				}
				//����Ҫ�ı�surface
				textData->textSurface = TTF_RenderUTF8_Blended(textData->font, textData->value, textColor);
				textData->dest->w = (float)textData->textSurface->w;
				textData->dest->h = (float)textData->textSurface->h;
			}
		}
	}

	void Text::DrawCallback(DisplayObject *self, SDL_Renderer *renderer)
	{
		Text *text = (Text *)self->subClass;
		if (text)
		{
			TextData *textData = text->mTextData;
			if (textData)
			{
				//�����ı�
				SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textData->textSurface);
				SDL_RenderCopyF(renderer, texture, nullptr, textData->dest);
				SDL_DestroyTexture(texture);
			}
		}
	}

	void Text::DestroyCallback(DisplayObject *self)
	{
		Text *text = (Text *)self->subClass;
		if (text)
		{
			TextData *textData = text->mTextData;
			if (textData)
			{
				free(textData->fontFile);
				free(textData->value);
				free(textData->dest);
				SDL_FreeSurface(textData->textSurface);
				TTF_CloseFont(textData->font);
				free(textData);
			}
		}
	}
}