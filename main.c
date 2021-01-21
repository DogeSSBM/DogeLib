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

void trackMouse(void)
{
	setColor(BLUE);
	drawLineCoords(mouse.pos, coordOffset(mouse.pos, mouse.vec));
	setColor(WHITE);
	drawPixelCoord(mouse.pos);
}

void wrapText(const Coord pos, const Coord window, const char *text)
{
	const Length textBound = {(gfx.fontSize*strlen(text))/2, gfx.fontSize};
	for(Direction i = DIR_U; i <= DIR_L; i++){
		if(coordInRangePair(
		coordShift(pos,i,dirUD(i)?textBound.y:textBound.x),
		(RangePair){(Range){0,window.x},(Range){0,window.y}}))
			continue;
		drawTextCenteredCoord(coordShift(
			pos,dirINV(i),dirUD(i)?window.y:window.x),text
		);
	}

}

int main(int argc, char const *argv[])
{
	const Length window = {800, 600};
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
		wrapText(pos, window, text);

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
