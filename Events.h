#pragma once

void events(const Ticks frameEnd, Offset *zscale)
{
	i32 ticksLeft = frameEnd - getTicks();
	while(ticksLeft > 0){
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
				zscale->y++;
				break;
			case SDLK_RIGHT:
				zscale->x--;
				break;
			case SDLK_DOWN:
				zscale->y--;
				break;
			case SDLK_LEFT:
				zscale->x++;
				break;
			}
			break;
		}
		ticksLeft = frameEnd - getTicks();
	}
}
