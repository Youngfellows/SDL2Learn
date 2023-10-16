#include "AudioPlayer.h"

namespace Dungeon
{
	AudioPlayer::AudioPlayer() :mSoundInfo(nullptr)
	{

	}

	AudioPlayer::~AudioPlayer()
	{
	}

	void AudioPlayer::SetAudioPlayerCallback(OnStartCallback onStartCallback,
		OnPauseCallback onPauseCallback,
		OnStopCallback onStopCallback,
		OnReleaseCallback onReleaseCallback,
		OnCompleteCallback onCompleteCallback)
	{
		this->OnStart = onStartCallback;
		this->OnStop = onStopCallback;
		this->OnPause = onPauseCallback;
		this->OnRelease = onReleaseCallback;
		this->OnComplete = onCompleteCallback;
	}

	SDL_bool AudioPlayer::InitAudio()
	{
		// ��ʼ����Ƶ��
		if (SDL_Init(SDL_INIT_AUDIO))
		{
			SDL_Log("Can not init audio: %s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	/*
	* ����������
	*/
	SDL_bool AudioPlayer::Create(const char *file)
	{
		SDL_AudioSpec audioSpec;
		Uint8 *sound;
		Uint32 soundLen;

		// ������Ƶ��Դ
		if (!SDL_LoadWAV(file, &audioSpec, &sound, &soundLen))
		{
			SDL_Log("Can not load audio: %s", SDL_GetError());
			return SDL_FALSE;
		}
		audioSpec.callback = &AudioCallback;//���ûص�����

		//��̬�����ڴ�
		if (this->mSoundInfo)
		{
			free(mSoundInfo);
		}
		this->mSoundInfo = (SoundInfo *)malloc(sizeof(SoundInfo));
		if (!mSoundInfo)
		{
			return SDL_FALSE;
		}
		mSoundInfo->file = (char *)malloc(sizeof(char) * SDL_strlen(file) + 1);
		if (mSoundInfo->file)
		{
			SDL_strlcpy(mSoundInfo->file, file, SDL_strlen(file) + 1);
		}
		mSoundInfo->sound = sound;
		mSoundInfo->soundLen = soundLen;
		mSoundInfo->soundPos = 0;
		mSoundInfo->completed = SDL_FALSE;
		mSoundInfo->device = 0;
		mSoundInfo->state = IDLE;
		audioSpec.userdata = mSoundInfo;//��������

		//���豸��ʼ����
		SDL_AudioDeviceID device = SDL_OpenAudioDevice(nullptr,
			SDL_FALSE, &audioSpec, nullptr, 0);
		if (!device)
		{
			SDL_Log("Can not open audio device: %s", SDL_GetError());
			SDL_FreeWAV(sound);
			return SDL_FALSE;
		}
		mSoundInfo->device = device;
	}

	/*
	* �������ص�
	*/
	void SDLCALL AudioPlayer::AudioCallback(void *userdata, Uint8 *stream, int len)
	{
		SDL_Log("AudioCallback len:%d", len);
		SoundInfo *soundInfo = (SoundInfo *)userdata;
		Uint32 remaining = soundInfo->soundLen - soundInfo->soundPos;//ʣ�����û�ж�ȡ��
		if (remaining > len)
		{
			SDL_memcpy(stream, soundInfo->sound + soundInfo->soundPos, len);
			soundInfo->soundPos += len;//�����Ѿ����ų���
		}
		else
		{
			SDL_memcpy(stream, soundInfo->sound + soundInfo->soundPos, remaining);
			soundInfo->soundPos = 0;
			soundInfo->completed = SDL_TRUE;//�������
			SDL_Log("AudioCallback completed");
		}
	}

	/*
	* ����
	*/
	void AudioPlayer::Start()
	{
		if (mSoundInfo)
		{
			if (mSoundInfo->device)
			{
				SDL_PauseAudioDevice(mSoundInfo->device, SDL_FALSE);//����ͣ
				mSoundInfo->state = PLAYING;
				if (OnStart)
				{
					OnStart(this);//�ص���ʼ
				}
				//����һ��������Ч��
				while (1)
				{
					if (mSoundInfo->completed)
					{
						//break;
						goto GO_TO_COMPLETE;//1. goto ���������	
					}

					//if (��ͣ����)
					//{
					//	//2. goto ����ͣ����
					//	break;
					//}
				
					if (mSoundInfo->state==STOP)
					{
						//break;
						goto GO_TO_STOP;//3. goto ��ֹͣ����
					}
					SDL_Delay(100);
				}
			}
		}

	GO_TO_COMPLETE:
		SDL_Log("GO_TO_COMPLETE");
		if (mSoundInfo)
		{
			mSoundInfo->state = IDLE;
		}
		CloseDevice();//�ر���Դ
		if (OnComplete)
		{
			OnComplete(this);
		}

	GO_TO_STOP:
		SDL_Log("GO_TO_STOP");
		Destory();
	}

	void AudioPlayer::Pause()
	{
		if (mSoundInfo)
		{
			if (mSoundInfo->device)
			{
				SDL_PauseAudioDevice(mSoundInfo->device, SDL_TRUE);//��ͣ
				mSoundInfo->state = PAUSE;
				if (OnPause)
				{
					OnPause(this);
				}
			}
		}
	}

	/*
	* ���²���
	*/
	void AudioPlayer::ReStart()
	{
		if (mSoundInfo)
		{
			if (Create(mSoundInfo->file))
			{
				Start();
			}
		}
	}

	/*
	* ֹͣ����
	*/
	void AudioPlayer::Stop()
	{
		if (mSoundInfo)
		{
			mSoundInfo->state = STOP;
		}
		Destory();
	}

	void AudioPlayer::CloseDevice()
	{
		if (mSoundInfo)
		{
			if (mSoundInfo->device)
			{
				SDL_CloseAudioDevice(mSoundInfo->device);//�ر�����
				SDL_FreeWAV(mSoundInfo->sound);//�Ƿ��ڴ�
			}
		}
	}

	/*
	* �Ƿ����ڲ���
	*/
	SDL_bool AudioPlayer::IsPlaying()
	{
		if (mSoundInfo)
		{
			if (mSoundInfo->device)
			{
				if (mSoundInfo->state == PLAYING)
				{
					return SDL_TRUE;
				}
			}
		}
		return SDL_FALSE;
	}

	void AudioPlayer::Destory()
	{
		if (OnRelease)
		{
			OnRelease(this);
		}
		if (mSoundInfo)
		{
			CloseDevice();
			free(mSoundInfo->file);
			free(mSoundInfo);
		}	
	}
}
