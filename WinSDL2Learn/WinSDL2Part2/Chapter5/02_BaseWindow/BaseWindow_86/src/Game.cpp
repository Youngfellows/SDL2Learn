#include "Game.h"
#include "Config.h"

namespace Dungeon
{
	Game::Game() :mIsRunning(true), mWindow(nullptr)
	{
	}

	Game::~Game()
	{
		SDL_Log("~Game()");
		Shutdown();
	}

	bool Game::Initialize()
	{
		// SDL库初始化
		// if (SDL_Init(SDL_INIT_VIDEO))
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			SDL_Log("Can not init video: %s", SDL_GetError());
			return false;
		}

		// 窗口初始化
		mWindow = SDL_CreateWindow(WINDOW_TITLE,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (!mWindow)
		{
			SDL_Log("Can not create window: %s", SDL_GetError());
			return false;
		}
		return true;
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
			long frame = 1000 / FRAMERATE;//每一帧显示时间
			long delay = frame - cost;
			if (delay > 0)
			{
				Update(delay);
			}
		}
	}
	void Game::Shutdown()
	{
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
		SDL_Log("Shutdown");
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
		if (delay)
		{
			SDL_Delay(delay);
		}
	}

	void Game::Draw()
	{

	}

}