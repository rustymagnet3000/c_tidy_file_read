#include <stdio.h>  // sprintf
#include "yd_handle_argv.h"

/* Read the file line by line, into seperate Structs, when found    */
/* then each menu option just reads through the Structs             */


int main(int argc, const char * argv[]) {
    
    yd_handle_command_line_input(&argc, argv);
    
    return 0;
}

