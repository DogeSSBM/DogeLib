#pragma once
#define DEFAULT_WINDOW_XLEN	800
#define DEFAULT_WINDOW_YLEN	600

struct{
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    int fontSize;
    Color fontColor;
    Color defaultColor;
    Length restoreLen;
    bool outlined;
}gfx = {};

static inline
void setWindowMode(const WindowMode mode)
{
    SDL_SetWindowFullscreen(gfx.window, mode);
}

static inline
void setWindowResizable(const bool resizable)
{
    SDL_SetWindowResizable(gfx.window, resizable);
}

static inline
bool getWindowResizable(void)
{
    return SDL_WINDOW_RESIZABLE & SDL_GetWindowFlags(gfx.window);
}

static inline
void setWindowLen(const Length len)
{
    SDL_SetWindowSize(gfx.window, len.x, len.y);
}

static inline
Length getWindowLen(void)
{
    Length ret = {0, 0};
    SDL_GetRendererOutputSize(gfx.renderer, &ret.x, &ret.y);
    return ret;
}

static inline
Length getWindowMid(void)
{
    Length ret = {0, 0};
    SDL_GetRendererOutputSize(gfx.renderer, &ret.x, &ret.y);
    return coordDiv(ret, 2);
}

static inline
bool coordInWindow(const Coord pos)
{
    const Length window = getWindowLen();
    return inBound(pos.x, 0, window.x) && inBound(pos.y, 0, window.y);
}

static inline
Length maximizeWindow(void)
{
    Length len = {0};
    gfx.restoreLen = getWindowLen();
    SDL_MaximizeWindow(gfx.window);
    SDL_GetWindowSize(gfx.window, &len.x, &len.y);
    return len;
}

static inline
Length restoreWindow(void)
{
    SDL_RestoreWindow(gfx.window);
    if(getWindowResizable())
    SDL_SetWindowSize(gfx.window, gfx.restoreLen.x, gfx.restoreLen.y);
    return gfx.restoreLen;
}

static inline
void setWindowSize(const uint x, const uint y)
{
    SDL_SetWindowSize(gfx.window, x, y);
}

static inline
void setBlend(const BlendMode mode)
{
    SDL_SetRenderDrawBlendMode(gfx.renderer, mode);
}

static inline
void drawPixel(const uint x, const uint y)
{
    SDL_RenderDrawPoint(gfx.renderer, x, y);
}

static inline
void drawPixelCoord(const Coord pos)
{
    SDL_RenderDrawPoint(gfx.renderer, pos.x, pos.y);
}

static inline
void drawLine(const uint x1, const uint y1, const uint x2, const uint y2)
{
    SDL_RenderDrawLine(gfx.renderer, x1, y1, x2, y2);
}

static inline
void drawLineCoords(const Coord pos1, const Coord pos2)
{
    SDL_RenderDrawLine(gfx.renderer, pos1.x, pos1.y, pos2.x, pos2.y);
}

static inline
void drawLineCoordPair(const CoordPair pair)
{
    SDL_RenderDrawLine(gfx.renderer, pair.pos1.x, pair.pos1.y, pair.pos2.x, pair.pos2.y);
}

static inline
void drawHLine(const uint x, const uint y, int len)
{
    SDL_RenderDrawLine(gfx.renderer, x, y, x+len, y);
}

static inline
void drawVLine(const uint x, const uint y, int len)
{
    SDL_RenderDrawLine(gfx.renderer, x, y, x, y+len);
}

static inline
void drawRect(const uint x, const uint y, const uint xlen, const uint ylen)
{
    SDL_RenderDrawRect(
    gfx.renderer,
    &(const Rect){x, y, xlen, ylen}
    );
}

static inline
void fillRect(const uint x, const uint y, const uint xlen, const uint ylen)
{
    SDL_RenderFillRect(
    gfx.renderer,
    &(const Rect){x, y, xlen, ylen}
    );
}

static inline
void drawRectCoords(const Coord pos1, const Coord pos2)
{
    SDL_RenderDrawRect(
    gfx.renderer,
    &(const Rect){
    pos1.x < pos2.x? pos1.x: pos2.x,
    pos1.y < pos2.y? pos1.y: pos2.y,
    abs(pos1.x-pos2.x),
    abs(pos1.y-pos2.y)
    }
    );
}

static inline
void fillRectCoords(const Coord pos1, const Coord pos2)
{
    SDL_RenderFillRect(
    gfx.renderer,
    &(const Rect){
    pos1.x < pos2.x? pos1.x: pos2.x,
    pos1.y < pos2.y? pos1.y: pos2.y,
    abs(pos1.x-pos2.x),
    abs(pos1.y-pos2.y)
    }
    );
}

