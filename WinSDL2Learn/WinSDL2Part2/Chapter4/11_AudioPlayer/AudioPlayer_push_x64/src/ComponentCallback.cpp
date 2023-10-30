#include "ComponentCallback.h"
#include "Text.h"
#include "Config.h"
#include <ctime>

namespace Dungeon
{

	ComponentCallback::ComponentCallback() :mComponentCallbackData(nullptr)
	{
		srand(time(0));//设置随机数种子
	}

	ComponentCallback::~ComponentCallback()
	{

	}

	void ComponentCallback::SetStateText(Text *text)
	{
		if (mComponentCallbackData)
		{
			mComponentCallbackData->stateText = text;//设置要更新的组件对象
		}
	}

	void ComponentCallback::SetAudioPlayer(AudioPlayer *audioPlayer)
	{
		if (mComponentCallbackData)
		{
			mComponentCallbackData->audioPlayer = audioPlayer;//设置播放器对象指针
		}
	}

	DisplayObject *ComponentCallback::Create()
	{
		//动态申请内存
		this->mComponentCallbackData = (ComponentCallbackData *)malloc(sizeof(ComponentCallbackData));
		if (!mComponentCallbackData)
		{
			return nullptr;
		}
		const char *psz = "Hello SDL Audio Player";
		mComponentCallbackData->message = (char *)malloc(sizeof(char) * (strlen(psz) + 1));
		if (!mComponentCallbackData->message)
		{
			return nullptr;
		}
		strcpy(mComponentCallbackData->message, psz);
		SDL_Log("ComponentCallback::Create:: %s", mComponentCallbackData->message);
		mComponentCallbackData->stateText = nullptr;
		mComponentCallbackData->audioPlayer = nullptr;

		//设置播放资源
		mComponentCallbackData->size = WAV_SOUND_SIZE;
		mComponentCallbackData->files = (char **)malloc(sizeof(char *) * (mComponentCallbackData->size));//创建二维数组
		if (!mComponentCallbackData->files)
		{
			return nullptr;
		}
		//动态申请数组元素0内存
		char *file0 = (char *)malloc(sizeof(char *) * strlen(WAV_SOUND_FILE_NAME)+1);
		if (!file0)
		{
			return nullptr;
		}
		strcpy(file0, WAV_SOUND_FILE_NAME);//为数组元素0赋值
		*(mComponentCallbackData->files + 0) = file0;//为二维数组元素赋值

		char *file1 = (char *)malloc(sizeof(char *) * strlen(PCM_2_FILE_NAME) + 1);
		if (!file1)
		{
			return nullptr;
		}
		strcpy(file1, PCM_2_FILE_NAME);//为数组元素0赋值
		*(mComponentCallbackData->files + 1) = file1;//为二维数组元素赋值


		//设置组件对象
		DisplayObject *displayObject = new DisplayObject();
		displayObject->SetSubClass(this);//把当前对象设置过去
		OnCallbackData *onCallback = displayObject->GetOnCallback();
		if (onCallback)
		{
			onCallback->OnDestory = &OnDestoryCallback;//设置回调函数
		}
		return displayObject;
	}

	void ComponentCallback::OnStartTextClickCallback(DisplayObject *self)
	{
		Text *start = (Text *)self->GetSubClass();
		//SDL_Log("ComponentCallback::OnStartTextClickCallback:: start:%p", start);
		if (start)
		{
			TextData *textData = start->GetTextData();
			if (textData)
			{
				DisplayObject *disObj = (DisplayObject *)textData->destObj;
				if (disObj)
				{
					ComponentCallback *callback = (ComponentCallback *)disObj->GetSubClass();
					if (callback)
					{
						ComponentCallbackData *data = callback->mComponentCallbackData;
						if (data)
						{
							char *msg = data->message;//获取成员
							SDL_Log("ComponentCallback::OnStartTextClickCallback::%s", msg);
							Text *stateText = data->stateText;
							if (stateText)
							{
								char msg[128];
								sprintf(msg, "%s: %s", STATE_TEXT, START_TEXT);
								stateText->TextSet(msg);
							}
							AudioPlayer *player = data->audioPlayer;
							if (player)
							{
								int index = rand() % WAV_SOUND_SIZE;
								char *file = *(data->files + index);
								SDL_Log("ComponentCallback::OnStartTextClickCallback:: index:%d,file:%s", index, file);

								//设置音频参数
								SDL_AudioSpec audioSpec;
								//audioSpec.freq = 44100;;
								//audioSpec.format = AUDIO_S32SYS;//AUDIO_U16SYS,AUDIO_S16SYS,AUDIO_S32SYS,AUDIO_F32SYS
								//audioSpec.channels = 2;
								//audioSpec.silence = 0;
								//audioSpec.samples = 2048;

								//player->Create(&audioSpec,PCM_2_FILE_NAME,SAVE_FILE_NAME,SDL_FALSE);//创建播放器并播放
								player->Create(&audioSpec, file,SAVE_FILE_NAME,SDL_FALSE);//创建播放器并播放
							}
						}
					}
				}
			}
		}
	}

