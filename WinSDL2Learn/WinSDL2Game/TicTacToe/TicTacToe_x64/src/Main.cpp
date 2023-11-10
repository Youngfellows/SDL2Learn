/* Tic-Tac-Toe using SDL2 */
#include <iostream>
#include <SDL2/SDL.h>

#include "Button.h"

// Define a player and state of a cell
static enum class State
{
	NONE,
	CROSS,
	CIRCLE,
};

// Each cell is a button and has a state
static struct Cell : Button
{
	State state;
	Cell() : state(State::NONE)
	{
	}
};

// Get index
inline int getIndex(const int cols, const int row, const int col)
{
	return cols * row + col;
}

// Load texture
SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *filePath)
{
	SDL_Texture *texture = nullptr;
	SDL_Surface *loadedSurface = nullptr;

	loadedSurface = SDL_LoadBMP(filePath);
	if (loadedSurface == nullptr)
	{
		std::cout << "SDL could not load texture! Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (texture == nullptr)
		{
			std::cout << "SDL could not create texture from surface! Error: " << SDL_GetError() << std::endl;
		}
	}

	SDL_FreeSurface(loadedSurface);
	return texture;
}


int main(int argc, char *argcv[])
{
	// Define window dimensions
	const int windowWidth = 500;
	const int windowHeight = windowWidth;

	// Initalise SDL video subsystem
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL could not intialise! Error: " << SDL_GetError() << std::endl;
		return -1;
	}

	// Create window
	SDL_Window *window = SDL_CreateWindow("Tic-Tac-Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "SDL could not create window! Error: " << SDL_GetError() << std::endl;
		return -1;
	}

	// Create renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == nullptr)
	{
		std::cout << "SDL could not create renderer! Error: " << SDL_GetError() << std::endl;
		return -1;
	}

	// Load textures for cross("X"), circle("O"), and an empty texture
	SDL_Texture *cross = loadTexture(renderer, "assets/Cross.bmp");
	SDL_Texture *circle = loadTexture(renderer, "assets/Circle.bmp");
	SDL_Texture *empty = loadTexture(renderer, "assets/Empty.bmp");

	// Create 3 x 3 grid of Cells
	const int rows = 3;
	const int cols = 3;
	const int totalCells = rows * cols;
	Cell grid[totalCells];

	// Define borders and thus dimensions of cells
	const int borderThickness = 10;
	const int buttonWidth = (windowWidth - 4 * borderThickness) / cols;
	const int buttonHeight = buttonWidth;

	// Set all cell starting positions, dimensions and state
	int cellStartY = borderThickness;
	for (int row = 0; row < rows; row++)
	{
		int cellStartX = borderThickness;
		for (int col = 0; col < cols; col++)
		{
			// Get index
			int index = getIndex(cols, row, col);

			// Set starting position and dimensions
			SDL_Rect rect = { cellStartX, cellStartY, buttonWidth, buttonHeight };
			grid[index].setButtonRect(rect);

			// Set to empty texture and center each texture onto button
			grid[index].setTexture(empty);
			grid[index].centerTextureRect();

			cellStartX += buttonWidth + borderThickness;
		}
		cellStartY += buttonHeight + borderThickness;
	}

	// Loop variables
	bool stop = false;
	SDL_Event event;
	State player = State::CIRCLE;
	State winner = State::NONE;
	int cellsFilled = 0;
	SDL_Color lightBlue = { 55, 171, 255, 255 };
	SDL_Color red = { 255, 0, 0, 255 };

	while (!stop)
	{
		// Handle events on queue
		while (SDL_PollEvent(&event) != 0)
		{
			// Handle quiting
			if (event.type == SDL_QUIT)
			{
				stop = true;
			}

			// If winner or no winner and all cells filled	
			if (winner == State::CIRCLE || winner == State::CROSS || (winner == State::NONE && cellsFilled == totalCells))
			{
				// Wait until another mouse down event to reset grid
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					// Clear
					for (int i = 0; i < totalCells; i++)
					{
						grid[i].state = State::NONE;
						grid[i].setTexture(empty);
						grid[i].setBackground({ 255,255,255,255 });
					}

					winner = State::NONE;
					cellsFilled = 0;
				}
			}
			// else no winner
			else
			{
				// Get mouse position and handle mouse events
				int x, y;
				SDL_GetMouseState(&x, &y);
				for (int i = 0; i < totalCells; i++)
				{
					// If cell is empty
					if (grid[i].state == State::NONE)
					{
						// If mouse down and inside the cell (Game logic)
						if (event.type == SDL_MOUSEBUTTONDOWN && grid[i].isMouseInside(x, y))
						{
							// Set state equal to state of player i.e. their symbol
							grid[i].state = player;
							cellsFilled++;

							// Set background colour for winning condition depending on winner
							SDL_Color background;
							if (player == State::CIRCLE) background = red;
							else background = lightBlue;

							/* CIRCLE */
							// Check each row
							if (grid[0].state == player && grid[1].state == player && grid[2].state == player)
							{
								grid[0].setBackground(background);
								grid[1].setBackground(background);
								grid[2].setBackground(background);
								winner = player;
							}
							if (grid[3].state == player && grid[4].state == player && grid[5].state == player)
							{
								grid[3].setBackground(background);
								grid[4].setBackground(background);
								grid[5].setBackground(background);
								winner = player;
							}
							if (grid[6].state == player && grid[7].state == player && grid[8].state == player)
							{
								grid[6].setBackground(background);
								grid[7].setBackground(background);
								grid[8].setBackground(background);
								winner = player;
							}

							// Check each col
							if (grid[0].state == player && grid[3].state == player && grid[6].state == player)
							{
								grid[0].setBackground(background);
								grid[3].setBackground(background);
								grid[6].setBackground(background);
								winner = player;
							}
							if (grid[1].state == player && grid[4].state == player && grid[7].state == player)
							{
								grid[1].setBackground(background);
								grid[4].setBackground(background);
								grid[7].setBackground(background);
								winner = player;
							}
							if (grid[2].state == player && grid[5].state == player && grid[8].state == player)
							{
								grid[2].setBackground(background);
								grid[5].setBackground(background);
								grid[8].setBackground(background);
								winner = player;
							}

							// Check diagonals
							if (grid[0].state == player && grid[4].state == player && grid[8].state == player)
							{
								grid[0].setBackground(background);
								grid[4].setBackground(background);
								grid[8].setBackground(background);
								winner = player;
							}
							if (grid[2].state == player && grid[4].state == player && grid[6].state == player)
							{
								grid[2].setBackground(background);
								grid[4].setBackground(background);
								grid[6].setBackground(background);
								winner = player;
							}

							// Switch players and set textures
							if (player == State::CIRCLE)
							{
								// Set circle texture and switch player to cross
								grid[i].setTexture(circle);
								player = State::CROSS;
							}
							else
							{
								// Set cross texture and switch player to circle
								grid[i].setTexture(cross);
								player = State::CIRCLE;
							}
						}
					}
				}
			}
		}

		// Clear screen to colour of current player
		if (player == State::CIRCLE)
		{
			// Red
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		}
		else
		{
			// Light blue
			SDL_SetRenderDrawColor(renderer, 55, 171, 255, 255);
		}
		SDL_RenderClear(renderer);

		// Render background and texture of every button
		for (int i = 0; i < totalCells; i++)
		{
			grid[i].renderBackground(renderer);
			grid[i].renderTexture(renderer);
		}

		// Update screen from backbuffer and clear backbuffer
		SDL_RenderPresent(renderer);

		// Slow down program
		SDL_Delay(10);

	}

	// Free textures
	SDL_DestroyTexture(cross);
	SDL_DestroyTexture(circle);
	cross = nullptr;
	window = nullptr;

	// Destroy renderer and window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = nullptr;
	window = nullptr;

	// Quit
	SDL_Quit();

	return 0;
}