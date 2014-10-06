/*
 * File:    Bitmap.h
 * A basic Bitmap API (header)
 * Author:  Chris Aslanoglou
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
    unsigned int bitmap_alltrue(bitmap_t, unsigned int);
    void bitmap_print(bitmap_t);



#ifdef	__cplusplus
}
#endif

#endif	/* BITMAP_H */

