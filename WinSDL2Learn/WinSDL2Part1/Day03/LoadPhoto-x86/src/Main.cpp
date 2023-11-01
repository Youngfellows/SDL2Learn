#include "Game.h"

//using namespace Dungeon;

int main(int argc, char *argv[])
{
	Dungeon::Game *game = new Dungeon::Game();
	if (game->Initialize())
	{
		game->Loop();
	}
	game->Shutdown();
	delete game;
	return 0;
}