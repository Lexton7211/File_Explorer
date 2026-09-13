#include "display.h"
#include "logic.h"
#include "vector.h"

int main(int argc, char *argv[]){
	Display display;
	if(setupDisplay(&display) != 0){
		return 1;
	}
	
	char *currentDir = systemCommand("pwd");
	char *files = systemCommand("ls -a");
	if(currentDir == NULL){
		return 1;
	}
	if(files == NULL){
		return 1;
	}
	//printf("Current Directory: %s\n", currentDir);
	//printf("Files In Directory: \n%s\n", files);
	

	//Vector text_caches;
	TextCache hello_cache;
	//vector_setup(&text_caches, 20, sizeof(TextCache));
	//vector_push_back(&text_caches, &)
	int running = 1;
	SDL_Event event;
	while(running){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				running = 0;
				continue;
			}
		}


		SDL_SetRenderDrawColor(display.renderer, 19, 18, 38, 255);
		SDL_RenderClear(display.renderer);
		createText(&display, &hello_cache, "Hello World!", 250, 250, 200, 70);
		SDL_RenderPresent(display.renderer);
		SDL_Delay(10);
	}
	//free(currentDir);
	//free(files);
	return 0;
}
