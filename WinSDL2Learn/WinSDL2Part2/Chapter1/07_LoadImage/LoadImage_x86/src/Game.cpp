#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"

namespace Dungeon
{
#define WIDTH 600
#define HEIGHT 500
#define FRAMERATE 60

	Game::Game() : mWindow(nullptr), mIsRunning(true), mScreen(nullptr), mImage(nullptr)
	{

	}

	bool Game::Initialize()
	{
		// SDL库初始化
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			SDL_Log("SDL库初始化失败: %s", SDL_GetError());
			return false;
		}

		// 窗口初始化
		mWindow = SDL_CreateWindow("Dungeon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (!mWindow)
		{
			SDL_Log("窗口初始化失败: %s", SDL_GetError());
			return false;
		}

		//Screen Surface 初始化
		mScreen = SDL_GetWindowSurface(mWindow);
		if (!mScreen)
		{
			SDL_Log("初始化Screen Surface失败: %s", SDL_GetError());
			return false;
		}

		//初始化图片
		mImage = IMG_Load("./resources/cat.jpg");
		if (!mImage)
		{
			SDL_Log("初始化图片资源失败: %s", SDL_GetError());
			return false;
		}
		return true;
	}

	void Game::Shutdown()
	{
		SDL_FreeSurface(mImage);
		SDL_DestroyWindowSurface(mWindow);
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

	void Game::Draw()
	{
		SDL_Rect src = { 0,0,mImage->w,mImage->h };
		SDL_BlitSurface(mImage, &src, mScreen, &src);
		SDL_UpdateWindowSurface(mWindow);
	}
}