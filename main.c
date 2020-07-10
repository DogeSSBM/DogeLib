#include "Includes.h"

int main(int argc, char const *argv[])
{
	init(800, 800);
	setFontSize(48);
	setFontColor(PINK);
	setColor(RED);
	const Range bounds = {4*48, 800-4*48};
	const char *text = "Hewwo :3";
	Coord pos = {bounds.min, bounds.min};
	Direction dir = DIR_R;
	while(1){
		Ticks frameStart = getTicks();
		clear();

		drawTextCentered(pos.x, pos.y, text);
		Coord point = coordShift(pos,dir,128);
		drawLineCoords(pos,point);
		drawLineCoords(point,coordShift(coordShift(point, dirINV(dir), 32),dirROR(dir),32));
		drawLineCoords(point,coordShift(coordShift(point, dirINV(dir), 32),dirROL(dir),32));

		Coord new = coordShift(pos, dir, 4);
		if(
			!inBound(new.x, bounds.min, bounds.max) ||
			!inBound(new.y, bounds.min, bounds.max)
		){
			dir = dirROR(dir);
		}
		pos = coordShift(pos, dir, 4);

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
