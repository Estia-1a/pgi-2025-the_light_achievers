#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

 pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ){

    pixelRGB* pixel = malloc(sizeof(pixelRGB)) ;
    
    pixel->R = data[(n*width + n*x)*y] ;
    pixel->G = data[(n*width + n*x)*y + 1] ;
    pixel->B =data[(n*width + n*x)*y + 2] ;

    return pixel;
 }