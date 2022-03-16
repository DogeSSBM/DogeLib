#pragma once

Direction dirROR(const Direction dir)
{
	return (dir+1)&0b11;
}

Direction dirROL(const Direction dir)
{
	return (dir-1)&0b11;
}

Direction dirINV(const Direction dir)
{
	return dir^0b10;
}

Direction dirLR(const Direction dir)
{
	return dir&1;
}

Direction dirUD(const Direction dir)
{
	return !(dir&1);
}

bool dirAXA(const Direction dir1, const Direction dir2)
{
	return dirUD(dir1) == dirUD(dir2);
}

Direction dirPOS(const Direction dir)
{
	return dir==DIR_R||dir==DIR_D;
}

Direction dirNEG(const Direction dir)
{
	return dir==DIR_L||dir==DIR_U;
}

int coordMin(const Coord coord)
{
	return coord.c1 < coord.c2 ? coord.c1 : coord.c2;
}

Coord coordLeast(const Coord pos1, const Coord pos2)
{
	return (Coord){pos1.x<pos2.x?pos1.x:pos2.x, pos1.y<pos2.y?pos1.y:pos2.y};;
}

int coordMax(const Coord coord)
{
	return coord.c1 > coord.c2 ? coord.c1 : coord.c2;
}

Coord coordMost(const Coord pos1, const Coord pos2)
{
	return (Coord){pos1.x>pos2.x?pos1.x:pos2.x, pos1.y>pos2.y?pos1.y:pos2.y};;
}

bool coordSame(const Coord pos1, const Coord pos2)
{
	return pos1.x == pos2.x && pos1.y == pos2.y;
}

int clamp(const int n, const int min, const int max)
{
	if(n < min)
		return min;
	if(n >= max)
		return max-1;
	return n;
}

bool inBound(const int n, const int min, const int max)
{
	return !(n < min || n >= max);
}

bool inRange(const int n, const Range range)
{
	return n >= range.min && n < range.max;
}

int wrap(const int n, const int min, const int max)
{
	const uint size = max-min;
	if(n < min)
		return max-abs(n);
	if(n >= max)
		return min+(n%size);
	return n;
}

// Returns true if both axies of coord are in range
bool coordInRange(const Coord coord, const Range range)
{
	return inRange(coord.x, range) && inRange(coord.y, range);
}

Coord coordClampLen(const Coord coord, const Length len)
{
	return (const Coord){clamp(coord.x, 0, len.x), clamp(coord.y, 0, len.y)};
}

// Returns true if each part of pos1 is less than their counterpart in pos2
bool coordMaxCoord(const Coord pos1, const Coord pos2)
{
	return pos1.x < pos2.x && pos1.y < pos2.y;
}

// Returns true if each part of pos1 is greater than or equal to their counterpart in pos2
bool coordMinCoord(const Coord pos1, const Coord pos2)
{
	return pos1.x >= pos2.x && pos1.y >= pos2.y;
}

// takes 2 opposite corner coords and returns rect
Rect coordsToRect(const Coord coord1, const Coord coord2)
{

	return (Rect){coord1.x,coord1.y,coord2.x-coord1.x,coord2.y-coord1.y};
}

// returns top left and lower right coord of rect
CoordPair rectToCoordPair(const Rect rect)
{
	return (CoordPair){
		(Coord){rect.x, rect.x+rect.w},
		(Coord){rect.y, rect.y+rect.h}
	};
}

// Returns true if coord is in rect
bool coordInRect(const Coord coord, const Rect rect)
{
    return inBound(coord.x, rect.x, rect.x+rect.w) && inBound(coord.y, rect.y, rect.y+rect.h);
}

// returns index of first rect that coord can be found in or -1 if in none
int coordInRectArr(const Coord coord, Rect *const rect, const int num)
{
	if(num < 1)
		return -1;
	for(int i = 0; i < num; i++)
		if(coordInRect(coord, rect[i]))
			return i;
	return -1;
}

bool coordNz(const Coord coord)
{
	return coord.x||coord.y;
}

Coord coordMul(const Coord coord, const int num)
{
	return (Coord){coord.x*num, coord.y*num};
}

Coord coordOffsetMul(const Coord coord1, const Coord coord2)
{
	return (Coord){coord1.x*coord2.x,coord1.y*coord2.y};
}

Coordf coordfOffsetMul(const Coordf coord1, const Coordf coord2)
{
	return (Coordf){coord1.x*coord2.x,coord1.y*coord2.y};
}

Coord coordInv(const Coord coord)
{
	return (Coord){-coord.x, -coord.y};
}

Coord coordAdd(const Coord coord1, const uint num)
{
	return (Coord){coord1.x+num,coord1.y+num};
}

Coord coordSub(const Coord coord1, const Coord coord2)
{
	return (Offset){coord1.x-coord2.x,coord1.y-coord2.y};
}

float coordfDist(const Coordf coord1, const Coordf coord2)
{
	return sqrtf(powf(coord2.x-coord1.x,2.0f)+powf(coord2.y-coord1.y,2.0f));
}

Coordf coordfDiv(const Coordf coord, const float num)
{
	return (Coordf){coord.x/num, coord.y/num};
}

Coord coordMod(const Coord coord, const int num)
{
	return (Coord){coord.x%num, coord.y%num};
}

Coordf coordfNormalize(const Coordf coord)
{
	return coordfDiv(coord, coordfDist((Coordf){0.0f,0.0f}, coord));
}

Coord coordMid(const Coord coord1, const Coord coord2)
{
	return (const Coord){(coord1.x+coord2.x)/2, (coord1.y+coord2.y)/2};
}

uint coordDistSq(const Coord coord1, const Coord coord2)
{
	Coord distvec = coordSub(coord2, coord1);
	distvec = coordOffsetMul(distvec, distvec);
	return distvec.x + distvec.y;
}

Coord coordDiv(const Coord coord, const int num)
{
	return (Coord){coord.x/num, coord.y/num};
}

Coord coordWrap(const Coord coord, const Range x, const Range y)
{
	return (Coord){
		wrap(coord.x, x.min, x.max),
		wrap(coord.y, y.min, y.max)
	};
}

Coord coordClamp(const Coord coord, const Range x, const Range y)
{
	return (Coord){
		clamp(coord.x, x.min, x.max),
		clamp(coord.y, y.min, y.max)
	};
}

Coord coordShift(const Coord coord, const Direction dir, const int units)
{
	if(dirUD(dir))
		return (Coord){coord.x, dirPOS(dir)? coord.y+units : coord.y-units};
	return (Coord){dirPOS(dir)? coord.x+units : coord.x-units, coord.y};
}

Coord coordOffset(const Coord coord, const Offset off)
{
	return (Coord){coord.x+off.x, coord.y+off.y};
}

Coordf coordfOffset(const Coordf coord, const Offsetf off)
{
	return (Coordf){coord.x+off.x, coord.y+off.y};
}

Rect rectOffset(const Rect rect, const Offset off)
{
	const Coord pos = coordOffset((Coord){rect.x, rect.y}, off);
	return (Rect){.x=pos.x, .y=pos.y, .w=rect.w, .h=rect.h};
}
