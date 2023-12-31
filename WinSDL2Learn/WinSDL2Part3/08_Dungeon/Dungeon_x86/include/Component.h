﻿#ifndef __Dungeon_Component__
#define __Dungeon_Component__

#include <string>
#include <vector>

namespace Dungeon
{
	class GameObject;

	class Component
	{
	protected:
		GameObject *mGameObject;//!<自身附着的游戏物体
		int	mUpdateOrder;//!<更新顺序

	public:
		//! 构造函数
		Component(class GameObject *gameObject);
		//! 析构函数
		virtual ~Component();

		//! 处理输入
		virtual void ProcessInput(const uint8_t *state);
		//! 每帧更新
		virtual void Update();

		//! 更新顺序的get和set
		int GetUpdateOrder() const;
		void SetUpdateOrder(int order);
		//! 游戏物体的get
		GameObject *GetGameObject();
	};
}

#endif	// __Dungeon_Component__