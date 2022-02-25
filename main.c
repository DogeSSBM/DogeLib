#include "Includes.h"

int main(int argc, char const *argv[])
{
	Length window = {800, 600};
	init();
	setWindowLen(window);

	while(1){
		Frame frame = frameStart();

        setColor(keyState(SDL_SCANCODE_SPACE)?RED:GREEN);
        fillCircleCoord(coordDiv(window, 2), 50);

		frameEnd(frame);
	}

	return 0;
}
