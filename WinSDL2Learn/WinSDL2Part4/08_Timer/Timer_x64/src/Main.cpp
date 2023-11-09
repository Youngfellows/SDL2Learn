#include <string>
#include <iostream>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "res_path.h"
#include "cleanup.h"
#include "Timer.h"
#include "Window.h"


int  main(int argc, char *argv[])
{
	Window::Init("timer");
	//Our timer:
	Timer timer;

	//Textures to display a message and ticks elapsed
	SDL_Texture *msg = nullptr, *ticks = nullptr;
	//Color for the text
	SDL_Color white = { 255, 255, 255 };
	//Rects for the text
	SDL_Rect msgBox, ticksBox;

	Window::m_pBox.x = 100;
	Window::m_pBox.y = 0;
	Window::m_pBox.h = 100;
	Window::m_pBox.w = 400;

	//Setup msg text
	msg = Window::RenderText("Press Enter to Reset Start Time. ", "./resources/sample.ttf",
		white, 30);

	Window::HandleEvents([&timer, white](SDL_Event e)
		{
			//SDL Event事件回调
			//窗口关闭事件
			if (e.type == SDL_QUIT)
			{
				Window::m_eventQuit = true;
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q)
			{
				//按键q关闭窗口
				Window::m_eventQuit = true;
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
			{
				//按下Enter按键开始计时器
				SDL_Log("Down the Enter key");
				timer.Start();
			}
			else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
			{
				//按下Space空格按键
				SDL_Log("Down the Space key");
				if (!timer.Paused()) {
					timer.Pause();
				}
				else {
					timer.Unpause();
				}
			}

		}, [&timer, white]()
		{
			//SDL绘制回调
			if (timer.Started()) {

				Window::m_pBox.x = 0;
				Window::m_pBox.y = 200;
				Window::m_pBox.h = 100;
				Window::m_pBox.w = 640;

				Window::Clear();
				std::stringstream ssTicks;
				ssTicks << "Since start time ";
				ssTicks << timer.Ticks();
				ssTicks << " ";
				ssTicks << "ms";
				Window::RenderText(ssTicks.str(), "./resources/sample.ttf",
					white, 30);
				ssTicks.str("");
			}

			//Update screen
			SDL_RenderPresent(Window::m_pRenderer.get());
		}
		);
	Window::Quit();
	return 0;
}