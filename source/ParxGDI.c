#include "ParxGDI.h"
#include "Parx_Pallet.h"

// the Pro-liter-riot's, Sklaven (a turned-out &or bent FSF/Open-Source) 
// [act 1, scene 1] 
// Eg. "Cash-in-Hand?", " U'r live?", "or still friends with Dr. Nelson Mandal";
//
// Citizen-Ken: 
//                We're going on a guilt trip too israil. & Do you need IT/Marketing in 3-D? 
// A-Thesis-on: 
//                Well it's comprized mostly of FreePascal & can't U c/c++ U'r time is drawing niegh 
//                 to obtain your companies, very, very own corprate, dirigible listings? 
//
//PS: Oblivious too device! & Revamped from sources listed bellow 
//
// ShinyQuagsire23 --> https://github.com/shinyquagsire23/DCPU-3DS
//& AlbertoSONIC --> https://github.com/AlbertoSONIC/3DS_Paint
//& xerpi --> https://github.com/xerpi 
//& steveice10 --> https://github.com/Steveice10/FBI
//& Lua-Player-Plus --> https://github.com/Rinnegatamante
//& smealum --> https://github.com/smealum/ctrulib

//portions revised --> Lua-Player-Plus :: Graphics.cpp :: DrawAlphaPixel
void SetPixEx(u8* screen, u16 bpp, int h, int x, int y, u32 colour)
{
//       int height=240;
       u32 v=(h-1-y+x*h)*bpp;
       u8 alpha = (((colour) >> 24) & 0xFF); //alpha 

     if (alpha == 0xFF)
      {	
        screen[v]=colour & 0xFF;         //blue
        screen[v+1]=(colour>>8) & 0xFF;  //green
        screen[v+2]=(colour>>16) & 0xFF; //red
      } 
      else 
      { //this alpha is slow, needs bitwise &= ~ re-written
//	float ratio = alpha / 255.0f;
//	screen[v] = ((colour & 0xFF) * ratio) + (screen[v] * (1.0 - ratio));               //blue
//	screen[v+1] = ((((colour) >> 8) & 0xFF) * ratio) + (screen[v+1] * (1.0 - ratio));  //green
//	screen[v+2] = ((((colour) >> 16) & 0xFF) * ratio) + (screen[v+2] * (1.0 - ratio)); //red 
	u8 b = screen[v];
	u8 g = screen[v+1];
	u8 r = screen[v+2];
	
	//lookup tables &or !float version should be faster need operands & moved to macro
	//revised --> smealum :: 3ds_hb_menu :: gfx.c :: gfxDrawSpriteAlpha
	screen[v] = (((colour & 0xFF) * alpha) + (b * (255 - alpha))) >> 8; //div 256;
	screen[v+1] = (((((colour) >> 8) & 0xFF)* alpha) + (g * (255 - alpha))) >> 8; //div 256;
	screen[v+2] = (((((colour) >> 16) & 0xFF)* alpha) + (r * (255 - alpha))) >> 8; //div 256;
        if (bpp == 4) screen[v+3] = ((colour) >> 24) & 0xFF; //set buffers alpha
      }
}

//found @ https://github.com/Lectem/3Damnesic 
#define ABGR8(r, g, b, a) ((((r)&0xFF)<<24) | (((g)&0xFF)<<16) | (((b)&0xFF)<<8) | (((a)&0xFF)<<0))
//& found //gs.h --> crtulib nintendo 3ds
//#define RGBA8(r,g,b,a) ((((r)&0xFF)<<24) | (((g)&0xFF)<<16) | (((b)&0xFF)<<8) | (((a)&0xFF)<<0))

u32 GetPixEx(u8* screen, u16 bpp, int h, int x, int y) 
{
 //       int height=240;
	u32 v=(h-1-y+x*h)*bpp;
	u32 colour =screen[v];
	colour += (screen[v+1] << 8);
	colour += (screen[v+2] << 16);
	if (bpp == 3)  // 24bit 
         colour += (0xFF << 24); 
          else colour += (screen[v+3] << 24); // 32bit using an alpha
        return colour;

//       (bytes_per_pixel(format) == 3) ? return ABGR8(screen[v],screen[v+1],screen[v+2],0xFF):
//        return ABGR8(screen[v],screen[v+1],screen[v+2],screen[v+3])
}

//todo
//LED-Memory * flick through FB[1,2,3] Vram/Cram/FSrom/sdmc buffer transfer speeds > (6 / 1.5) && old128 || new256?
int MaxWidth(u8* screen)
{ 
//top
   if (screen = (gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL) || gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL))) return 400;
//bottom
   else if (screen = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL)) return 340;
}

