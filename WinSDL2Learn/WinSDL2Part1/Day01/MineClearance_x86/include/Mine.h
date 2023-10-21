#ifndef _DUNGEON_MINE_H_
#define _DUNGEON_MINE_H_

#include <cstdlib>
#include <ctime>
#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Resource.h"

namespace Dungeon
{
	/*
	* ��������
	*/
	typedef struct MineData
	{
		SDL_FRect *dest;//��ʾλ��
		SDL_bool visible;//�Ƿ�ɼ�
	};

	/*
	* �׳�����
	*/
	typedef struct MinefieldData
	{
		SDL_FRect *boundry;//�׳��߽�
		MineData **mines;//Ҫ��ʾ���׸���
		int amount;//ɨ�����׸���
		int size;//������
	}MinefieldData;
}

namespace Dungeon
{
	class Mine
	{
	private:
		MinefieldData *mMinefieldData;

	public:
		Mine();
		~Mine();
		DisplayObject *Create(float x, float y, float w, float h, int size,
			float mineWidth, float mineHeight);
		static void OnDrawCallback(DisplayObject *self, Resource *resource,
			SDL_Renderer *renderer);//���ƻص�
		static void OnDestoryCallback(DisplayObject *self);
		static void OnPlayerMoveCallback(void *position);//����ƶ��ص�

	private:
		void CreateMins();//��������
	};

}

#endif // !_DUNGEON_MINE_H_

