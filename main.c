#include "DogeLib/Includes.h"

int main(int argc, char const *argv[])
{
    (void)argc; (void)argv;
    Length window = {.x = 800, .y = 600};
    init();
    setWindowLen(window);
    Texture *doggo = loadTexture("./Doggo16x16.png");

    while(1){
       const uint t = frameStart();

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
