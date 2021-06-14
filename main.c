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
	if(t.pos.x < 0.0f || t.pos.x >= (float)window.x){
		t.vec.x = -t.vec.x;
	}
	if(t.pos.y < 0.0f || t.pos.y >= (float)window.y){
		t.vec.y = -t.vec.y;
	}
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

void textDemo(const Length window)
{
	static Coord p[2] = {0};
	static uint i = 0;
	if(mouseBtnPressed(MOUSE_L))
		i = coordDistSq(mouse.pos, p[0]) > coordDistSq(mouse.pos, p[1]);
	if(mouseBtnState(MOUSE_L)){
		p[i] = coordClampLen(coordOffset(p[i], mouse.vec), window);
		fillCircleCoord(p[i], 5);
	}
	spanTextList(p[0], p[1], 4, (const char*[]){"This", "Is", "A", "Test"});
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

		textDemo(window);

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
