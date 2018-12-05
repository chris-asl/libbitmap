LibBitMap 
==========

A basic bitmap library in C.  

The Bitmap is represented in a `bitmap_t`, that is a pointer to a Bitmap_Struct.  
I've included a demo client file *demo.c*, for a quick-start.

All the methods are documented in the `Bitmap.c` file.  
Bellow I'll mention only the method names of the ones that are offered.  

**Methods offered**

    1. bitmap_allocate
    2. bitmap_destroy
    3. bitmap_setbit
    4. bitmap_unsetbit
    5. bitmap_getbit
    6. bitmap_alltrue
    7. bitmap_print
