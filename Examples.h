#pragma once

typedef struct{
	Coordf pos;
	float ang;
	float mag;
}Particle;

void particles(const Length window)
{
	static bool initialized = false;
	static Particle part[10];
	if(!initialized){
		initialized = true;
		for(uint i = 0; i < 10; i++){
			part[i].pos = CCf(coordDiv(window, 2));
			part[i].ang = degToRad(randRange(-180.0f, 180.0f));
			part[i].mag = randRange(0.0f, 4.0f);
		}
	}

	for(uint i = 0; i < 10; i++){
		fillCircleCoord(CfC(part[i].pos), 8);
		part[i].ang += degToRad(randRange(-8.0f, 8.0f));
		part[i].mag = fclamp(part[i].mag+randRange(-2.0f, 2.0f), -20.0f, 20.0f);
		Coordf cf = radMagToCf(part[i].ang, part[i].mag);
		Coordf new = cfTranslate(part[i].pos, cf);
		if(!finBound(new.x,0.0f,(float)window.x)){
			cf.x = -cf.x;
			new = cfTranslate(part[i].pos, cf);
			part[i].ang = cfToRad(cf);
			part[i].mag = cfMag(cf);
		}

		if(!finBound(new.y,0.0f,(float)window.y)){
			cf.y = -cf.y;
			new = cfTranslate(part[i].pos, cf);
			part[i].ang = cfToRad(cf);
			part[i].mag = cfMag(cf);
		}
		part[i].pos = new;

	}
}

typedef struct{
	Coordf pos[3];
	float ang[3];
	float mag[3];
}Triangle;

void tri(const Length window)
{
	static bool initialized = false;
	static Triangle tri[10];
	if(!initialized){
		initialized = true;
		for(uint i = 0; i < 10; i++){
			for(uint j = 0; j < 3; j++){
				tri[i].pos[j] = CCf(coordDiv(window, 2));
				tri[i].ang[j] = degToRad(randRange(-180.0f, 180.0f));
				tri[i].mag[j] = randRange(0.0f, 4.0f);
			}
		}
	}

	for(uint i = 0; i < 10; i++){
		for(uint j = 0; j < 3; j++){
			Coord c[3] = {CfC(tri[i].pos[0]), CfC(tri[i].pos[1]), CfC(tri[i].pos[2])};
			fillPoly(c, 3);
			tri[i].ang[j] += degToRad(randRange(-8.0f, 8.0f));
			tri[i].mag[j] = fclamp(tri[i].mag[j]+randRange(-2.0f, 2.0f), -20.0f, 20.0f);
			Coordf cf = radMagToCf(tri[i].ang[j], tri[i].mag[j]);
			Coordf new = cfTranslate(tri[i].pos[j], cf);
			if(!finBound(new.x,0.0f,(float)window.x)){
				cf.x = -cf.x;
				new = cfTranslate(tri[i].pos[j], cf);
				tri[i].ang[j] = cfToRad(cf);
				tri[i].mag[j] = cfMag(cf);
			}

			if(!finBound(new.y,0.0f,(float)window.y)){
				cf.y = -cf.y;
				new = cfTranslate(tri[i].pos[j], cf);
				tri[i].ang[j] = cfToRad(cf);
				tri[i].mag[j] = cfMag(cf);
			}
			tri[i].pos[j] = new;
		}
	}
}
