#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Game {
public:
	Game();
	bool initialize();
	void runLoop();
	void shutdown();
private:
	void processInput();
	void updateGame();
	void generateOutput();

	SDL_Window* mWindow;
	SDL_Surface* mScreenSurface = NULL;
	SDL_Surface* gBackground = NULL;
	SDL_Surface* gSprite = NULL;
	SDL_Surface* gStickman = NULL;
	SDL_Rect spriteCoords;
	SDL_Rect stickmanCoords;
	int xvelocity_Stickman;
	int yvelocity_Stickman;
	int xvelocity_Sprite;
	int yvelocity_Sprite;
	bool mIsRunning = true;


};
