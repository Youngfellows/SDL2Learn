#include "Game.h"
#include "Config.h"
#include "MovableRectangle.h"
#include "Cursor.h"
#include "Background.h"

namespace Dungeon
{
	Game::Game() :mIsRunning(true), mWindow(nullptr),
		mRenderer(nullptr), mMovableRectangle(nullptr),
		mResource(nullptr), mCursor(nullptr), mBackground(nullptr)
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

		// 加载资源
		mResource = new Resource();
		if (!mResource->load(mRenderer))
		{
			return false;
		}

		// 创建绘制组件
		if (!CreateComponents())
		{
			return false;
		}

		// 禁用默认光标
		SDL_ShowCursor(SDL_DISABLE);

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
			case SDL_MOUSEMOTION://鼠标移动事件
				MouseMoveEvent(&event);
				break;
			case SDL_MOUSEBUTTONDOWN://鼠标按下事件
				MouseDownEvent(&event);
				break;
			case SDL_MOUSEBUTTONUP://鼠标松开事件
				MouseUpEvent(&event);
				break;
			case SDL_MOUSEWHEEL://鼠标滚轮事件
				MouseWheelEvent(&event);
				break;
			case SDL_KEYDOWN://键盘按下事件
				KeyDownEvent(&event);
				break;
			case SDL_KEYUP://键盘松开事件
				KeyUpEvent(&event);
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
		// 创建可移动组件
		MovableRectangle *rect = new MovableRectangle();
		this->mMovableRectangle = rect->Create(
			START_X_POSITION, START_Y_POSITION, INNER_RECT_DEST_WIDTH, INNER_RECT_DEST_HEIGHT,
			INNER_RECT_FILL_COLOR, SDL_TRUE, INNER_RECT_BORDER_COLOR, PT_SIZE_5,
			BACKGROUND_RECT_DEST_WIDTH, BACKGROUND_RECT_DEST_HEIGHT, SPEED);

		if (!mMovableRectangle)
		{
			return SDL_FALSE;
		}

		// 创建光标组件
		Cursor *cursor = new Cursor();
		mCursor = cursor->Create(0, 0, CURSOR_DEST_RECT_WIDTH, CURSOR_DEST_RECT_HEIGHT);
		if (!mCursor)
		{
			return SDL_FALSE;
		}

		// 创建背景组件
		Background *background = new Background();
		mBackground = background->Create(START_X_POSITION, START_Y_POSITION, BACKGROUND_RECT_DEST_WIDTH,
			BACKGROUND_RECT_DEST_HEIGHT, BACKGROUND_RECT_FILL_COLOR, SDL_TRUE,
			BACKGROUND_RECT_BORDER_COLOR, PT_SIZE_20);
		if (!mBackground)
		{
			return SDL_FALSE;
		}

