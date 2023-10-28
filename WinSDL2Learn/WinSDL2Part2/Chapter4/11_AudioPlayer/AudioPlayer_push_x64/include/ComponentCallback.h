#ifndef _DUNGEON_COMPONENTCALLBACK_H_
#define _DUNGEON_COMPONENTCALLBACK_H_

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "SDL2/SDL.h"
#include "DisplayObject.h"
#include "Text.h"
#include "AudioPlayer.h"

namespace Dungeon
{
	typedef struct ComponentCallbackData
	{
		//AudioPlayer *mAudioPlayer;
		char *message;
		Text *stateText;
		AudioPlayer *audioPlayer;//wav 音频播放器
		char **files;//音频资源
		int size;//资源数量
	}ComponentCallbackData;
}

namespace Dungeon
{
	/*
	* 组件的点击事件回调
	*/
	class ComponentCallback
	{
	private:
		ComponentCallbackData *mComponentCallbackData;

	public:
		ComponentCallback();
		~ComponentCallback();
		DisplayObject *Create();
		void SetStateText(Text *text);
		void SetAudioPlayer(AudioPlayer *audioPlayer);
		static void OnStartTextClickCallback(DisplayObject *self);
		static void OnPauseTextClickCallback(DisplayObject *self);
		static void OnReStartTextClickCallback(DisplayObject *self);
		static void OnStopTextClickCallback(DisplayObject *self);
		static void OnDestoryCallback(DisplayObject *self);

	};
}
#endif // !_DUNGEON_COMPONENTCALLBACK_H_

