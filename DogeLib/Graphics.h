#ifndef DOGELIB_GRAPHICS_H
#define DOGELIB_GRAPHICS_H

#define DEFAULT_WINDOW_XLEN    800
#define DEFAULT_WINDOW_YLEN    600

struct{
    Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    uint fontSize;
    Color fontColor;
    Color defaultColor;
    Length restoreLen;
    Length prvLen;
    Length winLen;
    bool outlined;
    u32 winFlags;
}gfx = {0};

// sets the drawing blend mode
void setBlend(const BlendMode mode)
{
    SDL_SetRenderDrawBlendMode(gfx.renderer, mode);
}

// draws a pixel at (x, y)
void drawPixel(const int x, const int y)
{
    SDL_RenderDrawPoint(gfx.renderer, x, y);
}

// draws pixel at pos
void drawPixelCoord(const Coord pos)
{
    SDL_RenderDrawPoint(gfx.renderer, pos.x, pos.y);
}

// draws line from (x1, y1) to (x2, y2)
void drawLine(const int x1, const int y1, const int x2, const int y2)
{
    SDL_RenderDrawLine(gfx.renderer, x1, y1, x2, y2);
}

// draws line from a to b
void drawLineCoords(const Coord a, const Coord b)
{
    SDL_RenderDrawLine(gfx.renderer, a.x, a.y, b.x, b.y);
}

// draws a horizontal line at (x, y) of length len
void drawHLine(const int x, const int y, const int len)
{
    SDL_RenderDrawLine(gfx.renderer, x, y, x+len, y);
}

// draws a vertical line at (x, y) of length len
void drawVLine(const int x, const int y, const int len)
{
    SDL_RenderDrawLine(gfx.renderer, x, y, x, y+len);
}

// draws a rect at (x, y) of length (xlen, ylen)
void drawRect(const int x, const int y, const int xlen, const int ylen)
{
    SDL_RenderDrawRect(
        gfx.renderer,
        &(const Rect){.x = x, .y = y, .w = xlen, .h = ylen}
    );
}

// draws a rect at with corners
void drawRectCoords(const Coord a, const Coord b)
{
    SDL_RenderDrawRect(
        gfx.renderer,
        &(const Rect){
            .x = imin(a.x, b.x),
            .y = imin(a.y, b.y),
            .w = iabs(a.x-b.x),
            .h = iabs(a.y-b.y)
        }
    );
}

// draws a rect with top left corner and bottom right corners
void drawRectCorners(const int x1, const int y1, const int x2, const int y2)
{
    SDL_RenderDrawRect(
        gfx.renderer,
        &(const Rect){.x = x1, .y = y1, .w = iabs(x1-x2), .h = iabs(y1-y2)}
    );
}

// draws a rect with its center at (x, y) of length (xlen, ylen)
void drawRectCentered(const int x, const int y, const int xlen, const int ylen)
{
    SDL_RenderDrawRect(
        gfx.renderer,
        &(const Rect){.x = x - xlen/2, .y = y - ylen/2, .w = xlen, .h = ylen}
    );
}

// draws a rect centered at corners
void drawRectCenteredCorners(const int x1, const int y1, const int x2, const int y2)
{
    const int xlen = iabs(x1-x2);
    const int ylen = iabs(y1-y2);
    SDL_RenderDrawRect(
        gfx.renderer,
        &(const Rect){.x = x1 - xlen/2, .y = y1 - ylen/2, .w = xlen, .h = ylen}
    );
}

// draws a rect centered at corners
void drawRectCenteredCoords(const Coord a, const Coord b)
{
    SDL_RenderDrawRect(
        gfx.renderer,
        &(const Rect){
            .x = imin(a.x, b.x) - iabs(a.x-b.x)/2,
            .y = imin(a.y, b.y) - iabs(a.y-b.y)/2,
            .w = iabs(a.x-b.x),
            .h = iabs(a.y-b.y)
        }
    );
}

