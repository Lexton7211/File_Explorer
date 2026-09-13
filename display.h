#ifndef DISPLAY_H
#define DISPLAY_H
#define WINDOW_WIDTH 1400
#define WINDOW_HEIGHT 850

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>

extern SDL_Color white;
extern TTF_Font* font;

typedef struct {
	SDL_Window *window;
	SDL_Renderer *renderer;
} Display;

typedef struct {
	SDL_Texture* texture;
	char cached_text[256];
} TextCache;

int setupDisplay(Display *display);
void killDisplay(Display *display);
void createText(Display *display, TextCache *cache, const char* text, int x, int y, int w, int h);

#endif
