#pragma once

typedef enum{M_INT, M_BRANCH}MenuType;

typedef struct Menu{
	MenuType type;
	char *label;
	union{
		struct{
			uint numItem;
			struct Menu *item;
		}branch;
		int val;
	};
}Menu;

Coord drawMenu(const Coord coord, const Menu menu)
{
	if(menu.type == M_INT){
		drawTextCoord(coord, menu.label);
		char buf[32] = {0};
		sprintf(buf, "%i", menu.val);
		drawTextCoord(coordShift(coord, DIR_R, getTextXLen(menu.label)), buf);
		return coordShift(coord, DIR_D, getTextYLen(menu.label));
	}else{
		drawTextCoord(coord, menu.label);
		Coord subcoord = coordOffset(coord,(Coord){getTextSize()*4,getTextYLen(menu.label)});
		for(uint i = 0; i < menu.branch.numItem; i++){
			subcoord = drawMenu(subcoord, menu.branch.item[i]);
		}
		return (Coord){coord.x, subcoord.y};
	}
}
