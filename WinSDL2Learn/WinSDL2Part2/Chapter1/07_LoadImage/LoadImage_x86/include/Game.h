#ifndef _DUNGEON_GAME_H_
#define _DUNGEON_GAME_H_

namespace Dungeon
{
	class Game
	{
	private:
		class SDL_Window *mWindow;//!< ������ *mWindow������
		bool mIsRunning;//!< ����״̬
		class SDL_Surface *mScreen;//��ĻSurface
		class SDL_Surface *mImage;//ͼƬSurface

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

