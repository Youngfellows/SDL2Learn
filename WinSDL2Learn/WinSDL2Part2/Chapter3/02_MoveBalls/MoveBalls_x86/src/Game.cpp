#include "Game.h"
#include <iostream>


namespace Dungeon
{

	Game::Game() : mWindow(nullptr), mIsRunning(true), mRenderer(nullptr), mResource(nullptr)
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
			SDL_Log("Can not create Renderer: %s", SDL_GetError());
			return false;
		}

		// 加载图片
		mResource = new Resource();
		if (!mResource->Resource_Load(mRenderer))
		{
			return false;
		}

		// 创建50个球
		CreateBalls();

		return true;
	}

	void Game::Shutdown()
	{
		DestoryBalls();
		if (mResource)
		{
			mResource->Resource_Unload();
		}
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

	void Game::CreateBalls()
	{
		for (int i = 0; i < BALL_COUNT; i++)
		{
			Ball *ball = new Ball();
			ball->Ball_Create(WINDOW_WIDTH / 2,WINDOW_HEIGHT / 2,
				(rand() % 10 - 5),
				((float)(rand() % 1000)) / 1000 * 10 - 5,
				((float)(rand() % 1000)) / 1000 * 10 - 5);
			mBalls[i] = ball;
		}
	}

	void Game::DestoryBalls()
	{
		for (int i = 0; i < BALL_COUNT; i++)
		{
			delete mBalls[i];
		}
	}

	void Game::Draw()
	{
		SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
		SDL_RenderClear(mRenderer);

		for (int i = 0; i < BALL_COUNT; i++)
		{
			mBalls[i]->Ball_Draw(mRenderer, mResource);
		}

		SDL_RenderPresent(mRenderer);
	}
}