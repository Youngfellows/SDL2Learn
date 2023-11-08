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
			SDL_Log("Can not create renderer: %s", SDL_GetError());
			return false;
		}

		// 加载图片资源
		mResource = new Resource();
		if (!mResource->Create(mRenderer))
		{
			return false;
		}

		// 加载组件
		if (!CreateComponents())
		{
			return false;
		}

		// 禁用默认光标
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
		DrawComponents();//绘制组件
		SDL_RenderPresent(mRenderer);
	}

	SDL_bool Game::CreateComponents()
	{
		//创建光标
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
			mCursor->Draw(mResource, mRenderer);//绘制光标
		}
		if (mSliderBar)
		{
			mSliderBar->Draw(mResource, mRenderer);//绘制滑块
		}
	}

	void Game::ProcessMouseMoveEvent(SDL_Event *event)
	{
		if (mCursor)
		{
			mCursor->MouseMove(event);//光标处理鼠标移动事件
		}
		if (mSliderBar)
		{
			mSliderBar->MouseMove(event);//滑块处理鼠标移动事件
		}
	}
}