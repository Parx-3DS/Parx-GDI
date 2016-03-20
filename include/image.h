#include <3ds.h>

typedef struct
{
	u16 width, height;
	u8* data;
	u8 depth;
	bool used;
}imagebuff;
