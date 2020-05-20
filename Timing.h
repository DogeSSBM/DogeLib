#pragma once
#define FPS		60
#define TPF		(1000/FPS)

Ticks getTicks(void)
{
	return SDL_GetTicks();
}
