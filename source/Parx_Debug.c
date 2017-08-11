#include "parx/Parx_Debug.h"

void DebugTo(u8* screen, int x, int y, u32 colour, const char* str,...)
{
    char* formated[256];
    va_list ap;
    va_start(ap, str);
    snprintf(formated, 256, str, ap);
    //sprintf(formated, str, ap);
    va_end(ap);
    CanvasString(screen, formated, x, y, colour);
//    gfxFlushBuffers();
}