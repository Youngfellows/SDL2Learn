#include "Game.h"
#include "Config.h"
#include "Rectangle.h"
#include "EventListener.h"
#include "NoSignal.h"
#include "Photo.h"
#include "Text.h"
#include "SDL2/SDL_ttf.h"
#include <string>
#include "StarlitSky.h"
#include "Line.h"
#include "BrokenLine.h"

namespace Dungeon
{
	Game::Game() :mIsRunning(true), mWindow(nullptr),
		mRenderer(nullptr), mComponents(nullptr),
		mResource(nullptr), mFrames(0), mLastTicks(0)
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

			//没多大意义,只是为了更新title
			mFrames++;
			current = SDL_GetTicks();
			if (mFrames % 30 == 0)
			{
				Uint32 fps = 1000 / (current - mLastTicks);//按这个速度计算帧率
				std::string fpsStr = "Rendering ";
				fpsStr += std::to_string(BUBBLE_COUNT);
				fpsStr += " points, fps: ";
				fpsStr += std::to_string(fps);
				SDL_SetWindowTitle(mWindow, fpsStr.c_str());
			}
			mLastTicks = current;
		}
	}
	void Game::Shutdown()
	{
		FreeComponents();
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

		//NoSignal *noSignal = new NoSignal();//电视无信号组件
		//mComponents[0] = noSignal->Create(WINDOW_WIDTH, WINDOW_HEIGHT);
		//if (!mComponents[0])
		//{
		//	return SDL_FALSE;
		//}

		StarlitSky *starlitSky = new StarlitSky();//星空组件
		mComponents[0] = starlitSky->Create(mResource, BUBBLE_COUNT, STARLITSKY_COLOR, STARLITSKY_BACKGROUND_COLOR,
			STARLITSKY_START_X, STARLITSKY_START_Y, STARLITSKY_WIDTH, STARLITSKY_HEIGHT);
		if (!mComponents[0])
		{
			return SDL_FALSE;
		}

		Photo *cat = new Photo();//图片组件
		mComponents[1] = cat->Create(PHOTO_CAT_START_X, PHOTO_CAT_START_Y, PHOTO_CAT_WIDTH, PHOTO_CAT_HEIGHT,
			mResource->GetCatTexture(), &Dungeon::EventListener::OnClickCat);
		if (!mComponents[1])
		{
			return SDL_FALSE;
		}

		Photo *girl = new Photo();
		mComponents[2] = girl->Create(PHOTO_GIRL_START_X, PHOTO_GIRL_START_Y, PHOTO_GIRL_WIDTH, PHOTO_GIRL_HEIGHT,
			mResource->GetGirlTexture(), &Dungeon::EventListener::OnClickGirl);
		if (!mComponents[2])
		{
			return SDL_FALSE;
		}

		Text *text1 = new Text();//文本组件
		mComponents[3] = text1->Create(FONT_FILE, TEXT_1, PT_SIZE_30, TEXT_COLOR,
			TEXT_1_X_POSITION, TEXT_1_Y_POSITION, TEXT_BACKGROUND_COLOR,
			PADDING_LEFT, PADDING_TOP, PADDING_RIGHT, PADDING_BOTTOM,
			mComponents[1], 1, { &Dungeon::EventListener::OnClickText1 });
		if (!mComponents[3])
		{
			return SDL_FALSE;
		}

		Text *text2 = new Text();//文本组件
		mComponents[4] = text2->Create(FONT_FILE, TEXT_2, PT_SIZE_30, TEXT_COLOR,
			TEXT_2_X_POSITION, TEXT_2_Y_POSITION, TEXT_BACKGROUND_COLOR,
			PADDING_LEFT, PADDING_TOP, PADDING_RIGHT, PADDING_BOTTOM,
			mComponents[2], 1, { &Dungeon::EventListener::OnClickText2 });
		if (!mComponents[4])
		{
			return SDL_FALSE;
		}

		Rectangle *rectangle = new Rectangle();//矩形组件
		mComponents[5] = rectangle->Create(RECT_START_X, RECT_START_Y, RECT_WIDTH, RECT_HEIGHT
			, RECT_COLOR, RECT_BORDER_COLOR, PT_SIZE_25, mComponents[0], &Dungeon::EventListener::OnClickRect);
		if (!mComponents[5])
		{
			return SDL_FALSE;
		}

		Line *line = new Line();//直线组件
		SDL_FPoint start;
		start.x = POINT_1_X;
		start.y = POINT_1_Y;
		SDL_FPoint end;
		end.x = POINT_2_X;
		end.y = POINT_2_Y;
		mComponents[6] = line->Create(LINE_1_COLOR, start, end);
		if (!mComponents[6])
		{
			return SDL_FALSE;
		}

		BrokenLine *brokenLine = new BrokenLine();//折线组件
		mComponents[7] = brokenLine->Create(LINE_4_COLOR, 5,
			{ {POINT_1_X,POINT_1_Y},
			{POINT_3_X,POINT_3_Y},
			{POINT_4_X,POINT_4_Y},
			{POINT_5_X,POINT_5_Y},
			{POINT_6_X,POINT_6_Y},
			});
		if (!mComponents[7])
		{
			return SDL_FALSE;
		}

		Rectangle *rectangle2 = new Rectangle();//矩形组件
		mComponents[8] = rectangle2->Create(RECT_1_START_X, RECT_1_START_Y, RECT_1_WIDTH, RECT_1_HEIGHT
			, RECT_1_COLOR, RECT_1_BORDER_COLOR, PT_SIZE_25, mComponents[0], &Dungeon::EventListener::OnClickRect);
		if (!mComponents[8])
		{
			return SDL_FALSE;
		}

		Text *text3 = new Text();//文本组件
		mComponents[9] = text3->Create(FONT_FILE, TEXT_3, PT_SIZE_30, TEXT_COLOR,
			TEXT_3_X_POSITION, TEXT_3_Y_POSITION, TEXT_BACKGROUND_COLOR,
			PADDING_LEFT, PADDING_TOP, PADDING_RIGHT, PADDING_BOTTOM,
			mComponents[2], 1, { &Dungeon::EventListener::OnClickText3 });
		if (!mComponents[9])
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
			SDL_Log("Game::FreeComponents():: i:%d", i);
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