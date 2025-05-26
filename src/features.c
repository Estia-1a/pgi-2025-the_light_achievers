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

    printf("first_pixel: %d, %d, %d",data[0],data[1],data[2] );

    free_image_data(data);
}

void tenth_pixel(char *source_path) {
    unsigned char* data = NULL;
    int width = 0, height = 0, n = 0;

    read_image_data(source_path, &data, &width, &height, &n);

    printf("tenth_pixel: %d, %d, %d",data[27],data[28],data[29] );

    free_image_data(data);
}

void second_line(char *source_path) {
    unsigned char* data = NULL;
    int width = 0, height = 0, n = 0;

    read_image_data(source_path, &data, &width, &height, &n);

    int index = width*n ;

    printf("second_line: %d, %d, %d", data[index], data[index+1], data[index+2]);

    free_image_data(data);
}

void print_pixel(char *source_path, int x, int y){
    unsigned char* data = NULL;
    int width = 0, height = 0, n = 0;
    pixelRGB* pixel;

    read_image_data(source_path, &data, &width, &height, &n);

    pixel = get_pixel(data, width, height, n, x, y);

    if(pixel != NULL){
        printf("print_pixel (%d, %d): %d, %d, %d", x, y, pixel->R, pixel->G, pixel->B);
    }
    free_image_data(data);
}

void max_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;
 
    if (read_image_data(source_path, &data, &width, &height, &n) == 0) {
        printf("Error with %s\n", source_path);
        return;
    }
   
    int max = -1, max_x = -1, max_y = -1, max_r = -1, max_g = -1, max_b = -1;
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, n, x, y);
            int sum = pixel->R + pixel->G + pixel->B;
            if (sum > max) {
                max = sum;
                max_x = x;
                max_y = y;
                max_r = pixel->R;
                max_g = pixel->G;
                max_b = pixel->B;
            }
        }
    }
 
    printf("max_pixel (%d,%d) : %d, %d, %d\n", max_x, max_y, max_r, max_g, max_b);
 
 
    //printf("max_pixel (%d, %d): %d, %d, %d\n", x_max, y_max, r_max, g_max, b_max);
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

void blue_pixel(char *input_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;
   
    read_image_data(input_path, &data, &width, &height, &n);
 
    int size = width * height * n;
 
    for (int i = 0; i < size; i += n) {
        data[i] = 0;      
        data[i + 1] = 0;      
    }
 
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);    
}

void red_pixel(char *input_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;
   
    read_image_data(input_path, &data, &width, &height, &n);
 
    int size = width * height * n;
 
    for (int i = 0; i < size; i += n) {
        data[i+1] = 0;      
        data[i+2] = 0;      
    }
 
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);    
}

void gray_pixel(char *input_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;
    int gray;
   
    read_image_data(input_path, &data, &width, &height, &n);
 
    int size = width * height * n;
 
    for (int i = 0; i < size; i += n) {
        gray = (data[i] + data[i+1] + data[i+2]) / 3;
        data[i] = gray;      
        data[i + 1] = gray; 
        data[i + 2] = gray;      
    }
 
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);    
}

void invert_pixel(char *input_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;
   
    read_image_data(input_path, &data, &width, &height, &n);
 
    int size = width * height * n;
 
    for (int i = 0; i < size; i += n) {
        data[i] = 255 - data[i];
        data[i+1] = 255 - data[i+1];      
        data[i+2] = 255 - data[i+2];      
    }
 
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);    
}

void color_gray_luminance(char *input_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;
    int gray;
   
    read_image_data(input_path, &data, &width, &height, &n);
 
    int size = width * height * n;
 
    for (int i = 0; i < size; i += n) {
        gray = (data[i]*0.21 + data[i+1]*0.72 + data[i+2]*0.07);
        data[i] = gray;      
        data[i + 1] = gray; 
        data[i + 2] = gray;      
    }
 
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);    
}

void rotate_cw(char *input_path) {
    char *data = NULL;
    int width = 0, height = 0, n = 0;

    read_image_data(input_path, &data, &width, &height, &n);

    int new_width = height;
    int new_height = width;
    int size = width * height * n;

    char *rotated_data = malloc(size);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * n;
            int rota_x = height - 1 - y;
            int rota_y = x;
            int rota_index = (rota_y * new_width + rota_x) * n;

            for (int i = 0; i < n; i++) {
                rotated_data[rota_index + i] = data[index + i];
            }
        }
    }

    write_image_data("image_out.bmp", rotated_data, new_width, new_height);
    free_image_data(data);
    free_image_data(rotated_data);
}

void rotate_acw(char *input_path) {
    char *data = NULL;
    int width = 0, height = 0, n = 0;

    read_image_data(input_path, &data, &width, &height, &n);

    int new_width = height;
    int new_height = width;
    int size = width * height * n;

    char *rotated_data = malloc(size);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * n;
            int rota_x = y;
            int rota_y = height - 1 - x;
            int rota_index = (rota_y * new_width + rota_x) * n;

            for (int i = 0; i < n; i++) {
                rotated_data[rota_index + i] = data[index + i];
            }
        }
    }

    write_image_data("image_out.bmp", rotated_data, new_width, new_height);
    free_image_data(data);
    free_image_data(rotated_data);
}