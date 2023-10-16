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
		// 初始化音频库
		if (SDL_Init(SDL_INIT_AUDIO))
		{
			SDL_Log("Can not init audio: %s", SDL_GetError());
			return SDL_FALSE;
		}
		return SDL_TRUE;
	}

	/*
	* 创建播放器
	*/
	SDL_bool AudioPlayer::Create(const char *file)
	{
		SDL_AudioSpec audioSpec;
		Uint8 *sound;
		Uint32 soundLen;

		// 加载音频资源
		if (!SDL_LoadWAV(file, &audioSpec, &sound, &soundLen))
		{
			SDL_Log("Can not load audio: %s", SDL_GetError());
			return SDL_FALSE;
		}
		audioSpec.callback = &AudioCallback;//设置回调函数

		//动态申请内存
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
		audioSpec.userdata = mSoundInfo;//设置数据

		//打开设备开始播放
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
	* 播放器回调
	*/
	void SDLCALL AudioPlayer::AudioCallback(void *userdata, Uint8 *stream, int len)
	{
		SDL_Log("AudioCallback len:%d", len);
		SoundInfo *soundInfo = (SoundInfo *)userdata;
		Uint32 remaining = soundInfo->soundLen - soundInfo->soundPos;//剩余多少没有读取完
		if (remaining > len)
		{
			SDL_memcpy(stream, soundInfo->sound + soundInfo->soundPos, len);
			soundInfo->soundPos += len;//更新已经播放长度
		}
		else
		{
			SDL_memcpy(stream, soundInfo->sound + soundInfo->soundPos, remaining);
			soundInfo->soundPos = 0;
			soundInfo->completed = SDL_TRUE;//播放完成
			SDL_Log("AudioCallback completed");
		}
	}

	/*
	* 播放
	*/
	void AudioPlayer::Start()
	{
		if (mSoundInfo)
		{
			if (mSoundInfo->device)
			{
				SDL_PauseAudioDevice(mSoundInfo->device, SDL_FALSE);//不暂停
				mSoundInfo->state = PLAYING;
				if (OnStart)
				{
					OnStart(this);//回调开始
				}
				//产生一个阻塞的效果
				while (1)
				{
					if (mSoundInfo->completed)
					{
						//break;
						goto GO_TO_COMPLETE;//1. goto 到播放完成	
					}

					//if (暂停播放)
					//{
					//	//2. goto 到暂停播放
					//	break;
					//}
				
					if (mSoundInfo->state==STOP)
					{
						//break;
						goto GO_TO_STOP;//3. goto 到停止播放
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
		CloseDevice();//关闭资源
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
				SDL_PauseAudioDevice(mSoundInfo->device, SDL_TRUE);//暂停
				mSoundInfo->state = PAUSE;
				if (OnPause)
				{
					OnPause(this);
				}
			}
		}
	}

	/*
	* 重新播放
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
	* 停止播放
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
				SDL_CloseAudioDevice(mSoundInfo->device);//关闭声卡
				SDL_FreeWAV(mSoundInfo->sound);//是否内存
			}
		}
	}

	/*
	* 是否正在播放
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
