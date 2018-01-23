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
    
    // start at max size of 10 for struct array                     //
    // loop through file to a max of <10 found instances            //
    // the ralloc on the array to bring it to proper size           //
    
    struct YD_SEARCH_RESULT *result_array = malloc(10 * sizeof(struct YD_SEARCH_RESULT));
    int total_found = 0;
    total_found = yd_search_specifc_term(result_array, &fh, "label");

    result_array = realloc(result_array, (total_found * sizeof(struct YD_SEARCH_RESULT)));
    
    for(int i = 0; i < total_found; i++)
    {
        printf("WHOOP%p\tLine:%s\t%u\n", &result_array[i], result_array->line_text, result_array->line_number);
   //     free(result_array->line_text);
    }
    
    fclose(fh.file_ptr);
    putchar('\n');
    return 0;
}

/* free not actually freeing */
