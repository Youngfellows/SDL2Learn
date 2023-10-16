#define _CRT_SECURE_NO_WARNINGS

#include "Game.h"
#include "Config.h"
#include "Text.h"
#include <stdio.h>
#include "AudioPlayerCallback.h"

namespace Dungeon
{
	Game::Game() : mWindow(nullptr), mIsRunning(true), mRenderer(nullptr),
		mWelcomText(nullptr),
		mButtonStartText(nullptr),
		mButtonPauseText(nullptr),
		mButtonStopText(nullptr),
		mButtonReStartText(nullptr),
		mTipText(nullptr),
		mClickCount(0),
		mAudioPlayer(mAudioPlayer)
	{

	}

	bool Game::Initialize()
	{
		// TTF������ʼ��
		if (TTF_Init())
		{
			SDL_Log("Can not init ttf: %s", SDL_GetError());
			return false;
		}

		// SDL���ʼ��
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			SDL_Log("Can not init video: %s", SDL_GetError());
			return false;
		}

		// ���ڳ�ʼ��
		mWindow = SDL_CreateWindow("Dungeon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (!mWindow)
		{
			SDL_Log("Can not create window: %s", SDL_GetError());
			return false;
		}

		// ��ʼ��Renderer
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
		if (!mRenderer)
		{
			SDL_Log("Can not create renderer: %s", SDL_GetError());
			return false;
		}
		if (!CreateComponents())
		{
			return false;
		}

		return true;
	}

	void Game::Shutdown()
	{
		FreeComponents();
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}

	void Game::Loop()
	{
		while (mIsRunning)
		{
			uint32_t begin = SDL_GetTicks();

			Draw();
			Event();

			long current = SDL_GetTicks();
			long cost = current - begin;
			long frame = 1000 / FRAMERATE;//ÿһ֡�೤ʱ��
			long delay = frame - cost;
			//SDL_Log("delay=%ld", delay);
			if (delay > 0)
			{
				Update(delay);
			}
		}
	}

