#pragma once
typedef FILE			File;
typedef unsigned int		Ticks;

typedef unsigned char		uchar;
typedef unsigned int		uint;
typedef unsigned long		ul;
typedef unsigned long long	ull;

typedef uint8_t			u8;
typedef uint16_t			u16;
typedef uint32_t			u32;
typedef uint64_t			u64;

typedef int8_t			i8;
typedef int16_t			i16;
typedef int32_t			i32;
typedef int64_t			i64;

#define I8MIN			INT8_MIN
#define I8MAX			INT8_MAX
#define I16MIN			INT16_MIN
#define I16MAX			INT16_MAX
#define I32MIN			INT32_MIN
#define I32MAX			INT32_MAX
#define I64MIN			INT64_MIN
#define I64MAX			INT64_MAX

#define U8MAX			UINT8_MAX
#define U16MAX			UINT16_MAX
#define U32MAX			UINT32_MAX
#define U64MAX			UINT64_MAX

// evaluates to the absolute value of n
#define ABS(n)			((n)<0? -(n):(n))

// evaluates to n with a low bound of 0
#define ZFLOOR(n)			((n)<0?    0:(n))

typedef SDL_Event			Event;
typedef SDL_Rect 			Rect;
typedef SDL_Color 		Color;
typedef SDL_Surface 		Img;
typedef SDL_Keycode 		Key;
typedef SDL_BlendMode		BlendMode;
#define BLEND_NONE		SDL_BLENDMODE_NONE
#define BLEND_ALPHA		SDL_BLENDMODE_BLEND
#define BLEND_ADD			SDL_BLENDMODE_ADD
#define BLEND_MOD			SDL_BLENDMODE_MOD

typedef enum{
	FULLSCREEN	=		SDL_WINDOW_FULLSCREEN,
	BORDERLESS	=		SDL_WINDOW_FULLSCREEN_DESKTOP,
	WINDOWED	=		0
}WindowMode;

typedef union{
	int arr[2];
	struct{
		int x;
		int y;
	};
}Coord, Length;

bool sameCoord(const Coord pos1, const Coord pos2)
{
	return pos1.x == pos2.x && pos1.y == pos2.y;
}

void printCoord(const Coord pos)
{
	printf("(%2d,%2d)", pos.x, pos.y);
}

typedef enum{
	DIR_U = 0b00,
	DIR_R = 0b01,
	DIR_D = 0b10,
	DIR_L = 0b11
}Direction;

// evaluates to d rotated 90 degrees right (clockwise)
#define dirROR(d)			(((d)+1)&0b11)

// evaluates to d rotated 90 degrees left (counter-clockwise)
#define dirROL(d)			(((d)-1)&0b11)

// evaluates to the inverse of d (left<->right or up<->down)
#define dirINV(d)			((d)^0b10)

// evaluates true if d is left/right (horizontal)
#define dirIsLR(d)		((d)&1)

// evaluates true if d is up/down (vertical)
#define dirIsUD(d)		(!((d)&1))

// evaluates true if d is a positive direction (right/down)
#define dirIsPOS(d)		((d)==DIR_R||(d)==DIR_D)

// evaluates true if d is a negative direction (left/up)
#define dirIsNEG(d)		((d)==DIR_L||(d)==DIR_U)

// returns clamped the value of n between min (inclusive) and max (exclusive)
int clamp(const int n, const int min, const int max)
{
	if(n < min)
		return min;
	if(n >= max)
		return max-1;
	return n;
}

// true if n is between min (inclusive) and max (exclusive)
bool inBound(const int n, const int min, const int max)
{
	return n >= min && n < max;
}

// returns coord shifted n units in the direction of dir
Coord coordShift(const Coord coord, const Direction dir, const int n)
{
	Coord ret = coord;
	if(dirIsUD(dir)){
		ret.y += dirIsPOS(dir)? n : -n;
	}else{
		ret.x += dirIsPOS(dir)? n : -n;
	}
	return ret;
}
