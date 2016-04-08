//forked --> https://github.com/linoma/fb43ds/blob/master/source/gfxDraw.c

#define BLEND_PIXEL(p,sa,da,r,g,b)\
	p[0] = (p[0] * sa + b * da) >> 8;\
	p[1] = (p[1] * sa + g * da) >> 8;\
	p[2] = (p[2] * sa + r * da) >> 8;

void GradientFillRect(rect *prc,int radius,int mode,u32 s_col,u32 e_col,u8 *screen);
void FillRoundRect(rect * prc, int radius,u32 b_col,u32 f_col, u8* screen);
void RoundRectShadow(rect * prc, int radius,u32 col,int length, u8* screen);
void FillRect(rect * prc, u32 col, u8* screen);
void FloodFill(int x0, int y0, u32 fillColor, u32 interiorColor,u8 *screen);
