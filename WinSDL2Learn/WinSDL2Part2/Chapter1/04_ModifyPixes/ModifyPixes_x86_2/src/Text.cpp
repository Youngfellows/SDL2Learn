#include "Text.h"
#include <cstdarg>
#include "Config.h"

namespace Dungeon
{
	Text::Text() :mTextData(nullptr)
	{
	}

	Text::~Text()
	{
	}

	DisplayObject *Text::Create(const char *file, const char *value,
		int ptsize, uint32_t color, float x, float y, uint32_t bgColor,
		float left, float right, float top, float bottom, DisplayObject *destObj,
		int size, initializer_list<OnTextClickCallback> ls)
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

		mTextData->padding = (TextPadding *)malloc(sizeof(TextPadding));
		if (!mTextData->padding)
		{
			return nullptr;
		}
		mTextData->padding->left = left;
		mTextData->padding->top = top;
		mTextData->padding->right = right;
		mTextData->padding->bottom = bottom;

		mTextData->dest = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mTextData->dest)
		{
			return nullptr;
		}
		//mTextData->dest->x = x + mTextData->padding->left;
		mTextData->dest->x = x + left;
		mTextData->dest->y = y + top;
		mTextData->dest->w = 0;
		mTextData->dest->h = 0;

		mTextData->bgColor = bgColor;
		mTextData->background = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (mTextData->background)
		{
			mTextData->background->x = x;
			mTextData->background->y = y;
			mTextData->background->w = 0;
			mTextData->background->h = 0;
		}

		//创建数组保存函数回调
		mTextData->destObj = destObj;
		mTextData->textClickData = (TextClickData *)malloc(sizeof(TextClickData));
		if (!mTextData->textClickData)
		{
			return nullptr;
		}
		mTextData->textClickData->size = size;
		mTextData->textClickData->OnTextClicks = (OnTextClickCallback *)malloc(sizeof(OnTextClickCallback) * size);
		if (!mTextData->textClickData->OnTextClicks)
		{
			return nullptr;
		}

		int i = 0;
		for (auto ele = ls.begin(); ele != ls.end(); ++ele, i++)
		{
			OnTextClickCallback onTextClickCallback = *ele;
			*(mTextData->textClickData->OnTextClicks + i) = onTextClickCallback;//设置点击事件回调函数
			SDL_Log("Create,onTextClickCallback:%p", onTextClickCallback);
		}

		mTextData->move = SDL_FALSE;
		mTextData->point = (SDL_FPoint *)malloc(sizeof(SDL_FPoint));
		if (!mTextData->point)
		{
			return nullptr;
		}
		mTextData->point->x = 0;
		mTextData->point->y = 0;


		// 创建显示对象
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//设置要显示对象
		OnCallbackData *onCallback = displayObject->GetOnCallback();//设置回调函数
		if (onCallback)
		{
			onCallback->OnDraw = &OnDrawCallback;
			onCallback->OnMouseDown = &OnMouseDownCallback;//鼠标按下事件
			onCallback->OnMouseUp = &OnMouseUpCallback;
			onCallback->OnMouseMove = &OnMouseMoveCallback;
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
				SDL_FreeSurface(textData->textSurface);//是释放掉再更新
			}

			//创建要显示文本surface
			textData->textSurface = TTF_RenderUTF8_Blended(textData->font, textData->value, textColor);
			textData->dest->w = (float)textData->textSurface->w;
			textData->dest->h = (float)textData->textSurface->h;

			textData->background->w = textData->padding->left + textData->dest->w + textData->padding->right;
			textData->background->h = textData->padding->top + textData->dest->h + textData->padding->bottom;
		}
	}

	void Text::OnDrawCallback(DisplayObject *self, SDL_Surface *winSurface, Resource *resource)
	{
		Text *text = (Text *)self->GetSubClass();
		if (text)
		{
			text->Draw(winSurface, resource);
		}
	}

	void Text::OnMouseDownCallback(DisplayObject *self, SDL_Event *event)
	{
		Text *text = (Text *)self->GetSubClass();
		//SDL_Log("Text::OnMouseDownCallback:: text:%p", text);
		if (text)
		{
			text->MouseButtonDown(event);
		}
	}

	void Text::OnDestoryCallback(DisplayObject *self)
	{
		Text *text = (Text *)self->GetSubClass();
		if (text)
		{
			text->Destory();
		}
	}

	void Text::OnMouseUpCallback(DisplayObject *self, SDL_Event *event)
	{
		Text *text = (Text *)self->GetSubClass();
		if (text)
		{
			text->MouseButtonUp(event);
		}
	}

	void Text::OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{
		Text *text = (Text *)self->GetSubClass();
		if (text)
		{
			text->MouseMove(event);
		}
	}

	void Text::Draw(SDL_Surface *winSurface, Resource *resource)
	{
		TextData *textData = GetTextData();
		//TextData *textData = text->mTextData;
		if (textData)
		{
			//绘制文本
			if (textData->textSurface)
			{
				//绘制背景,填充
				SDL_Rect bgRect = {
				(int)textData->background->x,
				(int)textData->background->y,
				(int)textData->background->w,
				(int)textData->background->h
				};
				SDL_FillRect(winSurface, &bgRect, textData->bgColor);

				//获取文字矩形,绘制文本
				SDL_Surface *textSurface = textData->textSurface;
				SDL_Rect textSrc = { 0,0,textSurface->w,textSurface->h };
				SDL_Rect textDest = {
					(int)textData->dest->x,
					(int)textData->dest->y,
					(int)textData->dest->w,
					(int)textData->dest->h
				};
				SDL_BlitSurface(textSurface, &textSrc, winSurface, &textDest);
			}
		}
	}

	void Text::MouseButtonDown(SDL_Event *event)
	{
		TextData *textData = GetTextData();
		SDL_FPoint point = { event->button.x,event->button.y };
		//if (SDL_PointInFRect(&point, textData->dest))
		if (SDL_PointInFRect(&point, textData->background))
		{
			textData->move = SDL_TRUE;
			textData->point->x = point.x;
			textData->point->y = point.y;

			for (int i = 0; i < textData->textClickData->size; i++)
			{
				//textData->textClickData->OnTextClicks[i] = onTextClickCallback;
				OnTextClickCallback  OnTextClick = *(textData->textClickData->OnTextClicks + i);
				//SDL_Log("Click,1 onTextClickCallback:%p", OnTextClick);
				//OnTextClick(self);//回调点击事件
				OnTextClick(textData->destObj);
				//SDL_Log("Click,2 onTextClickCallback:%p", OnTextClick);
			}
		}
	}

	void Text::MouseButtonUp(SDL_Event *event)
	{
		TextData *textData = GetTextData();
		//TextData *textData = text->mTextData;
		if (textData)
		{
			textData->move = SDL_FALSE;
		}
	}

	void Text::MouseMove(SDL_Event *event)
	{
		if (!mTextData)
		{
			SDL_Log("Text::MouseMove():: mTextData is null");
			return;
		}

		SDL_bool move = mTextData->move;
		SDL_FPoint *point = mTextData->point;
		SDL_FPoint curPoint = { event->motion.x ,event->motion.y };
		SDL_FRect *inner = mTextData->background;
		SDL_FRect *dest = mTextData->dest;
		SDL_Log("Photo::MouseMove:: point(%f,%f),curPoint(%f,%f),move:%d",
			point->x, point->y, curPoint.x, curPoint.y, move);

		// 可拖动
		if (move)
		{
			float dx = curPoint.x - point->x;
			float dy = curPoint.y - point->y;
			SDL_Log("Photo::MouseMove:::: Drag Inner Rectangle,dx:%f,dy:%f", dx, dy);

			inner->x += dx;//更新矩形位置
			inner->y += dy;
			dest->x += dx;
			dest->y += dy;

			point->x = curPoint.x;//更新点坐标
			point->y = curPoint.y;

			//限定可拖动边界
			if (inner->x < 0)
			{
				inner->x = 0;//限定左边界
				dest->x = inner->x + mTextData->padding->left;
			}
			if (inner->x > WINDOW_WIDTH - inner->w)
			{
				inner->x = WINDOW_WIDTH - inner->w;//限定右边界
				dest->x = inner->x + mTextData->padding->left;
			}
			if (inner->y < 0)
			{
				inner->y = 0;//限定上边界
				dest->y = inner->y + mTextData->padding->top;
			}
			if (inner->y > WINDOW_HEIGHT - inner->h)
			{
				inner->y = WINDOW_HEIGHT - inner->h;//限定下边界
				dest->y = inner->y + mTextData->padding->top;
			}
		}
	}

	void Text::Destory()
	{
		SDL_Log("Text::Destory()::");
		TextData *textData = GetTextData();
		//TextData *textData = text->mTextData;
		if (textData)
		{
			SDL_FreeSurface(textData->textSurface);
			TTF_CloseFont(textData->font);
			Free(textData->point);
			Free(textData->background);
			Free(textData->padding);
			Free(textData->dest);
			Free(textData->value);
			Free(textData->file);
			Free(textData);
			textData->point = nullptr;
			textData->background = nullptr;
			textData->padding = nullptr;
			textData->dest = nullptr;
			textData->value = nullptr;
			textData->file = nullptr;
			textData = nullptr;
			//SDL_Log("Text::Destory():: 222");
		}
	}

	void Text::Free(void *data)
	{
		if (data)
		{
			free(data);
		}
	}
}