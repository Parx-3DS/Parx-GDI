#include "ParxGDI.h"

void line(u8* screen, int x0, int y0, int x1, int y1, u32 colour);
void box(u8* screen, int x, int y, int w, int h, u32 colour);
//void poly(u8* screen, int *argv, int argc, u32 colour);
//void poly(u8* screen, int *argv[], int argc, u32 colour);
void poly(u8* screen, int ** argv, int argc, u32 colour);
void CircleFill(u8* screen, int xCen, int yCen, int radius, u32 colour);
void Ellipse(u8* screen, int xctr, int yctr, int majaxis, int minaxis, int rotnrad, u32 colour);
#define Circle(screen, cx, cy, radius, colour) (Ellipse(screen, cx, cy, radius, radius, 0, colour));
