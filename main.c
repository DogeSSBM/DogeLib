#include "Includes.h"

int main(int argc, char const *argv[])
{
	const Length window = {1200, 900};
	const RangePair box = {
		.x = {200, 1000},
		.y = {200, 700}
	};
	init(window);

	setFontSize(48);
	setFontColor(PINK);
	const char* text = "DogeLib :3";
	Coord pos = {box.x.min, box.y.min};
	Direction dir = DIR_R;
	const uint speed = 4;

	while(1){
		Ticks frameStart = getTicks();
		clear();

		drawTextCenteredCoord(pos, text);
		if(!coordInRangePair(coordShift(pos, dir, speed), box))
			dir = dirROR(dir);
		pos = coordShift(pos, dir, speed);

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
