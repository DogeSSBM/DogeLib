#include "Includes.h"

int main(int argc, char const *argv[])
{
	init(800, 600);
	setColor(RED);
	Coord pos = {0, 300};
	while(1){
		Ticks frameStart = getTicks();

		clear();
		fillCircleCoord(pos, 50);
		pos.x = (pos.x+1)%800;
		draw();

		events(frameStart + TPF);
	}
	return 0;
}
