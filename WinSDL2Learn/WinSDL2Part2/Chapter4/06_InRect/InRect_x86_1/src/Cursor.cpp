#include "Cursor.h"

namespace Dungeon
{
	Cursor::Cursor() :mCursorData(nullptr)
	{

	}

	Cursor::~Cursor()
	{
	}

	CursorData *Cursor::Cursor_GetCursorData()
	{
		return this->mCursorData;
	}

	DisplayObject *Cursor::Cursor_Create(float x, float y, float w, float h)
	{
		this->mCursorData = (CursorData *)malloc(sizeof(CursorData));//��̬�����ڴ�
		if (!mCursorData)
		{
			return nullptr;
		}
		mCursorData->dest = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mCursorData->dest)
		{
			return nullptr;
		}
		mCursorData->dest->x = x;
		mCursorData->dest->y = y;
		mCursorData->dest->w = w;
		mCursorData->dest->h = h;

		//����Ҫ��ʾ�Ķ���
		DisplayObject *displayObject = new DisplayObject();

		//ΪdisplayObject���ûص�����
		if (!displayObject->DisplayObject_Create(&Cursor_OnDrawCallback,
			&Cursor_OnMouseMoveCallback, &Cursor_DestoryCallback))
		{
			//displayObject->DisplayObject_Destory();
			return nullptr;
		}
		displayObject->mSubClassData = this;//������ʾ����
		return displayObject;
	}

	/*
	* �����õĻص�����,ֻ���Ǿ�̬��,���ܷ��ʷǾ�̬��Ա,ͨ������������
	*/
	void Cursor::Cursor_DestoryCallback(DisplayObject *self)
	{
		//�ͷ��ڴ�
		Cursor *cursor = (Cursor *)self->mSubClassData;//��ȡ���ݵĶ���
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;

			if (data)
			{
				if (data->dest)
				{
					free(data->dest);
				}
				free(data);
			}
		}
	}

	/*
	* �����õĻص�����,ֻ���Ǿ�̬��,���ܷ��ʷǾ�̬��Ա,ͨ������������
	*/
	void Cursor::Cursor_OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		Cursor *cursor = (Cursor *)self->mSubClassData;//��ȡ���ݵĶ���
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;
			//CursorData *data = cursor->Cursor_GetCursorData();
			if (data)
			{
				//���ƹ��
				SDL_RenderCopyF(renderer, resource->Resource_GetCursorTexture(), nullptr, data->dest);
			}
		}
	}

	/*
	* �����õĻص�����,ֻ���Ǿ�̬��,���ܷ��ʷǾ�̬��Ա,ͨ������������
	*/
	void Cursor::Cursor_OnMouseMoveCallback(DisplayObject *self, SDL_Event *event)
	{
		Cursor *cursor = (Cursor *)self->mSubClassData;//��ȡ���ݵĶ���
		if (cursor)
		{
			CursorData *data = cursor->mCursorData;
			//CursorData *data = cursor->Cursor_GetCursorData();
			if (data)
			{
				//���¹��λ��
				data->dest->x = event->motion.x;
				data->dest->y = event->motion.y;
			}
		}
	}
}