#include "Includes.h"

Coord move(Coord pos, const Length window)
{
	const bool dirs[4] = {
		keyState(SDL_SCANCODE_W) || keyState(SDL_SCANCODE_UP),
		keyState(SDL_SCANCODE_D) || keyState(SDL_SCANCODE_RIGHT),
		keyState(SDL_SCANCODE_S) || keyState(SDL_SCANCODE_DOWN),
		keyState(SDL_SCANCODE_A) || keyState(SDL_SCANCODE_LEFT)
	};
	for(uint i = 0; i < 4; i++){
		if(dirs[i] && !dirs[dirINV(i)])
			pos = coordWrap(
				coordShift(pos,i,4),
				(Range){0,window.x},
				(Range){0,window.y}
			);
	}
	return pos;
}

void trackMouse(void)
{
	const Coord mnxt = coordAdd(mouse.pos, mouse.relative);
	const Coord mprv = coordSub(mouse.pos, mouse.relative);
	setColor(BLUE);
	drawLineCoords(mouse.pos, mnxt);
	setColor(RED);
	drawLineCoords(mouse.pos, mprv);
	setColor(WHITE);
	drawPixelCoord(mouse.pos);
}

int main(int argc, char const *argv[])
{
	const Length window = {1200, 900};
	init(window);
	setFontSize(48);
	setFontColor(PINK);
	const char* text = "DogeLib :3";
	Coord pos = coordDiv(window, 2);

	while(1){
		Ticks frameStart = getTicks();
		clear();

		pos = move(pos, window);
		trackMouse();
		drawTextCenteredCoord(pos, text);

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
