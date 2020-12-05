#pragma once

void events(const Ticks frameEnd)
{
	i32 ticksLeft = frameEnd - getTicks();
	do{
		Event event;
		if(SDL_WaitEventTimeout(&event, ticksLeft) && event.type == SDL_QUIT){
			printf("Quitting now!\n");
			exit(0);
		}
		ticksLeft = frameEnd - getTicks();
	}while(ticksLeft > 0);
	memcpy(keys.prev, keys.key, SDL_NUM_SCANCODES);
	memcpy(keys.key, SDL_GetKeyboardState(NULL), SDL_NUM_SCANCODES);
	mouse.prev.state = mouse.state;
	mouse.prev.pos = mouse.pos;
	mouse.state = SDL_GetMouseState(&mouse.pos.x, &mouse.pos.y);
	SDL_GetRelativeMouseState(&mouse.vec.x, &mouse.vec.y);
}
