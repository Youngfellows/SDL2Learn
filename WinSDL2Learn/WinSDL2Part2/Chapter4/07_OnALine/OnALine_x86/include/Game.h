#ifndef _DUNGEON_GAME_H_
#define _DUNGEON_GAME_H_

#include <SDL2/SDL.h>
#include "Resource.h"
#include "DisplayObject.h"

namespace Dungeon
{
	class Game
	{
	private:
		SDL_Window *mWindow;//!< ������ *mWindow������
		bool mIsRunning;//!< ����״̬
		SDL_Renderer *mRenderer;
		Resource *mResource;
		DisplayObject *mCursor;//���
		DisplayObject *mSliderBar;//����

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

		//���������
		SDL_bool CreateComponents();

		//! �ͷ������Դ
		void FreeComponents();

		//! �������
		void DrawComponents();

		//! �������ƶ��¼�
		void ProcessMouseMoveEvent(SDL_Event *event);
	};
}

#endif // !_DUNGEON_GAME_H_

