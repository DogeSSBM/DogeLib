#pragma once

void events()
{
	static SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				printf("Quitting now!\n");
				exit(0);
			break;
			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_ESCAPE){
					printf("Quitting now!\n");
					exit(0);
				}
			break;
			default:
				// default
			break;
		}
	}
}
