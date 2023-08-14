#ifndef DOGELIB_EVENTS_H
#define DOGELIB_EVENTS_H

void events(const uint endOfFrame)
{
    i32 ticksLeft = imax(1, endOfFrame - getTicks());
    mouse.prev.wheel = mouse.wheel;
    mouse.wheel = (const Coord){.x = 0, .y = 0};
    bool e = false;
    gfx.winFlags = SDL_GetWindowFlags(gfx.window);
    gfx.prvLen = gfx.winLen;

    if(itxt.it){
        itxt.it->bufPos = 0;
        memset(itxt.it->buf, '\0', ITBUFLEN);
    }
    do{
        Event event;
        if(ticksLeft > 0)
            e = SDL_WaitEventTimeout(&event, ticksLeft);
        else
            e = SDL_PollEvent(&event);
        if(e){
            switch(event.type)
            {
            case SDL_QUIT:
                printf("Quitting now!\n");
                exit(0);
                break;
            case SDL_MOUSEWHEEL:
                mouse.wheel.x += event.wheel.x;
                mouse.wheel.y += event.wheel.y;
                break;
            case SDL_KEYDOWN:
                if(inTextIsEnabled() && event.key.keysym.sym == SC_BACKSPACE && itxt.it->textLen > 0){
                    itxt.it->textLen--;
                    itxt.it->text[itxt.it->textLen] = '\0';
                }
                break;
            case SDL_TEXTINPUT:
                printf("SDL_TEXTINPUT\n");
                if(!itxt.it)
                    break;
                assertExpr(event.text.text);
                const st textLen = strlen(event.text.text);
                printf("(%zu): %s\n", textLen, event.text.text);
                memcpy(itxt.it->buf+itxt.it->bufPos, event.text.text, textLen);
                itxt.it->bufPos += textLen;
                printf("text: %s\n", itxt.it->text);
                break;
            case SDL_TEXTEDITING:
                printf("SDL_TEXTEDITING\n");
                break;
            default:
                break;
            }
        }
        ticksLeft = imax(0, endOfFrame - getTicks());
    }while(ticksLeft > 0 || e);
    gfx.winLen = getWindowLen();
    memcpy(keys.prev, keys.key, SDL_NUM_SCANCODES);
    memcpy(keys.key, SDL_GetKeyboardState(NULL), SDL_NUM_SCANCODES);
    mouse.prev.state = mouse.state;
    mouse.prev.pos = mouse.pos;
    mouse.prev.vec = mouse.vec;
    mouse.state = SDL_GetMouseState(&mouse.pos.x, &mouse.pos.y);
    SDL_GetRelativeMouseState(&mouse.vec.x, &mouse.vec.y);

    if(itxt.it){
        if(itxt.it->bufPos)
            inTextCommitBuf();
        if(itxt.endInput()){
            itxt.it = NULL;
            inTextStop();
            printf("Finished text input\n");
        }
    }
}

#endif /* end of include guard: DOGELIB_EVENTS_H */
