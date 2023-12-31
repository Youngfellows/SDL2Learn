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
		mSoundInfo->audioSpec = nullptr;
		mSoundInfo->soundLen = 0;
		mSoundInfo->soundPos = 0;
		mSoundInfo->completed = SDL_FALSE;
		mSoundInfo->device = 0;
		mSoundInfo->state = IDLE;
		mSoundInfo->sound = nullptr;
		mSoundInfo->file = nullptr;
		mSoundInfo->flag = nullptr;
		mSoundInfo->OnCreate = nullptr;
		mSoundInfo->OnStart = nullptr;
		mSoundInfo->OnStop = nullptr;
		mSoundInfo->OnPause = nullptr;
		mSoundInfo->OnComplete = nullptr;
		mSoundInfo->OnRelease = nullptr;
		mSoundInfo->OnProgress = nullptr;
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

		//启动读取音频数据线程,先把缓冲区的数据清空
		if (this->mSuperComputer)
		{
			delete	mSuperComputer;
			mSuperComputer = nullptr;
		}
		this->mSuperComputer = new SuperComputer();
		//设置播放器对象和回调函数给SuperComputer,音频加载完成了再去初始化播放器
		if (!mSuperComputer->Start(srcFileName, destFileName, save, this, &OnLoadAudioCallback))
		{
			return SDL_FALSE;
		}
	}

	/*
	* 音频资源加载成功的回调
	*/
	void AudioPlayer::OnLoadAudioCallback(AudioPlayer *slef, SoundData soundData)
	{
		SDL_Log("AudioPlayer::OnLoadAudioCallback:: Load Sound Success");
		AudioPlayer *audioPlayer = slef;
		//拷贝已经加载好的音频数据
		audioPlayer->mSoundInfo->soundLen = soundData.length;
		audioPlayer->mSoundInfo->sound = (char *)malloc(sizeof(char) * soundData.length);
		if (!audioPlayer->mSoundInfo->sound)
		{
			SDL_Log("Create sound memory error");
			return;
		}
		//注意:一定要用memcpy拷贝二进制数据
		//strcpy(audioPlayer->mSoundInfo->sound, soundData.sound);
		memcpy(audioPlayer->mSoundInfo->sound, soundData.sound, soundData.length);

#ifdef TEST_SAVE_PCM
		const char *fileName = "../x64/Debug/save_2.pcm";
		FILE *file = fopen(fileName, "wb");
		if (!file)
		{
			SDL_Log("open file error: %s", fileName);
			return;
		}
		fwrite(audioPlayer->mSoundInfo->sound, 1, audioPlayer->mSoundInfo->soundLen, file);
		fclose(file);

#endif // TEST_SAVE_PCM

		//创建播放线程并执行
		SDL_Thread *audioThread = SDL_CreateThread(&ThreadCallback, "Audio_Player_Thread", (void *)audioPlayer);
		if (!audioThread)
		{
			SDL_Log("AudioPlayer::OnLoadAudioCallback:: Create Thread Failed: %s", SDL_GetError());
		}
		else
		{
			//int status;
			SDL_Log("AudioPlayer::OnLoadAudioCallback:: Create Thread Success");
			//SDL_WaitThread(audioThread, &status);//等待子线程结束
			//SDL_Log("Thread Return Value:%d", status);
			//SDL_DetachThread(audioThread);//子线程自己运行,不影响主线程执行
			SDL_Log("AudioPlayer::OnLoadAudioCallback:: Create Detach Audio Thread");
		}
		/*this->mSuperComputer->Wait();
		int status;
		SDL_WaitThread(audioThread, &status);*/
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
					//soundInfo->sound = sound;//使用我的线程加载好的音频数据
					//soundInfo->soundLen = soundLen;
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
		const char *psz = "11111111111111111111";
		SDL_Log("AudioPlayer::Destory()::%s", psz);
		if (mSoundInfo)
		{
			if (mSoundInfo->sound)
			{
				free(mSoundInfo->sound);
			}

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
		if (mSuperComputer)
		{
			delete mSuperComputer;
			mSuperComputer = nullptr;
		}
	}
}