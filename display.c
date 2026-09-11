#include "display.h"
#include <SDL2/SDL_video.h>

int setupDisplay(Display *display){

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
		return 1;
	}

	display->window = SDL_CreateWindow("File Explorer",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			0);
	if (!display->window) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	display->renderer = SDL_CreateRenderer(display->window, -1, SDL_RENDERER_ACCELERATED);
	if (!display->renderer) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}
	return 0;
}

void killDisplay(Display *display){
	if(display->window){
		SDL_DestroyWindow(display->window);
	}
	SDL_Quit();
}
