#ifndef DOGELIB_INPUT_H
#define DOGELIB_INPUT_H

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

struct{
    Offset vec;
    Coord pos;
    u32 state;
    Coord wheel;
    struct{
        Offset vec;
        Coord pos;
        u32 state;
        Coord wheel;
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

int mouseScrolledX(void)
{
    return mouse.wheel.x;
}

int mouseScrolledY(void)
{
    return mouse.wheel.y;
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

bool keyCtrlState(void)
{
    return keyState(SDL_SCANCODE_LCTRL) || keyState(SDL_SCANCODE_RCTRL);
}

bool keyShiftState(void)
{
    return keyState(SDL_SCANCODE_LSHIFT) || keyState(SDL_SCANCODE_RSHIFT);
}

bool keyComboPressed(const Scancode modkey, const Scancode key)
{
    return keyPressed(key) && keyState(modkey);
}

bool checkCtrlKey(const Scancode key)
{
    return keyPressed(key) && keyCtrlState();
}

void input_init(void)
{
    mouse.pos = coordDivi(getWindowLen(), 2);
    mouse.prev.pos = coordDivi(getWindowLen(), 2);
}

Offset wasdKeyStateOffset(void)
{
    return (const Offset){
        .x = keyState(SDL_SCANCODE_D) - keyState(SDL_SCANCODE_A),
        .y = keyState(SDL_SCANCODE_S) - keyState(SDL_SCANCODE_W)
    };
}

Offset arrowKeyStateOffset(void)
{
    return (const Offset){
        .x = keyState(SDL_SCANCODE_RIGHT) - keyState(SDL_SCANCODE_LEFT),
        .y = keyState(SDL_SCANCODE_DOWN) - keyState(SDL_SCANCODE_UP)
    };
}

Offset dirKeyStateOffset(void)
{
    return coordLeast(coordAdd(wasdKeyStateOffset(), arrowKeyStateOffset()), iC(1,1));
}

Offset wasdKeyPressedOffset(void)
{
    return (const Offset){
        .x = keyPressed(SDL_SCANCODE_D) - keyPressed(SDL_SCANCODE_A),
        .y = keyPressed(SDL_SCANCODE_S) - keyPressed(SDL_SCANCODE_W)
    };
}

Offset arrowKeyPressedOffset(void)
{
    return (const Offset){
        .x = keyPressed(SDL_SCANCODE_RIGHT) - keyPressed(SDL_SCANCODE_LEFT),
        .y = keyPressed(SDL_SCANCODE_DOWN) - keyPressed(SDL_SCANCODE_UP)
    };
}

Offset dirKeyPressedOffset(void)
{
    return coordLeast(coordAdd(wasdKeyPressedOffset(), arrowKeyPressedOffset()), iC(1,1));
}

#endif /* end of include guard: DOGELIB_INPUT_H */
