#include "Parx_Buffer.h"

void lineSample(u8* screen, int x0, int y0, int x1, int y1, u8* buffer) {
  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;
 
  for(;;){
    SetPix(buffer,x0,y0,GetPix(screen,x0,y0));
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

//pillaged --> http://www.uwgb.edu/dutchs/Geometry/HTMLCanvas/ObliqueEllipses5.HTM
void EllipseSample(u8* screen, int xctr, int yctr, int majaxis, int minaxis, int rotnrad, int Axis, u8* buffer){
	//Draw ellipse of arbitrary orientation
	float t = 0; //Parametric equation variable
	int x0 = xctr + majaxis*cos(rotnrad);// initial x-val
	int y0 = yctr - majaxis*sin(rotnrad);// initial y-val
	int x1 = x0;// final x-val
	int y1 = y0;// final y-val
		
	for (t=0; t <= 6.3; t = t + 0.1)
	{
	x0=x1;
	y0=y1;
	x1= xctr + majaxis*cos(t)*cos(rotnrad) - minaxis*sin(t)*sin(rotnrad);
	y1= yctr - majaxis*cos(t)*sin(rotnrad) - minaxis*sin(t)*cos(rotnrad);
	lineSample (screen,x0,y0,x1,y1,buffer);
	}//close for loop
	
	//Draw Cartesian Axes
         if (Axis != 0) { 
	lineSample(screen,0,yctr,2*xctr,yctr,buffer);
	lineSample(screen,xctr,0,xctr,2*yctr,buffer);

	//Draw Major and Minor Axes
	lineSample(screen,xctr+majaxis*cos(rotnrad),yctr-majaxis*sin(rotnrad),xctr-majaxis*cos(rotnrad),yctr+majaxis*sin(rotnrad),buffer);
	lineSample(screen,xctr+minaxis*sin(rotnrad),yctr+minaxis*cos(rotnrad),xctr-minaxis*sin(rotnrad),yctr-minaxis*cos(rotnrad),buffer);
         }
}//close Ellipse()
