#include "Includes.h"

int main(int argc, char const *argv[])
{
	const Length window = {800, 600};
	init(window);

	const Coord p1 = {300, 300};
	const Coord p2 = {500, 300};
	Coord p3 = {400, 200};
	int speed = 2;

	setColor(RED);

	while(1){
		Ticks frameStart = getTicks();
		clear();

		fillTri(p1, p2, p3);
		if(!inBound(p3.y+speed, 150, 450))
			speed = -speed;
		p3.y+=speed;

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
