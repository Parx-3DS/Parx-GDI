#include <3ds.h>

#ifndef ParxGDI_Canvas
#include "Parx_Colours.h"
#include "Parx_Types.h"
#define ParxGDI_Canvas 
#endif

//24bit bytes_per_pixel(GSP_BGR8_OES) & 240 pixel's high as default in functions SetCanvasPixel & GetCanvasPixel 

//Utils
void ClrParx(u8* screen, u32 colour);
u8* RefParx(ParxLCD LCD);
int MaxWidth(u8* screen);

//Parx Canvas Pixel's
void SetPixEx(u8* screen, u16 bpp, int h, int x, int y, u32 colour);
#define SetPix(screen, x, y, colour) (SetPixEx(screen, 3, SCREEN_Y, x, y,colour))
u32 GetPixEx(u8* screen, u16 bpp, int h, int x, int y);
#define GetPix(screen, x, y) (GetPixEx(screen, 3, SCREEN_Y, x, y))

//Parx Canvas Rectangular Region's 
u32 SetRecEx(u8* screen, int Top, int Left, int Height, int Width, u8* Region, bool CleanUp, RamType RamLocal);
#define SetRecRe(screen, Top, Left, Height, Width, Region) (SetRecEx(screen, Top, Left, Height, Width, Region, 1, linear))

// bufferFormat 
// GSP_RGBA8_OES: 4;
// GSP_BGR8_OES: 3; 
// default: 2; 

u8 * GetRecEx(u8* screen, int Top, int Left, int Height, int Width, u16 bpp, RamType RamLocal);
#define GetRecRe(screen, Top, Left, Height, Width) (GetRecEx(screen, Top, Left, Height, Width, 3, linear))

