#include "AudioPlayer.h"
#include <cstdlib>
#include <ctime>

namespace Dungeon
{
	AudioPlayer::AudioPlayer() :mAudioPlayerData(nullptr)
	{
		srand(time(0));//产生随机数种子
		//动态申请内存,设置回调函数
		this->mAudioPlayerData = (AudioPlayerData *)malloc(sizeof(AudioPlayerData));
		if (mAudioPlayerData)
		{
			mAudioPlayerData->OnStart = &OnStart;
			mAudioPlayerData->OnPause = &OnPause;
			mAudioPlayerData->OnStop = &OnStop;
			mAudioPlayerData->OnComplete = &OnComplete;
			mAudioPlayerData->value = -1;
		}
	}

	AudioPlayer::~AudioPlayer()
	{
		SDL_Log("~AudioPlayer");
		Destory();
	}

	/*
	* 线程回调函数
	*/
	int SDLCALL AudioPlayer::ThreadCallback(void *userdata)
	{
		SDL_Log("In Audio Thread: %s", "start");
		AudioPlayer *audioPlayer = (AudioPlayer *)userdata;
		if (!audioPlayer)
		{
			return 0;
		}
		AudioPlayerData *data = audioPlayer->mAudioPlayerData;

		for (int i = 0; i < 30; i++)
		{
			SDL_Delay(1000);
			int state = rand() % 5;
			data->value = state;
			SDL_Log("In Audio Thread: %d,state=%d", i, state);
			switch (state)
			{
			case 1:
				data->OnStart(audioPlayer);
				break;
			case 2:
				data->OnPause(audioPlayer);
				break;
			case 3:
				data->OnStop(audioPlayer);
				break;
			case 4:
				data->OnComplete(audioPlayer);
				break;
			default:
				break;
			}
		}
		SDL_Log("In Audio Thread: %s", "end");
		return 10086;
	}

	void AudioPlayer::Start()
	{
		SDL_Log("Start");
		//启动播放线程,创建线程并执行
		AudioPlayer *userData = this;
		SDL_Thread *audioThread = SDL_CreateThread(&ThreadCallback, "Audio_Player_Thread", (void *)userData);
		if (!audioThread)
		{
			SDL_Log("Start Create Thread Failed: %s", SDL_GetError());
		}
		else
		{
			//int status;
			SDL_Log("Start Create Thread Success");
			//SDL_WaitThread(audioThread, &status);//等待子线程结束
			//SDL_Log("Thread Return Value:%d", status);
			//SDL_DetachThread(audioThread);//子线程自己运行,不影响主线程执行
			SDL_Log("Start Detach Audio Thread");
		}
	}

	void AudioPlayer::Pause()
	{
		SDL_Log("Pause");
	}

	void AudioPlayer::ReStart()
	{
		SDL_Log("ReStart");
	}
	void AudioPlayer::Stop()
	{
		SDL_Log("Stop");
	}

	void AudioPlayer::OnStart(AudioPlayer *data)
	{
		SDL_Log("OnStart");
		AudioPlayer *audioPlayer = (AudioPlayer *)data;
		if (audioPlayer)
		{
			AudioPlayerData *data = audioPlayer->mAudioPlayerData;
			if (data)
			{
				SDL_Log("OnStart,value:%d", data->value);
			}
		}
	}

	void AudioPlayer::OnPause(AudioPlayer *data)
	{
		SDL_Log("OnPause");
		AudioPlayer *audioPlayer = (AudioPlayer *)data;
		if (audioPlayer)
		{
			AudioPlayerData *data = audioPlayer->mAudioPlayerData;
			if (data)
			{
				SDL_Log("OnPause,value:%d", data->value);
			}
		}
	}

	void AudioPlayer::OnComplete(AudioPlayer *data)
	{
		SDL_Log("OnComplete");
		AudioPlayer *audioPlayer = (AudioPlayer *)data;
		if (audioPlayer)
		{
			AudioPlayerData *data = audioPlayer->mAudioPlayerData;
			if (data)
			{
				SDL_Log("OnComplete,value:%d", data->value);
			}
		}
	}

	void AudioPlayer::OnStop(AudioPlayer *data)
	{
		SDL_Log("OnStop");
		AudioPlayer *audioPlayer = (AudioPlayer *)data;
		if (audioPlayer)
		{
			AudioPlayerData *data = audioPlayer->mAudioPlayerData;
			if (data)
			{
				SDL_Log("OnStop,value:%d", data->value);
			}
		}
	}

	void AudioPlayer::Destory()
	{
		SDL_Log("Destory");
		if (mAudioPlayerData)
		{
			free(mAudioPlayerData);
		}
	}
}