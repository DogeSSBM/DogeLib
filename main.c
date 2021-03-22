#define POLY_SIDES	4
#include "Includes.h"

int main(int argc, char const *argv[])
{
	const Length window = {1600, 900};
	init(window);

	while(1){
		Ticks frameStart = getTicks();
		clear();

		setColor(PINK);
		polyDraw(window);

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
