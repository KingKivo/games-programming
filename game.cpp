#include "Game.h"

#pragma once

Game::Game()
{
}

bool Game::initialize() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		mWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (mWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			mScreenSurface = SDL_GetWindowSurface(mWindow);
		}

		gBackground = SDL_LoadBMP("images/background.bmp");
		gSprite = SDL_LoadBMP("images/Sprite.bmp");
		gStickman = SDL_LoadBMP("images/stickman.bmp");

		if (gBackground == NULL or gSprite == NULL or gStickman == NULL)
		{
			printf("Unable to load image %s! SDL Error: %s\n", "images/hello_world.bmp", SDL_GetError());
			success = false;
		}

		gSprite = SDL_LoadBMP("images/Sprite.bmp");
		if (gBackground == NULL or gSprite == NULL)
		{
			printf("Unable to load image %s! SDL Error: %s\n", "images/hello_world.bmp", SDL_GetError());
			success = false;
		}
	}

	return success;

	//sprite values
	spriteCoords.x = 510;
	spriteCoords.y = 10;
	spriteCoords.w = gSprite->w;
	spriteCoords.h = gSprite->h;
	//stickman values
	stickmanCoords.x = 20;
	stickmanCoords.y = 40;
	stickmanCoords.w = gStickman->w;
	stickmanCoords.h = gStickman->h;

	xvelocity_Sprite = 1;
	yvelocity_Sprite = 1;

	xvelocity_Stickman = 0;
	yvelocity_Stickman = 0;
}

void Game::runLoop(){
	while (mIsRunning) {
		processInput();
		updateGame();
		generateOutput();
	}
}

void Game::shutdown()
{
	//Deallocate surface
	SDL_FreeSurface(gBackground);
	SDL_FreeSurface(gSprite);
	SDL_FreeSurface(gStickman);
	gBackground = NULL;
	gSprite = NULL;
	gStickman = NULL;

	//Destroy window
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void Game::processInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			mIsRunning = false;
		}
		else if (e.type == SDL_KEYDOWN) {
			/*if (e.key.keysym.sym == SDLK_RIGHT && e.key.keysym.sym == SDLK_UP) {
				bool diagonal = true;
			}*/
			switch (e.key.keysym.sym) {
			case SDLK_q:
				mIsRunning = false;
				break;
			case SDLK_RIGHT:
				if (spriteCoords.x >= SCREEN_WIDTH - spriteCoords.x) {
					std::cout << "sprite x coord: " << spriteCoords.x << "\nsprite y coord: " \
						<< spriteCoords.y << std::endl; //to pinpoint the exact momeny x/y are determined to be out of bounds ill just get their values
					spriteCoords.x = SCREEN_WIDTH - spriteCoords.x;
					std::cout << "You cannot go out of bounds!" << std::endl;
				}
				else {
					spriteCoords.x++;
				}
				std::cout << "right has been pressed" << std::endl;
				xvelocity_Sprite += (int)1.2;
				break;

			case SDLK_LEFT:
				if (spriteCoords.x <= SCREEN_HEIGHT - SCREEN_WIDTH) {
					spriteCoords.x = SCREEN_HEIGHT - SCREEN_WIDTH;
					std::cout << "you cannot go out of bounds!" << std::endl;
				}
				else {
					spriteCoords.x--;
				}
				std::cout << "left has been pressed!" << std::endl;
				xvelocity_Sprite -= (int)1.2;
				break;

			case SDLK_UP:
				if (spriteCoords.y >= SCREEN_HEIGHT - spriteCoords.y) {
					spriteCoords.y = SCREEN_HEIGHT - spriteCoords.y;
					std::cout << "you cannot go out of bounds!" << std::endl;
				}
				else {
					spriteCoords.y--;
				}
				std::cout << "up has been pressed" << std::endl;
				yvelocity_Sprite -= (int)1.2;
				break;

			case SDLK_DOWN:
				if (spriteCoords.y <= SCREEN_HEIGHT - SCREEN_WIDTH) {
					spriteCoords.y = SCREEN_HEIGHT - SCREEN_WIDTH;
					std::cout << "you cannot go out of bounds!" << std::endl;
				}
				else {
					spriteCoords.y++;
				}
				std::cout << "down has been pressed!" << std::endl;
				yvelocity_Sprite += (int)1.2;
				break;

			case SDLK_w:
				if (stickmanCoords.y >= SCREEN_HEIGHT - stickmanCoords.y) {
					stickmanCoords.y = SCREEN_HEIGHT;
					std::cout << "you cannot go out of bounds!" << std::endl;
				}
				else {
					stickmanCoords.y--; //stickman goes up
				}
				std::cout << "w has been pressed" << std::endl;
				yvelocity_Stickman -= (int)1.2;
				break;

			case SDLK_a:
				if (stickmanCoords.x <= 0) {
					stickmanCoords.x = 0;
					std::cout << "you cannot go out of bounds!" << std::endl;
				}
				else {
					stickmanCoords.x--; //stickman goes left
				}
				std::cout << "a has been pressed" << std::endl;
				xvelocity_Stickman -= (int)1.2;
				break;

			case SDLK_s:
				if (stickmanCoords.y <= 0) {
					stickmanCoords.y = 0;
					std::cout << "you cannot go out of bounds!" << std::endl;
				}
				else {
					stickmanCoords.y++; //stickman goes down
				}
				std::cout << "s has been pressed" << std::endl;
				yvelocity_Stickman += (int)1.2;
				break;

			case SDLK_d:
				if (stickmanCoords.x >= SCREEN_WIDTH - stickmanCoords.x) {
					stickmanCoords.y = SCREEN_WIDTH - stickmanCoords.x;
					std::cout << "you cannot go out of bounds!" << std::endl;
				}
				else {
					stickmanCoords.x++; //stickman goes right
				}
				xvelocity_Stickman += (int)1.2;
				break;

			case SDLK_r: //debug key to reset everyones original position 
				std::cout << "\ndebug key was pressed\n" << std::endl;
				xvelocity_Sprite = 0;
				xvelocity_Stickman = 0;
				yvelocity_Sprite = 0;
				yvelocity_Stickman = 0;

				spriteCoords.x = 510;
				spriteCoords.y = 10;
				stickmanCoords.x = 20;
				stickmanCoords.y = 40;
				break;

			case SDLK_t:
				std::cout << "Ticks passed since initialisation: " << SDL_GetTicks << std::endl;
				break;

			default:
				break;
			}
		}
		//on event KEYUP, reset speed to 0 so it doesnt infinitely add up
		else if (e.type == SDL_KEYUP) {
			switch (e.key.keysym.sym) {
				//controls regarding 'sprite'
			case SDLK_RIGHT:
				std::cout << "right has been released" << std::endl;
				//xvelocity_Sprite = 0; 
				break;

			case SDLK_UP:
				std::cout << "up has been released" << std::endl;
				//yvelocity_Sprite = 0;
				break;

			case SDLK_LEFT:
				std::cout << "left has been released" << std::endl;
				//xvelocity_Sprite = 0;
				break;

			case SDLK_DOWN:
				std::cout << "down has been released" << std::endl;
				//yvelocity_Sprite = 0;
				break;
				//controls regarding 'stickman'
			case SDLK_w:
				std::cout << "w has been released" << std::endl;
				yvelocity_Stickman = 0;
				break;

			case SDLK_a:
				std::cout << "a has been released" << std::endl;
				xvelocity_Stickman = 0;
				break;

			case SDLK_s:
				std::cout << "s has been released" << std::endl;
				yvelocity_Stickman = 0;
				break;

			case SDLK_d:
				std::cout << "d has been released" << std::endl;
				xvelocity_Stickman = 0;
				break;

			default:
				break;
			}
		}
	}
}

