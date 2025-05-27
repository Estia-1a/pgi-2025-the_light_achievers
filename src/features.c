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

    free_image_data(data);
}

void min_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;
 
    if (read_image_data(source_path, &data, &width, &height, &n) == 0) {
        printf("Error with %s\n", source_path);
        return;
    }
   
    int min = 256*3+1, min_x = 0, min_y = 0, min_r = 0, min_g = 0, min_b = 0;
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, n, x, y);
            int sum = pixel->R + pixel->G + pixel->B;
            if (sum < min) {
                min = sum;
                min_x = x;
                min_y = y;
                min_r = pixel->R;
                min_g = pixel->G;
                min_b = pixel->B;
            }
        }
    }
 
    printf("min_pixel (%d,%d) : %d, %d, %d\n", min_x, min_y, min_r, min_g, min_b);
   
    free_image_data(data);
}

void max_component(char *source_path, char component) {
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;
 
    if (read_image_data(source_path, &data, &width, &height, &n) == 0) {
        printf("Error with %s\n", source_path);
        return;
    }
   
    int max = -1, max_x = -1, max_y = -1, max_r = -1, max_g = -1, max_b = -1, max_value = -1;
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB* pixel = get_pixel(data, width, height, n, x, y);
            int value = 0;

            if (component == 'R') {
                value = pixel->R;
            } else if (component == 'G') {
                value = pixel->G;
            } else if (component == 'B') {
                value = pixel->B;
            } else {
                printf("Invalid component: %c. Use R, G or B.\n", component);
                free_image_data(data);
                return;
            }

            if (value > max_value) {
                max_value = value;
                max_x = x;
                max_y = y;
            }
        }
    }

    printf("max_component %c (%d,%d): %d\n", component, max_x, max_y, max_value);

    free_image_data(data);
}

void color_green(char *input_path) {
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

void color_blue(char *input_path) {
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

void color_red(char *input_path) {
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

void color_gray(char *input_path) {
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

void mirror_horizontal(char *input_path) {
    char *data = NULL;
    int width = 0, height = 0, n = 0;

    read_image_data(input_path, &data, &width, &height, &n);

    int size = width * height * n;
    char *mirrored_data = malloc(size);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * n;
            int mir_index = (y * width + (width - 1 - x)) * n;

            for (int i = 0; i < n; i++) {
                mirrored_data[mir_index + i] = data[index + i];
            }
        }
    }

    write_image_data("image_out.bmp", mirrored_data, width, height);
    free_image_data(data);
    free_image_data(mirrored_data);
}

void mirror_vertical(char *input_path) {
    char *data = NULL;
    int width = 0, height = 0, n = 0;
 
    read_image_data(input_path, &data, &width, &height, &n);
 
    int size = width * height * n;
    char *mirrored_data = malloc(size);
 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_index = (y * width + x) * n;
            int dest_y = height - 1 - y;
            int dest_index = (dest_y * width + x) * n;
 
            for (int i = 0; i < n; i++) {
                mirrored_data[dest_index + i] = data[src_index + i];
            }
        }
    }
 
    write_image_data("image_out.bmp", mirrored_data, width, height);
 
    free_image_data(data);
    free_image_data(mirrored_data);
}

void mirror_total(char *source_input){
    mirror_horizontal(source_input);
    mirror_vertical("image_out.bmp");
}

void color_desaturate(char *input_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;

    read_image_data(input_path, &data, &width, &height, &n);

    int size = width * height * n;

    for (int i = 0; i < size; i += n) {
        int r = data[i];
        int g = data[i + 1];
        int b = data[i + 2];

        int min;

        if (r < g) {
            if (r < b)
                min = r;
            else
                min = b;
        } else {
        if (g < b)
            min = g;
         else
            min = b;
}
    int max;

    if (r > g) {
        if (r > b)
            max = r;
        else
            max = b;
    } else {
        if (g > b)
            max = g;
        else
            max = b;
    }

        int new_val = (min + max) / 2;

        data[i] = new_val;
        data[i + 1] = new_val;
        data[i + 2] = new_val;
    }

    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}
