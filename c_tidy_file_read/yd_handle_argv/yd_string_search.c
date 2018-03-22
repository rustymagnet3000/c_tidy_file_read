#include "yd_string_search.h"
#define MAX_ARRAY_SIZE 10000

void yd_string_search() {
    
    struct YD_FILE fh;
    fh.file_ptr = malloc(sizeof(FILE));
    if (!fh.file_ptr)
        yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);

    yd_return_file_ptr(filename_to_parse, &fh);

    // start at max size of 10000 for struct array              //
    // loop through file to a max of <10 found instances        //
    // ralloc trim to proper size                               //

    struct YD_SEARCH_RESULT *result_array = malloc(MAX_ARRAY_SIZE * sizeof(struct YD_SEARCH_RESULT));
    if (result_array == NULL)
        yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);
    
    int total_found = 0;
    char* search_term = (char*) malloc(FILENAME_BUFFER); /* allocate buffer */
    yd_handle_user_input(search_term, SEARCH_TERM);

    total_found = yd_search_specifc_term(result_array, &fh, search_term);

    result_array = realloc(result_array, (total_found * sizeof(struct YD_SEARCH_RESULT)));


    yd_console_header();

    char *padded_label;
    char padded_label_int[12]; //12 big enough for int inside a char array

    if(total_found > 0){
        
        yd_console_line_break();
        for(int i = 0; i < total_found; i++)
        {
            padded_label = yd_padded_string(result_array[i].line_text);
            sprintf(padded_label_int, "%d", result_array[i].line_number);
            yd_console_io(padded_label, padded_label_int);
            free(result_array[i].line_text);
        }
        
    } else {
        yd_console_io_lbl_and_pttrn("No items founds with that search term");
    }

    free(result_array);
    fclose(fh.file_ptr);
    putchar('\n');
}
