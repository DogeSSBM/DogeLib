#include "Includes.h"

int main(int argc, char const *argv[])
{
	init(800, 600);
	setFontSize(48);
	setFontColor(PINK);
	const Range bounds = {-4*48, 800+4*48};
	const char *text = "Hewwo :3";
	int x = bounds.min;
	while(1){
		Ticks frameStart = getTicks();
		clear();

		drawTextCentered(x, 300, text);
		x = wrap(x+4, bounds.min, bounds.max);

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
