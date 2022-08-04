#include "DogeLib/Includes.h"

int main(int argc, char const *argv[])
{
    (void)argc; (void)argv;
    Length window = {.x = 800, .y = 600};
    init();
    setWindowLen(window);

    Coord pos = coordDiv(getWindowLen(), 2);

    const SDL_Scancode dirKey[4] = {SDL_SCANCODE_UP, SDL_SCANCODE_RIGHT, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT};

    setColor(PINK);

	while(1){
       const uint t = frameStart();

        if(mouseBtnState(MOUSE_L)){
            drawTextCenteredCoord("Left clicked", mouse.pos);
        }

        for(Direction i = DIR_U; i <= DIR_L; i++)
            pos = coordShift(pos, i, 8*keyState(dirKey[i]));

        fillCircleCoord(pos, 32);

        frameEnd(t);
    }
    return 0;
}
