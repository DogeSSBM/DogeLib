#ifndef BAREBONES_H
#define BAREBONES_H

int example(void)
{
    init();

    while(1){
        const uint t = frameStart();

        frameEnd(t);
    }
}

#endif /* end of include guard: BAREBONES_H */
