#ifndef EVENTTYPES_H
#define EVENTTYPES_H

typedef struct{
    u32 type;
    char* str;
}ET;

char *E_UNK = "UNKNOWN EVENT TYPE";

ET allEt[37] = {
    {.type = SDL_AUDIODEVICEADDED, .str = "SDL_AUDIODEVICEADDED"},
    {.type = SDL_AUDIODEVICEREMOVED, .str = "SDL_AUDIODEVICEREMOVED"},
    // {.type = SDL_AudioDeviceEvent, .str = "SDL_AudioDeviceEvent"},
    {.type = SDL_CONTROLLERAXISMOTION, .str = "SDL_CONTROLLERAXISMOTION"},
    // {.type = SDL_ControllerAxisEvent, .str = "SDL_ControllerAxisEvent"},
    {.type = SDL_CONTROLLERBUTTONDOWN, .str = "SDL_CONTROLLERBUTTONDOWN"},
    {.type = SDL_CONTROLLERBUTTONUP, .str = "SDL_CONTROLLERBUTTONUP"},
    // {.type = SDL_ControllerButtonEvent, .str = "SDL_ControllerButtonEvent"},
    {.type = SDL_CONTROLLERDEVICEADDED, .str = "SDL_CONTROLLERDEVICEADDED"},
    {.type = SDL_CONTROLLERDEVICEREMOVED, .str = "SDL_CONTROLLERDEVICEREMOVED"},
    {.type = SDL_CONTROLLERDEVICEREMAPPED, .str = "SDL_CONTROLLERDEVICEREMAPPED"},
    // {.type = SDL_ControllerDeviceEvent, .str = "SDL_ControllerDeviceEvent"},
    {.type = SDL_DOLLARGESTURE, .str = "SDL_DOLLARGESTURE"},
    {.type = SDL_DOLLARRECORD, .str = "SDL_DOLLARRECORD"},
    // {.type = SDL_DollarGestureEvent, .str = "SDL_DollarGestureEvent"},
    {.type = SDL_DROPFILE, .str = "SDL_DROPFILE"},
    {.type = SDL_DROPTEXT, .str = "SDL_DROPTEXT"},
    {.type = SDL_DROPBEGIN, .str = "SDL_DROPBEGIN"},
    {.type = SDL_DROPCOMPLETE, .str = "SDL_DROPCOMPLETE"},
    // {.type = SDL_DropEvent, .str = "SDL_DropEvent"},
    {.type = SDL_FINGERMOTION, .str = "SDL_FINGERMOTION"},
    {.type = SDL_FINGERDOWN, .str = "SDL_FINGERDOWN"},
    {.type = SDL_FINGERUP, .str = "SDL_FINGERUP"},
    // {.type = SDL_TouchFingerEvent, .str = "SDL_TouchFingerEvent"},
    {.type = SDL_KEYDOWN, .str = "SDL_KEYDOWN"},
    {.type = SDL_KEYUP, .str = "SDL_KEYUP"},
    // {.type = SDL_KeyboardEvent, .str = "SDL_KeyboardEvent"},
    {.type = SDL_JOYAXISMOTION, .str = "SDL_JOYAXISMOTION"},
    // {.type = SDL_JoyAxisEvent, .str = "SDL_JoyAxisEvent"},
    {.type = SDL_JOYBALLMOTION, .str = "SDL_JOYBALLMOTION"},
    // {.type = SDL_JoyBallEvent, .str = "SDL_JoyBallEvent"},
    {.type = SDL_JOYHATMOTION, .str = "SDL_JOYHATMOTION"},
    // {.type = SDL_JoyHatEvent, .str = "SDL_JoyHatEvent"},
    {.type = SDL_JOYBUTTONDOWN, .str = "SDL_JOYBUTTONDOWN"},
    {.type = SDL_JOYBUTTONUP, .str = "SDL_JOYBUTTONUP"},
    // {.type = SDL_JoyButtonEvent, .str = "SDL_JoyButtonEvent"},
    {.type = SDL_JOYDEVICEADDED, .str = "SDL_JOYDEVICEADDED"},
    {.type = SDL_JOYDEVICEREMOVED, .str = "SDL_JOYDEVICEREMOVED"},
    // {.type = SDL_JoyDeviceEvent, .str = "SDL_JoyDeviceEvent"},
    {.type = SDL_MOUSEMOTION, .str = "SDL_MOUSEMOTION"},
    // {.type = SDL_MouseMotionEvent, .str = "SDL_MouseMotionEvent"},
    {.type = SDL_MOUSEBUTTONDOWN, .str = "SDL_MOUSEBUTTONDOWN"},
    {.type = SDL_MOUSEBUTTONUP, .str = "SDL_MOUSEBUTTONUP"},
    // {.type = SDL_MouseButtonEvent, .str = "SDL_MouseButtonEvent"},
    {.type = SDL_MOUSEWHEEL, .str = "SDL_MOUSEWHEEL"},
    // {.type = SDL_MouseWheelEvent, .str = "SDL_MouseWheelEvent"},
    {.type = SDL_MULTIGESTURE, .str = "SDL_MULTIGESTURE"},
    // {.type = SDL_MultiGestureEvent, .str = "SDL_MultiGestureEvent"},
    {.type = SDL_QUIT, .str = "SDL_QUIT"},
    // {.type = SDL_QuitEvent, .str = "SDL_QuitEvent"},
    {.type = SDL_SYSWMEVENT, .str = "SDL_SYSWMEVENT"},
    // {.type = SDL_SysWMEvent, .str = "SDL_SysWMEvent"},
    {.type = SDL_TEXTEDITING, .str = "SDL_TEXTEDITING"},
    // {.type = SDL_TextEditingEvent, .str = "SDL_TextEditingEvent"},
    {.type = SDL_TEXTINPUT, .str = "SDL_TEXTINPUT"},
    // {.type = SDL_TextInputEvent, .str = "SDL_TextInputEvent"},
    {.type = SDL_USEREVENT, .str = "SDL_USEREVENT"},
    // {.type = SDL_UserEvent, .str = "SDL_UserEvent"},
    {.type = SDL_WINDOWEVENT, .str = "SDL_WINDOWEVENT"}
    // {.type = SDL_WindowEvent, .str = "SDL_WindowEvent"},
    // {.type = SDL_CommonEvent, .str = "SDL_CommonEvent"}
};

#endif /* end of include guard: EVENTTYPES_H */
