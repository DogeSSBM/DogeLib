#ifndef TRANSPARENTWINDOW_H
#define TRANSPARENTWINDOW_H

void example(void)
{
    init();

    float state = 1.0f;
    while(1){
        const uint t = frameStart();

        const float statePrv = state;
        state += mouseScrolledY() * 0.10f;
        if(state > 1.0f)
            state = 1.0f;
        if(state < 0.0f)
            state = 0.0f;
        if(state != statePrv)
            winSetOpacity(state);

        frameEnd(t);
    }
}

#endif /* end of include guard: TRANSPARENTWINDOW_H */
