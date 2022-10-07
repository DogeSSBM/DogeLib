#include "DogeLib/Includes.h"

int main(int argc, char const *argv[])
{
    (void)argc; (void)argv;
    init();
    maximizeWindow();

    const uint n = rand()%10000;
    printf("%u has %u digits\n", n, digits(n));

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
    uint scale = coordMin(coordDivCoord((window = getWindowLen()), len));
    setTextColor(GREEN);
    Texture *nametag = NULL;

    while(1){
        const uint t = frameStart();

        if(keyPressed(SDL_SCANCODE_ESCAPE)){
            freeTexture(doggo);
            freeTexture(borko);
            return 0;
        }

        if(mouseBtnState(MOUSE_L) || mouseBtnState(MOUSE_R))
            origin = coordOffset(origin, mouseMovement());

        if(keyPressed(SDL_SCANCODE_SPACE)){
            origin = (const Coord){0};
            scale = coordMin(coordDivCoord((window = getWindowLen()), len));
        }
        for(Direction d = 0; d < 4; d++)
            if(keyPressed(keydir[d]))
                len = coordMost(iC(1,1), coordShift(len, d, 1));

        const int change = mouseScrolled(MW_U) - mouseScrolled(MW_D);
        if(change || !nametag){
            scale = imax(1, scale + change);
            freeTexture(nametag);
            setTextSize(scale/5);
            nametag = textTexture("Doggo");
        }

        for(int x = 0; x < len.x; x++){
            for(int y = 0; y < len.y; y++){
                const Coord pos = coordOffset(coordMul((const Coord){.x=x,.y=y}, scale), origin);
                drawTextureCoord(nametag, pos);
                setColor(GREY1);
                drawCircleCoord(coordAdd(pos, scale/2), scale/2);
                drawTextureCoordResize((x&1)^(y&1) ? borko : doggo, pos, iC(scale,scale));
                setColor(PINK);
                fillBorderCoordSquare(pos, scale, -1);
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
