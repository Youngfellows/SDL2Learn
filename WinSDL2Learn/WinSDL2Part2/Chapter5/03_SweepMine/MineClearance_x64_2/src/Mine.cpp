#include "Mine.h"
#include "Text.h"
#include "Config.h"

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
		//动态申请内存
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

		//创建数组,长度为size
		mMinefieldData->mines = (MineData **)malloc(sizeof(MineData *) * mMinefieldData->size);
		if (!mMinefieldData->mines)
		{
			return nullptr;
		}
		mMinefieldData->mStartText = nullptr;
		mMinefieldData->mMsgText = nullptr;

		//为数组元素赋值
		for (int i = 0; i < mMinefieldData->size; i++)
		{
			MineData *mineData = (MineData *)malloc(sizeof(MineData));
			if (!mineData)
			{
				SDL_Log("mineData is null");
				return nullptr;
			}
			//mMinefieldData->mines[i] = mineData;//通过角标为元素赋值,保存的是地址
			*((mMinefieldData->mines) + i) = mineData;//通过指针为元素赋值,保存的是地址
			mineData->dest = (SDL_FRect *)malloc(sizeof(SDL_FRect));
			if (!mineData->dest)
			{
				return nullptr;
			}
			mineData->dest->w = mineWidth;
			mineData->dest->h = mineHeight;
		}

		//创建地雷数据
		CreateMine();

		//创建要显示对象
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//设置要显示对象
		OnCallbackData *onCallback = displayObject->GetOnCallback();//设置回调函数
		if (onCallback)
		{
			onCallback->OnDraw = &OnDrawCallback;
			onCallback->OnDestory = &OnDestoryCallback;
		}
		SDL_Log("Mine create success");
		return displayObject;
	}

	void Mine::ResetMine()
	{
		// 更新雷的位置
		if (mMinefieldData)
		{
			CreateMine();
			mMinefieldData->amount = 0;
		}
	}

	/*
	* 生成位置随机的地雷
	*/
	void Mine::CreateMine()
	{
		if (mMinefieldData)
		{
			if (mMinefieldData->mines)
			{
				//要取得[a,b]的随机整数：(rand()%(b-a+1))+a;
				//要取得0~1之间的浮点数：rand() / double(RAND_MAX)


				int size = mMinefieldData->size;
				for (int i = 0; i < size; i++)
				{
					MineData *mineData = *(mMinefieldData->mines + i);//获取保存的地址,通过指针方式
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
						//MineData *mineData = mMinefieldData->mines[i];//获取保存的地址,通过索引方式

						mineData->visible = SDL_TRUE;
						mineData->dest->x = x;
						mineData->dest->y = y;
					}
				}
			}
		}
	}

	/*
	* 逻辑: 直线上的点触到雷,雷就消失
	* 缺点: 性能不高,而且还有可能触碰到了也不消失
	*/
	void Mine::CollideLogic1(SDL_FRect *playerPos)
	{
		MinefieldData *minefieldData = this->mMinefieldData;//获取雷场
		if (minefieldData)
		{
			//获取玩家的4个点位置坐标
			SDL_FPoint lTPoint = { playerPos->x,playerPos->y };
			SDL_FPoint rTPoint = { playerPos->x + playerPos->w,playerPos->y };
			SDL_FPoint lBPoint = { playerPos->x,playerPos->y + playerPos->h };
			SDL_FPoint rBPoint = { playerPos->x + playerPos->w,playerPos->y + playerPos->h };
			int xSize = (int)playerPos->w;//x方向的点数
			int ySize = (int)playerPos->w;//y方向的点数

			int size = minefieldData->size;
			for (int i = 0; i < size; i++)
			{
				MineData *mineData = *(minefieldData->mines + i);
				SDL_FRect *dest = mineData->dest;

				SDL_FPoint *lPoints = (SDL_FPoint *)malloc(sizeof(SDL_FPoint) * ySize);
				SDL_FPoint *tPoints = (SDL_FPoint *)malloc(sizeof(SDL_FPoint) * xSize);
				SDL_FPoint *rPoints = (SDL_FPoint *)malloc(sizeof(SDL_FPoint) * ySize);
				SDL_FPoint *bPoints = (SDL_FPoint *)malloc(sizeof(SDL_FPoint) * xSize);

				if (lPoints)	//左边线
				{
					for (int i = 0; i < ySize; i++)
					{
						//lPoints[i].x = position->x;
						(*(lPoints + i)).x = playerPos->x;
						(*(lPoints + i)).y = playerPos->y + i;
						if (mineData->visible && SDL_PointInFRect(lPoints, dest))//直线上的点触到雷
						{
							mineData->visible = SDL_FALSE;
							minefieldData->amount++;
							SDL_Log("Left touch mine");
							break;
						}
					}
					free(lPoints);//释放内存
				}

				if (tPoints)//上边线
				{
					for (int i = 0; i < xSize; i++)
					{
						//lPoints[i].x = position->x;
						(*(tPoints + i)).x = playerPos->x + i;
						(*(tPoints + i)).y = playerPos->y;

						if (mineData->visible && SDL_PointInFRect(tPoints, dest))//直线上的点触到雷
						{
							mineData->visible = SDL_FALSE;
							minefieldData->amount++;
							SDL_Log("Top touch mine");
							break;
						}
					}
					free(tPoints);//释放内存
				}

				if (rPoints)//右边线
				{
					for (int i = 0; i < ySize; i++)
					{
						//lPoints[i].x = position->x;
						(*(rPoints + i)).x = playerPos->x + playerPos->w;
						(*(rPoints + i)).y = playerPos->y + i;
						if (mineData->visible && SDL_PointInFRect(rPoints, dest))//直线上的点触到雷
						{
							mineData->visible = SDL_FALSE;
							minefieldData->amount++;
							SDL_Log("Right touch mine");
							break;
						}
					}
					free(rPoints);//释放内存
				}
				if (bPoints)//底边线
				{
					for (int i = 0; i < xSize; i++)
					{
						//lPoints[i].x = position->x;
						(*(bPoints + i)).x = playerPos->x + i;
						(*(bPoints + i)).y = playerPos->y + playerPos->h;
						if (mineData->visible && SDL_PointInFRect(bPoints, dest))//直线上的点触到雷
						{
							mineData->visible = SDL_FALSE;
							minefieldData->amount++;
							SDL_Log("Bottom touch mine");
							break;
						}
					}
					free(bPoints);//释放内存
				}

				//设置提示
				if (minefieldData->amount == minefieldData->size)
				{
					//SDL_Log("%s", GAME_OVER_TEXT);

					DisplayObject *msgTextObj = minefieldData->mMsgText;
					if (msgTextObj)
					{
						Text *msgText = (Text *)msgTextObj->GetSubClass();
						if (msgText)
						{
							char msg[256];
							sprintf(msg, "%s %d", GAME_OVER_TEXT, minefieldData->amount);
							msgText->TextSet(msg);
						}
					}
				}
				else
				{
					DisplayObject *msgTextObj = minefieldData->mMsgText;
					if (msgTextObj)
					{
						Text *msgText = (Text *)msgTextObj->GetSubClass();
						if (msgText)
						{
							char msg[256];
							sprintf(msg, "%s %d", ELIMINATE_TEXT, minefieldData->amount);
							msgText->TextSet(msg);
						}
					}
				}
			}
		}
	}

	/*
	*  逻辑: 直线上的点触到雷,雷就消失
	*  有点: 性能高,只要雷上的任意一个顶点落入玩家所在的矩形区域,就可以消灭到雷
	*/
	void Mine::CollideLogic2(SDL_FRect *playerPos)
	{
		MinefieldData *minefieldData = this->mMinefieldData;//获取雷场
		if (minefieldData)
		{
			// 遍历全部雷
			int size = minefieldData->size;
			for (int i = 0; i < size; i++)
			{
				MineData *mineData = *(minefieldData->mines + i);
				SDL_FRect *dest = mineData->dest;

				//每个雷的四个顶点坐标
				SDL_FPoint lTPoint = { dest->x,dest->y };
				SDL_FPoint rTPoint = { dest->x + dest->w,dest->y };
				SDL_FPoint lBPoint = { dest->x,dest->y + dest->h };
				SDL_FPoint rBPoint = { dest->x + dest->w,dest->y + dest->h };

				//性能高
				if (mineData->visible
					&& (SDL_PointInFRect(&lTPoint, playerPos)
						|| SDL_PointInFRect(&rTPoint, playerPos)
						|| SDL_PointInFRect(&lBPoint, playerPos)
						|| SDL_PointInFRect(&rBPoint, playerPos)))
				{
					mineData->visible = SDL_FALSE;
					minefieldData->amount++;
				}

				//设置提示
				DisplayObject *msgTextObj = minefieldData->mMsgText;
				Text *msgText = nullptr;
				char msg[256];
				if (msgTextObj)
				{
					msgText = (Text *)msgTextObj->GetSubClass();
				}

				if (minefieldData->amount == minefieldData->size)
				{

					sprintf(msg, "%s %d", GAME_OVER_TEXT, minefieldData->amount);
				}
				else
				{
					sprintf(msg, "%s %d", ELIMINATE_TEXT, minefieldData->amount);
				}

				if (msgText)
				{
					msgText->TextSet(msg);
				}
			}
		}
	}

	void Mine::OnPlayerPosChangeCallback(DisplayObject *self, SDL_FRect *playerPos)
	{
		Mine *mine = (Mine *)self->GetSubClass();
		if (mine)
		{
			//mine->CollideLogic1(playerPos);
			mine->CollideLogic2(playerPos);
		}
	}

	void Mine::OnDrawCallback(DisplayObject *self, Resource *resource, SDL_Renderer *renderer)
	{
		Mine *mine = (Mine *)self->GetSubClass();//获取数据
		if (mine)
		{
			MinefieldData *minefieldData = mine->mMinefieldData;//获取雷场
			if (minefieldData)
			{
				int size = minefieldData->size;
				for (int i = 0; i < size; i++)
				{
					//绘制地雷
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

	/*
	* 重置游戏
	*/
	void Mine::OnTextClickCallback(DisplayObject *self)
	{
		SDL_Log(" Mine::OnTextClickCallback:: Click Start Button");
		Text *text = (Text *)self->GetSubClass();
		if (text)
		{
			TextData *textData = text->GetTextData();
			if (textData)
			{
				DisplayObject *obj = textData->mine;
				if (obj)
				{
					Mine *mine = (Mine *)obj->GetSubClass();
					if (mine)
					{
						mine->ResetMine();//重置游戏
					}
				}
			}
		}
	}

	/*
	* 直接方式设置对象
	*/
	void Mine::SetTextComponents(DisplayObject *starText, DisplayObject *msgText)
	{
		if (this->mMinefieldData)
		{
			mMinefieldData->mStartText = starText;
			mMinefieldData->mMsgText = msgText;
		}
	}

	void Mine::OnDestoryCallback(DisplayObject *self)
	{
		Mine *mine = (Mine *)self->GetSubClass();//获取数据
		if (mine)
		{
			MinefieldData *minefieldData = mine->mMinefieldData;//获取雷场
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