	void ComponentCallback::OnPauseTextClickCallback(DisplayObject *self)
	{
		Text *pause = (Text *)self->GetSubClass();
		if (pause)
		{
			TextData *textData = pause->GetTextData();
			if (textData)
			{
				DisplayObject *disObj = (DisplayObject *)textData->destObj;
				if (disObj)
				{
					ComponentCallback *callback = (ComponentCallback *)disObj->GetSubClass();
					if (callback)
					{
						ComponentCallbackData *data = callback->mComponentCallbackData;
						if (data)
						{
							char *msg = data->message;//获取成员
							SDL_Log("ComponentCallback::OnPauseTextClickCallback::%s", msg);
							Text *stateText = data->stateText;
							if (stateText)
							{
								char msg[128];
								sprintf(msg, "%s: %s", STATE_TEXT, PAUSE_TEXT);
								stateText->TextSet(msg);
							}
							AudioPlayer *player = data->audioPlayer;
							if (player)
							{
								player->Pause();//暂停播放
							}
						}
					}
				}
			}
		}
	}

	void ComponentCallback::OnReStartTextClickCallback(DisplayObject *self)
	{
		Text *restart = (Text *)self->GetSubClass();
		if (restart)
		{
			TextData *textData = restart->GetTextData();
			if (textData)
			{
				DisplayObject *disObj = (DisplayObject *)textData->destObj;
				if (disObj)
				{
					ComponentCallback *callback = (ComponentCallback *)disObj->GetSubClass();
					if (callback)
					{
						ComponentCallbackData *data = callback->mComponentCallbackData;
						if (data)
						{
							char *msg = data->message;//获取成员
							SDL_Log("ComponentCallback::OnReStartTextClickCallback::%s", msg);
							Text *stateText = data->stateText;
							if (stateText)
							{
								char msg[128];
								sprintf(msg, "%s: %s", STATE_TEXT, RE_START_TEXT);
								stateText->TextSet(msg);
							}
							AudioPlayer *player = data->audioPlayer;
							if (player)
							{
								player->ReStart();//从新播放
							}
						}

					}
				}
			}
		}
	}

	void ComponentCallback::OnStopTextClickCallback(DisplayObject *self)
	{
		Text *stop = (Text *)self->GetSubClass();
		if (stop)
		{
			TextData *textData = stop->GetTextData();
			if (textData)
			{
				DisplayObject *disObj = (DisplayObject *)textData->destObj;
				if (disObj)
				{
					ComponentCallback *callback = (ComponentCallback *)disObj->GetSubClass();
					if (callback)
					{
						ComponentCallbackData *data = callback->mComponentCallbackData;
						if (data)
						{
							char *msg = data->message;//获取成员
							SDL_Log("ComponentCallback::OnStopTextClickCallback::%s", msg);
							Text *stateText = data->stateText;
							if (stateText)
							{
								char msg[128];
								sprintf(msg, "%s: %s", STATE_TEXT, STOP_TEXT);
								stateText->TextSet(msg);
							}
							AudioPlayer *player = data->audioPlayer;
							if (player)
							{
								player->Stop();//停止播放
							}
						}
					}
				}
			}
		}
	}

	void ComponentCallback::OnDestoryCallback(DisplayObject *self)
	{
		ComponentCallback *componentCallback = (ComponentCallback *)self->GetSubClass();
		if (componentCallback)
		{
			ComponentCallbackData *data = componentCallback->mComponentCallbackData;
			if (data)
			{
				char *msg = data->message;//获取成员
				SDL_Log("ComponentCallback::OnDestoryCallback::%s", msg);
				free(msg);
				free(data);
				msg = nullptr;
				data = nullptr;
			}
		}
	}
}