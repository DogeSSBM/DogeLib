#pragma once

void clearTerminal(void)
{
    printf("\e[1;1H\e[2J");
}

int mini(const int a, const int b)
{
    return a < b ? a : b;
}

int maxi(const int a, const int b)
{
    return a < b ? b : a;
}

float minf(const float a, const float b)
{
    return a < b ? a : b;
}

float maxf(const float a, const float b)
{
    return a < b ? b : a;
}

float randRangef(const float a, const float b)
{
    const float min = minf(a, b);
    const float max = maxf(a, b);
    const float range = max-min;
    return fmod(((float)rand()/RAND_MAX), range)*range+min;
}

int randRange(const int a, const int b)
{
    const int min = mini(a, b);
    const int max = maxi(a, b);
    return (rand() % (max-min)) + min;
}

void init(const int x, const int y)
{
    srand((unsigned)time(NULL));
    gfx_init(x, y);
    img_init();
    text_init();
    input_init();
}
