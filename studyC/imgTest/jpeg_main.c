#include <stdio.h>
#include <jpeglib.h>
#include <jerror.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <time.h>
#include "main.h"

extern struct fbsrc_t fb_v;

int rgb24to32(u8_t *buf24, u32_t *buf)
{
    /* FIXME: why? */
    int i;
    for(i = 0; i < fb_v.w * fb_v.h; i++)
    {
        *((u8_t *)&buf[i] + 2) = buf24[i * 3 + 0]; 
        *((u8_t *)&buf[i] + 1) = buf24[i * 3 + 1]; 
        *((u8_t *)&buf[i] + 0) = buf24[i * 3 + 2]; 
        *((u8_t *)&buf[i] + 3) = 0x00;
    }   

    return 0;
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
    u32_t *buf = malloc(fb_v.w * fb_v.h * fb_v.bpp / 8); 
    rgb24to32(buffer, buf);

    disp_lefttoright(buf, cinfo.output_width, cinfo.output_height, 1000);
    usleep(1000000);
    memset((u32_t *)fb_v.memo, 0, fb_v.h * fb_v.w * fb_v.bpp / 8);
    usleep(100000);
    disp_uptodown(buf, cinfo.output_width, cinfo.output_height, 1000);
    usleep(1000000);
    memset((u32_t *)fb_v.memo, 0, fb_v.h * fb_v.w * fb_v.bpp / 8);
    usleep(100000);
    disp_scroll(buf, cinfo.output_width, cinfo.output_height, 10000);
    usleep(1000000);
    memset((u32_t *)fb_v.memo, 0, fb_v.h * fb_v.w * fb_v.bpp / 8);
    usleep(100000);
    disp_uptodown_line(buf, cinfo.output_width, cinfo.output_height, 10000);

    free(buf);
    // End of the TEST

    free(buffer);
    fclose(infile);
    return 0;
}

int disp_show(u32_t *buf, JDIMENSION jpeg_width, JDIMENSION jpeg_height)
{/*{{{*/
    int i, j;

    for (j = 0; j < jpeg_height; j++) 
    {
        for (i = 0; i < jpeg_width; i++) 
        {
            fb_one_pixel(i, j, buf[i + j * jpeg_width]);
        }
    }
    
    return 0;/*}}}*/
}

int disp_lefttoright(u32_t *buf, JDIMENSION jpeg_width, JDIMENSION jpeg_height, int sleeptime)
{
    int i, j;

    for (i = 0; i < jpeg_width; i++) 
    {
        for (j = 0; j < jpeg_height; j++) 
        {
            fb_one_pixel(i, j, buf[i + j * jpeg_width]);
        }
        usleep(sleeptime);
    }
    
    return 0;
}

int disp_uptodown(u32_t *buf, JDIMENSION jpeg_width, JDIMENSION jpeg_height, int sleeptime)
{/*{{{*/
    int i, j;

    for (j = 0; j < jpeg_height; j++) 
    {
        for (i = 0; i < jpeg_width; i++) 
        {
            fb_one_pixel(i, j, buf[i + j * jpeg_width]);
        }
        usleep(sleeptime);
    }
    
    return 0;/*}}}*/
}

int disp_uptodown_line(u32_t *buf, JDIMENSION jpeg_width, JDIMENSION jpeg_height, int sleeptime)
{
    int i, j, k;
    int rand_line;
    int line_bord = 3;
    int sleep_space = 10;

    srand(time(NULL));

    for (j = 0; j < jpeg_height; j++) 
    {
        rand_line = rand() % (jpeg_height - line_bord);
        for (k = 0; k < line_bord; k++) 
        {
            for (i = 0; i < jpeg_width; i++) 
            {
                fb_one_pixel(i, rand_line + k, buf[i + (rand_line + k) * jpeg_width]);
            }
        }
        if (j % sleep_space == 0) 
        {
            usleep(sleeptime);
        }
    }
    disp_show(buf, jpeg_width, jpeg_height);
    
    return 0;
}

int disp_scroll(u32_t *buf, JDIMENSION jpeg_width, JDIMENSION jpeg_height, int sleeptime)
{/*{{{*/
    int i, j;
    int times = 10;
    int k, l;

    for (i = 0; i < jpeg_width / times; i++) 
    {
        for (j = 0; j < jpeg_height / times; j++) 
        {
            for (l = 0; l < times; l += 2) 
            {
                for (k = 0; k < times; k += 2) 
                {
                    fb_one_pixel(i + jpeg_width / times * l, j + jpeg_height / times * k, buf[(i + jpeg_width / times * l) + (j + jpeg_height / times * k) * jpeg_width]);
                }
            }
            for (l = 1; l < times; l += 2) 
            {
                for (k = 1; k < times; k += 2) 
                {
                    fb_one_pixel(i + jpeg_width / times * l, j + jpeg_height / times * k, buf[(i + jpeg_width / times * l) + (j + jpeg_height / times * k) * jpeg_width]);
                }
            }
        }
        usleep(sleeptime);
    }

    for (i = 0; i < jpeg_width / times; i++) 
    {
        for (l = 0; l < times; l++) 
        {
            for (j = 0; j < jpeg_height; j++) 
            {
                fb_one_pixel(i + jpeg_width / times * l, j, buf[i + jpeg_width / times * l + j * jpeg_width]);
            }
        }
        usleep(sleeptime);
    }

    return 0;/*}}}*/
}
