#ifndef _DUNGEON_GAME_H_
#define _DUNGEON_GAME_H_

#include <SDL2/SDL.h>

namespace Dungeon
{
	class Game
	{
	private:
		SDL_Window *mWindow;//!< ������ *mWindow������
		bool mIsRunning;//!< ����״̬
		SDL_Renderer *mRenderer;

	public:
		//! ���캯��
		Game();

		//! ��ʼ��
		bool Initialize();

		//! ��ѭ��
		void Loop();

		//! ��Ϸ����
		void Shutdown();

	private:
		//! �����¼�
		void Event();

		//! ���¸���״̬
		void Update(long delay);

		//! ��Ⱦ
		void Draw();
	};
}

#endif // !_DUNGEON_GAME_H_

