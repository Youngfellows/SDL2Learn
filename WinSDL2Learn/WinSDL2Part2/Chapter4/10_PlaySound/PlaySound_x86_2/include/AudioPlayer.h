#ifndef _DUNGEON_AUDIOPLAYER_H_
#define _DUNGEON_AUDIOPLAYER_H_

#include "SDL2/SDL.h"

namespace Dungeon
{
	class AudioPlayer;//��������

	//�����ص�
	typedef void (*OnCreateCallback)(AudioPlayer *audioPlayer);
	typedef void (*OnStartCallback)(AudioPlayer *audioPlayer);// ��ʼ����
	typedef void (*OnPauseCallback)(AudioPlayer *audioPlayer);
	typedef void (*OnStopCallback)(AudioPlayer *audioPlayer);
	typedef void (*OnReleaseCallback)(AudioPlayer *audioPlayer);
	typedef void (*OnCompleteCallback)(AudioPlayer *audioPlayer);
	typedef void (*OnProgressCallback)(AudioPlayer *audioPlayer, int len, int pos);

	typedef enum Mode
	{
		DEFAULT,//���β���
		SINGLE_LOOP,//����ѭ��
		LIST_LOOP,//�б�ѭ��
		RANDOM//�������
	}Mode;

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
		OnCreateCallback OnCreate;//�ص�����OnCreate
		OnStartCallback OnStart;//�ص�����OnStart
		OnPauseCallback OnPause;//�ص�����OnPause
		OnStopCallback OnStop;//�ص�����OnStop
		OnReleaseCallback OnRelease;//�ص�����OnRelease
		OnCompleteCallback OnComplete;//�ص�����OnComplete
		OnProgressCallback OnProgress;//�ص�����OnProgress
		char *flag;//��־
	} SoundInfo;
}

namespace Dungeon
{
	//��Ƴɵ�����

	class AudioPlayer
	{
	private:
		SoundInfo *mSoundInfo;//��Ƶ��Ϣ�ṹ��
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

