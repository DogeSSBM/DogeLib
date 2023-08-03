#ifndef DOGELIB_DOGEUTIL_H
#define DOGELIB_DOGEUTIL_H

void clearTerminal(void)
{
    printf(__extension__"\e[1;1H\e[2J");
}

float randRange(float a, float b)
{
    return ((b-a)*((float)rand()/RAND_MAX))+a;
}

void* recalloc(void *data, const st oldsize, const st newsize)
{
    data = realloc(data, newsize);
    if(newsize > oldsize)
        memset((char*)data+oldsize, 0, newsize-oldsize);
    return data;
}

void init(void)
{
    srand(time(NULL));
    gfx_init();
    img_init();
    text_init();
    input_init();
    inTextStop();
}

#endif /* end of include guard: DOGELIB_DOGEUTIL_H */
