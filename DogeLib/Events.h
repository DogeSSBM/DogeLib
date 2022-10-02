#ifndef EVENTS_H
#define EVENTS_H

void events(const uint endOfFrame)
{
    i32 ticksLeft = endOfFrame - getTicks();
    mouse.prev.wheel = mouse.wheel;
    mouse.wheel = 0;
    do{
        Event event;
        if(SDL_WaitEventTimeout(&event, ticksLeft>0?ticksLeft:1)){
            switch(event.type)
            {
            case SDL_QUIT:
                printf("Quitting now!\n");
                exit(0);
                break;
            case SDL_MOUSEWHEEL:
                if(event.wheel.x)
                    mouse.wheel |= event.wheel.x>0?MW_R:MW_L;
                if(event.wheel.y)
                    mouse.wheel |= event.wheel.y>0?MW_D:MW_U;
                break;
            case SDL_WINDOWEVENT_SIZE_CHANGED:
            case SDL_WINDOWEVENT:
                gfx.prvLen = getWindowLen();
                break;
            default:
                break;
            }
        }
        ticksLeft = endOfFrame - getTicks();
    }while(ticksLeft > 0);
    memcpy(keys.prev, keys.key, SDL_NUM_SCANCODES);
    memcpy(keys.key, SDL_GetKeyboardState(NULL), SDL_NUM_SCANCODES);
    mouse.prev.state = mouse.state;
    mouse.prev.pos = mouse.pos;
    mouse.prev.vec = mouse.vec;
    mouse.state = SDL_GetMouseState(&mouse.pos.x, &mouse.pos.y);
    SDL_GetRelativeMouseState(&mouse.vec.x, &mouse.vec.y);
}

#endif /* end of include guard: EVENTS_H */
