#ifndef DOGELIB_INPUTTEXT_H
#define DOGELIB_INPUTTEXT_H

#define ITBUFLEN    32

typedef struct InText{
    Coord pos;
    uint fontSize;
    Color fontColor;
    int selectionLen;
    st textSize;    // size of space allocated for text
    st textLen;     // string length of text
    char *text;
    Texture *texture;
    uint bufPos;
    char buf[ITBUFLEN];
}InText;

struct{
    bool prv;
    boolFunc endInput;
    InText *it;
}itxt;

InText inTextNew(const Coord pos, const uint fontSize, const Color fontColor)
{
    return (const InText){
        .pos = pos,
        .fontSize = fontSize,
        .fontColor = fontColor,
        .textSize = ITBUFLEN,
        .text = calloc(ITBUFLEN, sizeof(char)),
    };
}

void inTextFree(InText it)
{
    free(it.text);
}

void inTextReset(void)
{
    assertExpr(itxt.it);
    if(itxt.it->texture)
        textureFree(itxt.it->texture);
    assertExpr(itxt.it->text);
    free(itxt.it->text);
    *itxt.it = inTextNew(itxt.it->pos, itxt.it->fontSize, itxt.it->fontColor);
}

bool inTextIsEnabled(void)
{
    return SDL_IsTextInputActive();
}

void inTextStart(InText *it, boolFunc endInput)
{
    assertExpr(!itxt.it);
    itxt.it = it;
    itxt.endInput = endInput;
    SDL_StartTextInput();
}

void inTextStop(void)
{
    SDL_StopTextInput();
}

void inTextUpdateTexture(void)
{
    if(!itxt.it->text)
        return;
    const uint fontSize = itxt.it->fontSize;
    const Color fontColor = itxt.it->fontColor;
    setTextSize(itxt.it->fontSize);
    setTextColor(itxt.it->fontColor);
    if(itxt.it->texture)
        itxt.it->texture = textureFree(itxt.it->texture);
    itxt.it->texture = textTexture(itxt.it->text);
    if(fontSize != itxt.it->fontSize)
        setTextSize(fontSize);
    if(!colorSame(fontColor, itxt.it->fontColor))
        setTextColor(fontColor);
}

void inTextCommitBuf(void)
{
    assertExpr(itxt.it);
    if(itxt.it->bufPos == 0)
        return;
    printf("buf: %s\n", itxt.it->buf);
    const uint newLen = itxt.it->textLen + itxt.it->bufPos;
    if(itxt.it->textSize <= newLen){
        const uint newSize = itxt.it->textSize + itxt.it->textSize / 2;
        itxt.it->text = recalloc(itxt.it->text, itxt.it->textSize, newSize);
        itxt.it->textSize = newSize;
    }
    memcpy(itxt.it->text+itxt.it->textLen, itxt.it->buf, itxt.it->bufPos);
    itxt.it->textLen += itxt.it->bufPos;
    inTextUpdateTexture();
}

void inTextDraw(const InText it)
{
    if(!it.texture)
        return;
    drawTextureCoord(it.texture, it.pos);
}

#endif /* end of include guard: DOGELIB_INPUTTEXT_H */
