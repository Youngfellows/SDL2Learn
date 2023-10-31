#include "Game.h"
#include "Config.h"
#include "Rectangle.h"
#include "EventListener.h"

namespace Dungeon
{
	Game::Game() :mIsRunning(true), mWindow(nullptr),
		mRenderer(nullptr), mComponents(nullptr), mResource(nullptr)
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

		//加载资源
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
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
		SDL_Log("Shutdown");
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
			case SDL_MOUSEBUTTONDOWN://鼠标按钮按下事件
				MouseDownEvent(&event);
				break;
			case SDL_MOUSEBUTTONUP://鼠标按钮按键松开
				MouseUpEvent(&event);
				break;
			case SDL_MOUSEMOTION://鼠标移动事件
				MouseMoveEvent(&event);
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
		//创建指针数组
		//this->mComponents = (DisplayObject **)malloc(sizeof(DisplayObject *) * COMPONENT_SIZE);//C方式
		this->mComponents = new DisplayObject * [COMPONENT_SIZE];//C++方式

		Rectangle *rectangle = new Rectangle();//矩形组件
		mComponents[0] = rectangle->Create(RECT_START_X, RECT_START_Y, RECT_WIDTH, RECT_HEIGHT
			, RECT_COLOR, RECT_BORDER_COLOR, PT_SIZE_25, &Dungeon::EventListener::OnClickRect);
		if (!mComponents[0])
		{
			return SDL_FALSE;
		}

		return SDL_TRUE;
	}

	void Game::DrawComponents()
	{
		if (!mComponents)
		{
			SDL_Log("Game::DrawComponents():: mComponents is null");
			return;
		}
		for (int i = 0; i < COMPONENT_SIZE; i++)
		{
			//DisplayObject *component = mComponents[i];//获取数组元素
			DisplayObject *component = *(mComponents + i);//获取数组元素
			component->Draw(mResource, mRenderer);//绘制组件
		}
	}

	void Game::FreeComponents()
	{
		if (!mComponents)
		{
			SDL_Log("Game::FreeComponents():: mComponents is null");
			return;
		}
		for (int i = 0; i < COMPONENT_SIZE; i++)
		{
			//DisplayObject *component = mComponents[i];//获取数组元素
			DisplayObject *component = *(mComponents + i);//获取数组元素
			component->Destory();//释放组件资源
		}
		delete[] mComponents;//删除二维数组
		mComponents = nullptr;
	}

	void Game::MouseMoveEvent(SDL_Event *event)
	{
		if (!mComponents)
		{
			SDL_Log("Game::MouseMoveEvent():: mComponents is null");
			return;
		}
		for (int i = 0; i < COMPONENT_SIZE; i++)
		{
			//DisplayObject *component = mComponents[i];//获取数组元素
			DisplayObject *component = *(mComponents + i);//获取数组元素
			component->MouseMove(event);//传递鼠标移动事件给各个组件
		}
	}

	void Game::MouseDownEvent(SDL_Event *event)
	{
		SDL_MouseButtonEvent mouseButtonEvent = event->button;//鼠标按钮事件
		Uint8 button = mouseButtonEvent.button;
		switch (button)
		{
		case SDL_BUTTON_LEFT:
			SDL_Log("Game::MouseDownEvent:: Down mouse left button");
			break;
		case SDL_BUTTON_RIGHT:
			SDL_Log("Game::MouseDownEvent:: Down mouse right button");
			break;
		default:
			break;
		}
		if (!mComponents)
		{
			SDL_Log("Game::MouseMoveEvent():: mComponents is null");
			return;
		}
		for (int i = 0; i < COMPONENT_SIZE; i++)
		{
			//DisplayObject *component = mComponents[i];//获取数组元素
			DisplayObject *component = *(mComponents + i);//获取数组元素
			component->MouseDown(event);//传递按下鼠标事件给各个组件
		}
	}

	void Game::MouseUpEvent(SDL_Event *event)
	{
		SDL_MouseButtonEvent mouseButtonEvent = event->button;//鼠标按钮事件
		Uint8 button = mouseButtonEvent.button;
		switch (button)
		{
		case SDL_BUTTON_LEFT:
			SDL_Log("Game::MouseDownEvent:: Up mouse left button");
			break;
		case SDL_BUTTON_RIGHT:
			SDL_Log("Game::MouseDownEvent:: Up mouse right button");
			break;
		default:
			break;
		}
		if (!mComponents)
		{
			SDL_Log("Game::MouseMoveEvent():: mComponents is null");
			return;
		}
		for (int i = 0; i < COMPONENT_SIZE; i++)
		{
			//DisplayObject *component = mComponents[i];//获取数组元素
			DisplayObject *component = *(mComponents + i);//获取数组元素
			component->MouseUp(event);//传递按下鼠标事件给各个组件
		}
	}
}