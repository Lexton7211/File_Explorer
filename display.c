#include "display.h"
#include <SDL2/SDL_surface.h>

SDL_Color white = {255, 255, 255, 255};
TTF_Font *font = NULL;
int setupDisplay(Display *display){
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
		return 1;
	}

	if (TTF_Init() != 0) {
		fprintf(stderr, "TTF failed to initialise: %s\n", TTF_GetError());
		return 1;
	}
	font = TTF_OpenFont("assets/saira-font.ttf", 24);
	if(!font){
		printf("Problem loading font\n");
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

void createText(Display *display, TextCache *cache, const char* text, int x, int y, int w, int h){
    if (cache->texture == NULL || strcmp(cache->cached_text, text) != 0) {
        if (cache->texture) {
            SDL_DestroyTexture(cache->texture);
        }
        SDL_Surface* surface_message = TTF_RenderText_Solid(font, text, white);
        cache->texture = SDL_CreateTextureFromSurface(display->renderer, surface_message);
        SDL_FreeSurface(surface_message);
        strncpy(cache->cached_text, text, sizeof(cache->cached_text) - 1);
    }

    SDL_Rect message_rect = { x, y, w, h };
    SDL_RenderCopy(display->renderer, cache->texture, NULL, &message_rect);
}
