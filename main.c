#include "Includes.h"

Coord handlePos(Coord pos, const Length window)
{
	const u8 *keys = SDL_GetKeyboardState(NULL);
	bool dirs[4] = {
		keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP],
		keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT],
		keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN],
		keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]
	};
	for(uint i = 0; i < 4; i++){
		if(dirs[i] && !dirs[dirINV(i)])
			pos = coordClamp(
				coordShift(pos,i,4),
				(Range){0,window.x},
				(Range){0,window.y}
			);
	}
	return pos;
}

void handleMouse(void)
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

		pos = handlePos(pos, window);
		handleMouse();
		drawTextCenteredCoord(pos, text);

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
