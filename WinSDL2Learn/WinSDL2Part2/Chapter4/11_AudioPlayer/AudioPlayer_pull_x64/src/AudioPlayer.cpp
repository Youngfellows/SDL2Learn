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
	* 设置回调函数
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
		// 初始化音频库
		if (SDL_Init(SDL_INIT_AUDIO))
		{
			SDL_Log("Can not init audio: %s", SDL_GetError());
			return SDL_FALSE;
		}

		// 动态申请内存
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
	* 创建播放器
	*/
	SDL_bool AudioPlayer::Create(const char *file)
	{
		if (!mSoundInfo)
		{
			SDL_Log("Can not create audio player");
			return SDL_FALSE;
		}
		CloseDevice();//如果已经打开了播放设备,先关闭

		//动态申请内存
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

		//启动线程,创建线程并执行
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
			//SDL_WaitThread(audioThread, &status);//等待子线程结束
			//SDL_Log("Thread Return Value:%d", status);
			//SDL_DetachThread(audioThread);//子线程自己运行,不影响主线程执行
			SDL_Log("Create:: Detach Audio Thread");
		}
	}

	/*
	* 线程回调函数
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
				//Create创建播放器
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

					
					// 加载音频资源
					if (!SDL_LoadWAV(soundInfo->file, &audioSpec, &sound, &soundLen))
					{
						SDL_Log("Can not load audio: %s", SDL_GetError());
						return SDL_FALSE;
					}
					audioSpec.callback = &AudioCallback;//设置回调函数

					//动态申请内存
					soundInfo->sound = sound;
					soundInfo->soundLen = soundLen;
					soundInfo->soundPos = 0;
					soundInfo->completed = SDL_FALSE;
					soundInfo->device = 0;
					soundInfo->state = IDLE;
					//audioSpec.userdata = mSoundInfo;//设置数据
					audioSpec.userdata = audioPlayer;//设置回调数据

					//打开设备开始播放
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
					return SDL_TRUE;
				}
			}
		}
		return SDL_FALSE;
	}

	/*
	* 播放器回调
	*/
	void SDLCALL AudioPlayer::AudioCallback(void *userdata, Uint8 *stream, int len)
	{
		SDL_Log("AudioCallback len:%d", len);
		AudioPlayer *audioPlayer = (AudioPlayer *)userdata;
		if (!audioPlayer)
		{
			return;
		}
		SDL_memset(stream, 0, len);//清空缓冲区
		SoundInfo *soundInfo = audioPlayer->mSoundInfo;
		if (!soundInfo->completed)
		{
			Uint32 remaining = soundInfo->soundLen - soundInfo->soundPos;//剩余多少没有读取完
			if (remaining > len)
			{
				SDL_memcpy(stream, soundInfo->sound + soundInfo->soundPos, len);//把数据喂到缓冲区
				//SDL_MixAudio(stream, soundInfo->sound + soundInfo->soundPos, len,SDL_MIX_MAXVOLUME);//把数据喂到缓冲区,有bug,没声音
				soundInfo->soundPos += len;//更新已经播放长度
				if (soundInfo->OnProgress)
				{
					soundInfo->OnProgress(audioPlayer, soundInfo->soundLen, soundInfo->soundPos);
				}
			}
			else
			{
				SDL_memcpy(stream, soundInfo->sound + soundInfo->soundPos, remaining);//把数据喂到缓冲区
				//SDL_MixAudio(stream, soundInfo->sound + soundInfo->soundPos, remaining, SDL_MIX_MAXVOLUME);//把数据喂到缓冲区,有bug,没声音
				soundInfo->soundPos = 0;
				soundInfo->completed = SDL_TRUE;//播放完成
				SDL_Log("AudioCallback completed");
			}
		}
		else
		{
			soundInfo->state = IDLE;
			SDL_PauseAudioDevice(soundInfo->device, SDL_TRUE);//暂停
			SDL_Log("AudioCallback Already Play completed");
			if (soundInfo->OnComplete)
			{
				soundInfo->OnComplete(audioPlayer);
			}
		}
	}

	/*
	* 播放
	*/
	void AudioPlayer::Start()
	{
		if (mSoundInfo)
		{
			mSoundInfo->completed = SDL_FALSE;
			if (mSoundInfo->device)
			{
				SDL_PauseAudioDevice(mSoundInfo->device, SDL_FALSE);//不暂停
				mSoundInfo->state = PLAYING;
				if (mSoundInfo->OnStart)
				{
					mSoundInfo->OnStart(this);//回调OnStarCallback
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
				SDL_PauseAudioDevice(mSoundInfo->device, SDL_TRUE);//暂停
				mSoundInfo->state = PAUSE;
				if (mSoundInfo->OnPause)
				{
					mSoundInfo->OnPause(this);
				}
			}
		}
	}

	/*
	* 重新播放
	*/
	void AudioPlayer::ReStart()
	{
		Start();
	}

	/*
	* 停止播放
	*/
	void AudioPlayer::Stop()
	{
		if (mSoundInfo)
		{
			mSoundInfo->state = STOP;
			if (mSoundInfo->device)
			{
				SDL_PauseAudioDevice(mSoundInfo->device, SDL_TRUE);//暂停
			}
			mSoundInfo->soundPos = 0;
			mSoundInfo->completed = SDL_TRUE;//播放完成
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
					SDL_CloseAudioDevice(mSoundInfo->device);//关闭声卡
				}
				if (mSoundInfo->sound)
				{
					SDL_Log("sound:%p", mSoundInfo->sound);
					SDL_FreeWAV(mSoundInfo->sound);//释放内存
				}
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