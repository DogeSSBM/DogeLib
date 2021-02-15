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
	gfx.font = TTF_OpenFont("./LiberationMono.ttf", gfx.fontSize);
}

void setFontColor(Color c)
{
	gfx.fontColor = c;
}

void TB_setText(TextBox *tb, const char *text)
{
	size_t size = sizeof(char)*strlen(text)+1;
	tb->text = malloc(size);
	memset(tb->text, '\0', size);
	memcpy(tb->text, text, size);
}

void TB_setTextSize(TextBox *tb, int size)
{
	tb->size = size;
}

TextBox* TB_create(uint x, uint y, const char* text)
{
	TextBox *tb = malloc(sizeof(TextBox));
	TB_setText(tb, text);
	tb->r.x = x;
	tb->r.y = y;
	tb->backColor = BLACK;
	tb->textColor = GREY;
	tb->size = 48;
	return tb;
}

void TB_destroy(TextBox *tb)
{
	if(tb){
		if(tb->text){
			free(tb->text);
		}
		free(tb);
	}
}

void TB_draw(TextBox *tb)
{
	setFontSize(tb->size);
	SDL_Surface *surface = TTF_RenderText_Solid(
		gfx.font, tb->text, tb->textColor);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(
		gfx.renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &(tb->r.w), &(tb->r.h));
	setColor(tb->backColor);
	SDL_RenderFillRect(gfx.renderer, &(tb->r));
	SDL_RenderCopy(gfx.renderer, texture, NULL, &(tb->r));
	setColor(tb->textColor);
	// SDL_RenderDrawRect(gfx.renderer, &(tb->r));
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
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