		return SDL_TRUE;
	}

	void Game::DrawComponents()
	{
		if (mBackground)
		{
			mBackground->Draw(mResource, mRenderer);
		}

		if (mMovableRectangle)
		{
			// 两种方式回调都可以
			mMovableRectangle->Draw(mResource, mRenderer);
			//mMovableRectangle->Draw2(nullptr,mRenderer);
		}

		if (mCursor)
		{
			mCursor->Draw(mResource, mRenderer);//绘制光标
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
		if (mCursor)
		{
			mCursor->Destory();
			delete mCursor;
			mCursor = nullptr;
		}
		if (mBackground)
		{
			mBackground->Destory();
			delete mBackground;
			mBackground = nullptr;
		}
	}

	void Game::MouseMoveEvent(SDL_Event *event)
	{
		if (mMovableRectangle)
		{
			mMovableRectangle->MouseMove(event);//可拖动矩形处理鼠标移动事件
		}
		if (mCursor)
		{
			mCursor->MouseMove(event);//光标处理鼠标移动时间
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
		if (mMovableRectangle)
		{
			mMovableRectangle->MouseDown(event);
		}
	}

	void Game::MouseUpEvent(SDL_Event *event)
	{
		SDL_MouseButtonEvent mouseButtonEvent = event->button;//鼠标按钮事件
		Uint8 button = mouseButtonEvent.button;
		switch (button)
		{
		case SDL_BUTTON_LEFT:
			SDL_Log("Up mouse left button");
			break;
		case SDL_BUTTON_RIGHT:
			SDL_Log("Up mouse right button");
			break;
		default:
			break;
		}
		if (mMovableRectangle)
		{
			mMovableRectangle->MouseUp(event);
		}
	}

	void Game::MouseWheelEvent(SDL_Event *event)
	{
		SDL_Log("Mouse whell scroll");
		if (mMovableRectangle)
		{
			mMovableRectangle->MouseWheelScroll(event);
		}
	}

	void Game::KeyDownEvent(SDL_Event *event)
	{
		SDL_Keycode keycode = event->key.keysym.sym;
		SDL_Scancode scancode = event->key.keysym.scancode;
		SDL_Log("KeyDown,keycode:%d,%c,scancode:%d", keycode, keycode, scancode);
		switch (scancode)
		{
		case SDL_SCANCODE_LEFT://按下左方向键
			SDL_Log("keydown left key");
			ScanCodeLeftKeyDownEvent();
			break;
		case SDL_SCANCODE_RIGHT://按下右方向键
			SDL_Log("keydown right key");
			ScanCodeRightKeyDownEvent();
			break;
		case SDL_SCANCODE_DOWN://按下下方向键
			SDL_Log("keydown down key");
			ScanCodeDownKeyDownEvent();
			break;
		case SDL_SCANCODE_UP://按下上方向键
			SDL_Log("keydown up key");
			ScanCodeUpKeyDownEvent();
			break;
		default:
			break;
		}
	}

	void Game::KeyUpEvent(SDL_Event *event)
	{
		SDL_Keycode keycode = event->key.keysym.sym;
		SDL_Scancode scancode = event->key.keysym.scancode;
		SDL_Log("KeyUp,keycode:%d,%c,scancode:%d", keycode, keycode, scancode);
		switch (scancode)
		{
		case SDL_SCANCODE_LEFT://松开左方向键
			SDL_Log("keyup left key");
			ScanCodeLeftKeyUpEvent();
			break;
		case SDL_SCANCODE_RIGHT://松开右方向键
			SDL_Log("keyup right key");
			ScanCodeRightKeyUpEvent();
			break;
		case SDL_SCANCODE_DOWN://松开下方向键
			SDL_Log("keyup down key");
			ScanCodeDownKeyUpEvent();
			break;
		case SDL_SCANCODE_UP://松开上方向键
			SDL_Log("keyup up key");
			ScanCodeUpKeyUpEvent();
			break;
		default:
			break;
		}
	}

	void Game::ScanCodeLeftKeyDownEvent()
	{
		if (mMovableRectangle)
		{
			mMovableRectangle->ScanCodeLeftKeyDown();
		}
	}

	void Game::ScanCodeRightKeyDownEvent()
	{
		if (mMovableRectangle)
		{
			mMovableRectangle->ScanCodeRightKeyDown();
		}
	}

	void Game::ScanCodeLeftKeyUpEvent()
	{
		if (mMovableRectangle)
		{
			mMovableRectangle->ScanCodeLeftKeyUp();
		}
	}

	void Game::ScanCodeRightKeyUpEvent()
	{
		if (mMovableRectangle)
		{
			mMovableRectangle->ScanCodeRightKeyUp();
		}
	}

	void Game::ScanCodeUpKeyDownEvent()
	{
		if (mMovableRectangle)
		{
			mMovableRectangle->ScanCodeUpKeyDown();
		}
	}

	void Game::ScanCodeDownKeyDownEvent()
	{
		if (mMovableRectangle)
		{
			mMovableRectangle->ScanCodeDownKeyDown();
		}
	}

	void Game::ScanCodeUpKeyUpEvent()
	{
		if (mMovableRectangle)
		{
			mMovableRectangle->ScanCodeUpKeyUp();
		}
	}

	void Game::ScanCodeDownKeyUpEvent()
	{
		if (mMovableRectangle)
		{
			mMovableRectangle->ScanCodeDownKeyUp();
		}
	}

}