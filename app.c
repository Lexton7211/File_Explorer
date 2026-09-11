#include "display.h"
#include <SDL2/SDL_timer.h>

int main(){
	Display display;
	if(setupDisplay(&display) != 0){
		return 1;
	}

	int running = 1;
	SDL_Event event;
	while(running){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				running = 0;
				continue;
			}
		}

		
		
		SDL_SetRenderDrawColor(display.renderer, 255, 255, 255, 255);
		SDL_RenderClear(display.renderer);
		SDL_RenderPresent(display.renderer);
		SDL_Delay(10);
	}
	
	return 0;
}
