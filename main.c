#include "DogeLib/Includes.h"

int main(void)
{
    init();
    setTextColor(RED);
    setColor(CYAN);
    Coord p = getWindowMid();
    while(1){
        const uint t = frameStart();

        if(keyPressed(SC_ESCAPE))
            return 0;

        p = coordAdd(p, coordMuli(wasdKeyStateOffset(), 4));
        fillCircleCoord(mouse.pos, 32);
        drawTextCenteredCoord("Hello", p);

        frameEnd(t);
    }
    return 0;
}