// fills a rect at (x, y) with length (xlen, ylen)
void fillRect(const int x, const int y, const int xlen, const int ylen)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){.x = x, .y = y, .w = xlen, .h = ylen}
    );
}

// fills a rect with top left corner and bottom right corners
void fillRectCorners(const int x1, const int y1, const int x2, const int y2)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){.x = x1, .y = y1, .w = iabs(x1-x2), .h = iabs(y1-y2)}
    );
}

// fills a rect with its center at (x, y) of length (xlen, ylen)
void fillRectCentered(const int x, const int y, const int xlen, const int ylen)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){.x = x - xlen/2, .y = y - ylen/2, .w = xlen, .h = ylen}
    );
}

// fills a rect centered at corners
void fillRectCenteredCorners(const int x1, const int y1, const int x2, const int y2)
{
    const int xlen = iabs(x1-x2);
    const int ylen = iabs(y1-y2);
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){.x = x1 - xlen/2, .y = y1 - ylen/2, .w = xlen, .h = ylen}
    );
}

// fills a rect with corners
void fillRectCoords(const Coord a, const Coord b)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){
            .x = imin(a.x, b.x),
            .y = imin(a.y, b.y),
            .w = iabs(a.x-b.x),
            .h = iabs(a.y-b.y)
        }
    );
}

// fills a rect centered at corners
void fillRectCenteredCoords(const Coord a, const Coord b)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){
            .x = imin(a.x, b.x) - iabs(a.x-b.x)/2,
            .y = imin(a.y, b.y) - iabs(a.y-b.y)/2,
            .w = iabs(a.x-b.x),
            .h = iabs(a.y-b.y)
        }
    );
}

// draws a rect at pos with length len
void drawRectCoordLength(const Coord pos, const Length len)
{
    SDL_RenderDrawRect(
        gfx.renderer,
        &(const Rect){
            .x = pos.x,
            .y = pos.y,
            .w = len.x,
            .h = len.y
        }
    );
}

// fills a rect with its center at pos of length len
void drawRectCenteredCoordLength(const Coord pos, const Length len)
{
    SDL_RenderDrawRect(
        gfx.renderer,
        &(const Rect){
            .x = (pos.x) - len.x/2,
            .y = (pos.y) - len.y/2,
            .w = len.x,
            .h = len.y
        }
    );
}

// fills a rect at pos of length len
void fillRectCoordLength(const Coord pos, const Length len)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){
            .x = pos.x,
            .y = pos.y,
            .w = len.x,
            .h = len.y
        }
    );
}

// fills a rect centered at pos of length len
void fillRectCenteredCoordLength(const Coord pos, const Length len)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){
            .x = (pos.x) - len.x/2,
            .y = (pos.y) - len.y/2,
            .w = len.x,
            .h = len.y
        }
    );
}

// draws a rect
void drawRectRect(const Rect rect)
{
    SDL_RenderDrawRect(gfx.renderer, &rect);
}

// draws a rect centered on its x and y components
void drawRectCenteredRect(const Rect rect)
{
    SDL_RenderDrawRect(
        gfx.renderer,
        &(const Rect){
            .x = (rect.x) - rect.x/2,
            .y = (rect.y) - rect.y/2,
            .w = rect.w,
            .h = rect.h
        }
    );
}

// fills a rect
void fillRectRect(const Rect rect)
{
    SDL_RenderFillRect(gfx.renderer, &rect);
}

// fills a rect centered on its x and y components
void fillRectCenteredRect(const Rect rect)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){
            .x = (rect.x) - rect.x/2,
            .y = (rect.y) - rect.y/2,
            .w = rect.w,
            .h = rect.h
        }
    );
}

// draws a square at (x, y) with length len
void drawSquare(const int x, const int y, const int len)
{
    SDL_RenderDrawLine(gfx.renderer, x, y, x+len-1, y);
    SDL_RenderDrawLine(gfx.renderer, x, y, x, y+len-1);
    SDL_RenderDrawLine(gfx.renderer, x+len-1, y, x+len-1, y+len-1);
    SDL_RenderDrawLine(gfx.renderer, x, y+len-1, x+len-1, y+len-1);
}

