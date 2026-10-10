#ifndef DOGELIB_VEC_H
#define DOGELIB_VEC_H

// returns the angle of a vector centered at (0,0) pointing in the direction of coord
float cfToRad(const Coordf coord)
{
    return atan2f(coord.y, coord.x);
}

// converts radians to degrees
float radToDeg(const float rad)
{
    return rad*(180.0f/PI);
}

// returns the angle of a vector centered at (0,0) pointing in the direction of coord
float cfToDeg(const Coordf coord)
{
    return radToDeg(cfToRad(coord));
}

// converts degrees to radians
float degToRad(const float deg)
{
    return deg*(PI/180.0f);
}

// returns the other end position of a unit vector centered at (0, 0) with angle rad
Coordf radToCf(const float rad)
{
    return (const Coordf){.x = cosf(rad), .y = sinf(rad)};
}

// returns the other end position of a unit vector centered at (0, 0) with angle deg
Coordf degToCf(const float deg)
{
    return radToCf(degToRad(deg));
}

// converts a Coord to a Coordf
Coordf CCf(const Coord coord)
{
    return (const Coordf){.x = (float)coord.x, .y = (float)coord.y};
}

// converts a Coordf to a Coord
Coord CfC(const Coordf coordf)
{
    return (const Coord){.x = (int)coordf.x, .y = (int)coordf.y};
}

// returns a Coordf whose components are the are the max of the respective components of pos1 and pos2
Coordf cfMost(const Coordf pos1, const Coordf pos2)
{
    return (const Coordf){.x=fmost(pos1.x, pos2.x), .y=fmost(pos1.y, pos2.y)};
}

// returns a Coordf whose components are the are the max of the respective components of pos1 and pos2
Coordf cfLeast(const Coordf pos1, const Coordf pos2)
{
    return (const Coordf){.x=fleast(pos1.x, pos2.x), .y=fleast(pos1.y, pos2.y)};
}

// rounds the components of pos to be at least f
Coordf cfMaxf(const Coordf pos, const float f)
{
    return (const Coordf){.x=fmost(pos.x, f), .y=fmost(pos.y, f)};
}

// rounds the components of pos to be at most f
Coordf cfMinf(const Coordf pos, const float f)
{
    return (const Coordf){.x=fleast(pos.x, f), .y=fleast(pos.y, f)};
}

// clamps n so that it is at least min and at most max
float fclamp(const float n, const float min, const float max)
{
    if(n < min)
        return min;
    if(n >= max)
        return max-1;
    return n;
}

// returns true if n is greater than min (inclusive) and less than max (exclusive)
bool finBound(const float n, const float min, const float max)
{
    return n >= min && n < max;
}

// wraps the value of n between min and max
float fwrap(const float n, const float min, const float max)
{
    const float size = max-min;
    if(n < min)
        return max-fabs(n);
    if(n >= max)
        return min+(float)((int)n%(int)size);
    return n;
}

// offsets coord by the components of off
Coordf cfAdd(const Coordf coord, const Offsetf off)
{
    return (Coordf){.x = coord.x+off.x, .y = coord.y+off.y};
}

// multiplies the components of coord1 bt coord2
Coordf cfMul(const Coordf coord1, const Coordf coord2)
{
    return (Coordf){.x = coord1.x*coord2.x, .y = coord1.y*coord2.y};
}

// multiplies both components of coord by num
Coordf cfMulf(const Coordf coord, const float num)
{
    return (const Coordf){.x = coord.x*num, .y = coord.y*num};
}

// divides both components of coord1 by coord2. sets component to 0 in case of division by 0
Coordf cfDiv(const Coordf coord1, const Coordf coord2)
{
    return (Coordf){
        .x = coord2.x == 0 ? 0.0f : coord1.x/coord2.x,
        .y = coord2.y == 0 ? 0.0f : coord1.y/coord2.y
    };
}

// divides both components of coord by num. sets component to 0 in case of division by 0
Coordf cfDivf(const Coordf coord, const float num)
{
    return (Coordf){
        .x = num == 0 ? 0.0f : coord.x/num,
        .y = num == 0 ? 0.0f : coord.y/num
    };
}

// returns the distance between the two coords
float cfDist(const Coordf coord1, const Coordf coord2)
{
    return sqrtf(powf(coord2.x-coord1.x,2.0f)+powf(coord2.y-coord1.y,2.0f));
}

// returns the length of a vector with one point o at (0,0) and the other at coord
float cfMag(const Coordf coord)
{
    return sqrtf(coord.x*coord.x+coord.y*coord.y);
}

// creates a vector given angle in rads and a magnitude
Coordf radMagToCf(const float rad, const float mag)
{
    return cfMulf(radToCf(rad), mag);
}

// creates a vector given angle in rads and a magnitude
Coordf degMagToCf(const float deg, const float mag)
{
    return cfMulf(radToCf(degToRad(deg)), mag);
}

// normalized vector pointed at coord to a vector of unit length
Coordf cfNormalize(const Coordf coord)
{
    return cfDivf(coord, cfMag(coord));
}

// returns true if s and n have the same sign
bool sameSignf(const float s, const float n)
{
    return (s < 0.0f && n < 0.0f) || (s >= 0.0f && n >= 0.0f);
}

