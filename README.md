# 3DS-Sails  
Canvas & ... for Nintendo 3ds platform  

Pixil usage/demo

	screenTopLeft = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL); 
	screenTopRight = gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL); 

//test pattern 1st pass  
for (i = 0; i < 79; ++i)  
 for (j = 0; j < 200; ++j)  
	{  
        SetCanvasPixel(screenTopLeft,i,j,RED);  
                                SetCanvasPixel(screenTopRight,i,j,RED);  
                                SetCanvasPixel(screenTopLeft,i+80,j,CYAN);  
                                SetCanvasPixel(screenTopRight,i+80,j,CYAN);  
                                SetCanvasPixel(screenTopLeft,i+160,j,YELLOW);  
                                SetCanvasPixel(screenTopRight,i+160,j,YELLOW);  
                                SetCanvasPixel(screenTopLeft,i+240,j,BLACK);  
                                SetCanvasPixel(screenTopRight,i+240,j,BLACK);  
                                SetCanvasPixel(screenTopLeft,i+320,j,BLUE);  
                                SetCanvasPixel(screenTopRight,i+320,j,BLUE);  
				};  
//test pattern 2nd pass   
for (i = 0; i < 99; ++i)  
 for (j = 201; j < 239; ++j)  
	{  
                                SetCanvasPixel(screenTopLeft,i,j,PINK);  
                                SetCanvasPixel(screenTopRight,i,j,PINK);  
                                SetCanvasPixel(screenTopLeft,i+100,j,LIGHT_GREEN);  
                                SetCanvasPixel(screenTopRight,i+100,j,LIGHT_GREEN);  
                                SetCanvasPixel(screenTopLeft,i+200,j,WHITE);  
                                SetCanvasPixel(screenTopRight,i+200,j,WHITE);  
                                SetCanvasPixel(screenTopLeft,i+300,j,ORANGE);  
                                SetCanvasPixel(screenTopRight,i+300,j,ORANGE);  
				}  

				gfxFlushBuffers();
				//gfxSwapBuffers();

--> https://www.facebook.com/1596037147331761/photos/a.1629176367351172.1073741828.1596037147331761/1636255289976613/?type=1&theater

Pixil usage/demo II  
   switch(GetCanvasPixel(screenTopLeft,x,y))  
  {   
 	case RED: text_print(screenBottom, "Sampled a RED",100,120); break;  
	case GREEN: text_print(screenBottom, "Sampled a GREEN",100,120); break;  
 	case BLUE: text_print(screenBottom, "Sampled a BLUE",100,120); break;  
 	case CYAN: text_print(screenBottom, "Sampled a CYAN",100,120); break;  
 	case PINK: text_print(screenBottom, "Sampled a PINK",100,120); break;  
 	case YELLOW: text_print(screenBottom, "Sampled a YELLOW",100,120); break;  
 	case BLACK: text_print(screenBottom, "Sampled a BLACK",100,120); break;  
 	case WHITE: text_print(screenBottom, "Sampled a WHITE",100,120); break;   
 	case ORANGE: text_print(screenBottom, "Sampled a ORANGE",100,120); break;  
 	case LIGHT_GREEN: text_print(screenBottom, "Sampled a LIGHT GREEN",100,120); break;   
 	case PURPLE: text_print(screenBottom, "Sampled a PURPLE",100,120); break;  
	default:   
                ClearCanvas(screenBottom, BLACK);  
		break;  
  }  
  
//Primitive's usage/demo  
//Cracker; and the world is full of them; want a polygon?  

  				line(screenTopLeft, 0, 239, 399, 0, PINK);  
			  	line(screenTopRight, 0, 0, 399, 239, PINK);  
				Circle(screenTopLeft, 50, 50, 10, BLUE);  
				Circle(screenTopRight, 349, 50, 10, BLUE);  
				Ellipse(screenTopLeft, 50, 150, 20, 10, GREEN);  
				Ellipse(screenTopRight, 349, 150, 20, 10, GREEN);  

				gfxFlushBuffers();  

-->https://www.facebook.com/1596037147331761/photos/a.1629176367351172.1073741828.1596037147331761/1636836319918510/?type=1&theater
