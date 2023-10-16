#include "AudioPlayerCallback.h"


namespace Dungeon
{

	AudioPlayerCallback::AudioPlayerCallback()
	{

	}

	AudioPlayerCallback::~AudioPlayerCallback()
	{

	}

	void AudioPlayerCallback::OnStartCallback(AudioPlayer *audioPlayer)
	{
		SDL_Log("OnStart");
	}

	void AudioPlayerCallback::OnStopCallback(AudioPlayer *audioPlayer)
	{
		SDL_Log("OnStop");
	}

	void AudioPlayerCallback::OnPauseCallback(AudioPlayer *audioPlayer)
	{
		SDL_Log("OnPause");
	}

	void AudioPlayerCallback::OnReleaseCallback(AudioPlayer *audioPlayer)
	{
		SDL_Log("OnDestory");

	}

	void AudioPlayerCallback::OnCompleteCallback(AudioPlayer *audioPlayer)
	{
		if (audioPlayer)
		{
			audioPlayer->ReStart();
		}
	}
}