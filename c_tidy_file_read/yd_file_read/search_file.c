#include "search_file.h"

/* requirement: a dynamic allocation of structs contain each instance a substring is found in a file     */
// a pointer to a struct (will be used to store the base address of a dynamically allocated array of structs
// (the array buckets are allocated in heap memory)


struct YD_SEARCH_RESULT* yd_search_specifc_term(struct YD_FILE *fh, char *search_term){

    struct YD_SEARCH_RESULT *search_array = malloc(10 * sizeof(struct YD_SEARCH_RESULT));
    
    size_t bufsize = 256;
    int array_count = 0;
    int line_number = 0;
    char *ret;
    char *line = NULL;
    size_t len = 0;
    ssize_t read; // no. of chars in line
    
    while ((read = getline(&line, &len, fh->file_ptr)) != -1) {

        /* this is case-sensitive */
        if ((ret = strstr(line, search_term)) != NULL){

            search_array[array_count].line_number = line_number;
            search_array[array_count].line_text = malloc(sizeof(char)*bufsize);
            strcpy(search_array[array_count].line_text, line);
            
            printf("LINE:\t%s\n", search_array[array_count].line_text);
            
            array_count++;
        }

        line_number++;
    }
    
    free(line);
    
    
    return search_array;
}

