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
		SDL_Log("OnStartCallback");
	}

	void AudioPlayerCallback::OnStopCallback(AudioPlayer *audioPlayer)
	{
		SDL_Log("OnStopCallback");
	}

	void AudioPlayerCallback::OnPauseCallback(AudioPlayer *audioPlayer)
	{
		SDL_Log("OnPauseCallback");
	}

	void AudioPlayerCallback::OnReleaseCallback(AudioPlayer *audioPlayer)
	{
		SDL_Log("OnReleaseCallback");

	}

	void AudioPlayerCallback::OnCompleteCallback(AudioPlayer *audioPlayer)
	{
		/*if (audioPlayer)
		{
			audioPlayer->ReStart();
		}*/
		SDL_Log("OnCompleteCallback");
	}
}