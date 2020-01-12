#define DOGE_GFX
#include "Includes.h"

int main(int argc, char const *argv[])
{
	init(800, 600);
	setColor(RED);
	fillCircle(400, 300, 100);
	draw();
	while(1){
		events();
		delay(5);
	}
	return 0;
}
