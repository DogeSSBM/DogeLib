#include "DogeLib/Includes.h"

int main(void)
{
    init();
    Coord p = getWindowMid();
    char text[512] = "Hello";
    setColor(CYAN);

    while(1){
        const uint t = frameStart();

        if(keyPressed(SC_ESCAPE))
            return 0;

        if(mouseBtnReleased(MOUSE_L)){
            if(coordInRect(mousePos(), textCenteredRect(p, text)))
                textInputStart(text, 512, NULL);
            else
                textInputStop();
        }

        if(textInputState()){
            setTextColor(MAGENTA);
        }else{
            setTextColor(CYAN);
            p = coordAdd(p, coordMuli(wasdKeyStateOffset(), 4));
        }

        fillBorderCenteredCoord(p, textLength(text), 8);
        drawTextCenteredCoord(text, p);

        frameEnd(t);
    }
    return 0;
}