void Game::updateGame() {
	//bool quit = false;
	spriteCoords.x += xvelocity_Sprite;
	spriteCoords.y += yvelocity_Sprite;
	if (spriteCoords.x + xvelocity_Sprite <= 0 ||
		spriteCoords.x + xvelocity_Sprite >= SCREEN_WIDTH) {
		//spriteCoords.x = SCREEN_WIDTH - spriteCoords.w;
		xvelocity_Sprite = -xvelocity_Sprite;
	}
	//else {
	//	spriteCoords.x += xvelocity_Sprite;
	//}

	if (spriteCoords.y + yvelocity_Sprite <= 0 ||
		spriteCoords.y + yvelocity_Sprite >= SCREEN_HEIGHT) {
		//spriteCoords.y = SCREEN_HEIGHT - spriteCoords.y;
		yvelocity_Sprite = -yvelocity_Sprite;
	}

	if (stickmanCoords.x + xvelocity_Stickman >= SCREEN_WIDTH) {
		stickmanCoords.x = SCREEN_WIDTH - stickmanCoords.x;
	}
	else {
		stickmanCoords.x += xvelocity_Stickman;
	}

	if (stickmanCoords.y + yvelocity_Stickman >= SCREEN_HEIGHT) {
		stickmanCoords.y = SCREEN_HEIGHT - stickmanCoords.y;
	}
	else {
		stickmanCoords.y += yvelocity_Stickman;
	}
}

void Game::generateOutput() {
	SDL_BlitSurface(gBackground, NULL, mScreenSurface, NULL);
	SDL_BlitSurface(gSprite, NULL, mScreenSurface, &spriteCoords);
	SDL_BlitSurface(gStickman, NULL, mScreenSurface, &stickmanCoords);
	SDL_UpdateWindowSurface(mWindow);
}
