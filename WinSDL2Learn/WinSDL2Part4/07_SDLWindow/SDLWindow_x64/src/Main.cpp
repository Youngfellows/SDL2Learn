#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Window.h"

int main(int argc, char *argv[])
{
	//Show A Window
	//In main()
	//Load up an image and some text
	SDL_Texture *img, *msg;
	try {
		//Start our window
		Window::Init("Shiver's Window");

		int angle = 0;

		Window::HandleEvents([](SDL_Event e)
			{
				switch (e.key.keysym.sym) {
				case SDLK_q://按下按钮q或者Esc按键,关闭窗口
				case SDLK_ESCAPE:
					Window::m_eventQuit = true;
					break;
				}
				//按下按键a,显示文本
				if (e.key.keysym.sym == SDLK_a) {
					printf("keydown A \n");
					Window::Clear();
					std::string fontFile = "./resources/sample.ttf";
					std::string text = "TTF Fonts too!";
					SDL_Color color = { 255, 255, 255 };
					SDL_Texture *texture = Window::RenderText(text, fontFile, color, 25);
					SDL_DestroyTexture(texture);
				}

				//按下按键f,显示图片
				if (e.key.keysym.sym == SDLK_f) {
					printf("keydown F \n");
					Window::Clear();
					std::string imgFile = "./resources/image.png";
					SDL_Texture *image = Window::LoadImage(imgFile);
					SDL_DestroyTexture(image);
				}
			});



		Window::Quit();
	}
	catch (const std::runtime_error &e) {
		//Catch error and crash
		std::cout << e.what() << std::endl;
		Window::Quit();
		return -1;
	}
	return 0;
}