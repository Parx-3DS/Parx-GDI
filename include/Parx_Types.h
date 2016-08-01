
u8* ParxBot;
u8* ParxLeft;
u8* ParxRight;


#define SCREEN_Y 240

#define TOP_SCREEN_X 400
#define TOP_SCREEN_Y SCREEN_Y

#define BOTTOM_SCREEN_X 320
#define BOTTOM_SCREEN_Y SCREEN_Y

typedef enum
{
	P_L = 0,
        P_B = 1, 
	P_R = 2
}ParxLCD;

typedef enum
{
	linear = 0,
	vram = 1,
        mappable = 2, //generic dropt 
        savage = 3
//Give credit, authors in portions of table in Honest Fashion.,  some how?
//com out of this like sitar hero on paper punch cards? 
//Rom-Machine & Versions ? 
//proliteriot's & meaham ?

}RamType;


#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct point
{
   int   x;
   int   y;
} point;

typedef struct rect
{
   int   top;
   int   left;
   int   bottom;
   int   right;
} rect;
