﻿#include<Game.h>
#include "Setting.h"

namespace Dungeon
{
	Game::Game() :
		mWindow(nullptr),
		mRenderer(nullptr),
		mIsRunning(true),
		mTexture(nullptr)
	{

	}

	bool Game::Initialize()
	{
		// SDL库初始化
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
			return false;
		}

		// 窗口初始化
		//mWindow = SDL_CreateWindow("Dungeon", 400, 200, 640, 480, 0);
		mWindow = SDL_CreateWindow(Window::WINDOW_TITLE,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			Window::WINDOW_WIDTH, Window::WINDOW_HEIGHT,
			0);
		if (!mWindow)
		{
			SDL_Log("Failed to create window: %s", SDL_GetError());
			return false;
		}

		// 渲染器初始化
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
		if (!mRenderer)
		{
			SDL_Log("Failed to create renderer: %s", SDL_GetError());
			return false;
		}

		// 初始化SDL_image库
		if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
		{
			SDL_Log("Failed to initialize SDL_image: %s", SDL_GetError());
			return false;
		}

		// 加载数据
		LoadData();

		return true;
	}

	void Game::Loop()
	{
		while (mIsRunning)
		{
			Event();
			Update();
			Draw();
		}
	}

	void Game::Shutdown()
	{
		UnloadData();
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
		IMG_Quit();
	}

	void Game::Event()
	{
		SDL_Event event;
		// 如果事件队列中有未处理的事件，按顺序处理
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				// 退出事件，按下窗口的叉
			case SDL_QUIT:
				mIsRunning = false;
				break;
			default:
				break;
			}
		}
	}

	void Game::Update()
	{
		SDL_Delay(10);
	}

	void Game::Draw()
	{
		// 设置渲染器颜色（蓝）
		SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255);

		// 清除缓冲区
		SDL_RenderClear(mRenderer);

		// 绘制图片
		DrawImage();

		// 交换缓冲区
		SDL_RenderPresent(mRenderer);
	}

	void Game::DrawImage()
	{
		// 获取贴图的宽和高
		int textureW;
		int textureH;
		SDL_QueryTexture(mTexture, nullptr, nullptr, &textureW, &textureH);

		// 截取原图片（这里是完整截取）,如果图片太大,显示会超出Window窗口
		SDL_Rect imageRect{ 0, 0, textureW, textureH };

		// 截取图片,从左上角(100,100)开始截取150*200
		//SDL_Rect imageRect{ 100, 100, 150, 200 };

		// 图片目的地
		SDL_Rect dstRect{ 50, 50, 150, 200 };//显示为150*200
		//SDL_Rect dstRect{ 50, 50, textureW, textureH };//原图显示

		// 将截取好的图片拷贝并填充至目的地的长方形中
		SDL_RenderCopy(mRenderer, mTexture, &imageRect, &dstRect);//显示截取的部分

		//SDL_RenderCopy(mRenderer, mTexture, nullptr, &dstRect);//完全显示,会缩放
	}

	void Game::LoadData()
	{
		LoadTexture(Dungeon::Resources::JPG_YAYA_FILE_NAME);
	}

	void Game::UnloadData()
	{
		SDL_DestroyTexture(mTexture);
	}

	void Game::LoadTexture(const std::string fileName)
	{
		// 清空当前贴图，防止重复读取时内存泄漏
		if (mTexture)
		{
			SDL_DestroyTexture(mTexture);
		}

		// 读取图片存为surface形式
		SDL_Surface *surf = IMG_Load(fileName.c_str());
		if (!surf)
		{
			SDL_Log("Failed to load texture file %s", fileName.c_str());
		}

		// 将surface转换为texture形式
		SDL_Texture *tex = SDL_CreateTextureFromSurface(mRenderer, surf);
		// 释放surface的内存
		SDL_FreeSurface(surf);
		if (!tex)
		{
			SDL_Log("Failed to convert surface to texture for %s", fileName.c_str());
		}

		mTexture = tex;
	}
}