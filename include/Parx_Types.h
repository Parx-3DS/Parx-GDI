
u8* ParxBottom;
u8* ParxTopLeft;
u8* ParxTopRight;

#define TOP_SCREEN_X 400
#define TOP_SCREEN_Y 240

#define BOTTOM_SCREEN_X 320
#define BOTTOM_SCREEN_Y 240

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


typedef enum
{
        generic = 0,
	linear = 1,
	vram = 2 
}RamType;

typedef struct point
{
   int   x;
   int   y;
} point;

typedef struct rect
{
   int   x;
   int   y;
   int   h;
   int   w;
} rect;