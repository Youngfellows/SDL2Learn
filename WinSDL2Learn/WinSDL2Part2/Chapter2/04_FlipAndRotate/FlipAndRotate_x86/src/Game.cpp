#include "Game.h"

namespace Dungeon
{
#define WIDTH 600
#define HEIGHT 500
#define FRAMERATE 60
#define FILE_NAME "./resources/cat.bmp"

	Game::Game() : mWindow(nullptr), mIsRunning(true), mRenderer(nullptr),
		mImageTexture(nullptr), angle(0)
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

		// Renderer初始化
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
		if (!mRenderer)
		{
			SDL_Log("Can not create renderer: %s", SDL_GetError());
			return false;
		}

		// 加载位图资源
		SDL_Surface *imageSurface = SDL_LoadBMP(FILE_NAME);
		if (!imageSurface)
		{
			SDL_Log("Can not load image: %s", SDL_GetError());
			return false;
		}

		// Texture初始化
		mImageTexture = SDL_CreateTextureFromSurface(mRenderer, imageSurface);
		SDL_FreeSurface(imageSurface);
		if (!mImageTexture)
		{
			SDL_Log("Can not create texture: %s", SDL_GetError());
			return false;
		}

		return true;
	}

	void Game::Shutdown()
	{
		SDL_DestroyTexture(mImageTexture);
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

	void Game::Draw()
	{
		SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
		SDL_RenderClear(mRenderer);

		int w, h;
		SDL_QueryTexture(mImageTexture, nullptr, nullptr, &w, &h);
		//SDL_Rect destRect = { 0,0,w,h };
		SDL_Rect destRect = { 0,0,100,100 };

		angle += 0.5;
		SDL_RenderCopyEx(mRenderer, mImageTexture, nullptr, &destRect, angle, nullptr, SDL_FLIP_NONE);


		SDL_RenderPresent(mRenderer);
	}
}