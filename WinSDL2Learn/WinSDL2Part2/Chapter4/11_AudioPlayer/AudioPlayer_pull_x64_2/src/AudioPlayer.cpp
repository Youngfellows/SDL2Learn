#include "AudioPlayer.h"
#include "Config.h"

namespace Dungeon
{
	AudioPlayer::AudioPlayer() :mSoundInfo(nullptr), mSuperComputer(nullptr)
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
		//mSoundInfo->sound = nullptr;
		mSoundInfo->file = nullptr;
		mSoundInfo->flag = nullptr;
		return SDL_TRUE;
	}

	/*
	* 创建播放器
	*/
	SDL_bool AudioPlayer::Create(SDL_AudioSpec *audioSpec, const char *srcFileName,
		const char *destFileName, SDL_bool save)
	{
		if (!mSoundInfo)
		{
			SDL_Log("Can not create audio player");
			return SDL_FALSE;
		}
		if (!audioSpec)
		{
			SDL_Log("Can not create audio player,audioSpec is null");
			return SDL_FALSE;
		}
		CloseDevice();//如果已经打开了播放设备,先关闭

		//动态申请内存
		mSoundInfo->file = (char *)malloc(sizeof(char) * SDL_strlen(srcFileName) + 1);
		if (mSoundInfo->file)
		{
			SDL_strlcpy(mSoundInfo->file, srcFileName, SDL_strlen(srcFileName) + 1);
		}
		mSoundInfo->flag = (char *)malloc(sizeof(char) * SDL_strlen(FLAG_CREATE_AUDIO_PLAYER) + 1);
		if (mSoundInfo->flag)
		{
			SDL_strlcpy(mSoundInfo->flag, FLAG_CREATE_AUDIO_PLAYER, SDL_strlen(FLAG_CREATE_AUDIO_PLAYER) + 1);
		}

		//初始化一些参数
		mSoundInfo->soundLen = 0;
		mSoundInfo->soundPos = 0;
		mSoundInfo->completed = SDL_FALSE;
		mSoundInfo->device = 0;
		mSoundInfo->state = IDLE;
		mSoundInfo->audioSpec = audioSpec;//初始化音频参数

		//启动读取音频数据线程
		this->mSuperComputer = new SuperComputer();
		//设置播放器对象和回调函数给SuperComputer
		//if (!mSuperComputer->Start(srcFileName, destFileName, save,this, &OnAudioCallback))
		if (!mSuperComputer->Start(srcFileName, destFileName, save, this, nullptr))
		{
			return SDL_FALSE;
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
		/*this->mSuperComputer->Wait();
		int status;
		SDL_WaitThread(audioThread, &status);*/
	}

	/*
	* 1.线程回调函数
	* 2.采用push的方式播放音频
	*/
	void AudioPlayer::OnAudioCallback(AudioPlayer *self, AudioInfo *audioInfo)
	{
		if (self)
		{
			SoundInfo *soundInfo = self->mSoundInfo;
			if (soundInfo)
			{
				SDL_Log("OnAudioCallback:: State:%d", soundInfo->state);
				if (soundInfo->state == PLAYING)
				{
					SDL_Log("OnAudioCallback:: feed audio,State:%d", soundInfo->state);
					//填充音频数据push方式
					SDL_QueueAudio(soundInfo->device, audioInfo->pcm, audioInfo->len);
				}
			}
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

					// 获取配置的音频参数
					SDL_AudioSpec *audioSpec = soundInfo->audioSpec;
					if (!audioSpec)
					{
						SDL_Log("Can not open audio device,audioSpec is null");
						return SDL_FALSE;
					}
					Uint8 *sound;
					Uint32 soundLen;

					// 加载音频资源
					if (!SDL_LoadWAV(soundInfo->file, audioSpec, &sound, &soundLen))
					{
						SDL_Log("Can not load audio: %s", SDL_GetError());
						return SDL_FALSE;
					}
					//soundInfo->sound = sound;
					soundInfo->soundLen = soundLen;
					soundInfo->soundPos = 0;
					soundInfo->completed = SDL_FALSE;
					soundInfo->device = 0;
					soundInfo->state = IDLE;

					audioSpec->callback = &AudioCallback;//设置回调函数,pull方式,会出现问题
					//audioSpec->callback = nullptr;//设置回调函数,pull方式,会出现问题
					audioSpec->userdata = audioPlayer;//设置回调数据

					// 打开音频设备
					SDL_AudioSpec obtainSpec;
					SDL_AudioDeviceID device = SDL_OpenAudioDevice(nullptr,
						SDL_FALSE, audioSpec, &obtainSpec, 0);
					SDL_Log("obtainSpec: format:%d", obtainSpec.format);
					if (!device)
					{
						SDL_Log("Can not open audio device: %s", SDL_GetError());
						return SDL_FALSE;
					}
					soundInfo->device = device;

					/*if (SDL_OpenAudio(audioSpec, &obtainSpec) != 0)
					{
						SDL_Log("Can not open audio device: %s", SDL_GetError());
						return SDL_FALSE;
					}*/

					SDL_Log("ThreadCallback: %s", "Create Audio Player Success");
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
	* 播放器回调,向SuperComputer要列表中的数据来进行播放
	*/
	void SDLCALL AudioPlayer::AudioCallback(void *userdata, Uint8 *stream, int len)
	{
		SDL_Log("AudioPlayer::AudioCallback: 222222222222222,len:%d", len);

		AudioPlayer *audioPlayer = (AudioPlayer *)userdata;
		if (!audioPlayer)
		{
			return;
		}
		SDL_memset(stream, 0, len);//清空缓冲区
		SuperComputer *superComputer = audioPlayer->mSuperComputer;
		if (superComputer)
		{
			SoundInfo *soundInfo = audioPlayer->mSoundInfo;
			//这种方式不好，会出现声音卡顿现象,原因容器每一个buffer可能太小,解决办法
			// 1. 最好的方式是把声音全部加载到内存中
			// 2. 容器每一个buffer的内存要足够大,最好与len相同
			AudioInfo *audio = superComputer->GetAudio();//向线程列表要音频数据
			if (audio)
			{
				if (audio->len)
				{
					//buffer太大了会丢数据
					SDL_memcpy(stream, audio->pcm, len);//把数据喂到缓冲区
				}
				else
				{
					//buffer太小了会出现播放声音不连续
					SDL_memcpy(stream, audio->pcm, audio->len);//把数据喂到缓冲区
				}
				soundInfo->soundPos = audio->pos;
				if (soundInfo->OnProgress)
				{
					soundInfo->OnProgress(audioPlayer, audio->size, audio->pos);
				}

				if (audio->end)
				{
					soundInfo->soundPos = 0;
					soundInfo->completed = SDL_TRUE;//播放完成
					soundInfo->state = IDLE;
					//SDL_PauseAudioDevice(soundInfo->device, SDL_TRUE);//暂停
					SDL_Log("AudioCallback Already Play completed");
					if (soundInfo->OnComplete)
					{
						soundInfo->OnComplete(audioPlayer);
					}
				}
				//释放内存
				free(audio->pcm);
				free(audio);
			}
			else
			{
				SDL_Log("Get Audio is nullptr");
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
				SDL_ClearQueuedAudio(mSoundInfo->device);//丢弃所有等待发送到硬件的排队音频数据
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
					SDL_ClearQueuedAudio(mSoundInfo->device);//丢弃所有等待发送到硬件的排队音频数据
					//SDL_CloseAudioDevice(mSoundInfo->device);//关闭声卡
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
		if (mSuperComputer)
		{
			delete mSuperComputer;
			mSuperComputer = nullptr;
		}
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