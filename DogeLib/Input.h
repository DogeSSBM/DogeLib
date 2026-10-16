#ifndef DOGELIB_INPUT_H
#define DOGELIB_INPUT_H

struct{
    bool textInputState;
    bool textInputChange;
    u8 key[SDL_NUM_SCANCODES];
    u8 prev[SDL_NUM_SCANCODES];
    uint pressTime[SDL_NUM_SCANCODES];
    uint releaseTime[SDL_NUM_SCANCODES];
    uint lastUpdateTime;
    char *textInput;
    st textInputSize;
    st textInputPos;
    boolFunc textInputDone;
}keys = {0};

// returns true if currently inputting text
bool textInputState(void)
{
    return keys.textInputState;
}

// returns true when text input ends
bool textInputEnded(void)
{
    return !keys.textInputState && keys.textInputChange;
}

// stop inputting text
void textInputStop(void)
{
    printf("Text input stop\n");
    SDL_StopTextInput();
    keys.textInputState = false;
    keys.textInputChange = true;
    keys.textInput = NULL;
    keys.textInputSize = 0;
    keys.textInputPos = 0;
}

// a default function for when to stop text input
bool defaultTextInputDone(void)
{
    return keyCtrlState() && keyState(SC_RETURN);
}

// begin inputting text
void textInputStart(char *buf, const st bufsize, boolFunc textInputDone)
{
    printf("Text input start\n");
    SDL_StartTextInput();
    keys.textInputState = true;
    keys.textInput = buf;
    keys.textInputSize = bufsize;
    keys.textInputPos = strlen(buf);
    keys.textInputDone = textInputDone == NULL ? defaultTextInputDone : textInputDone;
}

// returns the current press state of the key
bool keyState(const Scancode key)
{
    return keys.key[key];
}

// returns true if the key was just pressed
bool keyPressed(const Scancode key)
{
    return !keys.textInputState && (keys.key[key] && !keys.prev[key]);
}

// returns true if the key was pressed last frame and is still pressed
bool keyHeld(const Scancode key)
{
    return keys.key[key] && keys.prev[key];
}

// returns true if the key was pressed or released
bool keyChanged(const Scancode key)
{
    return keys.key[key] != keys.prev[key];
}

// returns true if the key was released
bool keyReleased(const Scancode key)
{
    return !keys.key[key] && keys.prev[key];
}

// returns time at which the key was last pressed
uint keyPressTime(const Scancode key)
{
    return keys.pressTime[key];
}

// returns time at which the key was last released
uint keyReleaseTime(const Scancode key)
{
    return keys.releaseTime[key];
}

// returns the amount of time the key has been held
uint keyHeldTime(const Scancode key)
{
    if(keys.key[key])
        return keys.lastUpdateTime > keys.pressTime[key] ? keys.lastUpdateTime - keys.pressTime[key] : 0;
    return 0;
}

