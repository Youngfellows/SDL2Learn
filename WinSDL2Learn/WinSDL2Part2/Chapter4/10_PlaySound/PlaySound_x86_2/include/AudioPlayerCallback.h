#ifndef _DUNGEON_AUDIOPLAYER_CALLBACK_H_
#define _DUNGEON_AUDIOPLAYER_CALLBACK_H_

#include "AudioPlayer.h"

namespace Dungeon
{
	class AudioPlayerCallback
	{
	public:
		AudioPlayerCallback();
		~AudioPlayerCallback();

		static void OnStartCallback(AudioPlayer *audioPlayer);
		static void OnStopCallback(AudioPlayer *audioPlayer);
		static void OnPauseCallback(AudioPlayer *audioPlayer);
		static void OnReleaseCallback(AudioPlayer *audioPlayer);
		static void OnCompleteCallback(AudioPlayer *audioPlayer);
	};
}
#endif // !_DUNGEON_AUDIOPLAYER_CALLBACK_H_
