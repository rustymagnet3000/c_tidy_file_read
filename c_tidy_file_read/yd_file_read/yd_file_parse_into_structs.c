#include "yd_file_parse_into_structs.h"
#define MAX_ARRAY_SIZE 1000
#define START_ARRAY_SIZE 10

struct YD_SEARCH_RESULT *global_result_array;

const int yd_setup_predefined_array(const char *filename, char *search_term)
{
    //0/    read file
    struct YD_FILE fh;
    fh.file_ptr = malloc(sizeof(FILE));
    if (!fh.file_ptr)
        yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);
    
    yd_return_file_ptr(filename, &fh);

    global_result_array = malloc(START_ARRAY_SIZE * sizeof(struct YD_SEARCH_RESULT));
    if (global_result_array == NULL)
        yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);

    int total_found = 0;

    //2/    search for hardcoded string patterns
    total_found = yd_search_specifc_term(global_result_array, &fh, search_term);

    //3/    trim down struct
    global_result_array = realloc(global_result_array, (total_found * sizeof(struct YD_SEARCH_RESULT)));
    
    return total_found;
}

void yd_parse_file(const char *filename)
{
    // ******************************************************************************************** //
    // Read in a file, line by line, into a malloc string, print and free                           //
    // use an api called getline() downside is this adds a \n to each read line so padded code      //
    // needs to deal with this when padding out the string to the boundary                          //
    // ******************************************************************************************** //

    struct YD_FILE fh;
    /* Ensure file exists or fail */
    if((fh.file_ptr = fopen(filename, "r")) == NULL)
        yd_handle_error(INPUT_FILE_CANNOT_READ_OR_FIND);
    
    /* check for empty file & then rewind to start of file */
    fseek(fh.file_ptr, 0, SEEK_END);
    unsigned long fileLength = (unsigned long)ftell(fh.file_ptr);
    
    rewind(fh.file_ptr);
    
    if(fileLength == 0 ) // White-Space != empty
        yd_handle_error(INPUT_EMPTY_FILE);
    
    // start at max size of 10000 for struct array              //
    // loop through file to a max of <10 found instances        //
    // ralloc trim to proper size                               //
    
    struct YD_SEARCH_RESULT *result_array = malloc(MAX_ARRAY_SIZE * sizeof(struct YD_SEARCH_RESULT));
    if (result_array == NULL)
        yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);
    
    int total_found = 0;
    char* search_term = "AA"; /* allocate buffer */

    total_found = yd_search_specifc_term(result_array, &fh, search_term);
    
    result_array = realloc(result_array, (total_found * sizeof(struct YD_SEARCH_RESULT)));

    fclose(fh.file_ptr);
}
