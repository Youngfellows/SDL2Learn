#ifndef _DUNGEON_DISPLAYOBJECT_H_
#define _DUNGEON_DISPLAYOBJECT_H_

#include "SDL2/SDL.h"
#include "Resource.h"
#include "Cursor.h"
#include "RectInRect.h"

namespace Dungeon
{
	class Cursor;//��������
	class RectInRect;//��������

	/*
	* ���ַ�ʽ������,������ϵ̫ǿ��,û������������������
	*/
	class DisplayObject
	{
	private:
		Cursor *mCursor;//������
		RectInRect *mRectInRect;//�ھ��ζ���

	public:
		DisplayObject();
		~DisplayObject();
		SDL_bool CreateComponents();
		void Destory();
		void Draw(Resource *resource, SDL_Renderer *renderer);
		void OnMouseMove(SDL_Event *event);

	private:
		void SetCursor(Cursor *cursor);
		void SetRectInRect(RectInRect *rectInRect);
		void DrawCursor(Resource *resource, SDL_Renderer *renderer);
		void CursorOnMouseMove(SDL_Event *event);
		void DrawRectInRect(Resource *resource, SDL_Renderer *renderer);
		void RectInRectOnMouseMove(SDL_Event *event);
	};
}
#endif // !_DUNGEON_DISPLAYOBJECT_H_

