#pragma once

float randRange(float a, float b)
{
	return ((b-a)*((float)rand()/RAND_MAX))+a;
}
