#include "Includes.h"

typedef struct{
	Color color;
	Coordf pos;
	Vectorf vec;
	uint size;
}Thing;

Thing bounceThing(Thing t, const Length window)
{
	const Vectorf prev = t.pos;
	t.pos = cfTranslate(t.pos, t.vec);
	if(t.pos.x < 0.0f || t.pos.x >= (float)window.x)
		t.vec.x = -t.vec.x;
	if(t.pos.y < 0.0f || t.pos.y >= (float)window.y)
		t.vec.y = -t.vec.y;
	t.pos = cfTranslate(t.vec, prev);
	return t;
}

bool boundsInWindow(const Coord pos, const uint size)
{
	for(uint i = 0; i < 4; i++){
		if(!coordInWindow(coordShift(pos, i, size)))
			return false;
	}
	return true;
}

void drawThing(const Thing t)
{
	if(!boundsInWindow(CfC(t.pos), t.size))
		setColor(RED);
	else
		setColor(mouseMoving()? PINK : t.color);
	fillCircleCoord(CfC(t.pos), t.size);
	fillBorderCoordSquare(
		coordAdd(CfC(t.pos),-t.size),
		t.size*2,
		t.size/4
	);
}

Thing varyThing(const Thing t)
{
	return (const Thing){
		.color = t.color,
		.pos = t.pos,
		.vec = degToCf(wrap(cfToDeg(t.vec)+randRange(-5.0f, 5.0f),0.0f,360.0f)),
		.size = clamp(t.size+rand()%3-1, 0, 20),
	};
}

Thing randomThing(const Length window)
{
	return (const Thing){
		.color = WHITE,
		.pos.x = randRange(0.0f, (float)window.x),
		.pos.y = randRange(0.0f, (float)window.y),
		.vec = degToCf(randRange(0.0f, 360.0f)),
		.size = 5+rand()%15,
	};
}

int main(int argc, char const *argv[])
{
	Length window = {800, 600};
	init();
	setWindowLen(window);

	Thing t[6] = {0};
	for(uint i = 0; i < 6; i++)
		t[i] = randomThing(window);

	t[0].color = CYAN;
	t[1].color = RED;
	t[2].color = YELLOW;
	t[3].color = GREEN;
	t[4].color = BLUE;
	t[5].color = MAGENTA;

	Coord red[2] = {{window.x/4, 0}, (Coord){window.x/4, window.y}};
	Offset off = {window.x/2, 0};
	const char *optText[] = {"This", "Is", "A", "Test"};
	uint ind = 0;

	while(1){
		Ticks frameStart = getTicks();
		clear();

		for(uint i = 0; i < 6; i++){
			t[i] = bounceThing(t[i], getWindowLen());
			t[i] = varyThing(t[i]);
			drawThing(t[i]);
		}

		if(mouseMoveStart()){
			printf("Start\n");
		}else if(mouseMoveStop()){
			printf("Stop\n");
		}

		if(mouseBtnPressed(MOUSE_L))
			ind = coordDistSq(mouse.pos, red[0]) > coordDistSq(mouse.pos, red[1]);
		if(mouseBtnState(MOUSE_L)){
			setColor(WHITE);
			fillCircleCoord(red[ind], 3);
			red[ind] = coordOffset(red[ind], mouse.vec);
		}

		if(mouseBtnState(MOUSE_R))
			off = coordOffset(off, mouse.vec);

		const Coord blu[2]={coordOffset(red[0], off), coordOffset(red[1], off)};

		const uint num = 4;
		setTextSize(24);
		setTextColor(RED);
		spanTextList(red[0], red[1], num, optText);
		setTextColor(BLUE);
		spanTextListCentered(blu[0], blu[1], num, optText);

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