// draws a square at pos with length len
void drawSquareCoord(const Coord pos, const int len)
{
    SDL_RenderDrawLine(gfx.renderer, pos.x, pos.y, pos.x+len-1, pos.y);
    SDL_RenderDrawLine(gfx.renderer, pos.x, pos.y, pos.x, pos.y+len-1);
    SDL_RenderDrawLine(gfx.renderer, pos.x+len-1, pos.y, pos.x+len-1, pos.y+len-1);
    SDL_RenderDrawLine(gfx.renderer, pos.x, pos.y+len-1, pos.x+len-1, pos.y+len-1);
}

// draws a square centered on (x, y) with length len
void drawSquareCentered(const int x, const int y, const int len)
{
    const int px = x - len/2;
    const int py = y - len/2;
    SDL_RenderDrawLine(gfx.renderer, px, py, x+len-1, py);
    SDL_RenderDrawLine(gfx.renderer, px, py, x, py+len-1);
    SDL_RenderDrawLine(gfx.renderer, px+len-1, py, x+len-1, py+len-1);
    SDL_RenderDrawLine(gfx.renderer, px, py+len-1, x+len-1, py+len-1);
}

// draws a square centered at pos with length len
void drawSquareCenteredCoord(const Coord pos, const int len)
{
    const int px = pos.x - len/2;
    const int py = pos.y - len/2;
    SDL_RenderDrawLine(gfx.renderer, px, py, px+len-1, py);
    SDL_RenderDrawLine(gfx.renderer, px, py, px, py+len-1);
    SDL_RenderDrawLine(gfx.renderer, px+len-1, py, px+len-1, py+len-1);
    SDL_RenderDrawLine(gfx.renderer, px, py+len-1, px+len-1, py+len-1);
}

// fills a square at (x, y) with length len
void fillSquare(const int x, const int y, const int len)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){
            .x = x,
            .y = y,
            .w = len,
            .h = len
        }
    );
}

// fills a square at pos with length len
void fillSquareCoord(const Coord pos, const int len)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){
            .x = pos.x,
            .y = pos.y,
            .w = len,
            .h = len
        }
    );
}

// fills a square centered on (x, y) with length len
void fillSquareCentered(const int x, const int y, const int len)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){
            .x = x - len/2,
            .y = y - len/2,
            .w = len,
            .h = len
        }
    );
}

// fills a square centered at pos with length len
void fillSquareCenteredCoord(const Coord pos, const int len)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){
            .x = pos.x - len/2,
            .y = pos.y - len/2,
            .w = len,
            .h = len
        }
    );
}

// fills a square at x and y resized by resize
void fillSquareResize(const int x, const int y, const int len, const int resize)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){
            .x = x-resize,
            .y = y-resize,
            .w = len+resize*2,
            .h = len+resize*2
        }
    );
}

// fills a square at pos resized by resize
void fillSquareCoordResize(const Coord pos, const int len, const int resize)
{
    SDL_RenderFillRect(
        gfx.renderer,
        &(const Rect){
            .x = pos.x-resize,
            .y = pos.y-resize,
            .w = len+resize*2,
            .h = len+resize*2
        }
    );
}

// fills a border at (x, y) with length (xlen, ylen) and thickness b
void fillBorder(const int x, const int y, const int xlen, const int ylen, const int b)
{
    fillRect(x-b,           y-b,            xlen+2*b,   b);
    fillRect(x-b,           y+ylen,         xlen+2*b,   b);
    fillRect(x-b,           y,              b,          ylen);
    fillRect(x+xlen,        y,              b,          ylen);
}

