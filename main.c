#include "Includes.h"

Coord move(Coord pos, const Length window)
{
	const bool dirs[4] = {
		keyState(SDL_SCANCODE_W) || keyState(SDL_SCANCODE_UP),
		keyState(SDL_SCANCODE_D) || keyState(SDL_SCANCODE_RIGHT),
		keyState(SDL_SCANCODE_S) || keyState(SDL_SCANCODE_DOWN),
		keyState(SDL_SCANCODE_A) || keyState(SDL_SCANCODE_LEFT)
	};
	for(Direction i = DIR_U; i <= DIR_L; i++)
		if(dirs[i] && !dirs[dirINV(i)])
				coordShift(pos,i,4)
	return coordWrap(pos, (Range){0,window.x}, (Range){0,window.y});
}

void trackMouse(void)
{
	setColor(BLUE);
	drawLineCoords(mouse.pos, coordAdd(mouse.pos, mouse.vec));
	setColor(RED);
	drawLineCoords(mouse.pos, coordSub(mouse.pos, mouse.vec));
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
