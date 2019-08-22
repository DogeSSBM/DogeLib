#include "Includes.h"

int main(int argc, char const *argv[])
{
	gfx_init(800, 600);
	img_init();
	text_init();
	setColor(RED);
	fillCircle(400, 300, 100);
	draw();
	while(1){
		events();
		delay(5);
	}
	return 0;
}
