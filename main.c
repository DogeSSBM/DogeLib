#include "DogeLib/Includes.h"

int main(int argc, char const *argv[])
{
    (void)argc; (void)argv;
    init();


    const uint n = rand()%10000;

    printf("%u has %u digits\n", n, digits(n));

    setWindowLen((const Length){.x = 800, .y = 600});
    maximizeWindow();
    Texture *doggo = loadTexture("./Doggo16x16.png");
    Texture *borko = loadTexture("./Borko16x16.png");
    const Scancode keydir[4] = {
        SDL_SCANCODE_LEFT,
        SDL_SCANCODE_UP,
        SDL_SCANCODE_RIGHT,
        SDL_SCANCODE_DOWN
    };
    Length len = {.x=8,.y=6};
    Coord origin = {0};

    while(1){
        const uint t = frameStart();
        const Length window = getWindowLen();
        if(keyPressed(SDL_SCANCODE_SPACE))
            origin = (const Coord){0};
        else if(mouseBtnState(MOUSE_L) && mouseMoving())
            origin = coordOffset(origin, mouseMovement());

        if(keyPressed(SDL_SCANCODE_ESCAPE))
            return 0;

        for(Direction d = 0; d < 4; d++)
            if(keyPressed(keydir[d]))
                len = coordMost(iC(1,1), coordShift(len, d, 1));

        const uint scale = coordMin(coordDivCoord(window, len));

        for(int y = 0; y < len.y; y++){
            for(int x = 0; x < len.x; x++){
                const Coord pos = coordOffset(coordMul((const Coord){.x=x,.y=y}, scale), origin);
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
