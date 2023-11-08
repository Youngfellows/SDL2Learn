#ifndef _DUNGEON_AUDIOPLAYER_H_
#define _DUNGEON_AUDIOPLAYER_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	typedef	enum PlayerState
	{
		IDLE,//空闲状态
		PLAYING,//播放状态
		PAUSE,//暂停状态
		STOP//销毁
	}PlayerState;

	typedef struct SoundInfo
	{
		char *file;//音频文件
		Uint8 *sound;//音频
		Uint32 soundLen;//音频长
		Uint32 soundPos;//当前播放位置
		SDL_bool completed;//是否播放完成
		PlayerState state;//播放器状态
		SDL_AudioDeviceID device;//打开的声卡播放设备
	} SoundInfo;
}

namespace Dungeon
{
	class AudioPlayer
	{
	private:
		SoundInfo *mSoundInfo;//音频信息结构体
		typedef void (*OnStartCallback)(AudioPlayer *audioPlayer);//函数回调 ->> 开始播放
		typedef void (*OnPauseCallback)(AudioPlayer *audioPlayer);
		typedef void (*OnStopCallback)(AudioPlayer *audioPlayer);
		typedef void (*OnReleaseCallback)(AudioPlayer *audioPlayer);
		typedef void (*OnCompleteCallback)(AudioPlayer *audioPlayer);
		OnStartCallback OnStart;
		OnPauseCallback OnPause;
		OnStopCallback OnStop;
		OnReleaseCallback OnRelease;
		OnCompleteCallback OnComplete;

	public:
		AudioPlayer();
		~AudioPlayer();

		void SetAudioPlayerCallback(OnStartCallback onStartCallback,
			OnPauseCallback onPauseCallback,
			OnStopCallback onStopCallback,
			OnReleaseCallback onReleaseCallback,
			OnCompleteCallback onCompleteCallback);

		SDL_bool Create(const char *file);
		void Start();
		void Pause();
		void ReStart();
		void Stop();
		SDL_bool IsPlaying();
		SDL_bool InitAudio();

	private:
		void Destory();
		static void SDLCALL AudioCallback(void *userdata, Uint8 *stream, int len);
		void CloseDevice();

	};
}
#endif // ! _DUNGEON_AUDIOPLAYER_H_

