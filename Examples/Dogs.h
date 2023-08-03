#ifndef EXAMPLE_DOGS_H
#define EXAMPLE_DOGS_H

typedef struct State{
    Length window;
    Texture *doggo;
    Texture *borko;
    Length len;
    uint scale;
    Coord origin;
    Texture *nametag;
    Coord mdown;
    InputType lin;
    InputType rin;
}State;

State initState(void)
{
    setColor(MAGENTA);
    setTextColor(GREEN);
    State state = {
        .window = getWindowLen(),
        .doggo = loadTexture("./Doggo16x16.png"),
        .borko = loadTexture("./Borko16x16.png"),
        .len = {.x=8,.y=6},
        .scale = coordMin(coordDiv(state.window, state.len)),
        .origin = coordUncenter(getWindowMid(), coordMuli(state.len, state.scale)),
        .nametag = textTexture("Doggo")
    };
    setTextSize(state.scale/5);
    return state;
}

State updateState(State state)
{
    if(keyPressed(SC_ESCAPE) || checkCtrlKey(SC_Q)){
        textureFree(state.doggo);
        textureFree(state.borko);
        textureFree(state.nametag);
        exit(EXIT_SUCCESS);
    }
    state.lin = mouseBtnInputType(MOUSE_L);
    state.rin = mouseBtnInputType(MOUSE_R);
    if(state.lin == I_PRESSED || state.rin == I_PRESSED)
        state.mdown = mouse.pos;
    if(inputTypeState(state.lin) || inputTypeState(state.rin))
        state.origin = coordAdd(state.origin, mouseMovement());
    bool reload = false;
    if((reload = mouseScrolledY()))
        state.scale = imax(1, state.scale + mouseScrolledY());
    if(keyPressed(SC_SPACE)){
        reload = true;
        state.origin = coordUncenter(
            getWindowMid(),
            coordMuli(state.len, (state.scale = coordMin(coordDiv((state.window = getWindowLen()), state.len))))
        );
    }
    if(reload){
        textureFree(state.nametag);
        setTextSize(state.scale/5);
        state.nametag = textTexture("Doggo");
    }
    state.len = coordMaxi(coordAdd(state.len, dirKeyPressedOffset()), 1);
    return state;
}

void drawState(const State state)
{
    for(int x = 0; x < state.len.x; x++){
        for(int y = 0; y < state.len.y; y++){
            const Coord pos = coordOffScale(iC(x,y), state.origin, state.scale);
            drawTextureCoord(state.nametag, pos);
            drawTextureCoordResize((x^y)&1 ? state.borko : state.doggo, pos, iiC(state.scale));
        }
    }
    drawTextureCenteredCoordResize(state.doggo, mouse.pos, iC(state.lin?128:64, state.lin?128:64));
    if(inputTypeState(state.lin) || inputTypeState(state.rin))
        drawLineThickCoords(state.mdown, mouse.pos, 6);
}

int example(void)
{
    init();
    State state = initState();

    while(1){
        const uint t = frameStart();

        state = updateState(state);
        drawState(state);

        frameEnd(t);
    }
}

#endif /* end of include guard: EXAMPLE_DOGS_H */
