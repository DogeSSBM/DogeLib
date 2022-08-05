#pragma once

void img_quit(void)
{
    IMG_Quit();
}

void img_init(void)
{
    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initted = IMG_Init(flags);
    if((initted & flags) != flags) {
        printf("SDL_image borked! Error: %s\n", IMG_GetError());
        exit(0);
    }
    printf("Adding img_quit to atexit()\n");
    atexit(img_quit);
}

void freeImg(Img *image)
{
    if(image != NULL)
        SDL_FreeSurface(image);
}

Img* loadImg(const char *imgFile)
{
    Img *surface = IMG_Load(imgFile);
    if(surface == NULL){
        printf("Failed to load file %s! Error:%s\n",
            imgFile, IMG_GetError());
        exit(0);
    }
    return surface;
}

Texture* loadTexture(const char *imgFile)
{
    Img *img = IMG_Load(imgFile);
    Texture *t = SDL_CreateTextureFromSurface(gfx.renderer, img);
    SDL_FreeSurface(img);
    return t;
}

void drawImg(Img *image)
{
    Texture *t = SDL_CreateTextureFromSurface(gfx.renderer, image);
    SDL_RenderCopy(gfx.renderer, t, NULL, NULL);
    SDL_DestroyTexture(t);
}

void loadDrawImg(const char *imgFile)
{
    Img *img = IMG_Load(imgFile);
    if(img == NULL){
        printf("Failed to load file %s! Error:%s\n",
            imgFile, IMG_GetError());
        exit(0);
    }
    Texture *t = SDL_CreateTextureFromSurface(gfx.renderer, img);
    SDL_RenderCopy(gfx.renderer, t, NULL, NULL);
    SDL_DestroyTexture(t);
    SDL_FreeSurface(img);
}

Length textureLen(Texture *texture)
{
    Length len = {0};
    SDL_QueryTexture(texture, NULL, NULL, &len.x, &len.y);
    return len;
}

void drawTexture(Texture *texture, const int x, const int y)
{
    const Length len = textureLen(texture);
    SDL_RenderCopy(
        gfx.renderer,
        texture,
        &(const Rect){.w = len.x, .h = len.y},
        &(const Rect){.x = x, .y = y, .w = len.x, .h = len.y}
    );
}

void drawTextureCoord(Texture *texture, const Coord pos)
{
    drawTexture(texture, pos.x, pos.y);
}

void drawTextureCentered(Texture *texture, const int x, const int y)
{
    const Length len = textureLen(texture);
    SDL_RenderCopy(
        gfx.renderer,
        texture,
        &(const Rect){.w = len.x, .h = len.y},
        &(const Rect){.x = x - len.x/2, .y = y - len.y/2, .w = len.x, .h = len.y}
    );
}

void drawTextureCenteredCoord(Texture *texture, const Coord pos)
{
    drawTextureCentered(texture, pos.x, pos.y);
}

void drawTextureResize(Texture *texture, const int x, const int y, const int xlen, const int ylen)
{
    const Length len = textureLen(texture);
    SDL_RenderCopy(
        gfx.renderer,
        texture,
        &(const Rect){.w = len.x, .h = len.y},
        &(const Rect){.x = x, .y = y, .w = xlen, .h = ylen}
    );
}

void drawTextureCoordResize(Texture *texture, const Coord pos, const Length len)
{
    drawTextureResize(texture, pos.x, pos.y, len.x, len.y);
}

void drawTextureCenteredResize(Texture *texture, const int x, const int y, const int xlen, const int ylen)
{
    const Length len = textureLen(texture);
    SDL_RenderCopy(
        gfx.renderer,
        texture,
        &(const Rect){.w = len.x, .h = len.y},
        &(const Rect){.x = x - xlen/2, .y = y - ylen/2, .w = xlen, .h = ylen}
    );
}

void drawTextureCenteredCoordResize(Texture *texture, const Coord pos, const Length len)
{
    drawTextureCenteredResize(texture, pos.x, pos.y, len.x, len.y);
}
