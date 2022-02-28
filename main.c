#include "Includes.h"
typedef struct{
    Color color;
    Coordf pos;
    Vectorf vec;
    uint size;
}Thing;

Thing bounceThing(Thing t, const Length window)
{
    const Vectorf prev = t.pos;
    t.pos = cfTranslate(t.pos, t.vec);
    if(t.pos.x < 0.0f || t.pos.x >= (float)window.x){
        t.vec.x = -t.vec.x;
    }
    if(t.pos.y < 0.0f || t.pos.y >= (float)window.y){
        t.vec.y = -t.vec.y;
    }
    t.pos = cfTranslate(t.vec, prev);
    return t;
}

bool boundsInWindow(const Coord pos, const uint size)
{
    for(uint i = 0; i < 4; i++){
        if(!coordInWindow(coordShift(pos, i, size)))
            return false;
    }
    return true;
}

void drawThing(const Thing t)
{
    if(!boundsInWindow(CfC(t.pos), t.size))
        setColor(RED);
    else
        setColor(mouseMoving()? PINK : t.color);
    fillCircleCoord(CfC(t.pos), t.size);
    fillBorderCoordSquare(
        coordAdd(CfC(t.pos),-t.size),
        t.size*2,
        t.size/4
    );
}

Coord dirKey(void)
{
    Coord r = {0};
    r.x += keyState(SDL_SCANCODE_D)||keyState(SDL_SCANCODE_RIGHT);
    r.x -= keyState(SDL_SCANCODE_A)||keyState(SDL_SCANCODE_LEFT);
    r.y += keyState(SDL_SCANCODE_S)||keyState(SDL_SCANCODE_DOWN);
    r.y -= keyState(SDL_SCANCODE_W)||keyState(SDL_SCANCODE_UP);
    return r;
}

Coordf friction(const Coordf c)
{
    const float rad = cfToRad(c);
    const float mag = cfMag(c);
    if(fabs(mag) <= 0.2f)
        return (const Coordf){0.0f, 0.0f};
    return radMagToCf(rad, mag-0.2f);
}

Coordf accel(const Coordf c)
{
    return cfMagBound(
        cfTranslate(
            cfMul(
                CCf(dirKey()),
                keyState(SDL_SCANCODE_LSHIFT)?1.0f:0.4f
            ),
            friction(c)
        ),
        keyState(SDL_SCANCODE_LSHIFT)?5.0f:4.0f
    );
}

Thing move(const Thing player)
{
    const Coordf nxt = cfTranslate(player.pos, player.vec);
    Thing ret = {
        .vec = accel(player.vec),
        .pos = coordInWindow(CfC(nxt)) ? nxt : player.pos,
        .color = MAGENTA,
        .size = 12
    };

    const Coord cpos = CfC(ret.pos);
    setColor(MAGENTA);
    fillCircleCoord(cpos, 12);
    setColor(CYAN);
    fillCircleCoord(cpos, 3);
    setColor(BLUE);
    drawLineCoords(cpos, CfC(cfTranslate(ret.pos, cfScaleMag(ret.vec, 6.0f))));

    return ret;
}

Thing varyThing(const Thing t)
{
    return (const Thing){
        .color = t.color,
        .pos = t.pos,
        .vec = degToCf(wrap(cfToDeg(t.vec)+randRange(-5.0f, 5.0f),0.0f,360.0f)),
        .size = clamp(t.size+rand()%3-1, 0, 20),
    };
}

Thing randomThing(const Length window)
{
    return (const Thing){
        .color = WHITE,
        .pos.x = randRange(0.0f, (float)window.x),
        .pos.y = randRange(0.0f, (float)window.y),
        .vec = degToCf(randRange(0.0f, 360.0f)),
        .size = 5+rand()%15,
    };
}

void textDemo(const Length window)
{
    static Coord p[2] = {0};
    static Color c[2] = {WHITE, WHITE};
    static uint i = 0;
    if(mouseBtnPressed(MOUSE_L)){
        i = coordDistSq(mouse.pos, p[0]) > coordDistSq(mouse.pos, p[1]);
        c[0] = randColor();
        c[1] = (Color){255-c[0].r, 255-c[0].g, 255-c[0].b, 255};
    }
    if(mouseBtnState(MOUSE_L)){
        p[i] = coordClampLen(coordOffset(p[i], mouse.vec), window);
        fillCircleCoord(p[i], 5);
    }else{
        c[0] = WHITE;
        c[1] = WHITE;
    }

    const char* texts[] = {"This", "Is", "A", "Test"};
    setTextColor(c[0]);
    spanTextList(p[0], p[1], 4, texts);
    setTextColor(c[1]);
    spanTextListCentered(p[0], p[1], 4, texts);

    Rect c0[4] = {0};
    getTextListRect(c0, p[0], p[1], 4, texts);
    Rect c1[4] = {0};
    getTextListRectCentered(c1, p[0], p[1], 4, texts);

    const int r0 = coordInRectList(mouse.pos, c0, 4);
    const int r1 = coordInRectList(mouse.pos, c1, 4);
    for(int i = 0; i < 4; i++){
        setColor(i == r0 ? WHITE : YELLOW);
        drawRectRect(c0[i]);
        setColor(i == r1 ? WHITE : MAGENTA);
        drawRectRect(c1[i]);
    }
}

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    init(800, 600);

    Thing t[6] = {0};
    for(uint i = 0; i < 6; i++)
        t[i] = randomThing(getWindowLen());

    t[0].color = CYAN;
    t[1].color = RED;
    t[2].color = YELLOW;
    t[3].color = GREEN;
    t[4].color = BLUE;
    t[5].color = MAGENTA;

    Thing player = {
        .pos = CCf(getWindowMid()),
        .vec = {0.0f, 0.0f},
        .color = MAGENTA,
        .size = 12
    };

    while(1){
        const Ticks time = frameStart();

        player = move(player);

        for(uint i = 0; i < 6; i++){
            t[i] = bounceThing(t[i], getWindowLen());
            t[i] = varyThing(t[i]);
            drawThing(t[i]);
        }
        textDemo(getWindowLen());
        if(keyState(SDL_SCANCODE_ESCAPE))
            exit(0);

        frameEnd(time);
    }
    return 0;
}
