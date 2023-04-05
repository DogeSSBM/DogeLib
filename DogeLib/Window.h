#ifndef WINDOW_H
#define WINDOW_H

void winSetPos(const int x, const int y)
{
    SDL_SetWindowPosition(gfx.window, x, y);
}

void winSetPosCoord(const Coord pos)
{
    SDL_SetWindowPosition(gfx.window, pos.x, pos.y);
}

#endif /* end of include guard: WINDOW_H */
