#ifndef DOGELIB_COORDS_H
#define DOGELIB_COORDS_H

// rotates d 90deg right
static inline
Direction dirROR(const Direction d)
{
    return (d+1)&3u;
}

// rotates d 90deg left
static inline
Direction dirROL(const Direction d)
{
    return (d-1)&3u;
}

// inverts d (rotates 180deg)
static inline
Direction dirINV(const Direction d)
{
    return d^2u;
}

// true if d is left or right
static inline
Direction dirLR(const Direction d)
{
    return d&1;
}

// true if d is up or down
static inline
Direction dirUD(const Direction d)
{
    return !(d&1);
}

// returns true if a is aligned with the same axis as b
static inline
bool dirAXA(const Direction a, const Direction b)
{
    return dirUD(a) == dirUD(b);
}

// true if d is a positive direction (right or down)
static inline
Direction dirPOS(const Direction d)
{
    return d==DIR_R||d==DIR_D;
}

// true if d is a negative direction (left or up)
static inline
Direction dirNEG(const Direction d)
{
    return d==DIR_L||d==DIR_U;
}

// returns the minimum component of pos
static inline
int coordMin(const Coord pos)
{
    return imin(pos.x, pos.y);
}

// returns coord comprised of the lesser components of a and b
static inline
Coord coordLeast(const Coord a, const Coord b)
{
    return (const Coord){.x = imin(a.x, b.x), .y = imin(a.y, b.y)};
}

// returns the maximum component of pos
static inline
int coordMax(const Coord pos)
{
    return imax(pos.x, pos.y);
}

// returns coord comprised of the lesser components of a and b
static inline
Coord coordMost(const Coord a, const Coord b)
{
    return (const Coord){.x = imax(a.x, b.x), .y = imax(a.y, b.y)};
}

// returns true if both components of a and b are equal
static inline
bool coordSame(const Coord a, const Coord b)
{
    return a.x == b.x && a.y == b.y;
}

// returns coord with absolute value of both components of pos
static inline
Coord coordAbs(const Coord pos)
{
    return (const Coord){.x=pos.x<0?-pos.x:pos.x, .y=pos.y<0?-pos.y:pos.y};
}

// clamps n to be within min (inclusive) to max (exclusive)
static inline
int clamp(const int n, const int min, const int max)
{
    if(n < min)
        return min;
    if(n >= max)
        return max-1;
    return n;
}

// true if n within min (inclusive) and max (exclusive)
static inline
bool inBound(const int n, const int min, const int max)
{
    return !(n < min || n >= max);
}

// similar to clamp, but wraps values
static inline
int wrap(const int n, const int min, const int max)
{
    const uint size = max-min;
    if(n < min)
        return max-abs(n);
    if(n >= max)
        return min+(n%size);
    return n;
}

// Clamps both x and y component of coord to >= 0 and < their respective component in len
static inline
Coord coordClampLen(const Coord pos, const Length len)
{
    return (const Coord){.x = clamp(pos.x, 0, len.x), .y = clamp(pos.y, 0, len.y)};
}

// Returns true if the x and y component of coord are >= 0 and < their respective component in len
static inline
bool coordInLen(const Coord pos, const Length len)
{
    return pos.x >= 0 && pos.x < len.x && pos.y >= 0 && pos.y < len.y;
}

// Returns true if each part of pos1 is less than their counterpart in pos2
static inline
bool coordMaxCoord(const Coord a, const Coord b)
{
    return a.x < b.x && a.y < b.y;
}

// Returns true if each part of a is greater than or equal to their counterpart in b
static inline
bool coordMinCoord(const Coord a, const Coord b)
{
    return a.x >= b.x && a.y >= b.y;
}

// takes 2 opposite corner coords and returns rect
static inline
Rect coordsToRect(const Coord a, const Coord b)
{
    return (const Rect){
        .x = a.x,
        .y = a.y,
        .w = b.x - a.x,
        .h = b.y - a.y
    };
}

// resizes rect by len
static inline
Rect rectResize(const Rect rect, const int len)
{
    return (const Rect){
        .x = rect.x-len,
        .y = rect.y-len,
        .w = rect.w+2*len,
        .h = rect.h+2*len
    };
}

// returns true if neither components of pos are 0
static inline
bool coordNz(const Coord pos)
{
    return pos.x && pos.y;
}

// returns true if both components of pos are 0
static inline
bool coordEz(const Coord pos)
{
    return !pos.x && !pos.y;
}

// multiplies both components of pos by num
static inline
Coord coordMuli(const Coord pos, const int num)
{
    return (const Coord){.x = pos.x*num, .y = pos.y*num};
}

// multiplies each component of a and b
static inline
Coord CoordMul(const Coord a, const Coord b)
{
    return (const Coord){.x = a.x*b.x, .y = a.y*b.y};
}

