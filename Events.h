#pragma once

void events(const Ticks frameEnd)
{
	i32 ticksLeft = frameEnd - getTicks();
	do{
		Event event;
		if(!SDL_WaitEventTimeout(&event, ticksLeft))
			return;
		switch(event.type){
		case SDL_QUIT:
			printf("Quitting now!\n");
			exit(0);
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				printf("Quitting now!\n");
				exit(0);
				break;
			case SDLK_UP:

				break;
			case SDLK_DOWN:

				break;
			case SDLK_LEFT:

				break;
			case SDLK_RIGHT:

				break;
			}
			break;
		case SDL_MOUSEMOTION:

			break;
		case SDL_MOUSEBUTTONDOWN:

			break;
		case SDL_MOUSEBUTTONUP:

			break;
		}
		ticksLeft = frameEnd - getTicks();
	}while(ticksLeft > 0);
}
