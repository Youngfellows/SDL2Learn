#include "Game.h"
#include "Config.h"
#include "Player.h"
#include "Cursor.h"
#include "Background.h"
#include "Mine.h"
#include "Text.h"
#include "Ground.h"

namespace Dungeon
{
	Game::Game() :mIsRunning(true), mWindow(nullptr),
		mRenderer(nullptr), mPlayer(nullptr),
		mResource(nullptr), mCursor(nullptr), mBackground(nullptr),
		mMine(nullptr), mStartText(nullptr), mMsgText(nullptr)
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

		// 初始化SDL_image
		if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_WEBP))
		{
			SDL_Log("Can not init SDL_image: %s", SDL_GetError());
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
		IMG_Quit();
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
		Player *player = new Player();
		this->mPlayer = player->Create(
			START_X_POSITION, START_Y_POSITION, INNER_RECT_DEST_WIDTH, INNER_RECT_DEST_HEIGHT,
			INNER_RECT_FILL_COLOR, SDL_FALSE, INNER_RECT_BORDER_COLOR, PT_SIZE_5,
			BACKGROUND_RECT_DEST_WIDTH, BACKGROUND_RECT_DEST_HEIGHT, SPEED);

		if (!mPlayer)
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

		// 创建雷组件
		Mine *mine = new Mine();
		mMine = mine->Create(START_X_POSITION, START_Y_POSITION,
			MINE_FIELD_WIDTH, MINE_FIELD_HEIGHT, MINE_SIZE, MINE_DEST_RECT_WIDTH,
			MINE_DEST_RECT_HEIGHT);
		if (!mMine)
		{
			return SDL_FALSE;
		}
		// 设置玩家位置更新回调,重要
		mPlayer->SetOnPlayerMoveCallback(mMine, &Mine::OnPlayerPosChangeCallback);

		// 字体组件
		Text *starText = new Text();
		mStartText = starText->Create(FONT_FINE_NAME, START_TEXT, PT_SIZE_25,
			COLOR_START_TEXT, START_TEXT_X_POSITION, START_TEXT_Y_POSITION,
			BG_COLOR_START_TEXT, PADDING_LEFT, PADDING_TOP, PADDING_RIGHT, PADDING_BOTTOM,
			mMine, 2, { &Mine::OnTextClickCallback,&Player::OnTextClickCallback });//设置回调
		if (!mStartText)
		{
			return SDL_FALSE;
		}

		Text *msgText = new Text();
		mMsgText = msgText->Create(FONT_FINE_NAME, ELIMINATE_TEXT, PT_SIZE_25,
			COLOR_MSG_TEXT, MSG_TEXT_X_POSITION, MSG_TEXT_Y_POSITION,
			BG_COLOR_MSG_TEXT, PADDING_LEFT, PADDING_TOP, PADDING_RIGHT, PADDING_BOTTOM,
			nullptr, 0, {});//设置回调
		if (!mMsgText)
		{
			return SDL_FALSE;
		}

		// 设置text文本对象
		mine->SetTextComponents(mStartText, mMsgText);

		Ground *ground = new Ground();//场地1
		mGround1 = ground->Create(0, 0,
			WINDOW_WIDTH, WINDOW_HEIGHT,
			GROUND_X_TILE_SIZE, GROUND_Y_TILE_SIZE,
			mResource->GetGroundTexture());
		if (!mGround1)
		{
			return SDL_FALSE;
		}

		Ground *wall = new Ground();//场地2
		mGround2 = wall->Create(
			WALL_START_X_POSITION, WALL_START_Y_POSITION,
			WALL_WIDTH, WALL_HEIGHT,
			WALL_X_TILE_SIZE, WALL_X_TILE_SIZE,
			mResource->GetWallTexture());
		if (!mGround1)
		{
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	void Game::DrawComponents()
	{
		if (mGround1)
		{
			mGround1->Draw(mResource, mRenderer);
		}

		if (mGround2)
		{
			mGround2->Draw(mResource, mRenderer);
		}

		if (mBackground)
		{
			mBackground->Draw(mResource, mRenderer);
		}

		if (mMine)
		{
			mMine->Draw(mResource, mRenderer);//绘制雷
		}

		if (mPlayer)
		{
			// 两种方式回调都可以
			mPlayer->Draw(mResource, mRenderer);
			//mMovableRectangle->Draw2(nullptr,mRenderer);
		}

		if (mStartText)
		{
			mStartText->Draw(mResource, mRenderer);//绘制文字
		}
		if (mMsgText)
		{
			mMsgText->Draw(mResource, mRenderer);//绘制文字
		}

		if (mCursor)
		{
			mCursor->Draw(mResource, mRenderer);//绘制光标
		}

	}

	void Game::FreeComponents()
	{
		SDL_Log("Game:: FreeComponents");
		if (mGround2)
		{
			mGround2->Destory();
			delete mGround2;
			mGround2 = nullptr;
		}
		if (mGround1)
		{
			mGround1->Destory();
			delete mGround1;
			mGround1 = nullptr;
		}
		if (mPlayer)
		{
			mPlayer->Destory();
			delete mPlayer;
			mPlayer = nullptr;
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
		if (mMine)
		{
			mMine->Destory();
			delete mMine;
			mMine = nullptr;
		}
		if (mStartText)
		{
			mStartText->Destory();
			delete mStartText;
			mStartText = nullptr;
		}

		if (mMsgText)
		{
			mMsgText->Destory();
			delete mMsgText;
			mMsgText = nullptr;
		}
	}

	void Game::MouseMoveEvent(SDL_Event *event)
	{
		if (mPlayer)
		{
			mPlayer->MouseMove(event);//可拖动矩形处理鼠标移动事件
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
		if (mPlayer)
		{
			mPlayer->MouseDown(event);
		}
		if (mStartText)
		{
			mStartText->MouseDown(event);
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
		if (mPlayer)
		{
			mPlayer->MouseUp(event);
		}
	}

	void Game::MouseWheelEvent(SDL_Event *event)
	{
		SDL_Log("Mouse whell scroll");
		if (mPlayer)
		{
			mPlayer->MouseWheelScroll(event);
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
		if (mPlayer)
		{
			mPlayer->ScanCodeLeftKeyDown();
		}
	}

	void Game::ScanCodeRightKeyDownEvent()
	{
		if (mPlayer)
		{
			mPlayer->ScanCodeRightKeyDown();
		}
	}

	void Game::ScanCodeLeftKeyUpEvent()
	{
		if (mPlayer)
		{
			mPlayer->ScanCodeLeftKeyUp();
		}
	}

	void Game::ScanCodeRightKeyUpEvent()
	{
		if (mPlayer)
		{
			mPlayer->ScanCodeRightKeyUp();
		}
	}

	void Game::ScanCodeUpKeyDownEvent()
	{
		if (mPlayer)
		{
			mPlayer->ScanCodeUpKeyDown();
		}
	}

	void Game::ScanCodeDownKeyDownEvent()
	{
		if (mPlayer)
		{
			mPlayer->ScanCodeDownKeyDown();
		}
	}

	void Game::ScanCodeUpKeyUpEvent()
	{
		if (mPlayer)
		{
			mPlayer->ScanCodeUpKeyUp();
		}
	}

	void Game::ScanCodeDownKeyUpEvent()
	{
		if (mPlayer)
		{
			mPlayer->ScanCodeDownKeyUp();
		}
	}

}