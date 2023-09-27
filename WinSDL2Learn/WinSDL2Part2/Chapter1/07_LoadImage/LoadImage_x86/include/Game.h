#ifndef _DUNGEON_GAME_H_
#define _DUNGEON_GAME_H_

namespace Dungeon
{
	class Game
	{
	private:
		class SDL_Window *mWindow;//!< 先声明 *mWindow，窗口
		bool mIsRunning;//!< 运行状态
		class SDL_Surface *mScreen;//屏幕Surface
		class SDL_Surface *mImage;//图片Surface

	public:
		//! 构造函数
		Game();

		//! 初始化
		bool Initialize();

		//! 主循环
		void Loop();

		//! 游戏结束
		void Shutdown();

	private:
		//! 处理事件
		void Event();

		//! 更新各种状态
		void Update(long delay);

		//! 渲染
		void Draw();
	};
}

#endif // !_DUNGEON_GAME_H_

