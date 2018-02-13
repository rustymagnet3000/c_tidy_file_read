#include <stdio.h>  // sprintf
#include <stdlib.h> // getline, malloc
#include <unistd.h> // used for Sleep API
#include "yd_handle_argv.h"

/* Parse the file, on a background thread, while you load a menu    */
/* Read the file line by line, into seperate Structs, when found    */
/* then each menu option just reads through the Structs             */

int main(int argc, const char * argv[]) {

    yd_handle_command_line_input(&argc, argv);

   // yd_console_header();

    
    return 0;
}

