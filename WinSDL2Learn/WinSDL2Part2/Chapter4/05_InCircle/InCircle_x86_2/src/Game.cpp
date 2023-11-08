
#include "Game.h"

namespace Dungeon
{
#define WINDOW_WIDTH 600
#define WINDOW_WIDTH 500
#define FRAMERATE 60

	Game::Game() : mWindow(nullptr), mIsRunning(true), mRenderer(nullptr),
		mResource(nullptr), mLeftEye(nullptr), mRightEye(nullptr)
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
		mWindow = SDL_CreateWindow("Dungeon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_WIDTH, SDL_WINDOW_SHOWN);
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
		if (!mResource->Resource_Load(mRenderer))
		{
			return false;
		}
		CreateComponents();
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
				ProcessMouseEvent(&event);
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
		SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 2555);
		SDL_RenderClear(mRenderer);
		if (mLeftEye)
		{
			mLeftEye->DisplayObject_Draw(mResource, mRenderer);//绘制左眼
		}
		if (mRightEye)
		{
			mRightEye->DisplayObject_Draw(mResource, mRenderer);//绘制右眼
		}

		SDL_RenderPresent(mRenderer);
	}

	SDL_bool Game::CreateComponents()
	{
		Eyeball *leftEyeball = new Eyeball();
		Eyeball *rightEyeball = new Eyeball();
		mLeftEye = leftEyeball->Eyeball_Create(100, 100);
		mRightEye = rightEyeball->Eyeball_Create(160, 100);
		if (!mLeftEye || !mRightEye)
		{
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	void Game::FreeComponents()
	{
		if (mLeftEye)
		{
			mLeftEye->DisplayObject_Destory();
		}
		if (mRightEye)
		{
			mRightEye->DisplayObject_Destory();
		}
	}

	void Game::ProcessMouseEvent(SDL_Event *event)
	{
		if (mLeftEye)
		{
			mLeftEye->DisplayObject_OnMouseMove(event);
		}
		if (mRightEye)
		{
			mRightEye->DisplayObject_OnMouseMove(event);
		}
	}
}