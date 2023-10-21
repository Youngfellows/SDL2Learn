#include "Mine.h"

namespace Dungeon
{
	Mine::Mine() :mMinefieldData(nullptr)
	{
		srand(time(0));
	}

	Mine::~Mine()
	{
	}

	DisplayObject *Mine::Create(float x, float y, float w, float h, int size,
		float mineWidth, float mineHeight)
	{
		//��̬�����ڴ�
		this->mMinefieldData = (MinefieldData *)malloc(sizeof(MinefieldData));
		if (!mMinefieldData)
		{
			return nullptr;
		}
		mMinefieldData->size = size;
		mMinefieldData->amount = 0;

		mMinefieldData->boundry = (SDL_FRect *)malloc(sizeof(SDL_FRect));
		if (!mMinefieldData->boundry)
		{
			return nullptr;
		}
		mMinefieldData->boundry->x = x;
		mMinefieldData->boundry->y = y;
		mMinefieldData->boundry->w = w;
		mMinefieldData->boundry->h = h;

		//��������,����Ϊsize
		mMinefieldData->mines = (MineData **)malloc(sizeof(MineData *) * mMinefieldData->size);
		if (!mMinefieldData->mines)
		{
			return nullptr;
		}
		//Ϊ����Ԫ�ظ�ֵ
		for (int i = 0; i < mMinefieldData->size; i++)
		{
			MineData *mineData = (MineData *)malloc(sizeof(MineData));
			if (!mineData)
			{
				SDL_Log("mineData is null");
				return nullptr;
			}
			//mMinefieldData->mines[i] = mineData;//ͨ���Ǳ�ΪԪ�ظ�ֵ,������ǵ�ַ
			*((mMinefieldData->mines) + i) = mineData;//ͨ��ָ��ΪԪ�ظ�ֵ,������ǵ�ַ
			mineData->visible = SDL_TRUE;
			mineData->dest = (SDL_FRect *)malloc(sizeof(SDL_FRect));
			if (!mineData->dest)
			{
				return nullptr;
			}
			mineData->dest->w = mineWidth;
			mineData->dest->h = mineHeight;
		}

		//������������
		CreateMins();

		//����Ҫ��ʾ����
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//����Ҫ��ʾ����
		OnCallbackData *onCallback = displayObject->GetOnCallback();//���ûص�����
		if (onCallback)
		{
			onCallback->OnDraw = &OnDrawCallback;
			onCallback->OnDestory = &OnDestoryCallback;
		}
		SDL_Log("Mine create success");
		return displayObject;
	}

	/*
	* ����λ������ĵ���
	*/
	void Mine::CreateMins()
	{
		if (mMinefieldData)
		{
			if (mMinefieldData->mines)
			{
				//Ҫȡ��[a,b]�����������(rand()%(b-a+1))+a;
				//Ҫȡ��0~1֮��ĸ�������rand() / double(RAND_MAX)


				int size = mMinefieldData->size;
				for (int i = 0; i < size; i++)
				{
					MineData *mineData = *(mMinefieldData->mines + i);//��ȡ����ĵ�ַ,ͨ��ָ�뷽ʽ
					SDL_FRect *dest = mineData->dest;
					if (dest)
					{
						int x1 = (int)mMinefieldData->boundry->x;
						int x2 = (int)(mMinefieldData->boundry->x + mMinefieldData->boundry->w - dest->w);
						int y1 = (int)mMinefieldData->boundry->y;
						int y2 = (int)(mMinefieldData->boundry->y + mMinefieldData->boundry->h - dest->h);
						SDL_Log("x1:%f,x2:%f", x1, x2);
						SDL_Log("y1:%f,y2:%f", y1, y2);

						float x = (float)((rand() % (x2 - x1 + 1)) + x1);
						float y = (float)((rand() % (y2 - y1 + 1)) + y1);
						SDL_Log("x:%f,y:%f", x, y);
						//MineData *mineData = mMinefieldData->mines[i];//��ȡ����ĵ�ַ,ͨ��������ʽ


						mineData->dest->x = x;
						mineData->dest->y = y;
					}
				}
			}
		}
	}

