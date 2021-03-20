#pragma once
#define TPS		1000
#define FPS		60
#define TPF		(TPS/FPS)

static inline
Ticks getTicks(void)
{
	return SDL_GetTicks();
}

static inline
Ticks secondsToTicks(const uint sec)
{
	return TPS*sec;
}

static inline
Ticks getTimeIn(const uint sec)
{
	return TPS*sec+getTicks();
}
