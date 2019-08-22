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

void freeImg(Img *image)
{
	if(image != NULL)
		SDL_FreeSurface(image);
}

void drawImg(Img *image)
{
	SDL_Texture *t = SDL_CreateTextureFromSurface(gfx.renderer, image);
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
	SDL_Texture *t = SDL_CreateTextureFromSurface(gfx.renderer, img);
	SDL_RenderCopy(gfx.renderer, t, NULL, NULL);
	SDL_DestroyTexture(t);
	SDL_FreeSurface(img);
}
