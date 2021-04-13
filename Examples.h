// #pragma once
// #define POLY_SIDES	4
//
// typedef struct{
// 	Coordf pos;
// 	float ang;
// 	float mag;
// 	float mass;
// }Particle;
//
// void particles(const Length window)
// {
// 	static bool initialized = false;
// 	static Particle part[10];
// 	if(!initialized){
// 		initialized = true;
// 		for(uint i = 0; i < 10; i++){
// 			part[i].pos = CCf(coordDiv(window, 2));
// 			part[i].ang = degToRad(randRange(-180.0f, 180.0f));
// 			part[i].mag = randRange(0.0f, 4.0f);
// 		}
// 	}
//
// 	for(uint i = 0; i < 10; i++){
// 		fillCircleCoord(CfC(part[i].pos), 16);
// 		part[i].ang += degToRad(randRange(-8.0f, 8.0f));
// 		part[i].mag = fclamp(part[i].mag+randRange(-2.0f, 2.0f), -20.0f, 20.0f);
// 		Coordf cf = radMagToCf(part[i].ang, part[i].mag);
// 		Coordf new = cfTranslate(part[i].pos, cf);
// 		if(!finBound(new.x,0.0f,(float)window.x)){
// 			cf.x = -cf.x;
// 			new = cfTranslate(part[i].pos, cf);
// 			part[i].ang = cfToRad(cf);
// 			part[i].mag = cfMag(cf);
// 		}
//
// 		if(!finBound(new.y,0.0f,(float)window.y)){
// 			cf.y = -cf.y;
// 			new = cfTranslate(part[i].pos, cf);
// 			part[i].ang = cfToRad(cf);
// 			part[i].mag = cfMag(cf);
// 		}
// 		part[i].pos = new;
//
// 	}
// }
//
// typedef struct{
// 	Coordf pos[POLY_SIDES];
// 	float ang[POLY_SIDES];
// 	float mag[POLY_SIDES];
// }Poly;
//
// void polyDraw(const Length window)
// {
// 	static bool initialized = false;
// 	static Poly poly[10];
// 	if(!initialized){
// 		initialized = true;
// 		for(uint i = 0; i < 10; i++){
// 			for(uint j = 0; j < POLY_SIDES; j++){
// 				poly[i].pos[j] = (Coordf){
// 					randRange(0.0f,(float)window.x), randRange(0.0f, (float)window.y)
// 				};
// 				poly[i].ang[j] = degToRad(randRange(-180.0f, 180.0f));
// 				poly[i].mag[j] = randRange(0.0f, 4.0f);
// 			}
// 		}
// 	}
//
// 	for(uint i = 0; i < 10; i++){
// 		for(int j = 0; j < POLY_SIDES; j++){
// 			Coord c[POLY_SIDES+1];
// 			for(uint k = 0; k < POLY_SIDES; k++){
// 				c[k] = CfC(poly[i].pos[k]);
// 			}
// 			c[POLY_SIDES] = mouse.pos;
// 			setColor(randColor());
// 			drawPoly(c, POLY_SIDES+1);
// 			poly[i].ang[j] += degToRad(randRange(-8.0f, 8.0f));
//
// 			poly[i].mag[j] = fclamp(poly[i].mag[j]+randRange(-2.0f, 2.0f), -20.0f, 20.0f);
// 			Coordf cf = radMagToCf(poly[i].ang[j], poly[i].mag[j]);
// 			Coordf new = cfTranslate(poly[i].pos[j], cf);
// 			if(!finBound(new.x,0.0f,(float)window.x)){
// 				cf.x = -cf.x;
// 				new = cfTranslate(poly[i].pos[j], cf);
// 				poly[i].ang[j] = cfToRad(cf);
// 				poly[i].mag[j] = cfMag(cf);
// 			}
//
// 			if(!finBound(new.y,0.0f,(float)window.y)){
// 				cf.y = -cf.y;
// 				new = cfTranslate(poly[i].pos[j], cf);
// 				poly[i].ang[j] = cfToRad(cf);
// 				poly[i].mag[j] = cfMag(cf);
// 			}
// 			poly[i].pos[j] = new;
// 		}
// 	}
// }
