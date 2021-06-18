#pragma once

typedef enum{GFX_PIXEL, GFX_LINE, GFX_RECT, GFX_CIRCLE, GFX_POLY, GFX_TEXT}GfxType;

typedef struct Gfx{
	GfxType type;
	Color color;
	union{
		Coord pixel;
		Rect rect;
		Poly poly;
		struct{
			Coord start;
			Coord end;
		}line;
		struct{
			Coord pos;
			uint radius;
		}circle;
		struct{
			char *str;
			uint size;
		}text;
	};
	struct Gfx *next;
}Gfx;

typedef struct{
	Ticks startTime;
	Gfx *pipeline;
}Frame;

Frame frameStart()
{
	clear();
	return (Frame){.startTime = getTicks(), .pipeline = NULL};
}

void frameEnd(const Frame frame)
{

	draw();
	events(frame.startTime+TPF);
}
