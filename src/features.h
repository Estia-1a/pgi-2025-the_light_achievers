#include <stdio.h>

#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();
void dimension(const char*);
void first_pixel(char*);
void tenth_pixel(char *);
void second_line(char*);
void print_pixel(char *, int, int);
void max_pixel(char *, FILE*);
void min_pixel(char *, FILE*);
void max_component(char *, char, FILE*);
void min_component(char *, char, FILE*);
void color_green(char*);
void color_blue(char*);
void color_red(char*);
void color_gray(char*);
void color_invert(char*);
void color_gray_luminance(char*);
void rotate_cw(char*);
void rotate_acw(char*);
void mirror_horizontal(char*);
void mirror_vertical(char *);
void mirror_total(char *);
void color_desaturate(char *);
void scale_crop(char *, int, int, int, int);
void scale_nearest(char *, float);
void scale_bilinear(char *, float);
void stat_report(char *);

#endif