// returns a pointer to the name for the scancode or an empty string
const char* keyName(const Scancode key)
{
    return SDL_GetScancodeName(key);
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

// returns the current position of the mouse
Coord mousePos(void)
{
    return mouse.pos;
}

// returns true if mouseBtn was just pressed
bool mouseBtnPressed(const u32 mouseBtn)
{
    return mouse.state&mouseBtn && !(mouse.prev.state&mouseBtn);
}

// returns the current press state of mouseBtn
bool mouseBtnState(const u32 mouseBtn)
{
    return mouse.state&mouseBtn;
}

// returns true if mouseBtn was pressed last frame and is still pressed
bool mouseBtnHeld(const u32 mouseBtn)
{
    return mouse.state&mouseBtn && mouse.prev.state&mouseBtn;
}

// returns true if mouseBtn was just released
bool mouseBtnReleased(const u32 mouseBtn)
{
    return !(mouse.state&mouseBtn) && mouse.prev.state&mouseBtn;
}

// returns true if the press state if mouseBtn changed
bool mouseBtnChanged(const u32 mouseBtn)
{
    return (mouse.state&mouseBtn) != (mouse.prev.state&mouseBtn);
}

// returns the direction the mouse wheel was scrolled left or right
int mouseScrolledX(void)
{
    return mouse.wheel.x;
}

// returns the direction the mouse wheel was scrolled up or down
int mouseScrolledY(void)
{
    return mouse.wheel.y;
}

// returns true if mouse if currently moving
bool mouseMoving(void)
{
    return !coordSame(mouse.vec, (const Coord){0}) && !coordSame(mouse.prev.vec, (const Coord){0});
}

// returns true if mouse just began moving
bool mouseMoveStart(void)
{
    return !coordSame(mouse.vec, (const Coord){0}) && coordSame(mouse.prev.vec, (const Coord){0});
}

// returns true if mouse just stopped moving
bool mouseMoveStop(void)
{
    return !mouseMoving() && !coordSame(mouse.prev.vec, (const Coord){0});
}

// returns the distance the mouse has moved since last frame
Offset mouseMovement(void)
{
    return coordSub(mouse.pos, mouse.prev.pos);
}

// sets the relative mode of the mouse
void setRelativeMouse(const bool state)
{
    SDL_SetRelativeMouseMode(state);
}

// returns true if any of the Ctrl keys are pressed
bool keyCtrlState(void)
{
    return keyState(SC_LCTRL) || keyState(SC_RCTRL);
}

// returns true if any of the Shift keys are pressed
bool keyShiftState(void)
{
    return keyState(SC_LSHIFT) || keyState(SC_RSHIFT);
}

// returns true if both keys are pressed
bool keyComboState(const Scancode modkey, const Scancode key)
{
    return keyPressed(modkey) && keyState(key);
}

// returns true if modkey is pressed and key was just pressed
bool keyComboPressed(const Scancode modkey, const Scancode key)
{
    return keyPressed(modkey) && keyPressed(key);
}

// returns true if Ctrl is pressed and key was just pressed
bool checkCtrlKey(const Scancode key)
{
    return keyPressed(key) && keyCtrlState();
}

// inits input stuff
void input_init(void)
{

}

// returns an offset based on the state of the W A S and D keys
Offset wasdKeyStateOffset(void)
{
    return (const Offset){
        .x = keyState(SC_D) - keyState(SC_A),
        .y = keyState(SC_S) - keyState(SC_W)
    };
}

// returns an offset based on the state of the arrow keys
Offset arrowKeyStateOffset(void)
{
    return (const Offset){
        .x = keyState(SC_RIGHT) - keyState(SC_LEFT),
        .y = keyState(SC_DOWN) - keyState(SC_UP)
    };
}

// returns an offset based on the state of the W A S and D keys or the arrow keys
Offset dirKeyStateOffset(void)
{
    return coordLeast(coordAdd(wasdKeyStateOffset(), arrowKeyStateOffset()), iC(1,1));
}

// returns an offset based on if W A S or D was just pressed
Offset wasdKeyPressedOffset(void)
{
    return (const Offset){
        .x = keyPressed(SC_D) - keyPressed(SC_A),
        .y = keyPressed(SC_S) - keyPressed(SC_W)
    };
}

// returns an offset based on if arrow keys were just pressed
Offset arrowKeyPressedOffset(void)
{
    return (const Offset){
        .x = keyPressed(SC_RIGHT) - keyPressed(SC_LEFT),
        .y = keyPressed(SC_DOWN) - keyPressed(SC_UP)
    };
}

// returns an offset based on if W A S D or arrow keys were just pressed
Offset dirKeyPressedOffset(void)
{
    return coordLeast(coordAdd(wasdKeyPressedOffset(), arrowKeyPressedOffset()), iC(1,1));
}

#endif /* end of include guard: DOGELIB_INPUT_H */
