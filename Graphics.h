#pragma once

struct{
	uint xlen, ylen;
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;
	int fontSize;
	Color fontColor;
	Color defaultColor;
}gfx = {};

typedef enum{
	BLEND_NONE	= SDL_BLENDMODE_NONE,
	BLEND_ALPHA	= SDL_BLENDMODE_BLEND,
	BLEND_ADD	= SDL_BLENDMODE_ADD,
	BLEND_MOD	= SDL_BLENDMODE_MOD
}BlendMode;

void setBlend(BlendMode mode)
{
	SDL_SetRenderDrawBlendMode(gfx.renderer, mode);
}

void drawPixel(uint x, uint y)
{
	SDL_RenderDrawPoint(gfx.renderer, x, y);
}

void drawLine(uint x1, uint y1, uint x2, uint y2)
{
	SDL_RenderDrawLine(gfx.renderer, x1, y1, x2, y2);
}

void drawHLine(uint x, uint y, int len)
{
	SDL_RenderDrawLine(gfx.renderer, x, y, x+len, y);
}

void drawVLine(uint x, uint y, int len)
{
	SDL_RenderDrawLine(gfx.renderer, x, y, x, y+len);
}

void drawRect(uint x, uint y, uint xlen, uint ylen)
{
	Rect r = {x, y, xlen, ylen};
	SDL_RenderDrawRect(gfx.renderer, &r);
}

void fillRect(uint x, uint y, uint xlen, uint ylen)
{
	Rect r = {x, y, xlen, ylen};
	SDL_RenderFillRect(gfx.renderer, &r);
}

void drawSquare(uint x, uint y, uint len)
{
	Rect r = {x, y, len, len};
	SDL_RenderDrawRect(gfx.renderer, &r);
}

void fillSquare(uint x, uint y, uint len)
{
	Rect r = {x, y, len, len};
	SDL_RenderFillRect(gfx.renderer, &r);
}

void fillBorder(uint x, uint y, uint xlen, uint ylen, int b)
{
	fillRect(x-b, y-b, xlen+2*b, b);
	fillRect(x-b, y+ylen, xlen+2*b, b);
	fillRect(x-b, y, b, ylen);
	fillRect(x+xlen, y, b, ylen);
}

void drawCircle(uint x, uint y, uint radius)
{
	uint rsq = radius*radius;
	uint yoff = radius;
	for(uint xoff = 0; xoff <= yoff; xoff++){
		double yc = sqrt(rsq - (xoff+1)*(xoff+1));
		double ym = (double)yoff - 0.5;
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

void fillCircle(uint x, uint y, uint radius)
{
	uint rsq = radius*radius;
	uint yoff = radius;
	for(uint xoff = 0; xoff <= yoff; xoff++){
		double yc = sqrt(rsq - (xoff+1)*(xoff+1));
		double ym = (double)yoff - 0.5;
		// connecting 8 sections of circle
		drawLine(x+xoff, y-yoff, x+xoff, y+yoff);		// 7 to 1
		drawLine(x-yoff, y+xoff, x+yoff, y+xoff);		// 2 to 8
		drawLine(x-xoff, y-yoff, x-xoff, y+yoff);		// 3 to 5
		drawLine(x-yoff, y-xoff, x+yoff, y-xoff);		// 6 to 4
		yoff -= yc <= ym;
	}
}

void setColor(Color c)
{
	SDL_SetRenderDrawColor(gfx.renderer, c.r, c.g, c.b, c.a);
}

void setRGB(u8 r, u8 g, u8 b)
{
	SDL_SetRenderDrawColor(gfx.renderer, r, g, b, 255);
}

void setRGBA(u8 r, u8 g, u8 b, u8 a)
{
	SDL_SetRenderDrawColor(gfx.renderer, r, g, b, a);
}

void fillScreen()
{
	fillRect(0,0,gfx.xlen,gfx.ylen);
}

void clear()
{
	setColor(gfx.defaultColor);
	SDL_RenderClear(gfx.renderer);
	fillRect(0,0,gfx.xlen,gfx.ylen);
}

void draw()
{
	SDL_RenderPresent(gfx.renderer);
}

void saveScreenshot(const char* file_name)
{
	SDL_Surface *sshot = SDL_CreateRGBSurface(0, gfx.xlen, gfx.ylen, 32,
		0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(gfx.renderer, NULL, SDL_PIXELFORMAT_ARGB8888,
		sshot->pixels, sshot->pitch);
	SDL_SaveBMP(sshot, file_name);
	//SDL_FreeSurface(sshot);
}

void gfx_quit(void)
{
	// Destroy renderer
	SDL_DestroyRenderer(gfx.renderer);
	// Destroy window
	SDL_DestroyWindow(gfx.window);
	// Quit SDL subsystems
	SDL_Quit();
}

void gfx_init(uint winXlen, uint winYlen)
{
	srand(time(NULL));
	if(SDL_Init(SDL_INIT_VIDEO)<0){
		printf("SDL borked! Error: %s\n", SDL_GetError());
		exit(0);
	}
	else{
		//Create window
		SDL_CreateWindowAndRenderer(winXlen, winYlen, 0,
			&(gfx.window), &(gfx.renderer));
		printf("Adding gfx_quit to atexit()\n");
		atexit(gfx_quit);
		gfx.xlen = winXlen;
		gfx.ylen = winYlen;
		gfx.defaultColor = BLACK;
		SDL_SetRenderDrawBlendMode(gfx.renderer, SDL_BLENDMODE_BLEND);
		clear();
		draw();
		clear();
	}
}
