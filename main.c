#include "Includes.h"

typedef struct{
	Color color;
	Coordf pos;
	Vectorf vec;
	uint size;
}Thing;

int main(int argc, char const *argv[])
{
	const Length window = {800, 600};
	init(window);

	Thing t[6] = {0};

	t[0].color = CYAN;
	t[1].color = RED;
	t[2].color = YELLOW;
	t[3].color = GREEN;
	t[4].color = BLUE;
	t[5].color = MAGENTA;
	for(uint i = 0; i < 6; i++){
		t[i].pos.x = randRange(0.0f, (float)window.x);
		t[i].pos.y = randRange(0.0f, (float)window.y);
		t[i].vec = degToCf(randRange(0.0f, 360.0f));
		t[i].size = 5+rand()%15;
	}


	while(1){
		Ticks frameStart = getTicks();
		clear();

		for(uint i = 0; i < 6; i++){
			t[i].pos = cfTranslate(t[i].pos, t[i].vec);
			t[i].vec = degToCf(wrap(cfToDeg(t[i].vec)+randRange(-5.0f, 5.0f),0.0f,360.0f));
			t[i].size = clamp(t[i].size+rand()%3-1, 0, 20);
			setColor(t[i].color);
			fillCircleCoord(CfC(t[i].pos), t[i].size);
		}

		draw();
		events(frameStart + TPF);
	}
	return 0;
}
