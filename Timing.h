#pragma once

clock_t ClockPerMs = CLOCKS_PER_SEC / 1000;

clock_t refTime;

void resetTime()
{
	refTime = clock();
}

ull elapsedTime()
{
	return (ull)((clock() - refTime)/ClockPerMs);
}

void delay(uint ms)
{
	SDL_Delay(ms);
}