	/*
	* �߼�:ֱ���ϵĵ㴥����,�׾���ʧ
	*/
	void Mine::OnPlayerPosChangeCallback(DisplayObject *self, SDL_FRect *position)
	{
		Mine *mine = (Mine *)self->GetSubClass();
		if (mine)
		{
			MinefieldData *minefieldData = mine->mMinefieldData;//��ȡ�׳�
			if (minefieldData)
			{
				//��ȡ��ҵ�4����λ������
				SDL_FPoint lTPoint = { position->x,position->y };
				SDL_FPoint rTPoint = { position->x + position->w,position->y };
				SDL_FPoint lBPoint = { position->x,position->y + position->h };
				SDL_FPoint rBPoint = { position->x + position->w,position->y + position->h };
				int xSize = (int)position->w;//x����ĵ���
				int ySize = (int)position->w;//y����ĵ���

				int size = minefieldData->size;
				for (int i = 0; i < size; i++)
				{
					MineData *mineData = *(minefieldData->mines + i);
					SDL_FRect *dest = mineData->dest;

					////��bug,����Ҫ4�����е�һ�������ſ���,���Բ��ܰ��������̫����
					//if (SDL_PointInFRect(&lTPoint, dest)
					//	|| SDL_PointInFRect(&rTPoint, dest)
					//	|| SDL_PointInFRect(&lBPoint, dest)
					//	|| SDL_PointInFRect(&rBPoint, dest))
					//{
					//	mineData->visible = SDL_FALSE;
					//}

					SDL_FPoint *lPoints = (SDL_FPoint *)malloc(sizeof(SDL_FPoint) * ySize);
					SDL_FPoint *tPoints = (SDL_FPoint *)malloc(sizeof(SDL_FPoint) * xSize);
					SDL_FPoint *rPoints = (SDL_FPoint *)malloc(sizeof(SDL_FPoint) * ySize);
					SDL_FPoint *bPoints = (SDL_FPoint *)malloc(sizeof(SDL_FPoint) * xSize);

					if (lPoints)	//�����
					{
						for (int i = 0; i < ySize; i++)
						{
							//lPoints[i].x = position->x;
							(*(lPoints + i)).x = position->x;
							(*(lPoints + i)).y = position->y + i;
							if (SDL_PointInFRect(lPoints, dest))//ֱ���ϵĵ㴥����
							{
								mineData->visible = SDL_FALSE;
							}
						}
						free(lPoints);//�ͷ��ڴ�
					}

					if (tPoints)//�ϱ���
					{
						for (int i = 0; i < xSize; i++)
						{
							//lPoints[i].x = position->x;
							(*(tPoints + i)).x = position->x + i;
							(*(tPoints + i)).y = position->y;

							if (SDL_PointInFRect(tPoints, dest))//ֱ���ϵĵ㴥����
							{
								mineData->visible = SDL_FALSE;
							}
						}
						free(tPoints);//�ͷ��ڴ�
					}

					if (rPoints)//�ұ���
					{
						for (int i = 0; i < ySize; i++)
						{
							//lPoints[i].x = position->x;
							(*(rPoints + i)).x = position->x + position->w;
							(*(rPoints + i)).y = position->y + i;
							if (SDL_PointInFRect(rPoints, dest))//ֱ���ϵĵ㴥����
							{
								mineData->visible = SDL_FALSE;
							}
						}
						free(rPoints);//�ͷ��ڴ�
					}
					if (bPoints)//�ױ���
					{
						for (int i = 0; i < xSize; i++)
						{
							//lPoints[i].x = position->x;
							(*(bPoints + i)).x = position->x + i;
							(*(bPoints + i)).y = position->y + position->h;
							if (SDL_PointInFRect(bPoints, dest))//ֱ���ϵĵ㴥����
							{
								mineData->visible = SDL_FALSE;
							}
						}
						free(bPoints);//�ͷ��ڴ�
					}
				}
			}
		}
	}

	void Mine::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		Mine *mine = (Mine *)self->GetSubClass();//��ȡ����
		if (mine)
		{
			MinefieldData *minefieldData = mine->mMinefieldData;//��ȡ�׳�
			if (minefieldData)
			{
				int size = minefieldData->size;
				for (int i = 0; i < size; i++)
				{
					//���Ƶ���
					MineData *mineData = *(minefieldData->mines + i);
					if (mineData->visible && resource && renderer)
					{
						SDL_FRect *dest = mineData->dest;
						SDL_RenderCopyF(renderer, resource->GetMineTexture(), nullptr, dest);
					}

				}
			}
		}
	}

	void Mine::OnPlayerMoveCallback(void *position)
	{

	}

	void Mine::OnDestoryCallback(DisplayObject *self)
	{
		Mine *mine = (Mine *)self->GetSubClass();//��ȡ����
		if (mine)
		{
			MinefieldData *minefieldData = mine->mMinefieldData;//��ȡ�׳�
			if (minefieldData)
			{
				int size = minefieldData->size;
				MineData **mines = minefieldData->mines;
				for (int i = 0; i < size; i++)
				{
					MineData *mineData = *(mines + i);
					if (mineData->dest)
					{
						free(mineData->dest);
					}
					free(mineData);
				}
				free(mines);
				free(minefieldData);
				mines = nullptr;
				minefieldData = nullptr;
			}
		}
	}
}