// fills a border at pos with length len and thickness b
void fillBorderCoord(const Coord pos, const Length len, const int b)
{
    fillRect(pos.x-b,       pos.y-b,        len.x+2*b,  b);
    fillRect(pos.x-b,       pos.y+len.y,    len.x+2*b,  b);
    fillRect(pos.x-b,       pos.y,          b,          len.y);
    fillRect(pos.x+len.x,   pos.y,          b,          len.y);
}

// fills a border centered at (x, y) with length (xlen, ylen) and thickness b
void fillBorderCentered(const int x, const int y, const int xlen, const int ylen, const int b)
{
    const int px = x - xlen/2;
    const int py = y - ylen/2;
    fillRect(px-b,           py-b,            xlen+2*b,   b);
    fillRect(px-b,           py+ylen,         xlen+2*b,   b);
    fillRect(px-b,           py,              b,          ylen);
    fillRect(px+xlen,        py,              b,          ylen);
}

// fills a border centered at pos with length len and thickness b
void fillBorderCenteredCoord(const Coord pos, const Length len, const int b)
{
    const int px = pos.x - len.x/2;
    const int py = pos.y - len.y/2;
    fillRect(px-b,       py-b,        len.x+2*b,  b);
    fillRect(px-b,       py+len.y,    len.x+2*b,  b);
    fillRect(px-b,       py,          b,          len.y);
    fillRect(px+len.x,   py,          b,          len.y);
}

// fills a square border at pos with length len and thickness b
void fillBorderCoordSquare(const Coord pos, const int len, const int b)
{
    fillRect(pos.x-b,       pos.y-b,        len+2*b,    b);
    fillRect(pos.x-b,       pos.y+len,      len+2*b,    b);
    fillRect(pos.x-b,       pos.y,          b,          len);
    fillRect(pos.x+len,     pos.y,          b,          len);
}

// draws a circle centered at (x, y) with radius r
void drawCircle(const int x, const int y, const int r)
{
    const double rsq = (double)(r*r);
    int yoff = r;
    for(int xoff = 0; xoff <= yoff; xoff++){
        const double yc = sqrt(rsq - (xoff+1)*(xoff+1));
        const double ym = (double)yoff - 0.5;
        // 8 sections of circle
        drawPixel(x+xoff, y+yoff);        // 1
        drawPixel(x-yoff, y+xoff);        // 2
        drawPixel(x-xoff, y-yoff);        // 3
        drawPixel(x+yoff, y-xoff);        // 4

        drawPixel(x-xoff, y+yoff);        // 5
        drawPixel(x-yoff, y-xoff);        // 6
        drawPixel(x+xoff, y-yoff);        // 7
        drawPixel(x+yoff, y+xoff);        // 8
        yoff -= yc <= ym;
    }
}

// fills a circle centered at (x, y) with radius r
void fillCircle(const int x, const int y, const int r)
{
    const double rsq = (double)(r*r);
    int yoff = r;
    for(int xoff = 0; xoff <= yoff; xoff++){
        const double yc = sqrt(rsq - (xoff+1)*(xoff+1));
        const double ym = (double)yoff - 0.5;
        // connecting 8 sections of circle
        drawLine(x+xoff, y-yoff, x+xoff, y+yoff);        // 7 to 1
        drawLine(x-yoff, y+xoff, x+yoff, y+xoff);        // 2 to 8
        drawLine(x-xoff, y-yoff, x-xoff, y+yoff);        // 3 to 5
        drawLine(x-yoff, y-xoff, x+yoff, y-xoff);        // 6 to 4
        yoff -= yc <= ym;
    }
}

