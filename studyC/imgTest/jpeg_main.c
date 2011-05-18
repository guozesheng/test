#include <stdio.h>
#include <jpeglib.h>
#include <jerror.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include "main.h"

extern struct fbsrc_t fb_v;

int jpeg_main(const char *img_file)
{
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;
    unsigned char *buffer;
    unsigned int y;

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
    buffer = (unsigned char *)malloc(cinfo.output_width * cinfo.output_components);

    y = 0;
    while (cinfo.output_scanline < cinfo.output_height) 
    {
        jpeg_read_scanlines(&cinfo, &buffer, 1);
        memcpy((unsigned char *)fb_v.memo + y * fb_v.w * fb_v.bpp / 8, buffer, cinfo.output_width * cinfo.output_components);
        y++;    //next scanline
    }

    // finish decompress, destroy decompress object
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);

    free(buffer);
    fclose(infile);
    munmap(fb_v.memo, fb_v.w * fb_v.h * fb_v.bpp / 8);
    return 0;
}
