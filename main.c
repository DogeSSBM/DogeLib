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
				pos = coordShift(pos,i,4);
	return coordWrap(pos, (Range){0,window.x}, (Range){0,window.y});
}

void trackMouse(const Color color)
{
	setColor(u32ToColor(~colorToU32(color)));
	drawLineCoords(mouse.pos, coordOffset(mouse.pos, coordMul(mouse.vec, 3)));
	setColor(WHITE);
	fillCircleCoord(mouse.pos, 3);
}

void showText(const Coord pos, const Color color, const Coord window, const char *text)
{
	setFontColor(color);
	drawTextCenteredCoord(pos, text);
	for(Direction i = DIR_U; i <= DIR_L; i++){
		drawTextCenteredCoord(coordShift(pos, i, dirLR(i)?window.x:window.y), text);
	}

}

int main(int argc, char const *argv[])
{
	const Length window = {800, 600};
	init(window);
	setFontSize(48);
	const char* text = "DogeLib :3";
	Coord pos = coordDiv(window, 2);

	while(1){
		Ticks frameStart = getTicks();
		clear();

		setColor(mouseBtnState(MOUSE_L)?MAGENTA:CYAN);
		drawCircleCoord(mouse.pos, 10);

		setColor(mouseBtnState(MOUSE_L)?CYAN:MAGENTA);
		Coord vx[8] = {0};
		for(uint i = 0; i < 4; i++){
			vx[i*2] = coordShift(mouse.pos, i, 80);
			vx[i*2+1] = coordShift(coordShift(mouse.pos, dirINV(i), 60), dirROR(dirINV(i)), 60);
		}
		drawPoly(vx, 8);

		const Color color = mouseBtnState(MOUSE_L)?BLUE:RED;
		pos = move(pos, window);
		trackMouse(color);
		showText(pos, color, window, text);

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