// draws a circle centered at pos with radius r
void drawCircleCoord(const Coord pos, const int r)
{
    const double rsq = (double)(r*r);
    uint yoff = r;
    for(uint xoff = 0; xoff <= yoff; xoff++){
        const double yc = sqrt(rsq - (xoff+1)*(xoff+1));
        const double ym = (double)yoff - 0.5;
        // 8 sections of circle
        drawPixel(pos.x+xoff, pos.y+yoff);        // 1
        drawPixel(pos.x-yoff, pos.y+xoff);        // 2
        drawPixel(pos.x-xoff, pos.y-yoff);        // 3
        drawPixel(pos.x+yoff, pos.y-xoff);        // 4

        drawPixel(pos.x-xoff, pos.y+yoff);        // 5
        drawPixel(pos.x-yoff, pos.y-xoff);        // 6
        drawPixel(pos.x+xoff, pos.y-yoff);        // 7
        drawPixel(pos.x+yoff, pos.y+xoff);        // 8
        yoff -= yc <= ym;
    }
}

// fills a circle centered at pos with radius r
void fillCircleCoord(const Coord pos, const int r)
{
    const double rsq = (double)(r*r);
    uint yoff = r;
    for(uint xoff = 0; xoff <= yoff; xoff++){
        const double yc = sqrt(rsq - (xoff+1)*(xoff+1));
        const double ym = (double)yoff - 0.5;
        // connecting 8 sections of circle
        drawLine(pos.x+xoff, pos.y-yoff, pos.x+xoff, pos.y+yoff);// 7 to 1
        drawLine(pos.x-yoff, pos.y+xoff, pos.x+yoff, pos.y+xoff);// 2 to 8
        drawLine(pos.x-xoff, pos.y-yoff, pos.x-xoff, pos.y+yoff);// 3 to 5
        drawLine(pos.x-yoff, pos.y-xoff, pos.x+yoff, pos.y-xoff);// 6 to 4
        yoff -= yc <= ym;
    }
}

// draws a thick line with rounded edges from (x1, y1) to (x2, y2) with radius r
void drawLineThick(const int x1, const int y1, const int x2, const int y2, const int r)
{
    drawLine(x1, y1, x2, y2);
    if(r > 1){
        fillCircle(x1, y1, r-1);
        fillCircle(x2, y2, r-1);
    }
    for(int i = 0; i <= r; i++)
        for(Direction d = 0; d < 4; d++)
            drawLineCoords(
                coordShift((const Coord){.x = x1, .y = y1}, d, i),
                coordShift((const Coord){.x = x2, .y = y2}, d, i)
            );
}

// draws a thick line with rounded edges from a to b with radius r
void drawLineThickCoords(const Coord a, const Coord b, const int r)
{
    drawLineCoords(a, b);
    if(r > 1){
        fillCircleCoord(a, r-1);
        fillCircleCoord(b, r-1);
    }
    for(int i = 0; i <= r; i++){
        for(Direction d = 0; d < 4; d++){
            drawLineCoords(
                coordShift(a, d, i),
                coordShift(b, d, i)
            );
        }
    }
}

// gets current drawing color
Color getColor(void)
{
    Color c = {0};
    SDL_GetRenderDrawColor(gfx.renderer, &c.r, &c.g, &c.b, &c.a);
    return c;
}

// sets drawing color
void setColor(const Color c)
{
    SDL_SetRenderDrawColor(gfx.renderer, c.r, c.g, c.b, c.a);
}

// returns c as a u32
u32 colorToU32(const Color c)
{
    return *((u32*)&c);
}

// returns u as a Color
Color u32ToColor(const u32 u)
{
    return (const Color){
        .r = u&0xff,
        .g = (u>>8)&0xff,
        .b = (u>>16)&0xff,
        0xff
    };
}

// draws a tri
void drawTri(const Coord pos1, const Coord pos2, const Coord pos3)
{
    trigonColor(
        gfx.renderer,
        pos1.x, pos1.y,
        pos2.x, pos2.y,
        pos3.x, pos3.y,
        colorToU32(getColor())
    );
}

// fills a tri
void fillTri(const Coord pos1, const Coord pos2, const Coord pos3)
{
    filledTrigonColor(
        gfx.renderer,
        pos1.x, pos1.y,
        pos2.x, pos2.y,
        pos3.x, pos3.y,
        colorToU32(getColor())
    );
}

