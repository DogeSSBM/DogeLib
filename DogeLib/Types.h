#ifndef DOGELIB_TYPES_H
#define DOGELIB_TYPES_H

typedef FILE                File;
typedef time_t              Time;
typedef size_t              st;
typedef ptrdiff_t           dt;

typedef long int            lint;
typedef unsigned char       uchar;
typedef unsigned int        uint;
typedef unsigned long       ul;
typedef unsigned long long  ull;

typedef uint8_t             u8;
typedef uint16_t            u16;
typedef uint32_t            u32;
typedef uint64_t            u64;

typedef int8_t              i8;
typedef int16_t             i16;
typedef int32_t             i32;
typedef int64_t             i64;

#define I8MIN               INT8_MIN
#define I8MAX               INT8_MAX
#define I16MIN              INT16_MIN
#define I16MAX              INT16_MAX
#define I32MIN              INT32_MIN
#define I32MAX              INT32_MAX
#define I64MIN              INT64_MIN
#define I64MAX              INT64_MAX

#define U8MAX               UINT8_MAX
#define U16MAX              UINT16_MAX
#define U32MAX              UINT32_MAX
#define U64MAX              UINT64_MAX

typedef bool (*boolFunc)(void);

typedef SDL_Event           Event;
typedef SDL_Rect            Rect;
typedef SDL_Color           Color;
typedef SDL_Surface         Img;
typedef SDL_Keycode         Key;
typedef SDL_BlendMode       BlendMode;
typedef SDL_Texture         Texture;
typedef SDL_Scancode        Scancode;
typedef SDL_Window          Window;
#define BLEND_NONE          SDL_BLENDMODE_NONE
#define BLEND_ALPHA         SDL_BLENDMODE_BLEND
#define BLEND_ADD           SDL_BLENDMODE_ADD
#define BLEND_MOD           SDL_BLENDMODE_MOD

#define MOUSE_L             (SDL_BUTTON(SDL_BUTTON_LEFT))
#define MOUSE_M             (SDL_BUTTON(SDL_BUTTON_MIDDLE))
#define MOUSE_R             (SDL_BUTTON(SDL_BUTTON_RIGHT))
#define MOUSE_F             (SDL_BUTTON(SDL_BUTTON_X1))
#define MOUSE_B             (SDL_BUTTON(SDL_BUTTON_X2))

#define MW_D                1u
#define MW_R                (1u<<1)
#define MW_U                (1u<<2)
#define MW_L                (1u<<3)

#define PI                  ((float)M_PI)

typedef enum{
    FULLSCREEN = SDL_WINDOW_FULLSCREEN,
    BORDERLESS = SDL_WINDOW_FULLSCREEN_DESKTOP,
    WINDOWED = 0
}WindowMode;

typedef enum{I_PRESSED, I_RELEASED, I_HELD, I_NOOP}InputType;

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

typedef struct{
    Color color;
    uint numVertex;
    Coord *vertex;
}Poly;

// returns a Coord with positions x and y
Coord iC(const int x, const int y)
{
    return (const Coord){.x = x, .y = y};
}

// returns a Coord with x and y both equal to i
Coord iiC(const int i)
{
    return (const Coord){.x = i, .y = i};
}

// returns a rect at position x, y and length xlen, ylen
Rect iR(const int x, const int y, const int xlen, const int ylen)
{
    return (const Rect){.x = x, .y = y, .w = xlen, .h = ylen};
}

// returns the corner position of rect
Coord irC(const Rect rect)
{
    return iC(rect.x, rect.y);
}

// returns the length of rect
Length irL(const Rect rect)
{
    return iC(rect.w, rect.h);
}

// returns a rect at position pos and length len
Rect ccR(const Coord pos, const Length len)
{
    return (const Rect){.x = pos.x, .y = pos.y, .w = len.x, .h = len.y};
}

// returns a rect at position pos and length xlen, ylen
Rect ciR(const Coord pos, const int xlen, const int ylen)
{
    return (const Rect){.x = pos.x, .y = pos.y, .w = xlen, .h = ylen};
}

// returns a square rect at position pos and length len
Rect ciiS(const Coord pos, const int len)
{
    return (const Rect){.x = pos.x, .y = pos.y, .w = len, .h = len};
}

// returns a square rect at position x, y and length len
Rect iiS(const int x, const int y, const int len)
{
    return (const Rect){.x = x, .y = y, .w = len, .h = len};
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

typedef union{
    float arr[2];
    struct{
        float x;
        float y;
    };
}Coordf, Vectorf, Rangef, Lengthf, Offsetf;

// returns a float Coord with positions x and y
Coordf fC(const float x, const float y)
{
    return (const Coordf){.x=x, .y=y};
}

// returns a Coord with x and y both equal to i
Coordf ffC(const float i)
{
    return (const Coordf){.x = i, .y = i};
}

typedef enum{DIR_U = 0, DIR_R, DIR_D, DIR_L}Direction;

const char DirectionChar[4] = {'U', 'R', 'D', 'L'};

// returns the max of the ints
int imax(const int a, const int b)
{
    return a > b ? a : b;
}

// returns the min of the ints
int imin(const int a, const int b)
{
    return a < b ? a : b;
}

// returns the absolute value of i
int iabs(const int i)
{
    return i > 0 ? i : -i;
}

// exponentiation function for integers
int ipow(int num, int pow)
{
    if(pow == 0)
        return 1;
    while(--pow)
        num *= num;
    return num;
}

// returns the max of the floats
float fmost(const float a, const float b)
{
    return a > b ? a : b;
}

// returns the min of the floats
float fleast(const float a, const float b)
{
    return a < b ? a : b;
}

// makes n positive
int posSign(const int n)
{
    return n > 0 ? n : -n;
}

// makes n negative
int negSign(const int n)
{
    return n < 0 ? n : -n;
}

// makes n positive
float posSignf(const float n)
{
    return n > 0.0f ? n : -n;
}

// makes n negative
float negSignf(const float n)
{
    return n < 0.0f ? n : -n;
}

// matches the sign of n to s
int matchSign(const int s, const int n)
{
    return s > 0 ? posSign(n) : negSign(n);
}

// returns true if s and n have the same sign
bool sameSign(const int s, const int n)
{
    return (s < 0 && n < 0) || (s >= 0 && n >= 0);
}

// matches the sign of n to s
float matchSignf(const float s, const float n)
{
    return s > 0.0 ? posSignf(n) : negSignf(n);
}

// matches the sign of n to the inverse sign of s
int invSign(const int s, const int n)
{
    return s < 0 ? posSign(n) : negSign(n);
}

// matches the sign of n to the inverse sign of s
float invSignf(const float s, const float n)
{
    return s < 0.0 ? posSignf(n) : negSignf(n);
}

// returns n with l being its lower bound
int lbound(const int n, const int l)
{
    return n<l?l:n;
}

// returns n with l being its upper bound
int ubound(const int n, const int u)
{
    return n>u?u:n;
}

// returns n with l being its lower bound
float lboundf(const float n, const float l)
{
    return n<l?l:n;
}

// returns n with l being its upper bound
float uboundf(const float n, const float u)
{
    return n>u?u:n;
}

#endif /* end of include guard: DOGELIB_TYPES_H */
