#ifndef _DUNGEON_GAME_H_
#define _DUNGEON_GAME_H_

#include "SDL2/SDL.h"
#include "Eyeball.h"
#include "Resource.h"

namespace Dungeon
{
	class Game
	{
	private:
		SDL_Window *mWindow;//!< ������ *mWindow������
		bool mIsRunning;//!< ����״̬
		SDL_Renderer *mRenderer;
		Resource *mResource;
		DisplayObject *mLeftEye;
		DisplayObject *mRightEye;

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

		// ! �������(����)
		SDL_bool CreateComponents();

		// ! �ͷ����(����)
		void FreeComponents();

		void ProcessMouseEvent(SDL_Event *event);
	};
}

#endif // !_DUNGEON_GAME_H_

