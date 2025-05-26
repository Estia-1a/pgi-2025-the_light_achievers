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

void print_pixel(char *source_path, int x, int y){
    unsigned char* data = NULL;
    int width = 0, height = 0, n = 0;
    pixelRGB* pixel;

    read_image_data(source_path, &data, &width, &height, &n);

    pixel = get_pixel(data, width, height, n, x, y);

    if(pixel != NULL){
        printf("print_pixel (%d, %d): %d %d %d", x, y, pixel->R, pixel->G, pixel->B);
    }
    free_image_data(data);
}

void max_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;
 
    read_image_data(source_path, &data, &width, &height, &n);
 
    int i;
    int r_max, g_max, b_max, x_max, y_max, somme;
    int max = -1;
    

    for(i = 0; i<width*height*n; i += n){
        int pixelNum = i / n;  
        int x = pixelNum % width;
        int y = pixelNum / width;

     
        pixelRGB* pixel = get_pixel(data, width, height, n, x, y);

        somme = pixel->R + pixel->G + pixel->B;
        if (somme > max){
            max = somme;
            r_max = pixel->R;
            g_max = pixel->G;
            b_max = pixel->B;
            x_max = x;
            y_max = y;
        }
    }
 
    printf("max_pixel (%d, %d): %d, %d, %d\n", x_max, y_max, r_max, g_max, b_max);
    free_image_data(data);
}
     
void green_pixel(char *input_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;
   
    read_image_data(input_path, &data, &width, &height, &n);
 
    int size = width * height * n;
 
    for (int i = 0; i < size; i += n) {
        data[i] = 0;      
        data[i + 2] = 0;      
    }
 
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);    
}