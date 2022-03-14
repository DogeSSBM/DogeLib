#include "Includes.h"

int main(int argc, char const *argv[])
{
	Length window = {800, 600};
	init();
	setWindowLen(window);

	while(1){
        Ticks t = frameStart();

        if(keyPressed(SDL_SCANCODE_SPACE)){
            printf("Space pressed\n");
            drawTextCenteredCoord("Space pressed", getWindowMid());
        }
        if(mouseBtnState(MOUSE_L)){
            if(mouseBtnPressed(MOUSE_L))
                printf("Left clicked\n");
            drawTextCenteredCoord("Left clicked", mouse.pos);
        }
        frameEnd(t);
	}
	return 0;
}
