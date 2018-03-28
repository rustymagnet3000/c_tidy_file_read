#include <stdio.h>  // sprintf
#include "yd_handle_argv.h"
#include "search_file.h"
#include "yd_file_read.h"


int main(int argc, const char * argv[]) {
    
    yd_handle_command_line_input(&argc, argv);

    // TODO: check whether new print function works for Network or API requests         //
    // In memory array of structs held in handle_argv.c                                 //
    // Design goal: Separate presentation logic and model logic                         //
    // Design goal: arrays now done on background thread                                //

}
