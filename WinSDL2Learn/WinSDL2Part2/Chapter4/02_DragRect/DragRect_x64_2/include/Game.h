#ifndef _DUNGEON_GAME_H_
#define _DUNGEON_GAME_H_

#include <SDL2/SDL.h>
#include "RectShape.h"

namespace Dungeon
{
	class Game
	{
	private:
		SDL_Window *mWindow;//!< ������ *mWindow������
		bool mIsRunning;//!< ����״̬
		SDL_Renderer *mRenderer;
		RectShape *mFirst;
		RectShape *mLast;
		RectShape *mItem;

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

		void AddRectShape();
		void AddRectShape(RectShape *rectShape);
		void RectShapeDestory();
		void ProcessMouseEvent(SDL_Event *event);

	};
}

#endif // !_DUNGEON_GAME_H_

