#include <stdio.h>
#include <jpeglib.h>
#include <jerror.h>
#include <stdlib.h>
#include "main.h"

extern struct fbsrc_t fb_v;

int jpeg_main(char *img_file)
{
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;
    unsigned char *buffer;

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

    free(buffer);
    fclose(infile);
    return 0;
}
