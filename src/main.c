#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
  /*To use debug mode: 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or 
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld 
   */
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  } 

  else if ( strcmp( configuration.command, "dimension") == 0 ) {
    /* dimension() function is defined in feature.h and implemented in feature.c */
    dimension(configuration.filenames[0]);
  } 

  else if ( strncmp( configuration.command, "first_pixel", 11 ) == 0 ) {
    /* first_pixel() function is defined in feature.h and implemented in feature.c */
    first_pixel(configuration.filenames[0]);
  } 

  else if ( strncmp( configuration.command, "tenth_pixel", 11 ) == 0 ) {
    /* tenth_pixel() function is defined in feature.h and implemented in feature.c */
    tenth_pixel(configuration.filenames[0]);
  }

  else if ( strncmp( configuration.command, "second_line", 11 ) == 0 ) {
    /* second_line() function is defined in feature.h and implemented in feature.c */
    second_line(configuration.filenames[0]);
  }

  else if ( strncmp( configuration.command, "print_pixel", 11 ) == 0 ) {
    /* print_pixel() function is defined in feature.h and implemented in feature.c */
    int x = atoi(configuration.arguments[0]);
    int y = atoi(configuration.arguments[1]);
    print_pixel(configuration.filenames[0], x, y);
  }
   
  else if ( strncmp( configuration.command, "max_pixel", 11 ) == 0 ) {
    /* max_pixel() function is defined in feature.h and implemented in feature.c */
    max_pixel(configuration.filenames[0]);
  }

  else if ( strncmp( configuration.command, "green_pixel", 11 ) == 0 ) {
    /* green_pixel() function is defined in feature.h and implemented in feature.c */
    green_pixel(configuration.filenames[0]);
  }

  else if ( strncmp( configuration.command, "blue_pixel", 11 ) == 0 ) {
    /* blue_pixel() function is defined in feature.h and implemented in feature.c */
    blue_pixel(configuration.filenames[0]);
  }

  else if ( strncmp( configuration.command, "red_pixel", 11 ) == 0 ) {
    /* red_pixel() function is defined in feature.h and implemented in feature.c */
    red_pixel(configuration.filenames[0]);
  }

  else if ( strncmp( configuration.command, "gray_pixel", 11 ) == 0 ) {
    /* gray_pixel() function is defined in feature.h and implemented in feature.c */
    gray_pixel(configuration.filenames[0]);
  }

  else if ( strncmp( configuration.command, "invert_pixel", 11 ) == 0 ) {
    /* invert_pixel() function is defined in feature.h and implemented in feature.c */
    invert_pixel(configuration.filenames[0]);
  }

  else if ( strncmp( configuration.command, "color_gray_luminance", 11 ) == 0 ) {
    /* color_gray_luminance() function is defined in feature.h and implemented in feature.c */
    color_gray_luminance(configuration.filenames[0]);
  }

  else if ( strncmp( configuration.command, "rotate_cw", 11 ) == 0 ) {
    /* rotate_cw() function is defined in feature.h and implemented in feature.c */
    rotate_cw(configuration.filenames[0]);
  }
   
  return 0;
}
