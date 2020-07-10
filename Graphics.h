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

static inline
void setWindowMode(const WindowMode mode)
{
	SDL_SetWindowFullscreen(gfx.window, mode);
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
void drawLine(uint x1, uint y1, uint x2, uint y2)
{
	SDL_RenderDrawLine(gfx.renderer, x1, y1, x2, y2);
}

static inline
void drawLineCoords(const Coord pos1, const Coord pos2)
{
	SDL_RenderDrawLine(gfx.renderer, pos1.x, pos1.y, pos2.x, pos2.y);
}

static inline
void drawHLine(uint x, uint y, int len)
{
	SDL_RenderDrawLine(gfx.renderer, x, y, x+len, y);
}

static inline
void drawVLine(uint x, uint y, int len)
{
	SDL_RenderDrawLine(gfx.renderer, x, y, x, y+len);
}

static inline
void drawRect(uint x, uint y, uint xlen, uint ylen)
{
	Rect r = {x, y, xlen, ylen};
	SDL_RenderDrawRect(gfx.renderer, &r);
}

static inline
void fillRect(uint x, uint y, uint xlen, uint ylen)
{
	Rect r = {x, y, xlen, ylen};
	SDL_RenderFillRect(gfx.renderer, &r);
}

static inline
void drawRectCoords(const Coord pos1, const Coord pos2)
{
	Rect r = {
		pos1.x < pos2.x? pos1.x: pos2.x,
		pos1.y < pos2.y? pos1.y: pos2.y,
		ABS(pos1.x-pos2.x),
		ABS(pos1.y-pos2.y)
	};
	SDL_RenderDrawRect(gfx.renderer, &r);
}

static inline
void fillRectCoords(const Coord pos1, const Coord pos2)
{
	Rect r = {
		pos1.x < pos2.x? pos1.x: pos2.x,
		pos1.y < pos2.y? pos1.y: pos2.y,
		ABS(pos1.x-pos2.x),
		ABS(pos1.y-pos2.y)
	};
	SDL_RenderFillRect(gfx.renderer, &r);
}

static inline
void drawSquare(uint x, uint y, uint len)
{
	Rect r = {x, y, len, len};
	SDL_RenderDrawRect(gfx.renderer, &r);
}

static inline
void fillSquare(uint x, uint y, uint len)
{
	Rect r = {x, y, len, len};
	SDL_RenderFillRect(gfx.renderer, &r);
}

static inline
void fillSquareCoord(const Coord pos, const uint len)
{
	Rect r = {pos.x, pos.y, len, len};
	SDL_RenderFillRect(gfx.renderer, &r);
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

static inline
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

static inline
void fillHCircle(const uint x, const uint y,
const uint radius, const Direction dir)
{
	uint rsq = radius*radius;
	uint yoff = radius;
	for(uint xoff = 0; xoff <= yoff; xoff++){
		double yc = sqrt(rsq - (xoff+1)*(xoff+1));
		double ym = (double)yoff - 0.5;
		// connecting 8 sections of circle
		if(dir == DIR_R){
			// 7 to 1
			drawLine(x+xoff, y-yoff, x+xoff, y+yoff);
			// 2 to 6
			drawLine(x-yoff, y+xoff, x-yoff, y-xoff);
		}
		if(dir == DIR_D){
			// 2 to 8
			drawLine(x-yoff, y+xoff, x+yoff, y+xoff);
			// 3 to 7
			drawLine(x-xoff, y-yoff, x+xoff, y-yoff);
		}
		if(dir == DIR_L){
			// 3 to 5
			drawLine(x-xoff, y-yoff, x-xoff, y+yoff);
			// 4 to 8
			drawLine(x+yoff, y-xoff, x+yoff, y+xoff);
		}
		if(dir == DIR_U){
			// 6 to 4
			drawLine(x-yoff, y-xoff, x+yoff, y-xoff);
			// 5 to 1
			drawLine(x-xoff, y+yoff, x+xoff, y+yoff);
		}

		yoff -= yc <= ym;
	}
}

static inline
void drawCircleCoord(const Coord pos, const uint radius)
{
	uint rsq = radius*radius;
	uint yoff = radius;
	for(uint xoff = 0; xoff <= yoff; xoff++){
		double yc = sqrt(rsq - (xoff+1)*(xoff+1));
		double ym = (double)yoff - 0.5;
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
	uint rsq = radius*radius;
	uint yoff = radius;
	for(uint xoff = 0; xoff <= yoff; xoff++){
		double yc = sqrt(rsq - (xoff+1)*(xoff+1));
		double ym = (double)yoff - 0.5;
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
void setRGB(u8 r, u8 g, u8 b)
{
	SDL_SetRenderDrawColor(gfx.renderer, r, g, b, 255);
}

static inline
void setRGBA(u8 r, u8 g, u8 b, u8 a)
{
	SDL_SetRenderDrawColor(gfx.renderer, r, g, b, a);
}

static inline
void fillScreen()
{
	fillRect(0,0,gfx.xlen,gfx.ylen);
}

static inline
void clear()
{
	Color c = getColor();
	setColor(gfx.defaultColor);
	SDL_RenderClear(gfx.renderer);
	fillRect(0,0,gfx.xlen,gfx.ylen);
	setColor(c);
}

static inline
void draw()
{
	SDL_RenderPresent(gfx.renderer);
}

static inline
void saveScreenshot(const char* file_name)
{
	SDL_Surface *sshot = SDL_CreateRGBSurface(0, gfx.xlen, gfx.ylen, 32,
		0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(gfx.renderer, NULL, SDL_PIXELFORMAT_ARGB8888,
		sshot->pixels, sshot->pitch);
	SDL_SaveBMP(sshot, file_name);
	//SDL_FreeSurface(sshot);
}

static inline
void gfx_quit(void)
{
	// Destroy renderer
	SDL_DestroyRenderer(gfx.renderer);
	// Destroy window
	SDL_DestroyWindow(gfx.window);
	// Quit SDL subsystems
	SDL_Quit();
}

static inline
void gfx_init(uint winXlen, uint winYlen)
{
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
		SDL_SetRenderDrawBlendMode(gfx.renderer, BLEND_NONE);
		clear();
		draw();
		clear();
	}
}
