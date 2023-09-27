#include <SDL2/SDL.h>
#include "Game.h"

namespace Dungeon
{
#define WIDTH 600
#define HEIGHT 500
#define FRAMERATE 60

	Game::Game() : mWindow(nullptr), mIsRunning(true), mSurface(nullptr), x(0), mIsRebound(false)
	{

	}

	bool Game::Initialize()
	{
		// SDL���ʼ��
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			SDL_Log("SDL���ʼ��ʧ��: %s", SDL_GetError());
			return false;
		}

		// ���ڳ�ʼ��
		mWindow = SDL_CreateWindow("Dungeon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (!mWindow)
		{
			SDL_Log("���ڳ�ʼ��ʧ��: %s", SDL_GetError());
			return false;
		}

		//��ʼ��Surface
		mSurface = SDL_GetWindowSurface(mWindow);
		if (!mSurface)
		{
			SDL_Log("��ʼ��Surfaceʧ��: %s", SDL_GetError());
			return false;
		}
		return true;
	}

	void Game::Shutdown()
	{
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
			long frame = 1000 / FRAMERATE;//ÿһ֡�೤ʱ��
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
		// ����¼���������δ������¼�����˳����
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:// �˳��¼������´��ڵĲ�
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
		if (x >= (WIDTH - 100))
		{
			mIsRebound = true;
		}
		else if (x <= 0)
		{
			mIsRebound = false;
		}

		SDL_Log("mIsRebound=%d", mIsRebound);

		if (!mIsRebound)
		{
			x++;
		}
		else
		{
			x--;
		}

		SDL_Log("x=%d", x);
		SDL_Rect rect = { 0,0,WIDTH,HEIGHT };
		SDL_FillRect(mSurface, &rect, 0xffffffff);//ARGB
		SDL_Rect redRect = { x,0,100,100 };
		SDL_FillRect(mSurface, &redRect, 0xffff0000);
		SDL_UpdateWindowSurface(mWindow);
	}
}