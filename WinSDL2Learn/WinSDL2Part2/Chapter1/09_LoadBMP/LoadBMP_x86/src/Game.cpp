#include <SDL2/SDL.h>
#include "Game.h"

namespace Dungeon
{
#define WIDTH 600
#define HEIGHT 500
#define FRAMERATE 60

	Game::Game() : mWindow(nullptr), mIsRunning(true), mImage(nullptr), mScreen(nullptr)
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

		//��ʼ��
		mScreen = SDL_GetWindowSurface(mWindow);
		if (!mScreen)
		{
			SDL_Log("��ʼ��Surfaceʧ��: %s", SDL_GetError());
			return false;
		}

		//��ʼ��λͼ
		mImage = SDL_LoadBMP("./resources/cat.bmp");
		if (!mImage)
		{
			SDL_Log("����λͼʧ��: %s", SDL_GetError());
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
		// ����¼���������δ�������¼�����˳����
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
		SDL_Rect src = { 0,0,mImage->w,mImage->h };
		SDL_BlitSurface(mImage, &src, mScreen, &src);
		SDL_UpdateWindowSurface(mWindow);
	}
}