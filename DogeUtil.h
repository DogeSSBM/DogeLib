#pragma once

float randRange(float a, float b)
{
	return ((b-a)*((float)rand()/RAND_MAX))+a;
}

void init_all(uint winXlen, uint winYlen)
{
	gfx_init(winXlen, winYlen);
	img_init();
	text_init();
}
