#pragma once

typedef struct{
	Color color;
	uint numVertex;
	Coord *vertex;
}Poly;

Poly polyCreate(const uint numVertex, ...)
{
	va_list vlist;
	va_start(vlist, numVertex);
	Poly p = {
		.numVertex = numVertex,
		.vertex = malloc(sizeof(Coord)*numVertex)
	};

	for(uint i = 0; i < numVertex; i++){
		p.vertex[i] = va_arg(vlist, Coord);
	}
	return p;
}

void polyDestroy(const Poly p)
{
	if(p.vertex != NULL)
		free(p.vertex);
}

Rect polyBbRect(const Poly p)
{
	Coord min = {I32MAX, I32MAX};
	Coord max = {0, 0};
	for(uint i = 0; i < p.numVertex; i++){
		min = coordLeast(min, p.vertex[i]);
		max = coordMost(max, p.vertex[i]);
	}
	return (Rect){min.x, min.y, max.x-min.x, max.y-min.y};
}

CoordPair polyBbMinMax(const Poly p)
{
	CoordPair ret = {
		.min = {I32MAX, I32MAX},
		.max = {0, 0}
	};
	for(uint i = 0; i < p.numVertex; i++){
		ret.min = coordLeast(ret.min, p.vertex[i]);
		ret.max = coordMost(ret.max, p.vertex[i]);
	}
	return ret;
}
