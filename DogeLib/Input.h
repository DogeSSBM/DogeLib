#pragma once

struct{
    u8 key[SDL_NUM_SCANCODES];
    u8 prev[SDL_NUM_SCANCODES];
}keys = {0};

bool keyState(const Scancode key)
{
    return keys.key[key];
}

bool keyPressed(const Scancode key)
{
    return keys.key[key] && !keys.prev[key];
}

bool keyHeld(const Scancode key)
{
    return keys.key[key] && keys.prev[key];
}

bool keyChanged(const Scancode key)
{
    return keys.key[key] != keys.prev[key];
}

bool keyReleased(const Scancode key)
{
    return !keys.key[key] && keys.prev[key];
}

#define MOUSE_L        (SDL_BUTTON(SDL_BUTTON_LEFT))
#define MOUSE_M        (SDL_BUTTON(SDL_BUTTON_MIDDLE))
#define MOUSE_R        (SDL_BUTTON(SDL_BUTTON_RIGHT))
#define MOUSE_F        (SDL_BUTTON(SDL_BUTTON_X1))
#define MOUSE_B        (SDL_BUTTON(SDL_BUTTON_X2))

#define MW_D        1u
#define MW_R        (1u<<1)
#define MW_U        (1u<<2)
#define MW_L        (1u<<3)

struct{
    Offset vec;
    Coord pos;
    u32 state;
    u32 wheel;
    struct{
        Offset vec;
        Coord pos;
        u32 state;
        u32 wheel;
    }prev;
}mouse = {0};

bool mouseBtnPressed(const u32 mouseBtn)
{
    return mouse.state&mouseBtn && !(mouse.prev.state&mouseBtn);
}

bool mouseBtnState(const u32 mouseBtn)
{
    return mouse.state&mouseBtn;
}

bool mouseBtnHeld(const u32 mouseBtn)
{
    return mouse.state&mouseBtn && mouse.prev.state&mouseBtn;
}

bool mouseBtnReleased(const u32 mouseBtn)
{
    return !(mouse.state&mouseBtn) && mouse.prev.state&mouseBtn;
}

bool mouseBtnChanged(const u32 mouseBtn)
{
    return (mouse.state&mouseBtn) != (mouse.prev.state&mouseBtn);
}

bool mouseScrolled(const u32 mouseWheel)
{
    return mouse.wheel & mouseWheel;
}

bool mouseMoving(void)
{
    return !coordSame(mouse.vec, (const Coord){0}) && !coordSame(mouse.prev.vec, (const Coord){0});
}

bool mouseMoveStart(void)
{
    return !coordSame(mouse.vec, (const Coord){0}) && coordSame(mouse.prev.vec, (const Coord){0});
}

bool mouseMoveStop(void)
{
    return !mouseMoving() && !coordSame(mouse.prev.vec, (const Coord){0});
}

Length mouseMovement(void)
{
    return coordSub(mouse.pos, mouse.prev.pos);
}

void input_init(void)
{
    mouse.pos = coordDiv(getWindowLen(), 2);
    mouse.prev.pos = coordDiv(getWindowLen(), 2);
}
