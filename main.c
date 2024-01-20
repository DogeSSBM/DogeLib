#include "DogeLib/Includes.h"

int main(void)
{
    init();
    setTextColor(RED);
    Coord p = getWindowMid();
    const char *text = "Hello";
    while(1){
        const uint t = frameStart();

        if(keyPressed(SC_ESCAPE))
            return 0;

        p = coordAdd(p, coordMuli(wasdKeyStateOffset(), 4));
        setColor(CYAN);
        fillCircleCoord(mouse.pos, 32);
        setColor(MAGENTA);
        fillBorderCenteredCoord(p, textLength(text), 8);
        drawTextCenteredCoord(text, p);

        frameEnd(t);
    }
    return 0;
}
