#include <stdio.h>
#include <jpeglib.h>
#include <jerror.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include "main.h"

extern struct fbsrc_t fb_v;

u32_t * rgb24to32(u8_t *buf24)
{
    u32_t *buf = malloc(fb_v.w * fb_v.h * fb_v.bpp / 8); 
    if (buf == NULL) return NULL;

    /* FIXME: why? */
    int i;
    for(i = 0; i < fb_v.w * fb_v.h; i++)
    {
        *((u8_t *)&buf[i] + 2) = buf24[i * 3 + 0]; 
        *((u8_t *)&buf[i] + 1) = buf24[i * 3 + 1]; 
        *((u8_t *)&buf[i] + 0) = buf24[i * 3 + 2]; 
        *((u8_t *)&buf[i] + 3) = 0x00;
    }   

    return (u32_t *)buf;
}

int jpeg_main(const char *img_file)
{
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;
    u8_t *buffer;
    unsigned int y;
    register JSAMPARRAY lineBuf;

    // open jpeg file
    if ((infile = fopen(img_file, "rb")) == NULL)
    {
        perror("img open");
        exit(1);
    }

    // init jpeg decompress object error handler
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);

    // bind jpeg decompress object to infile
    jpeg_stdio_src(&cinfo, infile);

    // read jpeg header
    jpeg_read_header(&cinfo, TRUE);

    /*
     * decompress process.
     * note: after jpeg_start_decompress() is called.
     * the dimension infomation will be known
     * so allocate memory buffer for scanline immediately
     */
    jpeg_start_decompress(&cinfo);
    if ((cinfo.output_width > fb_v.w) || (cinfo.output_height > fb_v.h)) 
    {
        printf("Too large JPEG file, cannot display\n");
        exit(1);
    }
    lineBuf = cinfo.mem->alloc_sarray ((j_common_ptr) &cinfo, JPOOL_IMAGE, (cinfo.output_width * cinfo.output_components), 1);
    buffer = (unsigned char *)malloc(3 * cinfo.output_width * cinfo.output_height);
    if (buffer == NULL) 
    {
        perror("buffer");
        exit(1);
    }

    if (cinfo.output_components == 3) 
    {
        for (y = 0; y < cinfo.output_height; y++) 
        {
            jpeg_read_scanlines(&cinfo, lineBuf, 1);
            memcpy((buffer + y * cinfo.output_width * 3), lineBuf[0], 3 * cinfo.output_width);
        }
    }

    // finish decompress, destroy decompress object
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);

    // the flow is only for TEST
    u32_t *buf32 = rgb24to32(buffer);
    int i, j;
    for(i = 0; i < cinfo.output_height; i++)
    {
        for (j = 0; j < cinfo.output_width; j++)
        {
            fb_one_pixel(j, i, buf32[j + i * cinfo.output_width]);
        }   
        usleep(10000);
    }

    // End of the TEST

    free(buffer);
    fclose(infile);
    munmap(fb_v.memo, fb_v.w * fb_v.h * fb_v.bpp / 8);
    return 0;
}
