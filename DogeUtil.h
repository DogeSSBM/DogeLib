#pragma once

void clearTerminal(void)
{
	printf("\e[1;1H\e[2J");
}

float randRange(float a, float b)
{
	return ((b-a)*((float)rand()/RAND_MAX))+a;
}

void init(void)
{
	srand(time(NULL));
	gfx_init();
	img_init();
	text_init();
	input_init();
}
