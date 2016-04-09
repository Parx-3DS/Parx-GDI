//too be tested 

#include <3ds.h>

#define GraphicsBuffArray

#ifndef GraphicsBuffArray

#define ParxLeft *u8;
#define ParxRight *u8;
#define ParxBottom *u8;

void weald()
{ 
  ParxLeft= gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
  ParxRight= gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL);
  ParxBottom= gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL);
}  

#define GraphicsBuffArray 0

#else 

extern u8* ParxLeft[2];
extern u8* ParxRight[2];
extern u8* ParxBottom[2];

//#define ParxLeft gfxTopLeftFramebuffers;
//gfxTopRightFramebuffers *ParxRight;
//gfxBottomFramebuffers *ParxBottom;

#define GraphicsBuffArray 1

void weald()
{ 
  int i;
  for (i = 0; i > GraphicsBuffArray; i++) 
 { 
  ParxLeft[i]= gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
  ParxRight[i]= gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL);
  ParxBottom[i]= gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL);
 }
}  
 
#endif   


void reap()
{
 gfxSetDoubleBuffering(GFX_TOP, GraphicsBuffArray);
 gfxSetDoubleBuffering(GFX_BOTTOM, GraphicsBuffArray);
 weald();
} 
