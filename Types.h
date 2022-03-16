#pragma once
typedef FILE			File;
typedef time_t			Time;
typedef unsigned int		Ticks;

typedef long int			lint;
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

// #define ABS(n)			((n)<0? -(n):(n))
// #define ZFLOOR(n)			((n)<0?    0:(n))

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

#define PI				M_PI

typedef enum{
	FULLSCREEN	=		SDL_WINDOW_FULLSCREEN,
	BORDERLESS	=		SDL_WINDOW_FULLSCREEN_DESKTOP,
	WINDOWED	=		0
}WindowMode;

typedef union{
	int arr[2];
	struct{
		int c1;
		int c2;
	};
	struct{
		int x;
		int y;
	};
	struct{
		int min;
		int max;
	};
	struct{
		int neg;
		int pos;
	};
}Coord, Range, Length, Offset, Ratio;

static inline
Coord iC(const int x, const int y)
{
	return (Coord){x,y};
}

typedef union{
	Coord arr[2];
	struct{
		Coord c1;
		Coord c2;
	};
	struct{
		Coord pos1;
		Coord pos2;
	};
	struct{
		Coord x;
		Coord y;
	};
	struct{
		Coord min;
		Coord max;
	};
	struct{
		Coord neg;
		Coord pos;
	};
}CoordPair, RangePair, LengthPair, OffsetPair;

CoordPair iCp(const int x1, const int y1, const int x2, const int y2)
{
	return (CoordPair){(Coord){x1, y1}, (Coord){x2, y2}};
}

CoordPair CCp(const Coord pos1, const Coord pos2)
{
	return (CoordPair){pos1, pos2};
}

typedef union{
	float arr[2];
	struct{
		float x;
		float y;
	};
}Coordf, Vectorf, Rangef, Lengthf, Offsetf;

typedef enum{
	DIR_U = 0b00,
	DIR_R = 0b01,
	DIR_D = 0b10,
	DIR_L = 0b11
}Direction;

const char DirectionChar[4] = {'U', 'R', 'D', 'L'};

int posSign(const int n)
{
    return n > 0 ? n : -n;
}

int negSign(const int n)
{
    return n < 0 ? n : -n;
}

float posSignf(const float n)
{
    return n > 0.0f ? n : -n;
}

float negSignf(const float n)
{
    return n < 0.0f ? n : -n;
}

int matchSign(const int s, const int n)
{
    return s > 0 ? posSign(n) : negSign(n);
}

float matchSignf(const float s, const float n)
{
    return s > 0.0 ? posSignf(n) : negSignf(n);
}

int invSign(const int s, const int n)
{
    return s < 0 ? posSign(n) : negSign(n);
}

float invSignf(const float s, const float n)
{
    return s < 0.0 ? posSignf(n) : negSignf(n);
}

int lbound(const int n, const int l)
{
	return n<l?l:n;
}

int ubound(const int n, const int u)
{
    return n>u?u:n;
}

float lboundf(const float n, const float l)
{
    return n<l?l:n;
}

float uboundf(const float n, const float u)
{
    return n>u?u:n;
}
