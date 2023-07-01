#include "DogeLib/Includes.h"

int main(void)
{
    init();
    Texture *doggo = loadTexture("./Doggo16x16.png");
    Texture *borko = loadTexture("./Borko16x16.png");
    Length window = getWindowLen();
    Length len = {.x=8,.y=6};
    uint scale = coordMin(coordDiv(window, len));
    Coord origin = coordUncenter(getWindowMid(), coordMuli(len, scale));
    setTextColor(GREEN);
    setTextSize(scale/5);
    Texture *nametag = textTexture("Doggo");

    while(1){
        const uint t = frameStart();

        if(keyPressed(SC_ESCAPE) || checkCtrlKey(SC_Q)){
            freeTexture(doggo);
            freeTexture(borko);
            freeTexture(nametag);
            return 0;
        }

        if(mouseBtnState(MOUSE_L) || mouseBtnState(MOUSE_R))
            origin = coordAdd(origin, mouseMovement());

        if(mouseScrolledY() || keyPressed(SC_SPACE)){
            if(keyPressed(SC_SPACE))
                origin = coordUncenter(
                    getWindowMid(),
                    coordMuli(len, (scale = coordMin(coordDiv((window = getWindowLen()), len))))
                );
            else
                scale = imax(1, scale + mouseScrolledY());
            freeTexture(nametag);
            setTextSize(scale/5);
            nametag = textTexture("Doggo");
        }

        len = coordMaxi(coordAdd(len, dirKeyPressedOffset()), 1);
        for(int x = 0; x < len.x; x++){
            for(int y = 0; y < len.y; y++){
                const Coord pos = coordOffScale(iC(x,y), origin, scale);
                drawTextureCoord(nametag, pos);
                drawTextureCoordResize((x^y)&1 ? borko : doggo, pos, iiC(scale));
            }
        }
        drawTextureCenteredCoordResize(doggo, mouse.pos, iC(mouseBtnState(MOUSE_L)?128:64, mouseBtnState(MOUSE_R)?128:64));

        frameEnd(t);
    }
    return 0;
}
