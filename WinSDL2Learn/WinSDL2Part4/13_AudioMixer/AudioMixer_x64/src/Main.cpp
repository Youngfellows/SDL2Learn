﻿
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <string>

#include "Window.h"

/*
* 使用SDL_mixer播放音频
*/
int main(int argc, char *argv[])
{
	Window::Init("Zoom and Rotate Pic");

	bool success = true;

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	SDL_Texture *pic = Window::LoadImage("./resources/prompt.png");


	//Load music
	Mix_Music *gMusic = Mix_LoadMUS("./resources/beat.wav");
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	//Load sound effects
	Mix_Chunk *gScratch = Mix_LoadWAV("./resources/scratch.wav");
	if (gScratch == NULL)
	{
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	Mix_Chunk *gHigh = Mix_LoadWAV("./resources/high.wav");
	if (gHigh == NULL)
	{
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	Mix_Chunk *gMedium = Mix_LoadWAV("./resources/medium.wav");
	if (gMedium == NULL)
	{
		printf("Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	Mix_Chunk *gLow = Mix_LoadWAV("./resources/low.wav");
	if (gLow == NULL)
	{
		printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}


	Window::HandleEvents([&gMusic, &gHigh, &gMedium, &gLow, &gScratch](SDL_Event e)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				Window::m_eventQuit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_1) {//按键1
					//Play medium sound effect
					Mix_PlayChannel(-1, gHigh, 0);
				}
				else if (e.key.keysym.sym == SDLK_2) {//按键2
					//Play low sound effect
					Mix_PlayChannel(-1, gMedium, 0);
				}
				else if (e.key.keysym.sym == SDLK_3) {//按键3
					//Play scratch sound effect
					Mix_PlayChannel(-1, gLow, 0);
				}
				else if (e.key.keysym.sym == SDLK_4) {//按键4
					Mix_PlayChannel(-1, gScratch, 0);
				}
				else if (e.key.keysym.sym == SDLK_9) {//按键9
					//If there is no music playing
					if (Mix_PlayingMusic() == 0)
					{
						//Play the music
						Mix_PlayMusic(gMusic, -1);//播放
					}
					//If music is being played
					else
					{
						//If the music is paused
						if (Mix_PausedMusic() == 1)
						{
							//Resume the music
							Mix_ResumeMusic();//继续播放
						}
						//If the music is playing
						else
						{
							//Pause the music
							Mix_PauseMusic();//暂停播放
						}
					}
				}
				else if (e.key.keysym.sym == SDLK_0) {//按键0
					//Stop the music
					Mix_HaltMusic();//停止播放
				}

				else if (e.key.keysym.sym == SDLK_p) {

				}
			}
		}, [&pic]()
		{
			Window::Clear();
			SDL_Rect box = Window::Box();
			Window::Draw(pic, box);
			Window::Present();
		});

	//Free loaded images
	SDL_DestroyTexture(pic);

	//Free the sound effects
	Mix_FreeChunk(gScratch);
	Mix_FreeChunk(gHigh);
	Mix_FreeChunk(gMedium);
	Mix_FreeChunk(gLow);

	gScratch = NULL;
	gHigh = NULL;
	gMedium = NULL;
	gLow = NULL;

	//Free the music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;

	//Quit SDL subsystems
	Mix_Quit();

	Window::Quit();
	return 0;
}
