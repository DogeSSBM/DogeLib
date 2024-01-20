#ifndef DOGELIB_NET_H
#define DOGELIB_NET_H

void net_quit(void)
{
    SDLNet_Quit();
}

void net_init(void)
{
    if(SDLNet_Init() < 0){
        printf("SDL borked! Error: %s\n", SDLNet_GetError());
        exit(EXIT_FAILURE);
    }

    atexit(net_quit);
}

#endif /* end of include guard: DOGELIB_NET_H */