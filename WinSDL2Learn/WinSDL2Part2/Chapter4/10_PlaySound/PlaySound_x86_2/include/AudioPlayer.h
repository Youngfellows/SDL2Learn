#ifndef _DUNGEON_AUDIOPLAYER_H_
#define _DUNGEON_AUDIOPLAYER_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	typedef	enum PlayerState
	{
		IDLE,//����״̬
		PLAYING,//����״̬
		PAUSE,//��ͣ״̬
		STOP//����
	}PlayerState;

	typedef struct SoundInfo
	{
		char *file;//��Ƶ�ļ�
		Uint8 *sound;//��Ƶ
		Uint32 soundLen;//��Ƶ��
		Uint32 soundPos;//��ǰ����λ��
		SDL_bool completed;//�Ƿ񲥷����
		PlayerState state;//������״̬
		SDL_AudioDeviceID device;//�򿪵����������豸
	} SoundInfo;
}

namespace Dungeon
{
	//��Ƴɵ�����

	class AudioPlayer
	{
	private:
		SoundInfo *mSoundInfo;//��Ƶ��Ϣ�ṹ��
		typedef void (*OnStartCallback)(AudioPlayer *audioPlayer);//�����ص� ->> ��ʼ����
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
		static	void SDLCALL AudioCallback(void *userdata, Uint8 *stream, int len);
		void CloseDevice();

	};
}
#endif // ! _DUNGEON_AUDIOPLAYER_H_

