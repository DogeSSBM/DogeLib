#ifndef SERVER_H
#define SERVER_H

int example(void)
{
    init();

    TCPsocket server, client;
    IPaddress ip;
    printf("Starting server...\n");
    if(SDLNet_ResolveHost(&ip, NULL, 9999) == -1){
        printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
        exit(EXIT_FAILURE);
    }
    server = SDLNet_TCP_Open(&ip);
    if(!server){
        printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
        exit(EXIT_FAILURE);
    }

    while(1){
        const uint t = frameStart();

        if (keyPressed(SC_ESCAPE))
            return 0;

        /* try to accept a connection */
        client = SDLNet_TCP_Accept(server);
        if (!client){ /* no connection accepted */
            /*printf("SDLNet_TCP_Accept: %s\n",SDLNet_GetError()); */
            goto endOfFrame;
        }

        /* get the clients IP and port number */
        IPaddress *remoteip;
        remoteip = SDLNet_TCP_GetPeerAddress(client);
        if (!remoteip)
        {
            printf("SDLNet_TCP_GetPeerAddress: %s\n", SDLNet_GetError());
            goto endOfFrame;
        }

        /* print out the clients IP and port number */
        Uint32 ipaddr;
        ipaddr = SDL_SwapBE32(remoteip->host);
        printf("Accepted a connection from %d.%d.%d.%d port %hu\n", ipaddr >> 24,
               (ipaddr >> 16) & 0xff, (ipaddr >> 8) & 0xff, ipaddr & 0xff,
               remoteip->port);

        while(1){
            /* read the buffer from client */
            char message[1024];
            int len = SDLNet_TCP_Recv(client, message, 1024);
            if (!len){
                printf("SDLNet_TCP_Recv: %s\n", SDLNet_GetError());
                break;
            }
            /* print out the message */
            printf("Received: %.*s\n", len, message);
        }
        SDLNet_TCP_Close(client);

        endOfFrame:
        frameEnd(t);
    }
}

#endif /* end of include guard: SERVER_H */