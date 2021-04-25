#include "Includes.h"
#define SCALE 40
#define WLVLS 8
#define WSIZE (SCALE/WLVLS)
typedef enum{B_SOLID, B_WATER}BlockType;

typedef struct{
	BlockType type;
	u8 val;
}Block;

Block** initState(const Length len)
{
	Block **state = malloc(sizeof(Block*)*len.x);
	for(uint x = 0; x < len.x; x++){
		state[x] = malloc(sizeof(Block)*len.y);
		for(uint y = 0; y < len.y; y++){
			state[x][y].type = B_WATER;
			state[x][y].val = 0;
		}
	}

	for(uint x = 0; x < len.x; x++){
		state[x][0].type = B_SOLID;
		state[x][0].val = 0;
		state[x][len.y-1].type = B_SOLID;
		state[x][len.y-1].val = 0;
	}

	for(uint y = 1; y < len.y-1; y++){
		state[0][y].type = B_SOLID;
		state[0][y].val = 0;
		state[len.x-1][y].type = B_SOLID;
		state[len.x-1][y].val = 0;
	}
	return state;
}

// window to map
Coord wm(const Coord pos)
{
	return coordDiv(pos, SCALE);
}

// map to window
Coord mw(const Coord pos)
{
	return coordMul(pos, SCALE);
}

// window clamp
Coord wc(const Coord pos, const Length window)
{
	return coordClamp(pos, (Coord){0,window.x}, (Coord){0,window.y});
}

// map clamp
Coord mc(const Coord pos, const Length len)
{
	return coordClamp(pos, (Coord){0,len.x}, (Coord){0,len.y});
}

void drawState(Block **const state, const Length len)
{
	for(uint y = 0; y < len.y; y++){
		for(uint x = 0; x < len.x; x++){
			const Coord wpos = coordMul((Coord){x, y}, SCALE);
			if(state[x][y].type == B_SOLID){
				setColor(GREY);
				fillSquareCoord(wpos, SCALE);
				setColor(GREY3);
				drawSquareCoord(wpos, SCALE);
				continue;
			}
			setColor(GREY2);
			fillSquareCoord(wpos, SCALE);
			setColor(GREY1);
			drawSquareCoord(wpos, SCALE);
			if(state[x][y].type == B_WATER && state[x][y].val>0){
				const Coord tl = coordShift(wpos, DIR_D, WSIZE*(WLVLS-state[x][y].val));
				const Coord br = coordAdd(wpos, SCALE);
				setColor(BLUE);
				fillRectCoords(tl,br);
			}
		}
	}
}

void drawPause(const Length window)
{
	const Coord pos1a = {0,0};
	const Coord pos2a = {1,1};
	const Coord pos1b = {window.x,window.y};
	const Coord pos2b = {window.x-1,window.y-1};
	setColor(RED);
	drawRectCoords(pos1a, pos1b);
	drawRectCoords(pos2a, pos2b);
}

/*
0000000 0000000     0000000
0008000 0007000     0000000
00000#0 00010#0     00080#0
00####0 00####0     00####0
0000000 0000000 ... 0000000

0000000 0000000
0000000 0000000
00080#0 00080#0
00####0 00####0
0000000 0000000
*/

void flowState(Block **const state, const Length len)
{
	for(uint y = len.y-2; y > 1; y--){
		for(uint x = 0; x < len.x; x++){
			const Coord pos = {x, y};
			if(state[x][y].type == B_WATER && state[x][y].val > 0){
				for(int i = state[x][y].val; i > 0; i--){
					Direction dirlr = rand()&1?DIR_L:DIR_R;
					Coord adj = coordShift(pos, DIR_D, 1);
					if(
						state[adj.x][adj.y].type==B_WATER &&
						state[adj.x][adj.y].val<WLVLS
					){
						state[adj.x][adj.y].val++;
						state[x][y].val--;
						continue;
					}
					adj = coordShift(pos, dirlr, 1);
					if(
						state[adj.x][adj.y].type==B_WATER &&
						state[adj.x][adj.y].val<state[x][y].val
					){
						state[adj.x][adj.y].val++;
						state[x][y].val--;
						dirlr = dirINV(dirlr);
						continue;
					}
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	const Length len = {40, 25};
	const Length window = coordMul(len, SCALE);
	init(window);

	Block **state = initState(len);
	// Block **next = initState(len);

	bool pause = true;

	while(1){
		Ticks frameStart = getTicks();
		clear();

		const Coord mouseTile = mc(wm(mouse.pos), len);
		if(mouseBtnState(MOUSE_L)){
			state[mouseTile.x][mouseTile.y].type = B_SOLID;
			state[mouseTile.x][mouseTile.y].val = 0;
		}
		if(mouseBtnState(MOUSE_R)){
			state[mouseTile.x][mouseTile.y].type = B_WATER;
			state[mouseTile.x][mouseTile.y].val = WLVLS;
		}
		if(keyPressed(SDL_SCANCODE_SPACE))
			pause = !pause;

		if(!pause)
			flowState(state, len);

		drawState(state, len);
		if(pause)
			drawPause(window);

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
