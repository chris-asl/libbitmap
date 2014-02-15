/*
 * File:   Bitmap.h
 * Author: chris
 *
 * Created on February 14, 2014, 3:13 PM
 */

#ifndef BITMAP_H
#define	BITMAP_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct Bitmap_Struct* bitmap_t;

    bitmap_t bitmap_allocate(unsigned int);
    void bitmap_destroy(bitmap_t*);
    void bitmap_setbit(bitmap_t, unsigned int);
    void bitmap_unsetbit(bitmap_t, unsigned int);
    unsigned int bitmap_getbit(bitmap_t, unsigned int);
    unsigned int bitmap_alltrue(bitmap_t);
    void bitmap_print_word(bitmap_t, unsigned int);



#ifdef	__cplusplus
}
#endif

#endif	/* BITMAP_H */

