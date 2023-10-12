#include "Game.h"
#include "Config.h"
#include "Cursor.h"
#include "SliderBar.h"

namespace Dungeon
{
	Game::Game() : mWindow(nullptr), mIsRunning(true),
		mRenderer(nullptr), mResource(nullptr), mCursor(nullptr),
		mSliderBar(nullptr)
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
		mWindow = SDL_CreateWindow("Dungeon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
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

		// ����ͼƬ��Դ
		mResource = new Resource();
		if (!mResource->Create(mRenderer))
		{
			return false;
		}

		// �������
		if (!CreateComponents())
		{
			return false;
		}

		// ����Ĭ�Ϲ��
		SDL_ShowCursor(SDL_DISABLE);

		return true;
	}

	void Game::Shutdown()
	{
		FreeComponents();
		if (mResource)
		{
			mResource->Destory();
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
		DrawComponents();//�������
		SDL_RenderPresent(mRenderer);
	}

	SDL_bool Game::CreateComponents()
	{
		//�������
		Cursor *cursor = new Cursor();
		this->mCursor = cursor->Create(0, 0, CURSOR_WIDTH, CURSOR_HEIGHT);
		if (!mCursor)
		{
			return SDL_FALSE;
		}
		SliderBar *slidarBar = new SliderBar();
		this->mSliderBar = slidarBar->Create(SLIDERBAR_START_X_POSITION, SLIDERBAR_START_Y_POSITION,
			SLIDERBAR_WIDTH, SLIDERBAR_HEIGHT, SLIDER_WIDTH, SLIDERBAR_HEIGHT);
		if (!mSliderBar)
		{
			return SDL_FALSE;
		}

		return SDL_TRUE;
	}

	void Game::FreeComponents()
	{
		if (mCursor)
		{
			mCursor->Destory();
		}
		if (mSliderBar)
		{
			mSliderBar->Destory();
		}
	}

	void Game::DrawComponents()
	{
		if (mCursor)
		{
			mCursor->Draw(mResource, mRenderer);//���ƹ��
		}
		if (mSliderBar)
		{
			mSliderBar->Draw(mResource, mRenderer);//���ƻ���
		}
	}

	void Game::ProcessMouseMoveEvent(SDL_Event *event)
	{
		if (mCursor)
		{
			mCursor->MouseMove(event);//��괦������ƶ��¼�
		}
		if (mSliderBar)
		{
			mSliderBar->MouseMove(event);//���鴦������ƶ��¼�
		}
	}
}