	void Game::Event()
	{
		SDL_Event event;
		// ����¼���������δ������¼�����˳����
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:// �˳��¼������´��ڵĲ�
				mIsRunning = false;
				break;
			case SDL_MOUSEBUTTONDOWN://��갴��
				ProcessMouseDownEvent(&event);
				break;
			default:
				break;
			}
			//��ȡ������״̬
			//AudioPlayerState();//��bug
		}
	}

	void Game::Update(long delay)
	{
		if (delay > 0)
		{
			SDL_Delay(delay);
		}
	}

	void Game::Draw()
	{
		SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
		SDL_RenderClear(mRenderer);
		DrawComponents();
		SDL_RenderPresent(mRenderer);
	}


	SDL_bool Game::CreateComponents()
	{
		Text *welcomText = new Text();
		const char *wText = "SDL Audio Player";
		mWelcomText = welcomText->Create(FONT_FILE_NAME, wText, PT_SIZE_20, 0xff000000, 0, 0);
		if (!mWelcomText)
		{
			return SDL_FALSE;
		}

		Text *buttonStartText = new Text();
		const char *bStartText = "Start";
		mButtonStartText = buttonStartText->Create(FONT_FILE_NAME, bStartText, PT_SIZE_32, 0xffff0000, 10, 100);
		if (!mButtonStartText)
		{
			return SDL_FALSE;
		}

		Text *buttonPauseText = new Text();
		const char *bPauseText = "Pause";
		mButtonPauseText = buttonPauseText->Create(FONT_FILE_NAME, bPauseText, PT_SIZE_32, 0xffff0000, 10, 150);
		if (!mButtonPauseText)
		{
			return SDL_FALSE;
		}


		Text *buttonReStartText = new Text();
		const char *bReStartText = "ReStart";
		mButtonReStartText = buttonReStartText->Create(FONT_FILE_NAME, bReStartText, PT_SIZE_32, 0xffff0000, 10, 200);
		if (!mButtonReStartText)
		{
			return SDL_FALSE;
		}

		Text *buttonStopText = new Text();
		const char *bStopText = "Stop";
		mButtonStopText = buttonStopText->Create(FONT_FILE_NAME, bStopText, PT_SIZE_32, 0xffff0000, 10, 250);
		if (!mButtonStopText)
		{
			return SDL_FALSE;
		}

		Text *tipText = new Text();
		const char *tText = "State:Playing";
		mTipText = tipText->Create(FONT_FILE_NAME, tText, PT_SIZE_40, 0xff0000ff, 200, 200);
		if (!mTipText)
		{
			return SDL_FALSE;
		}

		//��ʼ��Audio������
		mAudioPlayer = new AudioPlayer();
		mAudioPlayer->SetAudioPlayerCallback(&AudioPlayerCallback::OnStartCallback,
			&AudioPlayerCallback::OnPauseCallback,
			&AudioPlayerCallback::OnStopCallback,
			&AudioPlayerCallback::OnReleaseCallback,
			&AudioPlayerCallback::OnCompleteCallback);
		if (!mAudioPlayer->InitAudio())
		{
			return SDL_FALSE;
		}

		return SDL_TRUE;
	}

	void Game::FreeComponents()
	{
		if (mWelcomText)
		{
			mWelcomText->Destroy();
		}
		if (mButtonStartText)
		{
			mButtonStartText->Destroy();
		}
		if (mButtonReStartText)
		{
			mButtonReStartText->Destroy();
		}
		if (mButtonPauseText)
		{
			mButtonPauseText->Destroy();
		}
		if (mButtonStopText)
		{
			mButtonStopText->Destroy();
		}
		if (mTipText)
		{
			mTipText->Destroy();
		}
	}

	void Game::DrawComponents()
	{
		if (mWelcomText)
		{
			mWelcomText->Draw(mRenderer);
		}
		if (mButtonStartText)
		{
			mButtonStartText->Draw(mRenderer);
		}
		if (mButtonPauseText)
		{
			mButtonPauseText->Draw(mRenderer);
		}
		if (mButtonReStartText)
		{
			mButtonReStartText->Draw(mRenderer);
		}
		if (mButtonStopText)
		{
			mButtonStopText->Draw(mRenderer);
		}


		if (mTipText)
		{
			mTipText->Draw(mRenderer);
		}
	}

	void  Game::AudioPlayerState()
	{
		if (mAudioPlayer)
		{
			SDL_bool isPlaying = mAudioPlayer->IsPlaying();
			SDL_bool isComplete = mAudioPlayer->IsCompleted();
			SDL_Log("isPlaying:%d,isComplete:%d", isPlaying, isComplete);
			if (!isPlaying && isComplete)
			{
				mAudioPlayer->ReStart();
			}
		}
	}

	void Game::ProcessMouseDownEvent(SDL_Event *event)
	{
		SDL_FPoint point = { event->button.x,event->button.y };
		SDL_Log("point(x:%f,y:%f)", point.x, point.y);
		if (mButtonStartText)
		{
			Text *buttonText = (Text *)mButtonStartText->subClass;//��ȡ��ʾ����
			if (buttonText)
			{
				TextData *textData = buttonText->GetTextData();
				if (textData)
				{
					SDL_FRect *dest = textData->dest;
					if (dest)
					{
						if (SDL_PointInFRect(&point, dest))
						{
							SDL_Log("Click Button Start");
							mClickCount++;
							char msg[256];
							//sprintf(msg, "Click Number: %d", mClickCount);
							sprintf(msg, "Click: %s", "Start");
							if (mTipText)
							{
								mTipText->TextSet(msg);
							}
							if (mAudioPlayer)
							{
								if (mAudioPlayer->Create(SOUND_FILE_NAME))
								{
									mAudioPlayer->Start();
								}
							}
						}
						else
						{
							SDL_Log("Click Other");
						}
					}
				}
			}
		}

		if (mButtonPauseText)
		{
			Text *buttonText = (Text *)mButtonPauseText->subClass;//��ȡ��ʾ����
			if (buttonText)
			{
				TextData *textData = buttonText->GetTextData();
				if (textData)
				{
					SDL_FRect *dest = textData->dest;
					if (dest)
					{
						if (SDL_PointInFRect(&point, dest))
						{
							SDL_Log("Click Button Pause");
							mClickCount++;
							char msg[256];
							//sprintf(msg, "Click Number: %d", mClickCount);
							sprintf(msg, "Click: %s", "Pause");
							if (mTipText)
							{
								mTipText->TextSet(msg);
							}
							if (mAudioPlayer)
							{
								mAudioPlayer->Pause();
							}
						}
						else
						{
							SDL_Log("Click Other");
						}
					}
				}
			}
		}

		if (mButtonReStartText)
		{
			Text *buttonText = (Text *)mButtonReStartText->subClass;//��ȡ��ʾ����
			if (buttonText)
			{
				TextData *textData = buttonText->GetTextData();
				if (textData)
				{
					SDL_FRect *dest = textData->dest;
					if (dest)
					{
						if (SDL_PointInFRect(&point, dest))
						{
							SDL_Log("Click Button ReStart");
							mClickCount++;
							char msg[256];
							//sprintf(msg, "Click Number: %d", mClickCount);
							sprintf(msg, "Click: %s", "ReStart");
							if (mTipText)
							{
								mTipText->TextSet(msg);
							}
							if (mAudioPlayer)
							{
								mAudioPlayer->ReStart();
							}
						}
						else
						{
							SDL_Log("Click Other");
						}
					}
				}
			}
		}


		if (mButtonStopText)
		{
			Text *buttonText = (Text *)mButtonStopText->subClass;//��ȡ��ʾ����
			if (buttonText)
			{
				TextData *textData = buttonText->GetTextData();
				if (textData)
				{
					SDL_FRect *dest = textData->dest;
					if (dest)
					{
						if (SDL_PointInFRect(&point, dest))
						{
							SDL_Log("Click Button Stop");
							mClickCount++;
							char msg[256];
							//sprintf(msg, "Click Number: %d", mClickCount);
							sprintf(msg, "Click: %s", "Stop");
							if (mTipText)
							{
								mTipText->TextSet(msg);
							}
							if (mAudioPlayer)
							{
								mAudioPlayer->Stop();
							}
						}
						else
						{
							SDL_Log("Click Other");
						}
					}
				}
			}
		}
	}
}