static inline
void drawRectCoordLength(const Coord pos, const Length len)
{
    SDL_RenderDrawRect(gfx.renderer, &(const Rect){pos.x, pos.y, len.x, len.y});
}

static inline
void fillRectCoordLength(const Coord pos, const Length len)
{
    SDL_RenderFillRect(gfx.renderer, &(const Rect){pos.x, pos.y, len.x, len.y});
}
static inline
void drawRectRect(const Rect rect)
{
    SDL_RenderDrawRect(gfx.renderer, &rect);
}

static inline
void fillRectRect(const Rect rect)
{
    SDL_RenderFillRect(gfx.renderer, &rect);
}

static inline
void drawSquareCoord(const Coord pos, const uint len)
{
    SDL_RenderDrawRect(
    gfx.renderer,
    &(const Rect){pos.x, pos.y, len, len}
    );
}

static inline
void drawSquare(const uint x, const uint y, const uint len)
{
    SDL_RenderDrawRect(
    gfx.renderer,
    &(const Rect){x, y, len, len}
    );
}

static inline
void fillSquare(const uint x, const uint y, const uint len)
{
    SDL_RenderFillRect(
    gfx.renderer,
    &(const Rect){x, y, len, len}
    );
}

static inline
void fillSquareResize(const uint x, const uint y, const uint len, const int resize)
{
    SDL_RenderFillRect(
    gfx.renderer,
    &(const Rect){
    x-resize, y-resize, len+resize*2, len+resize*2
    }
    );
}

static inline
void fillSquareCoord(const Coord pos, const uint len)
{
    SDL_RenderFillRect(
    gfx.renderer,
    &(const Rect){pos.x, pos.y, len, len}
    );
}

static inline
void fillSquareCoordResize(const Coord pos, const uint len, const int resize)
{
    SDL_RenderFillRect(
    gfx.renderer,
    &(const Rect){
    pos.x-resize, pos.y-resize, len+resize*2, len+resize*2
    }
    );
}

static inline
void fillBorder(uint x, uint y, uint xlen, uint ylen, int b)
{
    fillRect(x-b, y-b, xlen+2*b, b);
    fillRect(x-b, y+ylen, xlen+2*b, b);
    fillRect(x-b, y, b, ylen);
    fillRect(x+xlen, y, b, ylen);
}

static inline
void fillBorderCoords(const Coord pos, const Length len, const int b)
{
    fillRect(pos.x-b,		pos.y-b,		len.x+2*b,	b);
    fillRect(pos.x-b,		pos.y+len.y,	len.x+2*b,	b);
    fillRect(pos.x-b,		pos.y,		b,		len.y);
    fillRect(pos.x+len.x,	pos.y,		b,		len.y);
}

static inline
void fillBorderCoordSquare(const Coord pos, const uint len, const int b)
{
    fillRect(pos.x-b,		pos.y-b,		len+2*b,	b);
    fillRect(pos.x-b,		pos.y+len,		len+2*b,	b);
    fillRect(pos.x-b,		pos.y,		b,		len);
    fillRect(pos.x+len,	pos.y,		b,		len);
}

static inline
void drawCircle(const uint x, const uint y, const uint radius)
{
    const double rsq = (double)(radius*radius);
    uint yoff = radius;
    for(uint xoff = 0; xoff <= yoff; xoff++){
    const double yc = sqrt(rsq - (xoff+1)*(xoff+1));
    const double ym = (double)yoff - 0.5;
    // 8 sections of circle
    drawPixel(x+xoff, y+yoff);		// 1
    drawPixel(x-yoff, y+xoff);		// 2
    drawPixel(x-xoff, y-yoff);		// 3
    drawPixel(x+yoff, y-xoff);		// 4

    drawPixel(x-xoff, y+yoff);		// 5
    drawPixel(x-yoff, y-xoff);		// 6
    drawPixel(x+xoff, y-yoff);		// 7
    drawPixel(x+yoff, y+xoff);		// 8
    yoff -= yc <= ym;
    }
}

