#ifndef BAREBONES_H
#define BAREBONES_H

int example(void)
{
    init();

    while(1){
        const uint t = frameStart();

        const Coord middle = getWindowMid();

        if(keyPressed(SC_ESCAPE))
            return 0;

        setColor(RED);
        fillCircle(middle.x- 200, middle.y, 32);

        setColor(BLUE);
        fillCircle(middle.x+ 200, middle.y, 32);

        setColor(WHITE);
        fillCircleCoord(mouse.pos, 32);

        frameEnd(t);
    }
}

#endif /* end of include guard: BAREBONES_H */
