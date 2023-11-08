#include "Game.h"

namespace Dungeon
{
#define WIDTH 600
#define HEIGHT 500
#define FRAMERATE 60

	Game::Game() : mWindow(nullptr), mIsRunning(true),
		mRenderer(nullptr), mFirst(nullptr), mLast(nullptr), mItem(nullptr)
	{

	}

	bool Game::Initialize()
	{
		// SDL库初始化
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			SDL_Log("Can not init video: %s", SDL_GetError());
			return false;
		}

		// 窗口初始化
		mWindow = SDL_CreateWindow("Dungeon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
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

		AddRectShape();

		return true;
	}

	void Game::Shutdown()
	{
		RectShapeDestory();
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
			case SDL_MOUSEMOTION:
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
				ProcessMouseEvent(&event);
				break;
			default:
				break;
			}
		}
	}

	void Game::ProcessMouseEvent(SDL_Event *event)
	{
		mItem = mLast;
		while (mItem != nullptr)
		{
			if (mItem->RectShape_OnMouseEvent(event))
			{
				if (mItem != mLast)
				{
					if (mItem->mPre != nullptr)
					{
						mItem->mPre->mNext = mItem->mNext;
					}
					else
					{
						mFirst = mItem->mNext;
					}
					mItem->mNext->mPre = mItem->mPre;
					mItem->mNext = nullptr;
					AddRectShape(mItem);
				}
				break;//结束while循环
			}
			mItem = mItem->mPre;
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

		RectShape *item = mFirst;
		while (item != nullptr)
		{
			item->RectShape_Draw(mRenderer);
			item = item->mNext;
		}

		SDL_RenderPresent(mRenderer);
	}

	void Game::AddRectShape()
	{
		AddRectShape(new RectShape(0, 0, 80, 60, 0xffff0000));
		AddRectShape(new RectShape(100, 0, 80, 60, 0xffffff00));
		AddRectShape(new RectShape(200, 0, 80, 60, 0xff0000ff));
	}

	/*
	* 向链表插入节点元素
	*/
	void Game::AddRectShape(RectShape *rectShape)
	{
		if (mLast != nullptr)
		{
			mLast->mNext = rectShape;
			rectShape->mPre = mLast;
			mLast = rectShape;
		}
		else
		{
			mFirst = rectShape;
			mLast = rectShape;
		}
	}

	void Game::RectShapeDestory()
	{
		RectShape *item = mFirst;
		while (item != nullptr)
		{
			RectShape *current = item;
			item = item->mNext;
			delete current;
		}
		mFirst = nullptr;
		mLast = nullptr;
	}
}