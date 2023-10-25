#ifndef _DUNGEON_AUDIOPLAYER_H_
#define _DUNGEON_AUDIOPLAYER_H_
#include <SDL2/SDL.h>

namespace Dungeon
{
	class AudioPlayer;//先声明类

	/*设置回调函数*/
	typedef void (*OnStartCallback)(AudioPlayer *data);
	typedef void (*OnPauseCallback)(AudioPlayer *data);
	typedef void (*OnStopCallback)(AudioPlayer *data);
	typedef void (*OnCompleteCallback)(AudioPlayer *data);

	typedef struct AudioPlayerData
	{
		OnStartCallback OnStart;
		OnPauseCallback OnPause;
		OnStopCallback OnStop;
		OnCompleteCallback OnComplete;
		int value;
	}AudioPlayerData;
}

namespace Dungeon
{
	class AudioPlayer
	{
	private:
		AudioPlayerData *mAudioPlayerData;

	public:
		AudioPlayer();
		~AudioPlayer();
		void Start();
		void Pause();
		void ReStart();
		void Stop();
		void Destory();

	private:
		static void OnStart(AudioPlayer *data);
		static void OnPause(AudioPlayer *data);
		static void OnComplete(AudioPlayer *data);
		static void OnStop(AudioPlayer *data);
		static int SDLCALL ThreadCallback(void *userdata);
	};

}
#endif // ! _DUNGEON_AUDIOPLAYER_H_

