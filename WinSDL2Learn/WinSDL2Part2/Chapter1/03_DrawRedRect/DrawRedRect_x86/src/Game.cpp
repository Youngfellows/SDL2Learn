#include <SDL2/SDL.h>
#include "Game.h"

namespace Dungeon
{
#define WIDTH 600
#define HEIGHT 500
#define FRAMERATE 60

	Game::Game() : mWindow(nullptr), mIsRunning(true), mSurface(nullptr)
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

		// Surface 初始化
		mSurface = SDL_GetWindowSurface(mWindow);
		if (!mSurface)
		{
			SDL_Log("获取窗口Surface失败: %s", SDL_GetError());
			return false;
		}

		return true;
	}

	void Game::Shutdown()
	{
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
		//使用Surface,绘制背景-白色
		SDL_Rect rect = { 0,0,WIDTH,HEIGHT };
		SDL_FillRect(mSurface, &rect, 0xffffffff);//ARGB

		//使用Surface,绘制红色矩形
		SDL_Rect redRect = { 0,0,100,100 };
		SDL_FillRect(mSurface, &redRect, 0xffff0000);
		SDL_UpdateWindowSurface(mWindow);
	}
}