void ClearParx(u8* screen, u32 colour)
{ 
	int height=240;
	int width = MaxWidth(screen);
	int i, j;

	for(i=0;i<width;i++)
           for(j=0;j<height;j++)
		SetPix(screen,i,j,colour);
}

#define Dual_for(j, i, Top, Left, Width, Height, into) \
        for(i=Left;i<Width+Left;i++)  \
           for(j=Top;j<Height+Top;j++){into;}; 

//u32 transparent;
//#define SetRecRe(screen, Top, Left, Height, Width, Region) (SetRecEx(screen, Top, Left, Height, Width, Region, 1))
void SetRecEx(u8* screen, int Top, int Left, int Height, int Width, u8* Region, bool CleanUp, RamType RamLocal)
{ 
//	int CanvasWidth = MaxWidth(screen);
	int i, j;
        u32 Pixel;
	for(i=Left;i<Width+Left;i++)
           for(j=Top;j<Height+Top;j++)
		{
		Pixel = GetPix(Region,i-Left,j-Top);
		if (Pixel != transparent) SetPix(screen, i, j, Pixel);
                }

  if (CleanUp) switch(RamLocal){


       case linear: {linearFree(Region), linearSpaceFree;} break; // case vram: linearFree(Region); break; 
       case vram: {vramFree(Region), vramSpaceFree;} break; // case vram: vramFree(Region); break; 
       case mappable: {mappableFree(Region), mappableSpaceFree;} break; // added
       
//Vram's & etc, on of the places of 1.1 over-haul? Please review in tycob.h 
//Free the HDC's of engines & subsystems 

//calls
//       

// #include "TemplateFreeHDC.h"
      

//free GFX engines list who speak em pica200 needs 
//SF2D, citro3D and or other sons & daughters of the OpenGL?
       
       
      default:   free(Region); 
}

//in the begin there was --> SetPix(screen[j+Top*CanvasWidth+i+Left],i+Left,j+Top, Region[i,j])
}

u8 * GetRecEx(u8* screen, int Top, int Left, int Height, int Width, u16 bpp, RamType RamLocal)
{  
//	int CanvasWidth = MaxWidth(screen); ???
	u32 bitmapsize = Width*Height*bpp;
        u8* Region;

switch(RamLocal){
	
	
case linear: Region = (u8*)linearMemAlign(bitmapsize, 0x80);
             memset(Region, 0, bitmapsize);
             break;

case vram:   Region = (u8*)vramMemAlign(bitmapsize, 0x80);                  
             memset(Region, 0, bitmapsize);
             break;

case mappable: Region = (u8*)mappableAlloc(bitmapsize, 0x80);  //just added & untested !                
             ///memset(Region, 0, bitmapsize);  ?
             break;

//Vram's & etc, on of the places of 1.1 over-haul? Please review in tycob.h 
// #include "TemplateLoadHDC.h"
//Load & Free HDC's
//engines & subsystems 

// & portions modify --> xerpi :: libsf2d :: sf2d_texture.c :: sf2d_create_texture
//case vram:   bitmapsize = next_pow2(Width) * next_pow2(Height) * (bpp);
//             Region = (u8*)vramMemAlign(bitmapsize, 0x80); 
//             GX_SetMemoryFill(NULL, Region, 0x00000000, (u32*)&(Region)[bitmapsize], GX_FILL_TRIGGER | GX_FILL_32BIT_DEPTH,NULL, 0x00000000, NULL, 0);
//	     gspWaitForPSC0();
//             break;
//end over-hall & finacial barrier?    

default: 
	     Region = (u8*)malloc(bitmapsize);
             memset(Region, 0, bitmapsize);
}	
	int i, j;
	for(i=Left;i<Width+Left;i++)
           for(j=Top;j<Height+Top;j++)
			SetPix(Region, i-Left, j-Top, GetPix(screen,i,j));

// goal reached "section screen with out repeated getgfxframebuffer"
//	  Region[i,j] = GetCanvasPixel(screen[j+Top*CanvasWidth+i+Left],i+Left,j+Top);

	return Region;	
}

//the Pro-liter-riot's Sklaven "kennyd-lee" 
//present's "long sex-live the Pro-liter-riot, &  3 nude lcd's 1/2 of in 3-D"
//also (unmolested Citrus, GPU, GIMP, openGL &or Nanox or any & all other that "got bent Mozilla" that have endured some form of rape)?


//(Lady Zurich) 1.1  changes
// device context Handle, moved outside to new "savage" includes
// TemplateLoadHDC, TemplateFreeHDC see notes in tycob.h &or our ../DESK 
// memory mappable, savage added & generic dropt in enum
// *SetRecEx, *SpaceFree append *Free Re:memory 
