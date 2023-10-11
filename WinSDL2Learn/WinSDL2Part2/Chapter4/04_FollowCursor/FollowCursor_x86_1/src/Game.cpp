#include "Game.h"

namespace Dungeon
{
#define WIDTH 600
#define HEIGHT 500
#define FRAMERATE 60

	Game::Game() : mWindow(nullptr), mIsRunning(true), mRenderer(nullptr), mResource(nullptr), mCursor(nullptr)
	{

	}

	bool Game::Initialize()
	{
		// SDL���ʼ��
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			SDL_Log("Can not init video: %s", SDL_GetError());
			return false;
		}

		// ���ڳ�ʼ��
		mWindow = SDL_CreateWindow("Dungeon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (!mWindow)
		{
			SDL_Log("Can not create window: %s", SDL_GetError());
			return false;
		}

		// ��ʼ��Renderer
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
		if (!mRenderer)
		{
			SDL_Log("Can not create renderer: %s", SDL_GetError());
			return false;
		}

		// ����CursorͼƬ��Դ
		mResource = new Resource();
		if (!mResource->Resource_Load(mRenderer))
		{
			return false;
		}

		//�����Զ��������
		if (!CreateComponents())
		{
			return false;
		}

		//�ر�Ĭ�Ϲ��
		SDL_ShowCursor(SDL_DISABLE);

		return true;
	}

	void Game::Shutdown()
	{
		FreeComponents();
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
			case SDL_MOUSEMOTION:
				ProcessMouseMoveEvent(&event);
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

		Cursor *cursor = new Cursor();
		mCursor = cursor->Cursor_Create(0, 0, 20, 20);//��ʽ1
		if (!mCursor)
		{
			return SDL_FALSE;
		}
		/*
		if (!cursor->Cursor_Create(mDisplayObject, 0, 0, 30, 30))//��ʽ2,���ַ�ʽ���ܸ�ֵmDisplayObject,ֻ�Ǿֲ�����
		{
			return false;
		}*/
		return SDL_TRUE;
	}

	void Game::FreeComponents()
	{
		if (mCursor)
		{
			mCursor->DisplayObject_Destory();
		}
	}

	void Game::DrawComponents()
	{
		if (mCursor)
		{
			mCursor->DisplayObject_Draw(mResource, mRenderer);//����ָ��Ҫ�����
		}
	}

	void Game::ProcessMouseMoveEvent(SDL_Event *event)
	{
		if (mCursor)
		{
			mCursor->DisplayObject_OnMouseMove(event);
		}
	}

}