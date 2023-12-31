﻿#ifndef __Dungeon_Game__
#define __Dungeon_Game__

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace Dungeon
{
	class Game
	{
	private:
		std::vector<class GameObject *> mGameObjects;//!<游戏物体容器
		std::vector<class GameObject *> mPendingObjects;//!<等待状态的游戏物体容器
		SDL_Window *mWindow;//!<窗口
		SDL_Renderer *mRenderer;//!<渲染器
		bool mIsRunning;//!< 运行状态
		bool mIsUpdating;//!<是否在更新状态
		SDL_Texture *mTexture;//!<图片

	public:
		//!	构造函数
		Game();

		//!	初始化
		bool Initialize();
		//!	主循环
		void Loop();
		//!	游戏结束
		void Shutdown();

		//! 创建并存储游戏物体
		void CreateGameObject(class GameObject *gameObject);
		//! 移除游戏对象
		void RemoveGameObject(class GameObject *gameObject);

	private:
		//!	处理事件
		void Event();
		//!	更新各种状态
		void Update();
		//!	渲染
		void Draw();

		//! 加载数据
		void LoadData();
		//!	释放数据
		void UnloadData();
		//!	加载贴图
		void LoadTexture(const std::string fileName);

		//! 绘制图片
		void DrawImage();
	};
}

#endif	// __Dungeon_Game__