#ifndef _DUNGEON_GAME_H_
#define _DUNGEON_GAME_H_

#include <SDL2/SDL.h>
#include "Cursor.h"
#include "Resource.h"

namespace Dungeon
{
	class Game
	{
	private:
		class SDL_Window *mWindow;//!< ������ *mWindow������
		bool mIsRunning;//!< ����״̬
		SDL_Renderer *mRenderer;
		Cursor *mCursor;
		Resource *mResource;

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

