#include "AudioPlayerCallback.h"


namespace Dungeon
{

	AudioPlayerCallback::AudioPlayerCallback()
	{

	}

	AudioPlayerCallback::~AudioPlayerCallback()
	{

	}

	void AudioPlayerCallback::OnCreateCallback(AudioPlayer *audioPlayer)
	{
		SDL_Log("OnCreateCallback --->>>");
		if (audioPlayer)
		{
			audioPlayer->Start();//创建成功并播放
		}
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
		SDL_Log("OnCompleteCallback");
		if (audioPlayer)
		{
			audioPlayer->ReStart();//播放结束,重新播放
		}
	}

	void AudioPlayerCallback::OnProgressCallbacc(AudioPlayer *audioPlayer, int len, int pos)
	{
		SDL_Log("OnProgressCallbacc,len:%d,pos:%d", len, pos);
	}
}