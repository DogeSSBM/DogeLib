#pragma once

static inline
float cfToRad(const Coordf coord)
{
	return atan2f(coord.y, coord.x);
}

static inline
float radToDeg(const float rad)
{
	return rad*(180.0f/PI);
}

static inline
float cfToDeg(const Coordf coord)
{
	return radToDeg(cfToRad(coord));
}

static inline
float degToRad(const float deg)
{
	return deg*(PI/180.0f);
}

static inline
Coordf radToCf(const float rad)
{
	return (Coordf){cosf(rad), sinf(rad)};
}

static inline
Coordf degToCf(const float deg)
{
	return radToCf(degToRad(deg));
}

static inline
Coordf CCf(const Coord coord)
{
	return (Coordf){(float)coord.x,(float)coord.y};
}

static inline
Coord CfC(const Coordf coordf)
{
	return (Coord){(int)coordf.x,(int)coordf.y};
}

static inline
float fclamp(const float n, const float min, const float max)
{
	if(n < min)
		return min;
	if(n >= max)
		return max-1;
	return n;
}

static inline
bool finBound(const float n, const float min, const float max)
{
	return !(n < min || n >= max);
}

static inline
float fwrap(const float n, const float min, const float max)
{
	const float size = max-min;
	if(n < min)
		return max-fabs(n);
	if(n >= max)
		return min+(float)((int)n%(int)size);
	return n;
}

static inline
Coordf cfMul(const Coordf coord, const float num)
{
	return (Coordf){coord.x*num, coord.y*num};
}

static inline
Coordf cfDiv(const Coordf coord, const float num)
{
	if(num==0.0f)
		return coord;
	return (Coordf){coord.x/num, coord.y/num};
}

static inline
float cfDist(const Coordf coord1, const Coordf coord2)
{
	return sqrtf(powf(coord2.x-coord1.x,2.0f)+powf(coord2.y-coord1.y,2.0f));
}

static inline
float cfMag(const Coordf coord)
{
	return sqrtf(coord.x*coord.x+coord.y*coord.y);
}

static inline
Coordf radMagToCf(const float rad, const float mag)
{
	return cfMul(radToCf(rad), mag);
}

static inline
Coordf cfNormalize(const Coordf coord)
{
	return cfDiv(coord, cfMag(coord));
}

static inline
Coordf cfTranslate(const Coordf coord, const Vectorf vec)
{
	return (Coordf){coord.x+vec.x, coord.y+vec.y};
}

static inline
bool fSameSign(const float num1, const float num2)
{
	return (num1<0.0f&&num2<0.0f)||(num1>=0.0f&&num2>=0.0f);
}

static inline
Coordf cfNeg(const Coordf coord)
{
	return (Coordf){-coord.x, -coord.y};
}

static inline
Coordf cfAbs(const Coordf coord)
{
	return (Coordf){abs(coord.x), abs(coord.y)};
}

static inline
float cfCfToRad(const Coordf pos1, const Coordf pos2)
{
	return cfToRad(cfTranslate(pos2, cfNeg(pos1)));
}

static inline
float cfCfToDeg(const Coordf pos1, const Coordf pos2)
{
	return cfToDeg(cfTranslate(cfNeg(pos1), pos2));
}

static inline
float degReduce(const float deg)
{
	if(abs(fmod(deg, 360.0f))>180.0f)
		return -360.0f+fmod(deg, 360.0f);
	return deg;
}

static inline
float degInv(const float deg)
{
	return -360.0f+deg;
}

// takes a vertex and returns the angle between the 2 other points
static inline
float cf3Rad(const Coordf vtx, const Coordf pos1, const Coordf pos2)
{
	return abs(cfCfToRad(vtx, pos1)) + abs(cfCfToRad(vtx, pos2));
}

// takes a vertex and returns the angle between the 2 other points
static inline
float cf3Deg(const Coordf vtx, const Coordf pos1, const Coordf pos2)
{
	return abs(degReduce(cfCfToDeg(vtx, pos1) - cfCfToDeg(vtx, pos2)));
}