static inline
void fillCircle(const uint x, const uint y, const uint radius)
{
    const double rsq = (double)(radius*radius);
    uint yoff = radius;
    for(uint xoff = 0; xoff <= yoff; xoff++){
    const double yc = sqrt(rsq - (xoff+1)*(xoff+1));
    const double ym = (double)yoff - 0.5;
    // connecting 8 sections of circle
    drawLine(x+xoff, y-yoff, x+xoff, y+yoff);		// 7 to 1
    drawLine(x-yoff, y+xoff, x+yoff, y+xoff);		// 2 to 8
    drawLine(x-xoff, y-yoff, x-xoff, y+yoff);		// 3 to 5
    drawLine(x-yoff, y-xoff, x+yoff, y-xoff);		// 6 to 4
    yoff -= yc <= ym;
    }
}

static inline
void drawCircleCoord(const Coord pos, const uint radius)
{
    const double rsq = (double)(radius*radius);
    uint yoff = radius;
    for(uint xoff = 0; xoff <= yoff; xoff++){
    const double yc = sqrt(rsq - (xoff+1)*(xoff+1));
    const double ym = (double)yoff - 0.5;
    // 8 sections of circle
    drawPixel(pos.x+xoff, pos.y+yoff);		// 1
    drawPixel(pos.x-yoff, pos.y+xoff);		// 2
    drawPixel(pos.x-xoff, pos.y-yoff);		// 3
    drawPixel(pos.x+yoff, pos.y-xoff);		// 4

    drawPixel(pos.x-xoff, pos.y+yoff);		// 5
    drawPixel(pos.x-yoff, pos.y-xoff);		// 6
    drawPixel(pos.x+xoff, pos.y-yoff);		// 7
    drawPixel(pos.x+yoff, pos.y+xoff);		// 8
    yoff -= yc <= ym;
    }
}

static inline
void fillCircleCoord(const Coord pos, const uint radius)
{
    const double rsq = (double)(radius*radius);
    uint yoff = radius;
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

static inline
Color getColor(void)
{
    Color c = {0};
    SDL_GetRenderDrawColor(gfx.renderer, &c.r, &c.g, &c.b, &c.a);
    return c;
}

static inline
void setColor(const Color c)
{
    SDL_SetRenderDrawColor(gfx.renderer, c.r, c.g, c.b, c.a);
}

static inline
u32 colorToU32(const Color c)
{
    return *((u32*)&c);
}

static inline
Color u32ToColor(const u32 u)
{
    return (const Color){u&0xff, (u>>8)&0xff, (u>>16)&0xff, 0xff};
}

static inline
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

static inline
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

static inline
void setRGB(const u8 r, const u8 g, const u8 b)
{
    SDL_SetRenderDrawColor(gfx.renderer, r, g, b, 255);
}

static inline
void setRGBA(const u8 r, const u8 g, const u8 b, const u8 a)
{
    SDL_SetRenderDrawColor(gfx.renderer, r, g, b, a);
}

static inline
void fillScreen(void)
{
    SDL_RenderClear(gfx.renderer);
}

static inline
void clear(void)
{
    const Color c = getColor();
    setColor(gfx.defaultColor);
    SDL_RenderClear(gfx.renderer);
    setColor(c);
}

void outlineWindow(void)
{
    const Color c = getColor();
    setColor(WHITE);
    fillBorderCoords(iC(0,0), getWindowLen(), -2);
    setColor(c);
}

static inline
void draw(void)
{

    if(gfx.outlined)
        outlineWindow();
    SDL_RenderPresent(gfx.renderer);
}

const Ticks frameStart(void)
{
	clear();
	return getTicks();
}

void events(const Ticks);
void frameEnd(const Ticks t)
{
	draw();
	events(t+TPF);
}

static inline
void gfx_quit(void)
{
    SDL_DestroyRenderer(gfx.renderer);
    SDL_DestroyWindow(gfx.window);
    SDL_Quit();
}

static inline
void gfx_init(void)
{
    if(SDL_Init(SDL_INIT_VIDEO)<0){
    printf("SDL borked! Error: %s\n", SDL_GetError());
    exit(0);
    }
    else{
    //Create window
    SDL_CreateWindowAndRenderer(DEFAULT_WINDOW_XLEN, DEFAULT_WINDOW_YLEN, SDL_WINDOW_RESIZABLE,
    &gfx.window, &gfx.renderer);
    printf("Adding gfx_quit to atexit()\n");
    atexit(gfx_quit);
    gfx.defaultColor = BLACK;
        gfx.outlined = true;
    SDL_SetRenderDrawBlendMode(gfx.renderer, BLEND_NONE);
    gfx.restoreLen.x = DEFAULT_WINDOW_XLEN;
    gfx.restoreLen.y = DEFAULT_WINDOW_YLEN;
    setWindowResizable(true);
    clear();
    draw();
    clear();
    }
}
