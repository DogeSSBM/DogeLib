#include "DogeLib/Includes.h"

int main(int argc, char const *argv[])
{
    (void)argc; (void)argv;
    init();
    setWindowLen((const Length){.x = 800, .y = 600});
    maximizeWindow();
    Texture *doggo = loadTexture("./Doggo16x16.png");
    Texture *borko = loadTexture("./Borko16x16.png");

    Length len = {.x=8,.y=6};

    while(1){
        const uint t = frameStart();
        const Length window = getWindowLen();

        len.x = imax(1, len.x - keyPressed(SDL_SCANCODE_LEFT));
        len.y = imax(1, len.y - keyPressed(SDL_SCANCODE_UP));
        len.x = imax(1, len.x + keyPressed(SDL_SCANCODE_RIGHT));
        len.y = imax(1, len.y + keyPressed(SDL_SCANCODE_DOWN));
        const uint scale = coordMin(coordDivCoord(window, len));

        setColor(PINK);
        for(int y = 0; y < len.y; y++){
            for(int x = 0; x < len.x; x++){
                drawTextureCoordResize(
                    (x&1) ^ (y&1) ? borko : doggo,
                    coordMul((const Coord){.x=x,.y=y}, scale),
                    (const Length){
                        .x = scale,
                        .y = scale
                    }
                );
                fillBorderCoordSquare(
                    coordMul((const Coord){.x=x,.y=y}, scale),
                    scale,
                    -1
                );
            }
        }

        drawTextureCenteredCoordResize(
            doggo,
            mouse.pos,
            (const Length){
                .x = mouseBtnState(MOUSE_L) ? 128 : 64,
                .y = mouseBtnState(MOUSE_R) ? 128 : 64
            }
        );

        frameEnd(t);
    }
    return 0;
}
