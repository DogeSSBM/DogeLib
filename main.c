#include "Includes.h"
#define SCALE 20
#define WLVLS 6
#define WSIZE (SCALE/WLVLS)
typedef enum{B_SOLID, B_WATER}BlockType;

typedef struct{
	BlockType type;
	u8 val;
}Block;

void drawState(Block **const state, const Length len)
{
	for(uint y = 0; y < len.y; y++){
		for(uint x = 0; x < len.x; x++){
			const Coord pos = {x*SCALE, y*SCALE};
			if(state[x][y].type==B_SOLID){
				setColor(GREY);
				fillSquareCoord(pos,SCALE);
				setColor(GREY3);
				drawSquareCoord(pos,SCALE);
				continue;
			}else{
				if(state[x][y].val != 0){
					setColor(BLUE);
					fillSquareCoord(pos,SCALE);
				}
				if(state[x][y].val != WLVLS){
					setColor(WHITE);
					const uint surface = WSIZE*(WLVLS-state[x][y].val);
					fillRectCoords(pos, (Coord){pos.x+SCALE, pos.y+surface});
				}
			}
		}
	}
}

Coord mapClick(const Coord pos)
{
	return coordDiv(pos, SCALE);
}

void placeAt(Block **const state, const Length len, const Coord pos)
{
	const Coord ind = mapClick(pos);
	if(!coordMaxCoord(ind, coordAdd(len, -1)) || !coordMinCoord(ind, (Coord){1,1}))
		return;
	state[ind.x][ind.y].type = B_SOLID;
	state[ind.x][ind.y].val = WLVLS;
}

void scrollAt(Block **const state, const Length len, const Coord pos, const u8 mw)
{
	const Coord ind = mapClick(pos);
	if(!coordMaxCoord(ind, len) || state[ind.x][ind.y].type != B_WATER)
		return;
	if(mw == MW_D)
		state[ind.x][ind.y].val = state[ind.x][ind.y].val<WLVLS?state[ind.x][ind.y].val+1:WLVLS;
	else if(mw == MW_U)
		state[ind.x][ind.y].val = state[ind.x][ind.y].val>0?state[ind.x][ind.y].val-1:WLVLS;
}

void getAdj(Block **const state, const Coord pos, Block *const adj)
{
	for(uint i = 0; i < 4; i++){
		const Coord n = coordShift(pos, i, 1);
		adj[i] = state[n.x][n.y];
	}
}

void side(Block **const state, const Length len, const Coord pos)
{
	if(state[pos.x][pos.y].val == 0 || state[pos.x][pos.y].type != B_WATER)
		return;
	i8 difL = state[pos.x-1][pos.y].val - state[pos.x][pos.y].val;
	i8 difR = state[pos.x+1][pos.y].val - state[pos.x][pos.y].val;
	while((difL < 0 || difR < 0) && (state[pos.x][pos.y].val > 0)){
		if(difL == difR && difL < 0){
			if(state[pos.x][pos.y].val&1){
				state[pos.x][pos.y].val--;
				if(rand()&1)
					state[pos.x-1][pos.y].val++;
				else
					state[pos.x+1][pos.y].val++;
			}else{
				state[pos.x][pos.y].val-=2;
				state[pos.x-1][pos.y].val++;
				state[pos.x+1][pos.y].val++;
			}
		}else if(difL < difR){
			state[pos.x][pos.y].val--;
			state[pos.x-1][pos.y].val++;
		}else if(difR < difL){
			state[pos.x][pos.y].val--;
			state[pos.x+1][pos.y].val++;
		}

		difL = state[pos.x-1][pos.y].val - state[pos.x][pos.y].val;
		difR = state[pos.x+1][pos.y].val - state[pos.x][pos.y].val;
	}
}

void down(Block **const state, const Length len)
{
	for(uint x = 1; x < len.x-1; x++){
		for(uint y = len.y-2; y > 1; y--){
			const Coord pos = {x,y};
			if(state[pos.x][pos.y].type != B_WATER)
				continue;
			const Coord dn = coordShift(pos, DIR_D, 1);
			if(state[dn.x][dn.y].type == B_WATER){
				const int free = WLVLS - state[dn.x][dn.y].val;
				if(free > 0){
					if(free > state[pos.x][pos.y].val){
						state[dn.x][dn.y].val += state[pos.x][pos.y].val;
						state[pos.x][pos.y].val = 0;
					}else{
						state[pos.x][pos.y].val -= free;
						state[dn.x][dn.y].val += free;
					}
				}else{
					side(state, len, pos);
				}
			}else{
				side(state, len, pos);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	const Length len = {80, 45};
	const Length window = coordMul(len, SCALE);
	init(window);

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

	bool pause = true;
	while(1){
		Ticks frameStart = getTicks();
		clear();

		if(mouseBtnState(MOUSE_L))
			placeAt(state, len, mouse.pos);
		if(mouseScrolled(MW_U))
			scrollAt(state, len, mouse.pos, MW_U);
		if(mouseScrolled(MW_D))
			scrollAt(state, len, mouse.pos, MW_D);
		if(keyPressed(SDL_SCANCODE_SPACE))
			pause = !pause;

		if(!pause){
			down(state, len);
		}

		drawState(state, len);
		if(pause){
			const Coord pos1a = {0,0};
			const Coord pos2a = {1,1};
			const Coord pos1b = {window.x,window.y};
			const Coord pos2b = {window.x-1,window.y-1};
			setColor(RED);
			drawRectCoords(pos1a, pos1b);
			drawRectCoords(pos2a, pos2b);
		}
		draw();
		events(frameStart + TPF);
	}
	return 0;
}
