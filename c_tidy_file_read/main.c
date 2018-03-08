#include <stdio.h>  // sprintf
#include "yd_handle_argv.h"
#include "search_file.h"
#include "yd_file_read.h"
#include "yd_file_parse_into_structs.h"


void f(const int* total_found){
    
    int i = 0;
    do {
        yd_console_io_lbl_and_pttrn(global_result_array[i].line_text);
        i++;
    } while (i < *total_found);
}


int main(int argc, const char * argv[]) {
    
    // yd_handle_command_line_input(&argc, argv);
    const int records_found = yd_setup_predefined_array("labels.txt", "A");

    if(records_found > 0){
        f(&records_found);
    }
}
