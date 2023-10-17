#include "AudioPlayer.h"
#include "Config.h"

namespace Dungeon
{
	AudioPlayer::AudioPlayer() :mSoundInfo(nullptr)
	{

	}

	AudioPlayer::~AudioPlayer()
	{
	}

	/*
	* ���ûص�����
	*/
	void AudioPlayer::SetAudioPlayerCallback(
		OnCreateCallback onCreateCallback,
		OnStartCallback onStartCallback,
		OnPauseCallback onPauseCallback,
		OnStopCallback onStopCallback,
		OnReleaseCallback onReleaseCallback,
		OnCompleteCallback onCompleteCallback,
		OnProgressCallback onProgressCallback)
	{
		if (mSoundInfo)
		{
			mSoundInfo->OnCreate = onCreateCallback;
			mSoundInfo->OnStart = onStartCallback;
			mSoundInfo->OnStop = onStopCallback;
			mSoundInfo->OnPause = onPauseCallback;
			mSoundInfo->OnComplete = onCompleteCallback;
			mSoundInfo->OnRelease = onReleaseCallback;
			mSoundInfo->OnProgress = onProgressCallback;
		}
	}

	SDL_bool AudioPlayer::InitAudio()
	{
		// ��ʼ����Ƶ��
		if (SDL_Init(SDL_INIT_AUDIO))
		{
			SDL_Log("Can not init audio: %s", SDL_GetError());
			return SDL_FALSE;
		}

		// ��̬�����ڴ�
		this->mSoundInfo = (SoundInfo *)malloc(sizeof(SoundInfo));
		if (!mSoundInfo)
		{
			return SDL_FALSE;
		}
		mSoundInfo->sound = nullptr;
		mSoundInfo->file = nullptr;
		mSoundInfo->flag = nullptr;
		return SDL_TRUE;
	}

	/*
	* ����������
	*/
	SDL_bool AudioPlayer::Create(const char *file)
	{
		if (!mSoundInfo)
		{
			SDL_Log("Can not create audio player");
			return SDL_FALSE;
		}
		//��̬�����ڴ�
		mSoundInfo->file = (char *)malloc(sizeof(char) * SDL_strlen(file) + 1);
		if (mSoundInfo->file)
		{
			SDL_strlcpy(mSoundInfo->file, file, SDL_strlen(file) + 1);
		}
		mSoundInfo->flag = (char *)malloc(sizeof(char) * SDL_strlen(FLAG_CREATE_AUDIO_PLAYER) + 1);
		if (mSoundInfo->flag)
		{
			SDL_strlcpy(mSoundInfo->flag, FLAG_CREATE_AUDIO_PLAYER, SDL_strlen(FLAG_CREATE_AUDIO_PLAYER) + 1);
		}
	
		//�����߳�,�����̲߳�ִ��
		AudioPlayer *userData = this;
		SDL_Thread *audioThread = SDL_CreateThread(&ThreadCallback, "Audio_Player_Thread", (void *)userData);
		if (!audioThread)
		{
			SDL_Log("Create:: Thread Failed: %s", SDL_GetError());
		}
		else
		{
			//int status;
			SDL_Log("Create:: Thread Success");
			//SDL_WaitThread(audioThread, &status);//�ȴ����߳̽���
			//SDL_Log("Thread Return Value:%d", status);
			//SDL_DetachThread(audioThread);//���߳��Լ�����,��Ӱ�����߳�ִ��
			SDL_Log("Create:: Detach Audio Thread");
		}
	}

	/*
	* �̻߳ص�����
	*/
	int SDLCALL AudioPlayer::ThreadCallback(void *userdata)
	{
		SDL_Log("ThreadCallback:%s", "Thread Run");
		AudioPlayer *audioPlayer = (AudioPlayer *)userdata;
		if (audioPlayer)
		{
			SoundInfo *soundInfo = audioPlayer->mSoundInfo;
			if (soundInfo)
			{
				//SDL_Log("ThreadCallback:%s", "Thread Run 111");
				//Create����������
				if (SDL_strcmp(soundInfo->flag, FLAG_CREATE_AUDIO_PLAYER) == 0)
				{
					//SDL_Log("ThreadCallback:%s", "Thread Run 2222");
					if (audioPlayer->IsPlaying())
					{
						audioPlayer->Stop();
					}

					SDL_AudioSpec audioSpec;
					Uint8 *sound;
					Uint32 soundLen;

					// ������Ƶ��Դ
					if (!SDL_LoadWAV(soundInfo->file, &audioSpec, &sound, &soundLen))
					{
						SDL_Log("Can not load audio: %s", SDL_GetError());
						return SDL_FALSE;
					}
					audioSpec.callback = &AudioCallback;//���ûص�����

					//��̬�����ڴ�
					soundInfo->sound = sound;
					soundInfo->soundLen = soundLen;
					soundInfo->soundPos = 0;
					soundInfo->completed = SDL_FALSE;
					soundInfo->device = 0;
					soundInfo->state = IDLE;
					//audioSpec.userdata = mSoundInfo;//��������
					audioSpec.userdata = audioPlayer;//���ûص�����

					//���豸��ʼ����
					SDL_AudioDeviceID device = SDL_OpenAudioDevice(nullptr,
						SDL_FALSE, &audioSpec, nullptr, 0);
					if (!device)
					{
						SDL_Log("Can not open audio device: %s", SDL_GetError());
						SDL_FreeWAV(sound);
						return SDL_FALSE;
					}
					soundInfo->device = device;
					SDL_Log("ThreadCallback: %s", "Create Audio Player");
					if (soundInfo->OnCreate)
					{
						soundInfo->OnCreate(audioPlayer);
					}
				}
			}
		}
	}

