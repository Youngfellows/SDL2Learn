#include <SDL/SDL.h> // include SDL header
#include <DrawOnSurface.h>

//#define CAT_PHOTO_FILE "./resources/cat.jpg"
#define CAT_PHOTO_FILE "./resources/cat.bmp"

int main(int argc, char *argv[])
{
	SDL_Surface *screen; // even with SDL2, we can still bring ancient code back
	SDL_Window *window;
	SDL_Surface *image;

	SDL_Init(SDL_INIT_VIDEO); // init video

	// create the window like normal
	window = SDL_CreateWindow(
		"Draw on surface",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		550, 400, 0
	);

	// but instead of creating a renderer, we can draw directly to the screen
	screen = SDL_GetWindowSurface(window);
	image = SDL_LoadBMP(CAT_PHOTO_FILE);
	if (!image)
	{
		SDL_Log("Load img error:%s", SDL_GetError());
		return 1;
	}
	while (1) {
		// fill background
		SDL_FillRect(screen, NULL, 0xffffffff);
		drawRect(screen);
		drawBmp(screen, image);
		SDL_UpdateWindowSurface(window);

		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				break;
			}
		}
	}
	SDL_FreeSurface(image);
	SDL_FreeSurface(screen);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

void drawRect(struct SDL_Surface *surface)
{
	SDL_Rect rect = { 0, 0, 100, 100 };
	SDL_FillRect(surface, &rect, 0xffff0000);
}

void drawBmp(struct SDL_Surface *screen, struct SDL_Surface *image)
{
	SDL_Rect src = { 110, 0, image->w / 2, image->h / 2 };
	SDL_BlitSurface(image, &src, screen, &src);//绘制bmp图片
}
