#include "Game.h"
#include "Config.h"
#include "MovableRectangle.h"

namespace Dungeon
{
	Game::Game() :mIsRunning(true), mWindow(nullptr),
		mRenderer(nullptr), mMovableRectangle(nullptr)
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

		// 初始化Renderer
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
		if (!mRenderer)
		{
			SDL_Log("Can not create renderer: %s", SDL_GetError());
			return false;
		}

		// 创建绘制组件
		if (!CreateComponents())
		{
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
		SDL_Log("Game:: Shutdown");
		FreeComponents();
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
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
				MouseMoveEvent(&event);
				break;
			case SDL_MOUSEBUTTONDOWN:
				MouseDownEvent(&event);
				break;
			case SDL_MOUSEBUTTONUP:
				MouseUpEvent(&event);
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
		//绘制白色背景
		SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
		SDL_RenderClear(mRenderer);
		DrawComponents();//绘制组件
		SDL_RenderPresent(mRenderer);
	}

	SDL_bool Game::CreateComponents()
	{
		MovableRectangle *rect = new MovableRectangle();
		this->mMovableRectangle = rect->Create(
			100, 100, INNER_RECT_REST_WIDTH, INNER_RECT_REST_HEIGHT,
			INNER_RECT_FILL_COLOR, INNER_RECT_BORDER_COLOR, PT_SIZE_10,
			OUTER_RECT_REST_WIDTH, OUTER_RECT_REST_HEIGHT);

		if (!mMovableRectangle)
		{
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	void Game::DrawComponents()
	{
		if (mMovableRectangle)
		{
			// 两种方式回调都可以
			mMovableRectangle->Draw(mRenderer);
			//mMovableRectangle->Draw2(mRenderer);
		}
	}

	void Game::FreeComponents()
	{
		SDL_Log("Game:: FreeComponents");
		if (mMovableRectangle)
		{
			mMovableRectangle->Destory();
			delete mMovableRectangle;
			mMovableRectangle = nullptr;
		}
	}

	void Game::MouseMoveEvent(SDL_Event *event)
	{
		if (mMovableRectangle)
		{
			mMovableRectangle->MouseMove(event);
		}
	}

	void Game::MouseDownEvent(SDL_Event *event)
	{
		if (mMovableRectangle)
		{
			mMovableRectangle->MouseDown(event);
		}
	}

	void Game::MouseUpEvent(SDL_Event *event)
	{
		if (mMovableRectangle)
		{
			mMovableRectangle->MouseUp(event);
		}
	}

	void Game::ScanCodeLeftDownEvent()
	{

	}

	void Game::ScanCodeRightDownEvent()
	{

	}

	void Game::ScanCodeLeftUpEvent()
	{

	}

	void Game::ScanCodeRightUpEvent()
	{

	}

}