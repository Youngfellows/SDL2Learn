#define _CRT_SECURE_NO_WARNINGS

#include "Game.h"
#include "Config.h"
#include "Text.h"
#include <stdio.h>

namespace Dungeon
{
	Game::Game() : mWindow(nullptr), mIsRunning(true), mRenderer(nullptr),
		mWelcomText(nullptr), mButtonText(nullptr), mTipText(nullptr), mClickCount(0)
	{

	}

	bool Game::Initialize()
	{
		// TTF字体库初始化
		if (TTF_Init())
		{
			SDL_Log("Can not init ttf: %s", SDL_GetError());
			return false;
		}

		// SDL库初始化
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			SDL_Log("Can not init video: %s", SDL_GetError());
			return false;
		}

		// 窗口初始化
		mWindow = SDL_CreateWindow("Dungeon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (!mWindow)
		{
			SDL_Log("Can not create window: %s", SDL_GetError());
			return false;
		}

		// 初始化Renderer
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
		if (!mRenderer)
		{
			SDL_Log("Can not create renderer: %s", SDL_GetError());
			return false;
		}
		if (!CreateComponents())
		{
			return false;
		}

		return true;
	}

	void Game::Shutdown()
	{
		FreeComponents();
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}

	void Game::Loop()
	{
		while (mIsRunning)
		{
			uint32_t begin = SDL_GetTicks();

			Draw();
			Event();

			long current = SDL_GetTicks();
			long cost = current - begin;
			long frame = 1000 / FRAMERATE;//每一帧多长时间
			long delay = frame - cost;
			//SDL_Log("delay=%ld", delay);
			if (delay > 0)
			{
				Update(delay);
			}
		}
	}

	void Game::Event()
	{
		SDL_Event event;
		// 如果事件队列中有未处理的事件，按顺序处理
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:// 退出事件，按下窗口的叉
				mIsRunning = false;
				break;
			case SDL_MOUSEBUTTONDOWN://鼠标按下
				ProcessMouseDownEvent(&event);
				break;
			default:
				break;
			}
		}
	}

	void Game::Update(long delay)
	{
		if (delay > 0)
		{
			SDL_Delay(delay);
		}
	}

	void Game::Draw()
	{
		SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
		SDL_RenderClear(mRenderer);
		DrawComponents();
		SDL_RenderPresent(mRenderer);
	}


	SDL_bool Game::CreateComponents()
	{
		Text *welcomText = new Text();
		const char *wText = "Welcom to SDL2";
		mWelcomText = welcomText->Create(FONT_FILE_NAME, wText, PT_SIZE_20, 0xff000000, 0, 0);
		if (!mWelcomText)
		{
			return SDL_FALSE;
		}

		Text *buttonText = new Text();
		const char *bText = "Click Me";
		mButtonText = buttonText->Create(FONT_FILE_NAME, bText, PT_SIZE_32, 0xffff0000, 10, 100);
		if (!mButtonText)
		{
			return SDL_FALSE;
		}

		Text *tipText = new Text();
		const char *tText = "xxxx";
		mTipText = tipText->Create(FONT_FILE_NAME, tText, PT_SIZE_40, 0xff0000ff, 200, 200);
		if (!mTipText)
		{
			return SDL_FALSE;
		}

		return SDL_TRUE;
	}

	void Game::FreeComponents()
	{
		if (mWelcomText)
		{
			mWelcomText->Destroy();
		}
		if (mButtonText)
		{
			mButtonText->Destroy();
		}
		if (mTipText)
		{
			mTipText->Destroy();
		}
	}

	void Game::DrawComponents()
	{
		if (mWelcomText)
		{
			mWelcomText->Draw(mRenderer);
		}
		if (mButtonText)
		{
			mButtonText->Draw(mRenderer);
		}
		if (mTipText)
		{
			mTipText->Draw(mRenderer);
		}
	}

	void Game::ProcessMouseDownEvent(SDL_Event *event)
	{
		SDL_FPoint point = { event->button.x,event->button.y };
		SDL_Log("point(x:%f,y:%f)", point.x, point.y);
		if (mButtonText)
		{
			Text *buttonText = (Text *)mButtonText->subClass;//获取显示对象
			if (buttonText)
			{
				TextData *textData = buttonText->GetTextData();
				if (textData)
				{
					SDL_FRect *dest = textData->dest;
					if (dest)
					{
						if (SDL_PointInFRect(&point, dest))
						{
							SDL_Log("Click Button");
							mClickCount++;
							char msg[256];
							sprintf(msg, "Click Number: %d", mClickCount);
							if (mTipText)
							{
								//const char *ss = "sssssssss";
								mTipText->TextSet(msg);
							}
						}
						else
						{
							SDL_Log("Click Other");
						}
					}
				}
			}
		}
	}
}