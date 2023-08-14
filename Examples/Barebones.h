#ifndef BAREBONES_H
#define BAREBONES_H

int example(void)
{
    init();

    Texture *txtr = loadTexture("./Doggo16x16.png");
    Coord pos = getWindowMid();

    printf("Yay!\n");
    while(1){
        const uint t = frameStart();

        pos = coordAdd(pos, coordMuli(wasdKeyStateOffset(), coordMin(getWindowLen()) / 128));
        drawTextureCenteredCoordResize(txtr, pos, iiC(coordMin(getWindowLen()) / 12));

        if(keyPressed(SC_ESCAPE) || checkCtrlKey(SC_Q)){
            textureFree(txtr);
            exit(EXIT_SUCCESS);
        }

        frameEnd(t);
    }
}

#endif /* end of include guard: BAREBONES_H */
