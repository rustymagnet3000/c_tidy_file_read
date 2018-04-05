#include "yd_string_search.h"
#define MAX_ARRAY_SIZE 10000

struct YD_RESULTS* yd_string_search() {
    
    struct YD_FILE fh;
    fh.file_ptr = malloc(sizeof(FILE));
    if (!fh.file_ptr)
        yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);

    yd_return_file_ptr(filename_to_parse, &fh);

    // start at max size of 10000 for struct array              //
    // loop through file to a max of <10 found instances        //
    // ralloc trim to proper size                               //

    struct YD_RESULTS *results = malloc(1 * sizeof(struct YD_RESULTS));
    results->result_array = malloc(MAX_ARRAY_SIZE * sizeof(struct YD_SEARCH_RESULT));
    if (results->result_array == NULL)
        yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);
    
    
    char* search_term = (char*) malloc(FILENAME_BUFFER); /* allocate buffer */
    yd_handle_user_input(search_term, SEARCH_TERM);

    results->total_found = yd_search_specifc_term(results->result_array, &fh, search_term);

    results->result_array = realloc(results->result_array , (results->total_found * sizeof(struct YD_SEARCH_RESULT)));

    fclose(fh.file_ptr);
    return results;

}
