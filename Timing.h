#pragma once

clock_t ClockPerMs = CLOCKS_PER_SEC / 1000;

clock_t refTime;

void resetTime(void)
{
	refTime = clock();
}

ull elapsedTime(void)
{
	return (ull)((clock() - refTime)/ClockPerMs);
}

void delay(uint ms)
{
	resetTime();
	while(elapsedTime() < ms);
}