// inverts the sign of both components of pos
static inline
Coord coordInv(const Coord pos)
{
    return (const Coord){.x = -pos.x, .y = -pos.y};
}

// adds num to both components of pos
static inline
Coord coordAddi(const Coord pos, const int num)
{
    return (const Coord){.x = pos.x+num, .y = pos.y+num};
}

// subtracts each component of a from b
static inline
Coord coordSub(const Coord a, const Coord b)
{
    return (const Offset){.x = a.x-b.x, .y = a.y-b.y};
}

// subtracts num from both components of pos
static inline
Coord coordSubi(const Coord pos, const int num)
{
    return (const Coord){.x = pos.x-num, .y = pos.y-num};
}

// takes modulus of each component of a by b
static inline
Coord coordMod(const Coord a, const Coord b)
{
    return (const Coord){.x = a.x%b.x, .y = a.y%b.y};
}

// takes modulus of each component of pos by num
static inline
Coord coordModi(const Coord pos, const int num)
{
    return (const Coord){.x = pos.x%num, .y = pos.y%num};
}

// takes the midpoint of a and b
static inline
Coord coordMid(const Coord a, const Coord b)
{
    return (const Coord){.x = (a.x+b.x)/2, .y = (a.y+b.y)/2};
}

// takes the distance squared between a and b
static inline
uint coordDistSq(const Coord a, const Coord b)
{
    Coord distvec = coordSub(b, a);
    distvec = CoordMul(distvec, distvec);
    return distvec.x + distvec.y;
}

// divides each component of pos by num
// if num is 0, sets each component to 0
static inline
Coord coordDivi(const Coord pos, const int num)
{
    return (const Coord){.x = num ? pos.x / num : 0, .y = num ? pos.y / num : 0};
}

// divides each component of a by b
// if a component of b is 0, sets that component to 0
static inline
Coord coordDiv(const Coord a, const Coord b)
{
    return (const Coord){
        .x = b.x ? a.x/b.x : 0,
        .y = b.y ? a.y/b.y : 0
    };
}

static inline
Coord coordShift(const Coord coord, const Direction dir, const int units)
{
    if(dirUD(dir))
        return (const Coord){.x = coord.x, .y = dirPOS(dir)? coord.y+units : coord.y-units};
    return (const Coord){.x = dirPOS(dir)? coord.x+units : coord.x-units, .y = coord.y};
}

// adds each component of a to b
static inline
Coord coordAdd(const Coord a, const Offset b)
{
    return (const Coord){.x = a.x+b.x, .y = a.y+b.y};
}

// offsets the pos by 1/2 the length
static inline
Coord coordCenter(const Coord pos, const Length len)
{
    return coordAdd(pos, coordDivi(len, 2));
}

// offsets the pos by -1/2 the length
static inline
Coord coordUncenter(const Coord pos, const Length len)
{
    return coordAdd(pos, coordDivi(len, -2));
}

// scales and offsets pos
static inline
Coord coordOffScale(const Coord pos, const Offset off, const int scale)
{
    return coordAdd(coordMuli(pos, scale), off);
}

// takes pos, gets its position in terms of percentage of oldLen side lengths
// returns a new position offset by the same percentage of newLen's sides
static inline
Coord resizeTransform(const Length oldLen, const Length newLen, const Coord pos)
{
    return CfC(cfMul(CCf(newLen), cfDiv(CCf(pos), CCf(oldLen))));
}

// gets lower right corner of rect
static inline
Coord rectCorner(const Rect rect)
{
    return coordAdd(irC(rect), irL(rect));
}

// returns rect at pos with length len
static inline
Rect rectify(const Coord pos, const Length len)
{
    return (const Rect){
        .x = pos.x,
        .y = pos.y,
        .w = len.x,
        .h = len.y
    };
}

// offsets rect pos by 1/2 its length
static inline
Rect rectCenter(Rect r)
{
    const Length len = irL(r);
    return rectify(coordCenter(irC(r), len), len);
}

// returns rect pos offset by len of rect
static inline
Length unrectify(const Rect rect)
{
    return coordAdd(irC(rect), irL(rect));
}

// Returns true if pos is in rect
static inline
bool coordInRect(const Coord pos, const Rect rect)
{
    return inBound(pos.x, rect.x, rect.x+rect.w) && inBound(pos.y, rect.y, rect.y+rect.h);
}

// returns index of first rect that coord can be found in or -1 if in none
static inline
int coordInRectArr(const Coord coord, Rect *const rect, const int num)
{
    if(num < 1)
        return -1;
    for(int i = 0; i < num; i++)
        if(coordInRect(coord, rect[i]))
            return i;
    return -1;
}

// offsets rect by off
static inline
Rect rectOffset(const Rect rect, const Offset off)
{
    return (Rect){.x = rect.x+off.x, .y = rect.y+off.y, .w = rect.w, .h = rect.h};
}

#endif /* end of include guard: DOGELIB_COORDS_H */
