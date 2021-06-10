#pragma once

void drawText(uint x, uint y, const char *text)
{
	Rect r;
	r.x = x; r.y = y;
	SDL_Surface *surface = TTF_RenderText_Solid(gfx.font, text, gfx.fontColor);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(gfx.renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &r.w, &r.h);
	SDL_RenderCopy(gfx.renderer, texture, NULL, &r);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

Coord drawTextCoord(const Coord pos, const char *text)
{
	Rect r;
	r.x = pos.x; r.y = pos.y;
	SDL_Surface *surface = TTF_RenderText_Solid(gfx.font, text, gfx.fontColor);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(gfx.renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &r.w, &r.h);
	SDL_RenderCopy(gfx.renderer, texture, NULL, &r);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	const Coord ret = {pos.x+r.w, pos.y};
	return ret;
}

void drawTextCentered(uint x, uint y, const char *text)
{
	Rect r;
	r.x = x; r.y = y;
	SDL_Surface *surface = TTF_RenderText_Solid(gfx.font, text, gfx.fontColor);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(gfx.renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &r.w, &r.h);
	r.x-=r.w/2;
	r.y-=r.h/2;
	SDL_RenderCopy(gfx.renderer, texture, NULL, &r);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

static inline
void drawTextCenteredCoord(const Coord pos, const char *text)
{
	drawTextCentered(pos.x, pos.y, text);
}

static inline
Length getTextLength(const char *text)
{
	Length len = {0};
	TTF_SizeText(gfx.font, text, &len.x, &len.y);
	return len;
}

// draws a collection of strings evenly spaced between 2 points
void spanTextList(const Coord start, const Coord stop, const uint num, const char **textList)
{
	if(num == 0)
		return;
	const Length step = coordDiv(coordSub(stop, start), num>1?num-1:1);
	for(uint i = 0; i < num; i++){
		drawTextCenteredCoord(coordOffset(start, coordMul(step, i)), textList[i]);
	}
}

void spanTextListCentered(const Coord start, const Coord stop, const uint num, const char **textList)
{
	if(num == 0)
		return;
	const Length step = coordDiv(coordSub(stop, start), num+1);
	for(uint i = 1; i < num+1; i++){
		drawTextCenteredCoord(coordOffset(start, coordMul(step, i)), textList[i-1]);
	}
}

typedef struct{
	char* text;
	Rect r;
	int size;
	Color textColor;
	Color backColor;
}TextBox;

void setFontSize(int size)
{
	if(size == gfx.fontSize)
		return;
	if(gfx.font != NULL)
		TTF_CloseFont(gfx.font);
	gfx.fontSize = size;
	gfx.font = TTF_OpenFont("./FiraCode-Medium.ttf", gfx.fontSize);
}

void setFontColor(Color c)
{
	gfx.fontColor = c;
}

void text_quit(void)
{
	if(gfx.font != NULL){
		TTF_CloseFont(gfx.font);
	}
	TTF_Quit();
}

void text_init(void)
{
	if(TTF_Init()){
		printf("SDL_ttf borked! Error: %s\n", TTF_GetError());
		exit(0);

	}
	gfx.fontColor = WHITE;
	setFontSize(32);
	if(!gfx.font){
		printf("Unable to open font or set font size! Error: %s\n", TTF_GetError());
		exit(0);
	}
	printf("Adding text_quit to atexit()\n");
	atexit(text_quit);
}
