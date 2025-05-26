#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

 pixelRGB* get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ){

   if(data == NULL){
      return NULL;
   }

   if(x>=width || y>=height){
      return NULL;
   }

   else{
      pixelRGB* pixel = malloc(sizeof(pixelRGB)) ;
      
      pixel->R = data[(y * width + x) * n] ;
      pixel->G = data[(y * width + x) * n+ 1] ;
      pixel->B =data[(y * width + x) * n + 2] ;
   
      return pixel;
   }
 }