// draws a poly
void drawPoly(Coord *pos, const uint num)
{
    i16 posx[num];
    i16 posy[num];
    for(uint i = 0; i < num; i++){
        posx[i] = pos[i].x;
        posy[i] = pos[i].y;
    }
    polygonColor(gfx.renderer, posx, posy, num, colorToU32(getColor()));
}

// fills a poly
void fillPoly(Coord *pos, const uint num)
{
    i16 posx[num];
    i16 posy[num];
    for(uint i = 0; i < num; i++){
        posx[i] = pos[i].x;
        posy[i] = pos[i].y;
    }
    filledPolygonColor(gfx.renderer, posx, posy, num, colorToU32(getColor()));
}

// draws a bezier curve
void bezier(const Coord *pos, const uint numc, const uint nums)
{
    i16 posx[numc];
    i16 posy[numc];
    for(uint i = 0; i < numc; i++){
        posx[i] = pos[i].x;
        posy[i] = pos[i].y;
    }
    bezierColor(gfx.renderer, posx, posy, numc, nums, colorToU32(getColor()));
}

// sets red green and blue components of drawing color
void setRGB(const u8 r, const u8 g, const u8 b)
{
    SDL_SetRenderDrawColor(gfx.renderer, r, g, b, 255);
}

// sets red green blue and alpha components of drawing color
void setRGBA(const u8 r, const u8 g, const u8 b, const u8 a)
{
    SDL_SetRenderDrawColor(gfx.renderer, r, g, b, a);
}

// fills screen with current drawing color
void fillScreen(void)
{
    SDL_RenderClear(gfx.renderer);
}

// fills screen with defaultColor
void clear(void)
{
    const Color c = getColor();
    setColor(gfx.defaultColor);
    SDL_RenderClear(gfx.renderer);
    setColor(c);
}

// outlines the window
void outlineWindow(void)
{
    const Color c = getColor();
    setColor(WHITE);
    fillBorderCoord(iC(0,0), getWindowLen(), -2);
    setColor(c);
}

// renders everything to window
void draw(void)
{

    if(gfx.outlined)
        outlineWindow();
    SDL_RenderPresent(gfx.renderer);
}

// clears window and returns current time
uint frameStart(void)
{
    clear();
    return getTicks();
}

// renders window and handles events and frame timing
void frameEnd(const uint t)
{
    draw();
    events(t+TPF);
}

// cleans up gfx stuff
void gfx_quit(void)
{
    SDL_DestroyRenderer(gfx.renderer);
    SDL_DestroyWindow(gfx.window);
    SDL_Quit();
}

// initializes gfx stuff
void gfx_init(void)
{
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        printf("SDL borked! Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    gfx.window = SDL_CreateWindow(
        "main.out",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        DEFAULT_WINDOW_XLEN,
        DEFAULT_WINDOW_YLEN,
        SDL_WINDOW_RESIZABLE
    );

    gfx.renderer = SDL_CreateRenderer(gfx.window, -1, SDL_RENDERER_ACCELERATED);
    printf("Adding gfx_quit to atexit()\n");
    atexit(gfx_quit);

    gfx.defaultColor = BLACK;
    gfx.outlined = true;
    SDL_SetRenderDrawBlendMode(gfx.renderer, BLEND_NONE);
    gfx.restoreLen.x = DEFAULT_WINDOW_XLEN;
    gfx.restoreLen.y = DEFAULT_WINDOW_YLEN;
    setWindowResizable(true);
    gfx.winLen.x = DEFAULT_WINDOW_XLEN;
    gfx.prvLen.x = DEFAULT_WINDOW_XLEN;
    gfx.winLen.y = DEFAULT_WINDOW_YLEN;
    gfx.prvLen.y = DEFAULT_WINDOW_YLEN;

    clear();
    draw();
    clear();
}

#endif /* end of include guard: DOGELIB_GRAPHICS_H */
