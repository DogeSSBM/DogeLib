#include "Includes.h"

int main(int argc, char const *argv[])
{
	const uint scale = 30;
	init(scale*40, scale*30);
	setFontSize(scale);
	setFontColor(PINK);
	const char *text = "Hewwo :3";

	Coord pos = {scale, scale};
	const Length len = {scale*38, scale*28};
	Direction dir = DIR_U;
	while(1){
		Ticks frameStart = getTicks();
		clear();

		drawTextCenteredCoord(pos, text);
		if(!inBound(dirUD(dir)?pos.y:pos.x, scale+4, dirUD(dir)?len.y-4:len.x-4))
			dir = dirROR(dir);
		pos = coordShift(pos, dir, 4);

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
