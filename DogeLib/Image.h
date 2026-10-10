#ifndef DOGELIB_IMAGE_H
#define DOGELIB_IMAGE_H

// cleans up img stuff
void img_quit(void)
{
    IMG_Quit();
}

// initializes img stuff
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

// frees a Img
void freeImg(Img *image)
{
    if(image)
        SDL_FreeSurface(image);
}

// frees a Texture
Texture* textureFree(Texture *t)
{
    if(t)
        SDL_DestroyTexture(t);
    return NULL;
}

// loads an Img from a file
Img* loadImg(const char *file)
{
    Img *surface = IMG_Load(file);
    if(surface == NULL){
        printf("Failed to load file %s! Error:%s\n",
            file, IMG_GetError());
        exit(0);
    }
    return surface;
}

// creates a Texture from an Img
Texture* imgTexture(Img *img)
{
    Texture *t = SDL_CreateTextureFromSurface(gfx.renderer, img);
    freeImg(img);
    return t;
}

// loads a Texture from a file
Texture* loadTexture(const char *file)
{
    Img *img = IMG_Load(file);
    Texture *t = SDL_CreateTextureFromSurface(gfx.renderer, img);
    SDL_FreeSurface(img);
    return t;
}

// draws an Img
void drawImg(Img *image)
{
    Texture *t = SDL_CreateTextureFromSurface(gfx.renderer, image);
    SDL_RenderCopy(gfx.renderer, t, NULL, NULL);
    SDL_DestroyTexture(t);
}

// loads an Img from a file and draws it immidiately
void loadDrawImg(const char *file)
{
    Img *img = IMG_Load(file);
    if(img == NULL){
        printf("Failed to load file %s! Error:%s\n",
            file, IMG_GetError());
        exit(0);
    }
    Texture *t = SDL_CreateTextureFromSurface(gfx.renderer, img);
    SDL_RenderCopy(gfx.renderer, t, NULL, NULL);
    SDL_DestroyTexture(t);
    SDL_FreeSurface(img);
}

// gets the Length of Texture
Length textureLen(Texture *texture)
{
    Length len = {0};
    SDL_QueryTexture(texture, NULL, NULL, &len.x, &len.y);
    return len;
}

// returns a bounding Rect of the texture at pos
Rect textureRect(Texture *texture, const Coord pos)
{
    return rectify(pos, textureLen(texture));
}

// draws a texture at x y
Length drawTexture(Texture *texture, const int x, const int y)
{
    const Length len = textureLen(texture);
    SDL_RenderCopy(
        gfx.renderer,
        texture,
        &(const Rect){.w = len.x, .h = len.y},
        &(const Rect){.x = x, .y = y, .w = len.x, .h = len.y}
    );
    return len;
}

// draws a texture at pos
Length drawTextureCoord(Texture *texture, const Coord pos)
{
    return drawTexture(texture, pos.x, pos.y);
}

// draws a texture centered at x y
Length drawTextureCentered(Texture *texture, const int x, const int y)
{
    const Length len = textureLen(texture);
    SDL_RenderCopy(
        gfx.renderer,
        texture,
        &(const Rect){.w = len.x, .h = len.y},
        &(const Rect){.x = x - len.x/2, .y = y - len.y/2, .w = len.x, .h = len.y}
    );
    return len;
}

// draws a texture centered at pos
Length drawTextureCenteredCoord(Texture *texture, const Coord pos)
{
    return drawTextureCentered(texture, pos.x, pos.y);
}

// resizes a texture to xlen ylen and draws it at x y
Length drawTextureResize(Texture *texture, const int x, const int y, const int xlen, const int ylen)
{
    const Length len = textureLen(texture);
    SDL_RenderCopy(
        gfx.renderer,
        texture,
        &(const Rect){.w = len.x, .h = len.y},
        &(const Rect){.x = x, .y = y, .w = xlen, .h = ylen}
    );
    return len;
}

// resizes a texture to len and draws it at pos
Length drawTextureCoordResize(Texture *texture, const Coord pos, const Length len)
{
    return drawTextureResize(texture, pos.x, pos.y, len.x, len.y);
}

// resizes a texture to xlen ylen and draws it centered at x y
Length drawTextureCenteredResize(Texture *texture, const int x, const int y, const int xlen, const int ylen)
{
    const Length len = textureLen(texture);
    SDL_RenderCopy(
        gfx.renderer,
        texture,
        &(const Rect){.w = len.x, .h = len.y},
        &(const Rect){.x = x - xlen/2, .y = y - ylen/2, .w = xlen, .h = ylen}
    );
    return len;
}

// resizes a texture to len and draws it centered at pos
Length drawTextureCenteredCoordResize(Texture *texture, const Coord pos, const Length len)
{
    return drawTextureCenteredResize(texture, pos.x, pos.y, len.x, len.y);
}

#endif /* end of include guard: DOGELIB_IMAGE_H */