// inverts the sign of both components of pos
Coordf cfInv(const Coordf pos)
{
    return (const Coordf){.x = -pos.x, .y = -pos.y};
}

// returns coord with absolute value of both components of pos
Coordf cfAbs(const Coordf coord)
{
    return (const Coordf){.x = fabs(coord.x), .y = fabs(coord.y)};
}

// returns the maximum component of pos
float cfMax(const Coordf pos)
{
    return fmost(pos.x, pos.y);
}

// returns the minimum component of pos
float cfMin(const Coordf pos)
{
    return fleast(pos.x, pos.y);
}

// returns true if both components of a and b are equal
bool cfSame(const Coordf a, const Coordf b)
{
    return a.x == b.x && a.y == b.y;
}

// takes modulus of each component of pos by num
Coordf cfModf(const Coordf pos, const float num)
{
    return (const Coordf){
        .x = fmod(pos.x, num),
        .y = fmod(pos.y, num)
    };
}

// takes modulus of each component of a by b
Coordf cfMod(const Coordf a, const Coordf b)
{
    return (const Coordf){
        .x = fmod(a.x, b.x),
        .y = fmod(a.y, b.y)
    };
}

// subtracts each component of a from b
Coordf cfSub(const Coordf a, const Coordf b)
{
    return (const Coordf){
        .x = a.x-b.x,
        .y = a.y-b.y
    };
}

// adds num to both components of pos
Coordf cfAddf(const Coordf pos, const float num)
{
    return (const Coordf){
        .x=pos.x+num,
        .y=pos.y+num
    };
}

// rounds pos down to the nearest multiple of scale
Coordf cfSnap(const Coordf pos, const float scale)
{
    return cfSub(pos, cfModf(pos, scale));
}

// rounds pos to the nearest multiple of scale
Coordf cfSnapMid(const Coordf pos, const float scale)
{
    return cfSnap(cfAddf(pos, scale/2), scale);
}

// takes pos, gets its position in terms of percentage of oldLen
// returns a new position offset by the same percentage of newLen's sides
Coordf resizeTransformf(const Lengthf oldLen, const Lengthf newLen, const Coordf pos)
{
    return cfMul(newLen, cfDiv(pos, oldLen));
}

// returns angle of vector with orgin at pos1 and end at pos2
float cfCfToRad(const Coordf pos1, const Coordf pos2)
{
    return cfToRad(cfAdd(pos2, cfInv(pos1)));
}

// returns angle of vector with orgin at pos1 and end at pos2
float cfCfToDeg(const Coordf pos1, const Coordf pos2)
{
    return cfToDeg(cfAdd(cfInv(pos1), pos2));
}

// reduces the angle to +-180deg
float degReduce(float deg)
{
    deg = fmod(deg, 360.0f);
    return fabs(deg) > 180.0f ? -360.0f + deg : deg;
}

// reduces the angle to +-pi rad
float radReduce(float rad)
{
    rad = fmod(rad, PI);
    return fabs(rad) > PI ? -2.0f*PI + rad : rad;
}

// inverts the angle
float degInv(const float deg)
{
    return -360.0f+deg;
}

// takes a vertex and returns the angle between the 2 other points (always <= pi rad)
float cf3Rad(const Coordf vtx, const Coordf pos1, const Coordf pos2)
{
    return fabs(cfCfToRad(vtx, pos1)) + fabs(cfCfToRad(vtx, pos2));
}

// takes a vertex and returns the angle between the 2 other points (always <= 180deg)
float cf3Deg(const Coordf vtx, const Coordf pos1, const Coordf pos2)
{
    return fabs(degReduce(cfCfToDeg(vtx, pos1) - cfCfToDeg(vtx, pos2)));
}

// takes a vector and rotates it n rads
Coordf cfRotateRad(const Coordf vec, const float n)
{
    return radMagToCf(cfToRad(vec) + n, cfMag(vec));
}

// takes a vector and rotates it d deg
Coordf cfRotateDeg(const Coordf vec, const float d)
{
    return cfRotateRad(vec, degToRad(d));
}

// returns true if line [p0, p1] intersects with line [p2, p3], sets intersection point to at if not NULL
bool lineIntersection(const Coordf p0, const Coordf p1, const Coordf p2, const Coordf p3, Coordf *at)
{
    const Coordf s1 = {.x = p1.x - p0.x, .y = p1.y - p0.y};
    const Coordf s2 = {.x = p3.x - p2.x, .y = p3.y - p2.y};
    const float d = -s2.x * s1.y + s1.x * s2.y;
    const float s = d!=0 ? (-s1.y * (p0.x - p2.x) + s1.x * (p0.y - p2.y)) / d : 1000000.0f;
    const float t = d!=0 ? ( s2.x * (p0.y - p2.y) - s2.y * (p0.x - p2.x)) / d : 1000000.0f;

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1){
        if(at){
            at->x = p0.x + (t * s1.x);
            at->y = p0.y + (t * s1.y);
        }
        return true;
    }
    return false;
}

#endif /* end of include guard: DOGELIB_VEC_H */
