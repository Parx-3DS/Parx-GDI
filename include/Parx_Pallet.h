

//forked --> https://github.com/mtheall/screenshot_png
//bytes per pixel, for handling the Framebuffers pallet of colours

// --> screenshot_png.c :: bytes_per_pixel
u32 bytes_per_pixel(GSPGPU_FramebufferFormats format);
// --> main.c :: rgb_to_pixel
void rgb_to_pixel(u8 *dst, const u8 *src, GSPGPU_FramebufferFormats format);
// --> screenshot_png.c :: pixel_to_rgba
void pixel_to_rgba(u8 *dst, const u8 *src, GSPGPU_FramebufferFormats format);