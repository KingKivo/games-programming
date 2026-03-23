#include "Game.h"

int main(int argc, char* args[]) {
	Game newGame = Game();

	newGame.initialize();
	newGame.runLoop();
	newGame.shutdown();

	return 0;
}
