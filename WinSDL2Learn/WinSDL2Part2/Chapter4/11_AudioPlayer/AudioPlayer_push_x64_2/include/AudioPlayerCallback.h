#ifndef _DUNGEON_AUDIOPLAYER_CALLBACK_H_
#define _DUNGEON_AUDIOPLAYER_CALLBACK_H_

#include "AudioPlayer.h"

namespace Dungeon
{
	/*
	* 回调函数
	*/
	class AudioPlayerCallback
	{
		/*private:
			AudioPlayer *mAudioPlayer;*/

	public:
		AudioPlayerCallback();
		~AudioPlayerCallback();

		static void OnCreateCallback(AudioPlayer *audioPlayer);
		static void OnStartCallback(AudioPlayer *audioPlayer);
		static void OnStopCallback(AudioPlayer *audioPlayer);
		static void OnPauseCallback(AudioPlayer *audioPlayer);
		static void OnReleaseCallback(AudioPlayer *audioPlayer);
		static void OnCompleteCallback(AudioPlayer *audioPlayer);
		static void OnProgressCallbacc(AudioPlayer *audioPlayer, int len, int pos);
	};
}
#endif // !_DUNGEON_AUDIOPLAYER_CALLBACK_H_
