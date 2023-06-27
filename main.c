#include "DogeLib/Includes.h"

int main(void)
{
    init();

    while(1){
        const uint t = frameStart();

        if(keyPressed(SC_ESCAPE) || checkCtrlKey(SC_Q)){
            freeTexture(doggo);
            freeTexture(borko);
            return 0;
        }

        if(mouseBtnState(MOUSE_L) || mouseBtnState(MOUSE_R))
            origin = coordAdd(origin, mouseMovement());

        const int change = mouseScrolledY();
        if(keyPressed(SC_SPACE) || change || !nametag){
            if(keyPressed(SC_SPACE))
                origin = coordUncenter(
                    getWindowMid(),
                    coordMuli(len, (scale = coordMin(coordDiv((window = getWindowLen()), len))))
                );
            else
                scale = imax(1, scale + change);
            freeTexture(nametag);
            setTextSize(scale/5);
            nametag = textTexture("Doggo");
        }
        len = coordMaxi(coordAdd(len, dirKeyPressedOffset()), 1);

        for(int x = 0; x < len.x; x++){
            for(int y = 0; y < len.y; y++){
                const Coord pos = coordOffScale(iC(x,y), origin, scale);
                drawTextureCoord(nametag, pos);
                setColor(GREY1);
                drawCircleCoord(coordAddi(pos, scale/2), scale/2);
                drawTextureCoordResize((x&1)^(y&1) ? borko : doggo, pos, iiC(scale));
                setColor(PINK);
                drawSquareCoord(pos, scale);
            }
        }

        drawTextureCenteredCoordResize(
            doggo,
            mouse.pos,
            iC(mouseBtnState(MOUSE_L) ? 128 : 64, mouseBtnState(MOUSE_R) ? 128 : 64)
        );

        frameEnd(t);
    }
    return 0;
}
