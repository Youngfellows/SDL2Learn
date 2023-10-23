#include "Text.h"

namespace Dungeon
{
	Text::Text() :mTextData(nullptr)
	{
	}

	Text::~Text()
	{
	}

	DisplayObject *Text::Create(const char *file, const char *value,
		int ptsize, uint32_t color, float x, float y, OnTextClickCallback onTextClickCllback)
	{
		TTF_Font *font = TTF_OpenFont(file, ptsize);//打开字体
		if (!font)
		{
			SDL_Log("Can not open font: %s", SDL_GetError());
			return nullptr;
		}
		//动态申请内存
		this->mTextData = (TextData *)malloc(sizeof(TextData));
		if (!mTextData)
		{
			return nullptr;
		}
		mTextData->font = font;
		mTextData->file = (char *)malloc(sizeof(char) * SDL_strlen(file) + 1);
		if (!mTextData->file)
		{
			return nullptr;
		}
		SDL_strlcpy(mTextData->file, file, SDL_strlen(file) + 1);
		mTextData->value = (char *)malloc(sizeof(char) * SDL_strlen(value) + 1);
		if (!mTextData->value)
		{
			return nullptr;
		}
		SDL_strlcpy(mTextData->value, value, SDL_strlen(value) + 1);
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
		mTextData->dest->w = 0;
		mTextData->dest->h = 0;
		mTextData->OnTextClick = onTextClickCllback;

		// 创建显示对象
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//设置要显示对象
		OnCallbackData *onCallback = displayObject->GetOnCallback();//设置回调函数
		if (onCallback)
		{
			onCallback->OnDraw = &OnDrawCallback;
			onCallback->OnMouseDown = &OnMouseDownCallback;//鼠标按下事件
			onCallback->OnDestory = &OnDestoryCallback;
		}
		TextSet(mTextData->value);//设置文本信息
		return displayObject;
	}

	TextData *Text::GetTextData()
	{
		return this->mTextData;
	}

	void Text::TextSet(const char *value)
	{
		TextData *textData = this->mTextData;
		if (textData)
		{
			textData->value = (char *)malloc(sizeof(char) * SDL_strlen(value) + 1);
			if (textData->value)
			{
				SDL_strlcpy(textData->value, value, SDL_strlen(value) + 1);
			}
			SDL_Color textColor = {
			(textData->color & 0x00ff0000) >> 16,
			(textData->color & 0x0000ff00) >> 8,
			(textData->color & 0x000000ff),
			(textData->color & 0xff000000) >> 24
			};

			if (textData->textSurface)
			{
				SDL_FreeSurface(textData->textSurface);
			}

			//创建要显示文本surface
			textData->textSurface = TTF_RenderUTF8_Blended(textData->font, textData->value, textColor);
			textData->dest->w = (float)textData->textSurface->w;
			textData->dest->h = (float)textData->textSurface->h;
		}
	}

	void Text::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		Text *text = (Text *)self->GetSubClass();
		if (text)
		{
			TextData *textData = text->GetTextData();
			//TextData *textData = text->mTextData;
			if (textData)
			{
				//绘制文本
				if (textData->textSurface)
				{
					SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textData->textSurface);
					SDL_RenderCopyF(renderer, texture, nullptr, textData->dest);
					SDL_DestroyTexture(texture);
				}
			}
		}
	}

	void Text::OnMouseDownCallback(DisplayObject *self, SDL_Event *event)
	{
		Text *text = (Text *)self->GetSubClass();
		if (text)
		{
			TextData *textData = text->GetTextData();
			SDL_FPoint point = { event->button.x,event->button.y };
			if (SDL_PointInFRect(&point, textData->dest))
			{
				if (textData->OnTextClick)
				{
					textData->OnTextClick(self);//回调点击事件
				}
			}
		}
	}

	void Text::OnDestoryCallback(DisplayObject *self)
	{
		Text *text = (Text *)self->GetSubClass();
		if (text)
		{
			TextData *textData = text->GetTextData();
			//TextData *textData = text->mTextData;
			if (textData)
			{
				SDL_FreeSurface(textData->textSurface);
				TTF_CloseFont(textData->font);
				free(textData->dest);
				free(textData->value);
				free(textData->file);
				free(textData);
				textData = nullptr;
			}
		}
	}
}