#include "DogeLib/Includes.h"

int main(int argc, char const *argv[])
{
    (void)argc; (void)argv;
    Length window = {.x = 800, .y = 600};
    init();
    setWindowLen(window);

    Coord pos = coordDiv(getWindowLen(), 2);
    Texture *doggo = loadTexture("./Doggo16x16.png");
    const Scancode dirKey[4] = {
        SDL_SCANCODE_UP,
        SDL_SCANCODE_RIGHT,
        SDL_SCANCODE_DOWN,
        SDL_SCANCODE_LEFT
    };

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
