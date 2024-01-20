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
___
```c
int main(void)
```
This declares our main function which is our program entry point.
```c
init();
```
This function initializes DogeLib. Initialization includes -
* Graphics structures
* Font handling
* Image functionality
* Text input handling
* Window creation
```c
setTextColor(RED);
```
This sets our text drawing color to red.
```c
setColor(CYAN);
```
This sets our drawing color to cyan.
```c
Coord p = getWindowMid();
```
This creates a coordinate (which is just a struct with 2 integers, x and y).
It initializes the values of x and y to the middle of the window. In DogeLib
the top left of the window is 0,0.
```c
while(1){
```
This is our main loop. Every frame executes the body of this loop.
```c
const uint t = frameStart();
```
`frameStart()` clears the window to the default color (which is now black), it
also returns the number of milliseconds since the program began. We record this
value in the variable `t` for use later.
```c
if(keyPressed(SC_ESCAPE))
    return 0;
```
We check to see if the escape key is pressed, and if so, return from main,
exiting the program.
```c
p = coordAdd(p, coordMuli(wasdKeyStateOffset(), 4));
```
We update the value of `p` here, lets break this down function by function
starting with the inner most function and working our way out.
```c
wasdKeyStateOffset()
```
We use this function to get an `Offset` (which is just another typedef name of
`Coord`) struct that contains the state of the W, A, S, and D keys. This is
useful in situations where you would like to use those keys for movement.
The x value will be set to the state of the D key - the state of the A key.
The y value will be set to the state of the S key - the state of the W key.
For example, the value returned would be:
(-1,  1) if A and S are being held,
( 0, -1) if W is being held,
( 1,  1) if D and S are being held.
```c
coordMuli()
```
(Short for coordinate multiply integer)
This function takes 2 arguments: a `Coord` or `Offset`, and an integer. Both
components of the `Coord` will be multiplied by the integer.
```c
coordAdd()
```
This function takes 2 coordinates and multiplies their respective components.


Putting it all together, we are updating the value of `p` to whatever it's
current value is, plus, the offset value of the state of the W, A, S, and D
keys multiplied by 4.
```c
fillCircleCoord(mouse.pos, 32);
```
(Short for fill circle at a coordinate)
This fills in a circle whose color will be the current drawing color (which is
cyan at the moment), of a given radius (32 in this example).
```c
drawTextCenteredCoord("Hello", p);
```
(Short for draw text centered at a coordinate)
This draws the text "Hello" such that it is centered on the coordinate `p`. The
text size will be whatever the current text draw size is (32 by default). The
color of the text will be whatever the current text drawing color is (it is
currently red).
```c
frameEnd(t);
```
This function should be called at the end of our main loop. It renders
everything to the window, and then handles inputs and frame timing.
```c
return 0;
```
This line is never reached, as we never break from our loop, but is needed so
the compiler doesn't yell at us about not returning an `int` from `main`.

That's it! That is a high level view of everything that occurs in this example
program!
