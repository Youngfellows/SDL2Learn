#include "AudioPlayer.h"
#include <iostream>

using namespace std;
using namespace Dungeon;

int main(int argc, char *argv[])
{
	cout << "SDL2 Thread" << endl;
	
	AudioPlayer *audioPlayer = new AudioPlayer();
	audioPlayer->Start();

	SDL_Log("Thread main start");
	SDL_Delay(2*60 * 1000);
	SDL_Log("Thread main finish");

	return 0;
}