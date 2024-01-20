#ifndef CLIENT_H
#define CLIENT_H

// function that returns true when done editing current field
bool done(void)
{
    return keyState(SC_ESCAPE) || keyState(SC_RETURN);
}

int example(void)
{
    init();
    SDL_StopTextInput();

    printf("Starting client...\n");
    IPaddress ip;
    TCPsocket tcpsock;

    if(SDLNet_ResolveHost(&ip, "192.168.130.195", 9999) < 0){
        printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
        exit(EXIT_FAILURE);
    }

    tcpsock = SDLNet_TCP_Open(&ip);
    if(!tcpsock){
        printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
        exit(EXIT_FAILURE);
    }

    bool textIn = false;
    bool send = false;
    char message[1024] = {0};
    setTextSize(16);
    setTextColor(WHITE);
    while(1){
        const uint t = frameStart();

        if(keyPressed(SC_ESCAPE))
            return 0;

        if(!textIn){
            if(keyPressed(SC_RETURN))
                textIn = true;
        }else{
            if(send){
                if(!textInputState()){
                    int len = strlen(message);

                    if(len){
                        int result;

                        /* print out the message */
                        printf("Sending: %.*s\n", len, message);

                        result =
                            SDLNet_TCP_Send(tcpsock, message, len); /* add 1 for the NULL */
                        if (result < len)
                            printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
                    }
                    send = false;
                }
            }else{
                if(!keyState(SC_RETURN)){
                    send = true;
                    textInputStart(message, 128, done);
                }
            }
        }
        drawTextCenteredCoord(message, getWindowMid());

        frameEnd(t);
    }
}


#endif /* end of include guard: CLIENT_H */
