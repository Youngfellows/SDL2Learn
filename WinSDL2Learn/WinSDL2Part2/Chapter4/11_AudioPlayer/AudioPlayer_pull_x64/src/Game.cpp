#include "Game.h"
#include "Config.h"
#include "Text.h"
#include "ComponentCallback.h"

namespace Dungeon
{
	Game::Game() :mIsRunning(true), mWindow(nullptr),
		mRenderer(nullptr), mResource(nullptr), mComponents(nullptr)
	{
	}

	Game::~Game()
	{
		SDL_Log("~Game()");
		Shutdown();
	}

	bool Game::Initialize()
	{
		// 初始化TTF字体库
		if (TTF_Init() != 0)
		{
			SDL_Log("Can not init ttf: %s", SDL_GetError());
			return false;
		}


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

		// 加载资源
		mResource = new Resource();
		if (!mResource->Load(mRenderer))
		{
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
		if (mResource)
		{
			mResource->Unload();
			delete mResource;
			mResource = nullptr;
		}
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
			case SDL_MOUSEBUTTONDOWN://鼠标按下事件
				MouseDownEvent(&event);
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
		mComponents = new DisplayObject * [COMPONENT_SIZE];//分配指针数组

		//添加回调函数组件
		ComponentCallback *callbackComponent = new ComponentCallback();
		mComponents[0] = callbackComponent->Create();
		if (!mComponents[0])
		{
			return SDL_FALSE;
		}

		//添加文本显示组件
		Text *start = new Text();
		mComponents[1] = start->Create(FONT_FINE_NAME, START_TEXT, PT_SIZE_25,
			COLOR_TEXT, START_TEXT_X_POSITION, START_TEXT_Y_POSITION,
			BG_COLOR_TEXT, PADDING_LEFT, PADDING_RIGHT, PADDING_TOP, PADDING_BOTTOM, 
			mComponents[0], 1, { &ComponentCallback::OnStartTextClickCallback });
		if (!mComponents[1])
		{
			return SDL_FALSE;
		}
		

		Text *pause = new Text();
		mComponents[2] = pause->Create(FONT_FINE_NAME, PAUSE_TEXT, PT_SIZE_25,
			COLOR_TEXT, PAUSE_TEXT_X_POSITION, PAUSE_TEXT_Y_POSITION,
			BG_COLOR_TEXT, PADDING_LEFT, PADDING_RIGHT, PADDING_TOP, PADDING_BOTTOM, 
			mComponents[0], 1, { &ComponentCallback::OnPauseTextClickCallback });
		if (!mComponents[2])
		{
			return SDL_FALSE;
		}

		Text *reStar = new Text();
		mComponents[3] = reStar->Create(FONT_FINE_NAME, RE_START_TEXT, PT_SIZE_25,
			COLOR_TEXT, RE_START_TEXT_X_POSITION, RE_START_TEXT_Y_POSITION,
			BG_COLOR_TEXT, PADDING_LEFT, PADDING_RIGHT, PADDING_TOP, PADDING_BOTTOM, 
			mComponents[0], 1, { &ComponentCallback::OnReStartTextClickCallback });
		if (!mComponents[3])
		{
			return SDL_FALSE;
		}

		Text *stop = new Text();
		mComponents[4] = stop->Create(FONT_FINE_NAME, STOP_TEXT, PT_SIZE_25,
			COLOR_TEXT, STOP_TEXT_X_POSITION, STOP_TEXT_Y_POSITION,
			BG_COLOR_TEXT, PADDING_LEFT, PADDING_RIGHT, PADDING_TOP, PADDING_BOTTOM, 
			mComponents[0], 1, { &ComponentCallback::OnStopTextClickCallback });
		if (!mComponents[4])
		{
			return SDL_FALSE;
		}

		Text *state = new Text();
		mComponents[5] = state->Create(FONT_FINE_NAME, STATE_TEXT, PT_SIZE_25,
			STATE_COLOR_TEXT, STATE_TEXT_X_POSITION, STATE_TEXT_Y_POSITION,
			STATE_BG_COLOR_TEXT, PADDING_LEFT, PADDING_RIGHT, PADDING_TOP, PADDING_BOTTOM, 
			nullptr, 0, {});
		if (!mComponents[5])
		{
			return SDL_FALSE;
		}
		//callbackComponent->SetStateText(state);//设置stateText文本指针给组件

		return SDL_TRUE;
	}

	void Game::DrawComponents()
	{
		//SDL_Log("Game::DrawComponents");
		if (mComponents)
		{
			for (int i = 0; i < COMPONENT_SIZE; i++)
			{
				DisplayObject *component = mComponents[i];//获取指针数组元素
				if (component)
				{
					component->Draw(nullptr, mRenderer);//绘制各个组件
				}
			}
		}
	}

	void Game::FreeComponents()
	{
		//SDL_Log("Game::FreeComponents");
		if (mComponents)
		{
			for (int i = 0; i < COMPONENT_SIZE; i++)
			{
				DisplayObject *component = mComponents[i];//获取指针数组元素
				if (component)
				{
					component->Destory();//释放各个组件资源
				}
			}
		}
	}

	void Game::MouseDownEvent(SDL_Event *event)
	{
		SDL_MouseButtonEvent mouseButtonEvent = event->button;//鼠标按钮事件
		Uint8 button = mouseButtonEvent.button;
		switch (button)
		{
		case SDL_BUTTON_LEFT:
			SDL_Log("Down mouse left button");
			break;
		case SDL_BUTTON_RIGHT:
			SDL_Log("Down mouse right button");
			break;
		default:
			break;
		}
		if (mComponents)
		{
			for (int i = 0; i < COMPONENT_SIZE; i++)
			{
				DisplayObject *component = mComponents[i];//获取指针数组元素
				if (component)
				{
					component->MouseDown(event);//传递鼠标按下事件给各个组件
				}
			}
		}
	}
}