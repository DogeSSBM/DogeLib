#include "DogeLib/Includes.h"

void drawWasd(const int scale)
{
    const Scancode wasd[4] = {SC_W, SC_A, SC_S, SC_D};
    for(int i = 0; i < 4; i++){
        setTextColor(keyState(wasd[i]) ? GREEN : GREY);
        const Rect r = iiS(i == 0 ? scale : (i-1) * scale, i == 0 ? 0 : scale, scale);
        setColor(DARKERGREY);
        fillRectRect(r);
        setColor(GREY);
        fillBorderRect(r, -imax(1, scale / 12));
        setColor(BLACK);
        fillBorderRect(r, -1);
        setTextSize(imax(scale - 4, 1));
        drawTextCenteredCoord(keyName(wasd[i]), rectMid(r));

        if(!keyState(wasd[i]))
            continue;

        const Coord textPos = {.x = 0, .y = getWindowLen().y - (4-i)*scale};
        setTextColor(DARKGREY);
        char buf[256] = {0};
        const char *name = keyName(wasd[i]);
        sprintf(buf, "%s: %u", name, keyHeldTime(wasd[i]));
        drawTextCoord(buf, textPos);
    }
}

int main(void)
{
    init();
    Coord p = getWindowMid();
    char text[512] = "Hello";
    Texture *doggo = loadTexture("./Doggo16x16.png");
    Texture *borko = loadTexture("./Borko16x16.png");

    while(1){
        const uint t = frameStart();
        const int scale = coordMin(getWindowLen()) / 8;
        if(keyPressed(SC_ESCAPE))
            return 0;

        if(!textInputState()){
            p = coordAdd(p, coordMuli(dirKeyStateOffset(), 4));
            if(mouseBtnReleased(MOUSE_L) && coordInRect(mousePos(), textCenteredRect(p, text)))
                textInputStart(text, 512, defaultTextInputDone);
        }else{
            if(mouseBtnReleased(MOUSE_L) && !coordInRect(mousePos(), textCenteredRect(p, text)))
                textInputStop();
        }

        drawTextureCoordResize(textInputState() ? borko : doggo, iC(getWindowLen().x-scale, 0), iiC(scale));
        drawWasd(scale);

        setColor(DARKGREY);
        fillBorderCenteredCoord(p, textLength(text), imax(1, scale / 12));
        setTextColor(textInputState() ? MAGENTA : CYAN);
        drawTextCenteredCoord(text, p);

        frameEnd(t);
    }
    return 0;
}
