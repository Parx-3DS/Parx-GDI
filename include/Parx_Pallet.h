

//forked --> https://github.com/mtheall/screenshot_png
//bytes per pixel, for handling the Framebuffers pallet of colours

GSPGPU_FramebufferFormats palletformat(u8 FormatIndex);
// --> screenshot_png.c :: bytes_per_pixel
u32 bppixel(GSPGPU_FramebufferFormats format);
// --> main.c :: rgb_to_pixel
void rgb2pixel(u8 *dst, const u8 *src, GSPGPU_FramebufferFormats format);
// --> screenshot_png.c :: pixel_to_rgba
void pixel2rgba(u8 *dst, const u8 *src, GSPGPU_FramebufferFormats format);
