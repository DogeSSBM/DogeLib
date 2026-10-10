#ifndef DOGELIB_DISPLAY_H
#define DOGELIB_DISPLAY_H

// gets the index of the display the window is on
int getWinDisplayIndex(void)
{
    return SDL_GetWindowDisplayIndex(gfx.window);
}

// gets the display rectangle the window is on
Rect getWinDisplayRect(void)
{
    Rect rect = {0};
    SDL_GetDisplayBounds(getWinDisplayIndex(), &rect);
    return rect;
}

// gets the display length the window is on
Length getWinDisplayLen(void)
{
    Rect rect = {0};
    assert(SDL_GetDisplayBounds(getWinDisplayIndex(), &rect) >= 0);
    return irL(rect);
}

// gets the length of the display at index i
Length getDisplayIndexLen(const uint i)
{
    Rect rect = {0};
    assert(SDL_GetDisplayBounds(i, &rect) >= 0);
    return irL(rect);
}

// gets the display rectange at index i
Rect getDisplayIndexRect(const uint i)
{
    Rect rect = {0};
    assert(SDL_GetDisplayBounds(i, &rect) >= 0);
    return rect;
}

// gets the offset of the display the window is on
Coord getWinDisplayOffset(void)
{
    Rect rect = {0};
    SDL_GetDisplayBounds(getWinDisplayIndex(), &rect);
    return irC(rect);
}

// gets the offset of the display at index i
Coord getDisplayIndexOffset(const uint i)
{
    Rect rect = {0};
    SDL_GetDisplayBounds(i, &rect);
    return irC(rect);
}

// gets the number of displays
uint getDisplayNum(void)
{
    const int ret = SDL_GetNumVideoDisplays();
    assert(ret > 0);
    return ret;
}

// gets the length of all displays together
Length getDisplayTotalLen(void)
{
    const uint numDisplay = getDisplayNum();
    Length ret = {0};
    for(uint i = 0; i < numDisplay; i++){
        ret = coordMost(ret, unrectify(getDisplayIndexRect(i)));
    }
    return ret;
}

#endif /* end of include guard: DOGELIB_DISPLAY_H */
