//  Created by rustymagnet on 01/01/2018
#include <stdio.h>  // sprintf
#include <stdlib.h> // getline, malloc
#include <unistd.h> // used for Sleep API
#include "yd_file_read.h"  /* orchestrates file reading */
#include "yd_console_io.h"
#include "yd_time.h"
#include "yd_calculate_time_taken.h"
#include "search_file.h"
#include "yd_handle_argv.h"
/* next step: update to support file parsing                                    */
/* then start to parse the file, on a background thread, while you load a menu  */


int main(int argc, const char * argv[]) {
    
    struct YD_FILE fh;
    
    fh.file_ptr = malloc(sizeof(FILE));
    if (!fh.file_ptr) {
        printf("Malloc issue\n");
        exit(EXIT_FAILURE);
    }

    yd_return_file_ptr("labels.txt", &fh);
    
    struct YD_SEARCH_RESULT *result;
    result = yd_search_specifc_term(&fh, "label");
    

    fclose(fh.file_ptr);
    putchar('\n');
    return 0;
}

/* free not actually freeing */


