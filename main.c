#include "DogeLib/Includes.h"
<<<<<<< HEAD
=======
// uncomment one of the below example files and call example() in the main function for a demonstration of DogeLib
// #include "Examples/Dogs.h"
// #include "Examples/Server.h"
#include "Examples/Client.h"
// #include "Examples/Barebones.h"
// #include "Examples/TransparentWindow.h"
// #include "Examples/TextInput.h"

>>>>>>> b630c6dadb9c5a5942bde2fd6644fc4bbd8788e9

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
