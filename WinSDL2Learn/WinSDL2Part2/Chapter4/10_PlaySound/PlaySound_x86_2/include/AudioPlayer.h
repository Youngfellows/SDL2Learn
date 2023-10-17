#ifndef _DUNGEON_AUDIOPLAYER_H_
#define _DUNGEON_AUDIOPLAYER_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	class AudioPlayer;//先声明类

	//函数回调
	typedef void (*OnCreateCallback)(AudioPlayer *audioPlayer);
	typedef void (*OnStartCallback)(AudioPlayer *audioPlayer);// 开始播放
	typedef void (*OnPauseCallback)(AudioPlayer *audioPlayer);
	typedef void (*OnStopCallback)(AudioPlayer *audioPlayer);
	typedef void (*OnReleaseCallback)(AudioPlayer *audioPlayer);
	typedef void (*OnCompleteCallback)(AudioPlayer *audioPlayer);
	typedef void (*OnProgressCallback)(AudioPlayer *audioPlayer, int len, int pos);

	typedef enum Mode
	{
		DEFAULT,//单次播放
		SINGLE_LOOP,//单曲循环
		LIST_LOOP,//列表循环
		RANDOM//随机播放
	}Mode;

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
		OnCreateCallback OnCreate;//回调函数OnCreate
		OnStartCallback OnStart;//回调函数OnStart
		OnPauseCallback OnPause;//回调函数OnPause
		OnStopCallback OnStop;//回调函数OnStop
		OnReleaseCallback OnRelease;//回调函数OnRelease
		OnCompleteCallback OnComplete;//回调函数OnComplete
		OnProgressCallback OnProgress;//回调函数OnProgress
		char *flag;//标志
	} SoundInfo;
}

namespace Dungeon
{
	//设计成单例的

	class AudioPlayer
	{
	private:
		SoundInfo *mSoundInfo;//音频信息结构体
		/*OnStartCallback OnStart;
		OnPauseCallback OnPause;
		OnStopCallback OnStop;
		OnReleaseCallback OnRelease;
		OnCompleteCallback OnComplete;*/

	public:
		AudioPlayer();
		~AudioPlayer();

		void SetAudioPlayerCallback(
			OnCreateCallback onCreateCallback,
			OnStartCallback onStartCallback,
			OnPauseCallback onPauseCallback,
			OnStopCallback onStopCallback,
			OnReleaseCallback onReleaseCallback,
			OnCompleteCallback onCompleteCallback,
			OnProgressCallback onProgressCallback);

		SDL_bool Create(const char *file);
		void Start();
		void Pause();
		void ReStart();
		void Stop();
		SDL_bool IsPlaying();
		SDL_bool InitAudio();
		SDL_bool IsCompleted();
		void Destory();
	private:
		static void SDLCALL AudioCallback(void *userdata, Uint8 *stream, int len);
		void CloseDevice();
		static int SDLCALL ThreadCallback(void *userdata);
	};
}
#endif // ! _DUNGEON_AUDIOPLAYER_H_

