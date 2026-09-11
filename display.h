#ifndef DISPLAY_H
#define DISPLAY_H
#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700

#include <stdio.h>
#include <SDL2/SDL.h>

typedef struct {
	SDL_Window *window;
	SDL_Renderer *renderer;
} Display;

int setupDisplay(Display *display);
void killDisplay(Display *display);

#endif
