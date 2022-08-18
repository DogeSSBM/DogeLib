#include "DogeLib/Includes.h"

typedef struct{
    uint index;
    Offset off;
    Length len;
}Display;

bool getScale(Length *window, uint *scale)
{
    const Length windowNew = getWindowLen();
    if(coordSame(*window, windowNew))
        return false;
    *window = windowNew;
    const Length dspTotal = getDisplayTotalLen();
    *scale = imax(
        imax(dspTotal.x/windowNew.x, dspTotal.y/windowNew.x),
        imax(dspTotal.x/windowNew.y, dspTotal.y/windowNew.y)
    );

    return true;
}

int main(void)
{
    init();
    Length window = {0};
    uint scale = 0;
    maximizeWindow();
    getScale(&window, &scale);

    const uint dspNum = getDisplayNum();
    const Length dspTotal = getDisplayTotalLen();
    Display dsp[dspNum];
    for(uint i = 0; i < dspNum; i++){
        dsp[i].index = i;
        dsp[i].off = getDisplayIndexOffset(i);
        dsp[i].len = getDisplayIndexLen(i);
    }

    const Color dspColor[6] = {RED, YELLOW, GREEN, CYAN, BLUE, MAGENTA};

    while(1){
        const uint t = frameStart();

        if(getScale(&window, &scale)){
            printf(
                "Window resized to (%4u,%4u). dspTotal (%4u,%4u). Rescaled to %u\n",
                window.x, window.y, dspTotal.x, dspTotal.y, scale
            );
            for(uint i = 0; i < dspNum; i++){
                printf(
                    "\tdsp[%u]:\n\t\toff (%4u,%4u).\n\t\tlen (%4u,%4u).\n",
                    i, dsp[i].off.x, dsp[i].off.y, dsp[i].len.x, dsp[i].len.y
                );
            }
            printf("\n");
        }
        for(uint i = 0; i < dspNum; i++){
            setColor(dspColor[i%6]);
            fillRectCoordLength(coordDiv(dsp[i].off, scale), coordDiv(dsp[i].len, scale));
        }

        frameEnd(t);
    }
    return 0;
}

void drawDoggos(const Coord origin, const Length len, const uint scale, Texture *doggo, Texture *borko)
{
    assert(scale > 0);
    assert(len.y > 0);
    assert(len.x > 0);
    setColor(PINK);
    for(int y = 0; y < len.y; y++){
        for(int x = 0; x < len.x; x++){
            drawTextureCoordResize(
                (x&1) ^ (y&1) ? borko : doggo,
                coordOffset(coordMul((const Coord){.x=x,.y=y}, scale), origin),
                (const Length){
                    .x = scale,
                    .y = scale
                }
            );
            fillBorderCoordSquare(
                coordOffset(coordMul((const Coord){.x=x,.y=y}, scale), origin),
                scale,
                -1
            );
        }
    }
}

Coord originOffset(const Coord origin)
{
    if(keyPressed(SDL_SCANCODE_SPACE))
        return (const Coord){0};

    if(mouseBtnState(MOUSE_L) && mouseMoving())
        return coordOffset(origin, mouseMovement());
    return origin;
}

int main2(int argc, char const *argv[])
{
    (void)argc; (void)argv;
    init();
    setWindowLen((const Length){.x = 800, .y = 600});
    maximizeWindow();
    Texture *doggo = loadTexture("./Doggo16x16.png");
    Texture *borko = loadTexture("./Borko16x16.png");
    Length len = {.x=8,.y=6};
    Coord origin = {0};

    while(1){
        const uint t = frameStart();
        const Length window = getWindowLen();

        origin = originOffset(origin);

        len.x = imax(1, len.x - keyPressed(SDL_SCANCODE_LEFT));
        len.y = imax(1, len.y - keyPressed(SDL_SCANCODE_UP));
        len.x = imax(1, len.x + keyPressed(SDL_SCANCODE_RIGHT));
        len.y = imax(1, len.y + keyPressed(SDL_SCANCODE_DOWN));
        const uint scale = coordMin(coordDivCoord(window, len));

        drawDoggos(origin, len, scale, doggo, borko);

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
