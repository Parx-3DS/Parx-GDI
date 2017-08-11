

case linear: Region = (u8*)linearMemAlign(bitmapsize, 0x80);
             memset(Region, 0, bitmapsize);
             break;

//engines & subsystems 
//Vram's & etc, on of the places of 1.1 over-haul? 
//Please review in tycob.h & have a look on your Three-DS, Computer ../DESK? 

//#include "cpp3ds_LoadHDC.h"
//#include "citrus_LoadHDC.h"

//#include "SD2D_LoadHDC.h"
//#include "Citro3D_LoadHDC.h"
//#include "Caelina_LoadHDC.h"

//Load & Free HDC's
//case vram:   bitmapsize = next_pow2(Width) * next_pow2(Height) * (bpp);
//             Region = (u8*)vramMemAlign(bitmapsize, 0x80); 
//             GX_SetMemoryFill(NULL, Region, 0x00000000, (u32*)&(Region)[bitmapsize], GX_FILL_TRIGGER | GX_FILL_32BIT_DEPTH,NULL, 0x00000000, NULL, 0);
//	     gspWaitForPSC0();
//             break;
//end over-hall & finacial barrier?    

default: 
	     Region = (u8*)malloc(bitmapsize);
             memset(Region, 0, bitmapsize);
