#ifndef DOGELIB_TEXT_H
#define DOGELIB_TEXT_H

// renders text to image
Img* textImg(const char *text)
{
    return TTF_RenderText_Solid(gfx.font, text, gfx.fontColor);
}

// renders text to texture
Texture* textTexture(const char *text)
{
    return imgTexture(textImg(text));
}

// draws text at x y position
Length drawText(const char *text, const int x, const int y)
{
    Texture *t = textTexture(text);
    const Rect r = textureRect(t, iC(x,y));
    SDL_RenderCopy(gfx.renderer, t, NULL, &r);
    textureFree(t);
    return iC(r.w, r.h);
}

// draws text at pos
Length drawTextCoord(const char *text, const Coord pos)
{
    return drawText(text, pos.x, pos.y);
}

// draws text centered on pos x y
Length drawTextCentered(const char *text, const int x, const int y)
{
    Texture *t = textTexture(text);
    const Length len = drawTextureCentered(t, x, y);
    textureFree(t);
    return len;
}

// draws text centered on pos
Length drawTextCenteredCoord(const char *text, const Coord pos)
{
    return drawTextCentered(text, pos.x, pos.y);
}

// returns the length of text if it were to be rendered
Length textLength(const char *text)
{
    Length len = {0};
    TTF_SizeText(gfx.font, text, &len.x, &len.y);
    return len;
}

// returns the top left coord of text given its center pos
Coord textCenteredCoord(const Coord center, const char *text)
{
    return coordSub(center, coordDivi(textLength(text), 2));
}

// returns rect given pos and text
Rect textRect(const Coord pos, const char *text)
{
    return rectify(pos, textLength(text));
}

// returns rect with pos as top left coord of text given its center pos
Rect textCenteredRect(const Coord center, const char *text)
{
    const Length len = textLength(text);
    return rectify(coordSub(center, coordDivi(len, 2)), len);
}

// returns the x component of the length of the text if it were to be rendered
int getTextXLen(const char *text)
{
    Length len = {0};
    TTF_SizeText(gfx.font, text, &len.x, &len.y);
    return len.x;
}

// returns the y component of the length of the text if it were to be rendered
int getTextYLen(const char *text)
{
    Length len = {0};
    TTF_SizeText(gfx.font, text, &len.x, &len.y);
    return len.y;
}

// spaces coords evenly between start and stop
Coord* spanListCoords(Coord *coords, const Coord start, const Coord stop, const uint num)
{
    if(num == 0 || coords == NULL)
        return coords;
    const Length step = coordDivi(coordSub(stop, start), num>1?num-1:1);
    for(uint i = 0; i < num; i++)
        coords[i] = coordAdd(start, coordMuli(step, i));
    return coords;
}

// spaces coords evenly centered between start and stop
Coord* spanListCoordsCentered(Coord *coords, const Coord start, const Coord stop, const uint num)
{
    if(num == 0 || coords == NULL)
        return coords;
    const Length step = coordDivi(coordSub(stop, start), num+1);
    for(uint i = 1; i < num+1; i++)
        coords[i-1] = coordAdd(start, coordMuli(step, i));
    return coords;
}

// gets rectangles of multiple texts spaced evenly between start and stop
Rect* getTextListRect(const char **textList, Rect *const rect, const Coord start, const Coord stop, const uint num)
{
    if(num == 0 || rect == NULL)
        return rect;

    const Length step = coordDivi(coordSub(stop, start), num>1?num-1:1);
    for(uint i = 0; i < num; i++){
        const Length len = textLength(textList[i]);
        const Coord pos = coordSub(
            coordAdd(start, coordMuli(step, i)),
            coordDivi(len,2)
        );
        rect[i].x = pos.x;
        rect[i].y = pos.y;
        rect[i].w = len.x;
        rect[i].h = len.y;
    }
    return rect;
}

// gets rectangles of multiple texts spaced evenly centered between start and stop
Rect* getTextListRectCentered(const char **textList, Rect *const rect, const Coord start, const Coord stop, const uint num)
{
    if(num == 0 || rect == NULL)
        return rect;

    const Length step = coordDivi(coordSub(stop, start), num+1);
    for(uint i = 1; i < num+1; i++){
        const Length len = textLength(textList[i-1]);
        const Coord pos = coordSub(
            coordAdd(start, coordMuli(step, i)),
            coordDivi(len,2)
        );
        rect[i-1].x = pos.x;
        rect[i-1].y = pos.y;
        rect[i-1].w = len.x;
        rect[i-1].h = len.y;
    }
    return rect;
}

// returns the index of the first rectangle that coord is in otherwise returns -1
int coordInRectList(const Coord coord, Rect *const rect, const int num)
{
    if(num < 1)
        return -1;
    for(int i = 0; i < num; i++)
        if(coordInRect(coord, rect[i]))
            return i;
    return -1;
}

// returns the index of the first text rectangle that coord is in otherwise returns -1
int coordInTextList(const Coord coord, const Coord start, const Coord stop, const uint num, const char **textList)
{
    Rect r[num];
    return coordInRectArr(coord, getTextListRect(textList, r, start, stop, num), num);
}

// draws a collection of strings spaced evenly between 2 points
void spanTextList(const char **textList, const Coord start, const Coord stop, const uint num)
{
    if(num == 0)
        return;
    const Length step = coordDivi(coordSub(stop, start), num>1?num-1:1);
    for(uint i = 0; i < num; i++){
        drawTextCenteredCoord(textList[i], coordAdd(start, coordMuli(step, i)));
    }
}

// draws a collection of strings spaced evenly centered between 2 points
void spanTextListCentered(const char **textList, const Coord start, const Coord stop, const uint num)
{
    if(num == 0)
        return;
    const Length step = coordDivi(coordSub(stop, start), num+1);
    for(uint i = 1; i < num+1; i++){
        drawTextCenteredCoord(textList[i-1], coordAdd(start, coordMuli(step, i)));
    }
}

// sets the size of text to be rendered
void setTextSize(const uint size)
{
    if(size == gfx.fontSize)
        return;
    if(gfx.font != NULL)
        TTF_CloseFont(gfx.font);
    gfx.fontSize = size;
    gfx.font = TTF_OpenFont("DogeLib/FiraCode.ttf", gfx.fontSize);
}

// gets the current size of text to be rendered
int getTextSize(void)
{
    return gfx.fontSize;
}

// sets the color of text to be rendered
void setTextColor(const Color c)
{
    gfx.fontColor = c;
}

// gets the current color of text to be rendered
Color getTextColor(void)
{
    return gfx.fontColor;
}

// cleans up text stuff
void text_quit(void)
{
    if(gfx.font != NULL){
        TTF_CloseFont(gfx.font);
    }
    TTF_Quit();
}

// initializes text stuff
void text_init(void)
{
    if(TTF_Init()){
        printf("SDL_ttf borked! Error: %s\n", TTF_GetError());
        exit(0);

    }
    gfx.fontColor = WHITE;
    setTextSize(32);
    if(!gfx.font){
        printf("Unable to open font or set font size! Error: %s\n", TTF_GetError());
        exit(0);
    }
    printf("Adding text_quit to atexit()\n");
    atexit(text_quit);
}

#endif /* end of include guard: DOGELIB_TEXT_H */
