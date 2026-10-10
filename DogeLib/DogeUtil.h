#ifndef DOGELIB_DOGEUTIL_H
#define DOGELIB_DOGEUTIL_H

// clears the terminal
void clearTerminal(void)
{
    printf(__extension__"\e[1;1H\e[2J");
}

// returns a random number between a and b
float randRange(float a, float b)
{
    return ((b-a)*((float)rand()/RAND_MAX))+a;
}

// reallocs and zeros data to new size
void* recalloc(void *data, const st newsize)
{
    data = realloc(data, newsize);
    memset((char*)data, 0, newsize);
    return data;
}

// inits everything
void init(void)
{
    srand(time(NULL));
    gfx_init();
    img_init();
    net_init();
    text_init();
    input_init();
    SDL_StopTextInput();
}

#endif /* end of include guard: DOGELIB_DOGEUTIL_H */
