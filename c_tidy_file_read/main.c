#include <stdio.h>  // sprintf
#include "yd_handle_argv.h"
#include "search_file.h"
#include "yd_file_read.h"


int main(int argc, const char * argv[]) {
    
    yd_handle_command_line_input(&argc, argv);
    
    // globally prep'd array now done on background thread, after validating file and filename was ok //
    

}
