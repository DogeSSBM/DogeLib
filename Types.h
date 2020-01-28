#pragma once

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ul;
typedef unsigned long long ull;

typedef FILE File;
typedef time_t Time;
// typedef void(*Callback)(void);

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

#define I8MIN INT8_MIN
#define I8MAX INT8_MAX
#define I16MIN INT16_MIN
#define I16MAX INT16_MAX
#define I32MIN INT32_MIN
#define I32MAX INT32_MAX
#define I64MIN INT64_MIN
#define I64MAX INT64_MAX

#define U8MAX UINT8_MAX
#define U16MAX UINT16_MAX
#define U32MAX UINT32_MAX
#define U64MAX UINT64_MAX

#ifdef DOGE_GFX
typedef SDL_Rect Rect;
typedef SDL_Color Color;
typedef SDL_Surface Img;
typedef SDL_Keycode Key;
#endif

void typeInfo(void)
{
	printf("byte          bits(CHAR_BIT)  = %-+20d %X\n",
	CHAR_BIT, CHAR_BIT);
	
	printf("signed char   min (SCHAR_MIN) = %-+20d %X\n",
	SCHAR_MIN, SCHAR_MIN);
	
	printf("signed char   max (SCHAR_MAX) = %-+20d %X\n",
	SCHAR_MAX, SCHAR_MAX);
	
	printf("unsigned char max (UCHAR_MAX) = %-+20d %X\n",
	UCHAR_MAX, UCHAR_MAX);
	
	printf("short int     min (SHRT_MIN)  = %-+20d %X\n",
	SHRT_MIN, SHRT_MIN);
	
	printf("short int     max (SHRT_MAX)  = %-+20d %X\n",
	SHRT_MAX, SHRT_MAX);
	
	printf("int           min (INT_MIN)   = %-+20d %X\n",
	INT_MIN, INT_MIN);
	
	printf("int           max (INT_MAX)   = %-+20d %X\n",
	INT_MAX, INT_MAX);
	
	printf("char          min (CHAR_MIN)  = %-+20d %X\n",
	CHAR_MIN, CHAR_MIN);
	
	printf("char          max (CHAR_MAX)  = %-+20d %X\n",
	CHAR_MAX, CHAR_MAX);
	
	printf("long          min (LONG_MIN)  = %-+20ld %lX\n",
	LONG_MIN, LONG_MIN);
	
	printf("long          max (LONG_MAX)  = %-+20ld %lX\n",
	LONG_MAX, LONG_MAX);
	
}
