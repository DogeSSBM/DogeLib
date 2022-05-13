#pragma once

float cfToRad(const Coordf coord)
{
	return atan2f(coord.y, coord.x);
}

float radToDeg(const float rad)
{
	return rad*(180.0f/PI);
}

float cfToDeg(const Coordf coord)
{
	return radToDeg(cfToRad(coord));
}

float degToRad(const float deg)
{
	return deg*(PI/180.0f);
}

Coordf radToCf(const float rad)
{
	return (Coordf){cosf(rad), sinf(rad)};
}

Coordf degToCf(const float deg)
{
	return radToCf(degToRad(deg));
}

Coordf CCf(const Coord coord)
{
	return (Coordf){(float)coord.x,(float)coord.y};
}

Coord CfC(const Coordf coordf)
{
	return (Coord){(int)coordf.x,(int)coordf.y};
}

float fclamp(const float n, const float min, const float max)
{
	if(n < min)
		return min;
	if(n >= max)
		return max-1;
	return n;
}

bool finBound(const float n, const float min, const float max)
{
	return !(n < min || n >= max);
}

float fwrap(const float n, const float min, const float max)
{
	const float size = max-min;
	if(n < min)
		return max-fabs(n);
	if(n >= max)
		return min+(float)((int)n%(int)size);
	return n;
}

Coordf cfMul(const Coordf coord, const float num)
{
	return (Coordf){coord.x*num, coord.y*num};
}

Coordf cfDiv(const Coordf coord, const float num)
{
	if(num==0.0f)
		return coord;
	return (Coordf){coord.x/num, coord.y/num};
}

float cfDist(const Coordf coord1, const Coordf coord2)
{
	return sqrtf(powf(coord2.x-coord1.x,2.0f)+powf(coord2.y-coord1.y,2.0f));
}

float cfMag(const Coordf coord)
{
	return sqrtf(coord.x*coord.x+coord.y*coord.y);
}

// creates a vector given angle in rads and a magnitude
Coordf radMagToCf(const float rad, const float mag)
{
	return cfMul(radToCf(rad), mag);
}

// creates a vector given angle in rads and a magnitude
Coordf degMagToCf(const float deg, const float mag)
{
	return cfMul(radToCf(degToRad(deg)), mag);
}

Coordf cfNormalize(const Coordf coord)
{
	return cfDiv(coord, cfMag(coord));
}

Coordf cfTranslate(const Coordf coord, const Vectorf vec)
{
	return (Coordf){coord.x+vec.x, coord.y+vec.y};
}

bool fSameSign(const float num1, const float num2)
{
	return (num1<0.0f&&num2<0.0f)||(num1>=0.0f&&num2>=0.0f);
}

Coordf cfNeg(const Coordf coord)
{
	return (Coordf){-coord.x, -coord.y};
}

Coordf cfAbs(const Coordf coord)
{
	return (Coordf){abs(coord.x), abs(coord.y)};
}

float cfCfToRad(const Coordf pos1, const Coordf pos2)
{
	return cfToRad(cfTranslate(pos2, cfNeg(pos1)));
}

float cfCfToDeg(const Coordf pos1, const Coordf pos2)
{
	return cfToDeg(cfTranslate(cfNeg(pos1), pos2));
}

float degReduce(const float deg)
{
	if(abs(fmod(deg, 360.0f))>180.0f)
		return -360.0f+fmod(deg, 360.0f);
	return deg;
}

float degInv(const float deg)
{
	return -360.0f+deg;
}

// takes a vertex and returns the angle between the 2 other points
float cf3Rad(const Coordf vtx, const Coordf pos1, const Coordf pos2)
{
	return abs(cfCfToRad(vtx, pos1)) + abs(cfCfToRad(vtx, pos2));
}

// takes a vertex and returns the angle between the 2 other points
float cf3Deg(const Coordf vtx, const Coordf pos1, const Coordf pos2)
{
	return abs(degReduce(cfCfToDeg(vtx, pos1) - cfCfToDeg(vtx, pos2)));
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
