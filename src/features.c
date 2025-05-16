#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension(const char* source_path) {    
    unsigned char* data = NULL;
    int width = 0, height = 0, n = 0;

    read_image_data(source_path, &data, &width, &height, &n);

    printf("dimension : %d, %d \n", width, height);

    free_image_data(data);
}

void first_pixel(char *source_path) {
    unsigned char* data = NULL;
    int width = 0, height = 0, n = 0;

    read_image_data(source_path, &data, &width, &height, &n);

    printf("first_pixel: %d %d %d",data[0],data[1],data[2] );

    free_image_data(data);
}

void tenth_pixel(char *source_path) {
    unsigned char* data = NULL;
    int width = 0, height = 0, n = 0;

    read_image_data(source_path, &data, &width, &height, &n);

    printf("tenth_pixel: %d %d %d",data[27],data[28],data[29] );

    free_image_data(data);
}

void second_line(char *source_path) {
    unsigned char* data = NULL;
    int width = 0, height = 0, n = 0;

    read_image_data(source_path, &data, &width, &height, &n);

    int index = width*n ;

    printf("second_line: %d %d %d", data[index], data[index+1], data[index+2]);

    free_image_data(data);
}

void print_pixel1(char *source_path, int x, int y){
    unsigned char* data = NULL;
    int width = 0, height = 0, n = 0;

    read_image_data(source_path, &data, &width, &height, &n);

    int index = (y*width + x)*n ;

    printf("print_pixel (%d, %d): %d %d %d", x, y, data[index], data[index+1], data[index+2]);

    free_image_data(data);
}

void print_pixel2(char *source_path, int x, int y){
    unsigned char* data = NULL;
    int width = 0, height = 0, n = 0;

    read_image_data(source_path, &data, &width, &height, &n);

    pixelRGB* pixel = get_pixel(data, width, height, n, x, y);

    printf("print_pixel (%d, %d): %d %d %d", x, y, pixel->R, pixel->G, pixel->B);
}

void max_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channels = 0;
 
    read_image_data(source_path, &data, &width, &height, &channels);
    int x, y, r, g, b, somme, index;
    int max_x = 0, max_y = 0, max_r = 0, max_g = 0, max_b = 0, max_somme = 0;
 
    for ( y = 0; y < height; y++) {
        for ( x = 0; x < width; x++) {
            index = (y * width + x) * channels;
            r = data[index];
            g = data[index + 1];
            b = data[index + 2];
            somme = r + g + b;
            if (somme > max_somme) {
                max_somme = somme;
                max_x = x;
                max_y = y;
                max_r = r;
                max_g = g;
                max_b = b;
            }
        }
    }
    printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_r, max_g, max_b);
    free_image_data(data);
}