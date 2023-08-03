#ifndef DOGELIB_COLORS_H
#define DOGELIB_COLORS_H

u8* colorIndex(Color *c, const int i)
{
    if(iabs(i)%3 == 0)
        return &(c->r);
    if(iabs(i)%3 == 1)
        return &(c->g);
    return &(c->b);
}

bool colorSame(const Color a, const Color b)
{
    return a.r == b.r && a.g == b.g && a.b == b.b;
}

const Color WHITE   = {0xFF, 0xFF, 0xFF, 0xFF};
const Color PINK    = {0xFF, 0xC0, 0xCB, 0xFF};
const Color CYAN    = {0x00, 0xFF, 0xFF, 0xFF};
const Color RED     = {0xFF, 0x00, 0x00, 0xFF};
const Color YELLOW  = {0xFF, 0xFF, 0x00, 0xFF};
const Color GREEN   = {0x00, 0xFF, 0x00, 0xFF};
const Color BLUE    = {0x00, 0x00, 0xFF, 0xFF};
const Color MAGENTA = {0xFF, 0x00, 0xFF, 0xFF};
const Color BLACK   = {0x00, 0x00, 0x00, 0xFF};
const Color GREY    = {0x80, 0x80, 0x80, 0xFF};

const Color GREY1   = {0xAA, 0xAA, 0xAA, 0xFF};
const Color GREY2   = {0x7E, 0x7E, 0x7E, 0xFF};
const Color GREY3   = {0x52, 0x52, 0x52, 0xFF};

#endif /* end of include guard: DOGELIB_COLORS_H */