	/*
	* �������ص�
	*/
	void SDLCALL AudioPlayer::AudioCallback(void *userdata, Uint8 *stream, int len)
	{
		SDL_Log("AudioCallback len:%d", len);
		AudioPlayer *audioPlayer = (AudioPlayer *)userdata;
		if (!audioPlayer)
		{
			return;
		}
		SoundInfo *soundInfo = audioPlayer->mSoundInfo;
		if (!soundInfo->completed)
		{
			Uint32 remaining = soundInfo->soundLen - soundInfo->soundPos;//ʣ�����û�ж�ȡ��
			if (remaining > len)
			{
				SDL_memcpy(stream, soundInfo->sound + soundInfo->soundPos, len);
				soundInfo->soundPos += len;//�����Ѿ����ų���
				if (soundInfo->OnProgress)
				{
					soundInfo->OnProgress(audioPlayer, soundInfo->soundLen, soundInfo->soundPos);
				}
			}
			else
			{
				SDL_memcpy(stream, soundInfo->sound + soundInfo->soundPos, remaining);
				soundInfo->soundPos = 0;
				soundInfo->completed = SDL_TRUE;//�������
				SDL_Log("AudioCallback completed");
			}
		}
		else
		{
			soundInfo->state = IDLE;
			SDL_PauseAudioDevice(soundInfo->device, SDL_TRUE);//��ͣ
			SDL_Log("AudioCallback Already Play completed");
			if (soundInfo->OnComplete)
			{
				soundInfo->OnComplete(audioPlayer);
			}
		}
	}

	/*
	* ����
	*/
	void AudioPlayer::Start()
	{
		if (mSoundInfo)
		{
			mSoundInfo->completed = SDL_FALSE;
			if (mSoundInfo->device)
			{
				SDL_PauseAudioDevice(mSoundInfo->device, SDL_FALSE);//����ͣ
				mSoundInfo->state = PLAYING;
				if (mSoundInfo->OnStart)
				{
					mSoundInfo->OnStart(this);//�ص�OnStarCallback
				}
			}
		}
	}

	void AudioPlayer::Pause()
	{
		if (mSoundInfo)
		{
			if (mSoundInfo->device)
			{
				SDL_PauseAudioDevice(mSoundInfo->device, SDL_TRUE);//��ͣ
				mSoundInfo->state = PAUSE;
				if (mSoundInfo->OnPause)
				{
					mSoundInfo->OnPause(this);
				}
			}
		}
	}

	/*
	* ���²���
	*/
	void AudioPlayer::ReStart()
	{
		Start();
	}

	/*
	* ֹͣ����
	*/
	void AudioPlayer::Stop()
	{
		if (mSoundInfo)
		{
			mSoundInfo->state = STOP;
			if (mSoundInfo->device)
			{
				SDL_PauseAudioDevice(mSoundInfo->device, SDL_TRUE);//��ͣ
			}
			mSoundInfo->soundPos = 0;
			mSoundInfo->completed = SDL_TRUE;//�������
			if (mSoundInfo->OnStop)
			{
				mSoundInfo->OnStop(this);
			}
		}
		//Destory();
	}

	void AudioPlayer::CloseDevice()
	{
		if (mSoundInfo)
		{
			if (mSoundInfo->device)
			{
				if (mSoundInfo->device)
				{
					SDL_CloseAudioDevice(mSoundInfo->device);//�ر�����
				}
				if (mSoundInfo->sound)
				{
					SDL_Log("sound:%p", mSoundInfo->sound);
					SDL_FreeWAV(mSoundInfo->sound);//�ͷ��ڴ�
				}
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

	SDL_bool AudioPlayer::IsCompleted()
	{
		if (mSoundInfo)
		{
			return mSoundInfo->completed;
		}
		return SDL_TRUE;
	}

	void AudioPlayer::Destory()
	{
		if (mSoundInfo)
		{
			if (mSoundInfo->OnRelease)
			{
				mSoundInfo->OnRelease(this);
			}
			CloseDevice();
			if (mSoundInfo->flag)
			{
				free(mSoundInfo->flag);
			}
			if (mSoundInfo->file)
			{
				free(mSoundInfo->file);
			}
			free(mSoundInfo);
		}
	}
}
