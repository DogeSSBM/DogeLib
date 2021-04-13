#include "Includes.h"

int main(int argc, char const *argv[])
{
	const Length window = {1200, 900};
	init(window);

	Poly pps[3] = {
		polyCreate(3, )
	}

	while(1){
		Ticks frameStart = getTicks();
		clear();

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
