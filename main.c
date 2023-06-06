#include "DogeLib/Includes.h"

int main(void)
{
    init();

    Texture *doggo = loadTexture("./Doggo16x16.png");
    Texture *borko = loadTexture("./Borko16x16.png");
    const Scancode keydir[4] = {
        SDL_SCANCODE_UP,
        SDL_SCANCODE_RIGHT,
        SDL_SCANCODE_DOWN,
        SDL_SCANCODE_LEFT,
    };
    Length window = {0};
    Length len = {.x=8,.y=6};
    Coord origin = {0};
    uint scale = coordMin(coordDiv((window = getWindowLen()), len));
    setTextColor(GREEN);
    Texture *nametag = NULL;

    uint wposi = 0;
    Coord wpos = {0};
    winSetPosCoord(wpos);
    while(1){
        const uint t = frameStart();

        if(
            keyPressed(SDL_SCANCODE_ESCAPE) ||
            (keyState(SDL_SCANCODE_LCTRL) && keyPressed(SDL_SCANCODE_Q))
        ){
            freeTexture(doggo);
            freeTexture(borko);
            return 0;
        }

        if(keyPressed(SDL_SCANCODE_RETURN)){
            wposi = (wposi+1)%4;
            const Length wlen = getWindowLen();
            const Length dlen = getWinDisplayLen();
            if(wposi == 0 || wposi == 3)
                wpos.x = 0;
            if(wposi == 1 || wposi == 2)
                wpos.x = dlen.x-wlen.x;
            if(wposi <= 1)
                wpos.y = 0;
            if(wposi > 1)
                wpos.y = dlen.y-wlen.y;

            winSetPosCoord(wpos);
        }

        if(mouseBtnState(MOUSE_L) || mouseBtnState(MOUSE_R))
            origin = coordAdd(origin, mouseMovement());

        if(keyPressed(SDL_SCANCODE_SPACE)){
            origin = (const Coord){0};
            scale = coordMin(coordDiv((window = getWindowLen()), len));
        }
        for(Direction d = 0; d < 4; d++)
            if(keyPressed(keydir[d]))
                len = coordMost(iC(1,1), coordShift(len, d, 1));

        const int change = mouseScrolledY();
        if(change || !nametag){
            scale = imax(1, scale + change);
            freeTexture(nametag);
            setTextSize(scale/5);
            nametag = textTexture("Doggo");
        }

        for(int x = 0; x < len.x; x++){
            for(int y = 0; y < len.y; y++){
                const Coord pos = coordAdd(coordMuli((const Coord){.x=x,.y=y}, scale), origin);
                drawTextureCoord(nametag, pos);
                setColor(GREY1);
                drawCircleCoord(coordAddi(pos, scale/2), scale/2);
                drawTextureCoordResize((x&1)^(y&1) ? borko : doggo, pos, iC(scale,scale));
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
