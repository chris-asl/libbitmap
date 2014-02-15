/*
 * File:   main.c
 * Author: chris
 *
 * Created on February 14, 2014, 3:13 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Bitmap.h"
#include <limits.h>
/*
 *
 */
int main(int argc, char** argv)
{
    bitmap_t bitmap = bitmap_allocate(10);
    if (bitmap == NULL)
        exit(EXIT_FAILURE);

    int i;
    for (i = 0; i < 10; i++) {
        bitmap_setbit(bitmap, i);
    }
    
    if (bitmap_alltrue(bitmap)){
        printf("bitmap is enabled\n");
    }
    bitmap_destroy(&bitmap);
    return (EXIT_SUCCESS);
}

