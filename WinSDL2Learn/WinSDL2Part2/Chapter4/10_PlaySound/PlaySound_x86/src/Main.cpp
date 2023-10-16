#include <iostream>
#include "AudioPlayer.h"
#include "Config.h"
#include "AudioPlayerCallback.h"

using namespace std;
using namespace Dungeon;

int main(int argc, char *argv[])
{
	cout << "Hello SDL2 Audio" << endl;

	AudioPlayer *mAudioPlayer = new AudioPlayer();
	AudioPlayerCallback *callback = new AudioPlayerCallback();
	mAudioPlayer->SetAudioPlayerCallback(&AudioPlayerCallback::OnStartCallback,
		&AudioPlayerCallback::OnPauseCallback,
		&AudioPlayerCallback::OnStopCallback,
		&AudioPlayerCallback::OnReleaseCallback,
		&AudioPlayerCallback::OnCompleteCallback);
	if (mAudioPlayer->InitAudio())
	{
		if (mAudioPlayer->Create(SOUND_FILE_NAME))
		{
			mAudioPlayer->Start();
		}
	}


	return 0;
}