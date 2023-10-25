#include "ComponentCallback.h"
#include "Text.h"
#include "Config.h"

namespace Dungeon
{

	ComponentCallback::ComponentCallback() :mComponentCallbackData(nullptr)
	{

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
								sprintf(msg,"%s:%s",STATE_TEXT,START_TEXT);
								stateText->TextSet("");
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
								sprintf(msg, "%s:%s", STATE_TEXT, PAUSE_TEXT);
								stateText->TextSet("");
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
								sprintf(msg, "%s:%s", STATE_TEXT, RE_START_TEXT);
								stateText->TextSet("");
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
								sprintf(msg, "%s:%s", STATE_TEXT, STOP_TEXT);
								stateText->TextSet("");
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