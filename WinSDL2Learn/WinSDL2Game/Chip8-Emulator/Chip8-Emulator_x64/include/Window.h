#pragma once
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include <functional>
#include "SDL2/SDL.h"
#include "Button.h"

namespace GUI
{
	class Button;

	// Class responsible for window creation with background image and buttons.
	class Window
	{
		friend class Button;

		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Texture *backgroundImage;
		std::vector<Button *> buttons;
		bool keepWindowOpen;

		void AttachButton(Button *button);

	public:

		Window(int x, int y, const std::string &title);
		~Window();

		void Refresh();
		void HandleEvents();
		void SetBackgroundImage(std::string loadPath);
		bool KeepWindowOpen();
	};
}