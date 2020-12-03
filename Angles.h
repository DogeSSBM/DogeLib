#pragma once

float coordfToRads(const Coordf coord)
{
	return atan2f(coord.y, coord.x);
}
