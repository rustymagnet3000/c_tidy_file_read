//  Created by rustymagnet on 01/01/2018
#include <stdio.h>  // sprintf
#include <unistd.h> // used for Sleep API
#include "yd_file_read.h"  /* orchestrates file reading */
#include "yd_console_io.h"
#include "yd_time.h"
#include "yd_calculate_time_taken.h"
#include "search_file.h"

void yd_handle_command_line_input(int *argc, const char * argv[]){
    
    if (*argc > 2) {
        printf("Too many inputs\n\n");
        goto error_flow;
    }
    
    switch(*argc) {
        case 1:
            printf("No inputs supplied\n");
            goto error_flow;
        case 2:
            printf("Argument supplied: %s\n", argv[1]);
            break;
        default :
            printf("Unexpected failure\n\n");
            goto error_flow;

        error_flow:
            exit(99);
    }
}

int main(int argc, const char * argv[]) {

    /* next step: update to support file parsing                                    */
    /* first step; need an argc and argv to capture the filename to read            */
    /* then start to parse the file, on a background thread, while you load a menu  */
    
    yd_handle_command_line_input(&argc, argv);
    yd_console_header();

    FILE *fp;
    fp = yd_return_file_ptr("labels.txt");

    YD_SEARCH_RESULT *result;
    result = yd_search_specifc_term(fp, "version");
    
    putchar('\n');
    return 0;
}
