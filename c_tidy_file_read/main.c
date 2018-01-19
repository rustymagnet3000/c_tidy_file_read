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

    
    
    
    
    
    
    
    
    
    
    
//    yd_console_header();
//    yd_handle_command_line_input(&argc, argv);
    
    
//    /* init struct and allocate size */
//    struct YD_FILE_HELPER fh;
//    fh = malloc(sizeof(struct YD_FILE_HELPER));
//    if(fh == NULL) {
//        printf("Bad malloc error\n");
//        exit(1);
//    }
//    const struct YD_FILE_HELPER init_file_helper = {.file = NULL, .num_of_lines = 0};
//    *fh = init_file_helper;
//
//    yd_return_file_ptr("labels.txt", fh);
//

//
//
//    while ((read = getline(&line, &len, &(fh->file))) != -1) {
//        printf("Retrieved line of length %zu :\n", read);
//        printf("%s", line);
//    }
//
//    free(line);

    








//            if ((ret = strstr(buffer, search_term)) != NULL){
//                /* init pointer to struct and allocate size */
//                search_array[array_count] = malloc(sizeof(struct YD_SEARCH_RESULT));
//               // search_array[array_count] = init_result;
//                search_array[array_count]->count = search_array[array_count]->count + 1;
//                search_array[array_count]->line_number = line_number;
//               // search_array[array_count]->line_text =
//                array_count++;
//            }

//  line_number++;



//   free(result);

/* free not actually freeing */


