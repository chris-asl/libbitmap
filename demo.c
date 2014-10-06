/*
 * File:    demo.c
 * Purpose: Used as a demonstration of the Bitmap API
 * Author: Chris Aslanoglou
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Bitmap.h"
#include <limits.h>

void print_result(int);

int main(void)
{
    bitmap_t bitmap = bitmap_allocate(6);
    if (bitmap == NULL)
        exit(EXIT_FAILURE);

    int i;
    for (i = 0; i < 3; i++) {
        bitmap_setbit(bitmap, i);
    }
    
    // Check up to 3 digits
    print_result(bitmap_alltrue(bitmap, 3));
    
    // Check up all digits
    print_result(bitmap_alltrue(bitmap, 0));

    bitmap_print(bitmap);
    
    bitmap_destroy(&bitmap);
    return (EXIT_SUCCESS);
}

void print_result(int result) {
    if (result)
        printf("Bitmap is enabled\n");
    else
        printf("Bitmap is disabled\n");
}

