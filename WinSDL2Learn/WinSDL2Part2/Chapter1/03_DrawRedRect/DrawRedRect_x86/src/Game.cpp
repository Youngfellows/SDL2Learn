#include <SDL2/SDL.h>
#include "Game.h"

namespace Dungeon
{
#define WIDTH 400
#define HEIGHT 300

	Game::Game() : mWindow(nullptr), mIsRunning(true), mSurface(nullptr)
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

		// Surface ��ʼ��
		mSurface = SDL_GetWindowSurface(mWindow);
		if (!mSurface)
		{
			SDL_Log("��ȡ����Surfaceʧ��: %s", SDL_GetError());
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
			Draw();
			Event();
			Update();
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

	void Game::Update()
	{
		SDL_Delay(16);
	}

	void Game::Draw()
	{
		SDL_Rect rect = { 0,0,WIDTH,HEIGHT };
		SDL_FillRect(mSurface, &rect, 0xffffffff);//ARGB
		SDL_Rect redRect = { 0,0,100,100 };
		SDL_FillRect(mSurface, &redRect, 0xffff0000);
		SDL_UpdateWindowSurface(mWindow);
	}
}