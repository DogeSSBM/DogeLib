#include "DogeLib/Includes.h"

int main(void)
{
    init();
    Coord p = getWindowMid();
    char text[512] = "Hello";
    const Scancode wasd[4] = {SC_W, SC_A, SC_S, SC_D};
    while(1){
        const int scale = coordMin(getWindowLen()) / 8;
        const uint t = frameStart();

        if(keyPressed(SC_ESCAPE))
            return 0;

        if(mouseBtnReleased(MOUSE_L)){
            if(coordInRect(mousePos(), textCenteredRect(p, text)))
                textInputStart(text, 512, NULL);
            else
                textInputStop();
        }

        for(int i = 0; i < 4; i++){
            setTextColor(keyState(wasd[i]) ? GREEN : GREY);
            const Rect r = { .x = i == 0 ? scale : (i-1) * scale, .y = i == 0 ? 0 : scale,
                             .w = scale,                          .h = scale};
            setColor(DARKGREY);
            fillRectRect(r);
            setColor(LIGHTGREY);
            fillBorderRect(r, -imax(1, scale / 12));
            setColor(BLACK);
            fillBorderRect(r, -1);
            setTextSize(imax(scale - 4, 1));
            drawTextCenteredCoord(keyName(wasd[i]), rectMid(r));

            if(!keyState(wasd[i]))
                continue;

            const Coord textPos = {.x = 0, .y = getWindowLen().y - (4-i)*scale};
            setTextColor(GREY);
            char buf[256] = {0};
            const char *name = keyName(wasd[i]);
            sprintf(buf, "%s: %u", name, keyHeldTime(wasd[i]));
            drawTextCoord(buf, textPos);
        }

        if(!textInputState())
            p = coordAdd(p, coordMuli(dirKeyStateOffset(), 4));
        setTextColor(textInputState() ? MAGENTA : CYAN);

        setColor(GREY);
        fillBorderCenteredCoord(p, textLength(text), imax(1, scale / 12));
        drawTextCenteredCoord(text, p);

        frameEnd(t);
    }
    return 0;
}
