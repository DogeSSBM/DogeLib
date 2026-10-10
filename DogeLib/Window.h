#ifndef DOGELIB_WINDOW_H
#define DOGELIB_WINDOW_H

// sets window mode fullscreen / borderless / windowed
void setWindowMode(const WindowMode mode)
{
    SDL_SetWindowFullscreen(gfx.window, mode);
}

// sets if window is resizable
void setWindowResizable(const bool resizable)
{
    SDL_SetWindowResizable(gfx.window, resizable);
}

// gets if window is resizable
bool getWindowResizable(void)
{
    return SDL_WINDOW_RESIZABLE & SDL_GetWindowFlags(gfx.window);
}

// sets length of window
void setWindowLen(const Length len)
{
    gfx.prvLen = gfx.winLen;
    SDL_SetWindowSize(gfx.window, len.x, len.y);
}

// gets length of window on previous frame
Length getWindowPrvLen(void)
{
    return gfx.prvLen;
}

// gets length of window
Length getWindowLen(void)
{
    Length ret = {0};
    SDL_GetWindowSize(gfx.window, &ret.x, &ret.y);
    return ret;
}

// returns if window was resized
bool windowResized(void)
{
    return !coordSame(gfx.prvLen, gfx.winLen);
}

// gets midpoint of window
Coord getWindowMid(void)
{
    Length ret = {0};
    SDL_GetWindowSize(gfx.window, &ret.x, &ret.y);
    return coordDivi(ret, 2);
}

// returns if a display coord is within window
bool coordInWindow(const Coord pos)
{
    const Length window = getWindowLen();
    return inBound(pos.x, 0, window.x) && inBound(pos.y, 0, window.y);
}

// maximizes window then returns its length
Length maximizeWindow(void)
{
    Length len = {0};
    gfx.restoreLen = getWindowLen();
    SDL_MaximizeWindow(gfx.window);
    SDL_GetWindowSize(gfx.window, &len.x, &len.y);
    return len;
}

// restored window to the size it was before maximizing
Length restoreWindow(void)
{
    SDL_RestoreWindow(gfx.window);
    if(getWindowResizable())
    SDL_SetWindowSize(gfx.window, gfx.restoreLen.x, gfx.restoreLen.y);
    return gfx.restoreLen;
}

// moves window to x y display pos
void winSetPos(const int x, const int y)
{
    SDL_SetWindowPosition(gfx.window, x, y);
}

// moves window to coord display pos
void winSetPosCoord(const Coord pos)
{
    SDL_SetWindowPosition(gfx.window, pos.x, pos.y);
}

// returns if window is maximized
bool winIsMaximized(void)
{
    return SDL_WINDOW_MINIMIZED & gfx.winFlags;
}

// returns if window is minimized
bool winIsMinimized(void)
{
    return SDL_WINDOW_MINIMIZED & gfx.winFlags;
}

// confines mouse to window
void winSetGrab(const bool isGrabbed)
{
    SDL_SetWindowGrab(gfx.window, isGrabbed);
}

// returns if mouse is confined to window
bool winIsGrabbed(void)
{
    return SDL_GetWindowGrab(gfx.window);
}

// gets the window currently with focus
Window* winGetFocused(void)
{
    return SDL_GetMouseFocus();
}

// returns if window is focused
bool winIsFocused(void)
{
    return winGetFocused() == gfx.window;
}

// gets opacity of window
float winGetOpacity(void)
{
    float value = 0.0f;
    SDL_GetWindowOpacity(gfx.window, &value);
    return value;
}

// sets opacity of window
void winSetOpacity(const float value)
{
    SDL_SetWindowOpacity(gfx.window, value);
}

#endif /* end of include guard: DOGELIB_WINDOW_H */
