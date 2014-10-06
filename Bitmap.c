/*
 * File:    Bitmap.c
 * A basic Bitmap API
 * Author:  Chris Aslanoglou
 */
#include "Bitmap.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char* bitmap_array;
struct Bitmap_Struct {
    unsigned int sizeBytes, bitsNum;
    bitmap_array bitmap;
};

// Forward declarations of not public functions
void bitmap_print_word(bitmap_t, unsigned int);

// API Functions
/**
 * Allocates the necessary memory for the bitmap
 * @param bitsNumber The number of bits to allocate
 * @return The bitmap instance on success, otherwise NULL
 */
bitmap_t bitmap_allocate(unsigned int bitsNumber)
{
    if (bitsNumber > 0) {
        bitmap_t tmp = malloc(sizeof(struct Bitmap_Struct));
        if (tmp == NULL) {
            perror("bitmap_allocate - Error: Bitmap_Struct allocation");
            return NULL;
        }
        unsigned int bytes = (bitsNumber + CHAR_BIT - 1)/ CHAR_BIT;
        tmp->bitmap = malloc(bytes*sizeof(char));
        if (tmp->bitmap == NULL) {
            perror("bitmap_allocate - Error: bitmap allocation");
            return NULL;
        }
        memset(tmp->bitmap, 0, bytes);
        tmp->sizeBytes = bytes;
        tmp->bitsNum = bitsNumber;
        return tmp;
    }
    else {
        fprintf(stderr, "bitmap_allocate - Error: Size must be > 0\n");
        return NULL;
    }
}

/**
 * Frees up all the allocated memory and
 * invalidates the pointer
 * @param bptr The pointer to the bitmap instance
 */
void bitmap_destroy(bitmap_t* bptr) 
{
    free((*bptr)->bitmap);
    (*bptr)->bitmap = NULL;
    (*bptr)->bitsNum = -1;
    (*bptr)->sizeBytes = -1;
    free(*bptr);
    *bptr = NULL;
    return;
}

/**
 * Function enabling the i-th bit into the bitmap
 * @param b The bitmap object
 * @param i The index of bit to be set to one (starting from 0)
 */
void bitmap_setbit(bitmap_t b, unsigned int i)
{
    // (i / CHAR_BIT) will return the idx of the bitmap array
    // (i & (CHAR_BIT -1) ) acts as modulo operation
    if (i >= b->bitsNum) {
        fprintf(stderr, "bitmap_setbit - Error: index out of bounds\n"
                "(have %d)\n", b->bitsNum);
        return;
    }
    (b->bitmap)[i/CHAR_BIT] |= 1 << (i & (CHAR_BIT - 1));
}


/**
 * Function for disabling the i-th bit into the bitmap
 * @param b The bitmap object
 * @param i The index of bit to be set to zero (starting from 0)
 */
void bitmap_unsetbit(bitmap_t b, unsigned int i)
{
    if (i >= b->bitsNum) {
        fprintf(stderr, "bitmap_unsetbit - Error: index out of bounds "
                "(have %d)\n", b->bitsNum);
        return;
    }
    (b->bitmap)[i/CHAR_BIT] &= ~(1 << (i & (CHAR_BIT - 1)));
}

/**
 * Function returning the 1st, 2nd, etc.. bits
 * @param b The bitmap object
 * @param i The index of the bit to return (Caution: i starts from 1)
 * 
 * @return 
 *      The bit requested on success, otherwise 0
 */
unsigned int bitmap_getbit(bitmap_t b, unsigned int i)
{
    if (i > b->bitsNum) {
        fprintf(stderr, "bitmap_getbit - Error: index out of bounds\n"
                "(have %d)\n", b->bitsNum);
        return 0;
    }
    return (b->bitmap[i/CHAR_BIT] & (i & (CHAR_BIT - 1))) ? 1 : 0;
}

/*
 * Function responsible for checking if all bits or chechBits bits are set
 * @param b (bitmap_t)
 *      The bitmap
 * @param checkBits (unsigned int)
 *      The number of bits to check, if this is equal to 0, then all the bits
 *      will be checked
 * @return 
 *      True (1) or False (0) will be returned
 */
unsigned int bitmap_alltrue(bitmap_t b, unsigned int checkBits)
{
    unsigned int i, count = 0, bytes_num = 0, bits_num = 0;
    // find the max number that can be represented 
    // with (bits_requested / CHAR_BITS)
    unsigned int max_num_bits = 0;
    if (checkBits == 0)
        max_num_bits = (2 << ((b->bitsNum & (CHAR_BIT - 1)) - 1)) - 1;
    else
        max_num_bits = (2 << ((checkBits & (CHAR_BIT - 1)) - 1)) - 1;
    // find the max number that can be represented from a byte (char)
    unsigned int max_num_bytes = (2 << (CHAR_BIT - 1)) - 1;
    for (i = 0; i < b->sizeBytes; i++) {
        if (i == (b->sizeBytes - 1)) {
            // probably not all bits of the last byte are used
            bits_num = ((b->bitmap)[i] == max_num_bits) ? 1 : 0;
            if (b->sizeBytes == 1)
                return bits_num;
        }
        else
            count += (b->bitmap)[i];
    }
    unsigned int max_sum_num = (b->sizeBytes - 1) * max_num_bytes;
    bytes_num = (count == max_sum_num) ? 1 : 0;
    return (bytes_num & bits_num) ? 1 : 0;
}


/**
 * Prints the bitmap in binary form 
 * (1st, 2nd, etc.. bits are from left to right)
 * @param b The bitmap to be printed
 */
void bitmap_print(bitmap_t b)
{
    unsigned int i;
    for (i = 0; i < b->sizeBytes; i++) {
        bitmap_print_word(b, i);
    }
}

/*
 * Used for printing the bitmap 
 * API private method
 */
void bitmap_print_word(bitmap_t b, unsigned int word)
{
    char str[9] = {0};
    int i;
    int num = (b->bitmap)[word];
    for (i = 7; i >= 0; i--) {
        str[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    printf("%s\n", str);
}


