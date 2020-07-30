#include "Includes.h"

void drawAll(const Range win, const int scale, const Offset zscale)
{
	for(int x = -4; x <= 4; x++){
		for(int y = -4; y <= 4; y++){
			for(int z = -4; z <= 4; z++){
				Coord3 c3 = {x*scale, y*scale, z*scale};
				Coord sq[4];
				sq[0] = coord3Project(c3, win, zscale);
				sq[1] = coordShift(sq[0], DIR_R, scale);
				sq[2] = coordShift(sq[0], DIR_D, scale);
				sq[3] = coordShift(sq[2], DIR_R, scale);

				drawLineCoords(sq[0], sq[1]);
				drawLineCoords(sq[0], sq[2]);
				drawLineCoords(sq[1], sq[3]);
				drawLineCoords(sq[2], sq[3]);

				for(uint i = 0; i < 4; i++){
					drawLineCoords(
						sq[i],
						coordOffset(sq[i], zscale)
					);
					sq[i] = coordOffset(sq[i], zscale);
				}

				drawLineCoords(sq[0], sq[1]);
				drawLineCoords(sq[0], sq[2]);
				drawLineCoords(sq[1], sq[3]);
				drawLineCoords(sq[2], sq[3]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	const Range win = {1000, 1000};
	const int scale = 10;
	Offset zscale = {3, -3};
	init(win);
	const Color axisc[3] = {RED, GREEN, BLUE};
	while(1){
		Ticks frameStart = getTicks();
		clear();
		for(uint i = 0; i < 3; i++){
			setColor(axisc[i]);
			Coord3 c3 = {0};
			drawLineCoord3(
				dimensionShift(c3, i,  500),
				dimensionShift(c3, i, -500),
				win,
				zscale
			);
		}
		setColor(WHITE);
		drawAll(win, scale, zscale);
		draw();
		events(frameStart + TPF, &zscale);
	}
	return 0;
}
