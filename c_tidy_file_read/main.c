//  Created by rustymagnet on 01/01/2018
#include <stdio.h>  // sprintf
#include <unistd.h> // used for Sleep API
#include "yd_file_read.h"  /* orchestrates file reading */
#include "yd_console_io.h"
#include "yd_time.h"
#include "yd_calculate_time_taken.h"
#include "search_file.h"
#include "yd_handle_argv.h"


int main(int argc, const char * argv[]) {

    /* next step: update to support file parsing                                    */
    /* first step; need an argc and argv to capture the filename to read            */
    /* then start to parse the file, on a background thread, while you load a menu  */
    
    yd_handle_command_line_input(&argc, argv);
    yd_console_header();

    YD_FILE_HELPER *file_helper;
    file_helper = yd_return_file_ptr("labels.txt");

    YD_SEARCH_RESULT *result;
//    result = yd_search_specifc_term(file_helper, "label");
    
    char * line = NULL;
    size_t len = 0;
    size_t read;
    char *ret;
    
    printf("num of lines %d\n", file_helper->num_of_lines);
    printf("file pointer %p\n", file_helper->file);
    
    
        while ((read = getline(&line, &len, file_helper->file)) != -1) {
    
            putchar('X');
    
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
        }
    
    
    free(result);
    
    /* free not actually freeing */
    putchar('\n');
    return 0;
}
