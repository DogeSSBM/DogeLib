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
			}
			break;
		}
		ticksLeft = frameEnd - getTicks();
	}while(ticksLeft > 0);
}
