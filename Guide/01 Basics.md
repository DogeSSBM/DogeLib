# Basics
The rest of the guide assumes the reader has a basic understanding of
programming in C.
## Barebones Example
A barebones DogeLib program might look something like the following:
```c
#include "DogeLib/Includes.h"

int main(void)
{
    init();
    setTextColor(RED);
    setColor(CYAN);
    Coord p = getWindowMid();
    while(1){
        const uint t = frameStart();

        if(keyPressed(SC_ESCAPE))
            return 0;

        p = coordAdd(p, coordMuli(wasdKeyStateOffset(), 4));
        fillCircleCoord(mouse.pos, 32);
        drawTextCenteredCoord("Hello", p);

        frameEnd(t);
    }
    return 0;
}
```
Lets go through this line by line -
```c
#include "DogeLib/Includes.h"
```
This simply includes DogeLib.
```c
int main(void)
```
This declares our main function which is our program entry point.
