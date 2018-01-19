#include "search_file.h"

/* requirement: a dynamic allocation of structs contain each instance a substring is found in a file     */
// a pointer to a struct (will be used to store the base address of a dynamically allocated array of structs
// (the array buckets are allocated in heap memory)

//struct YD_SEARCH_RESULT {
//    int line_number;
//    char * line_text;
//};

struct YD_SEARCH_RESULT* yd_search_specifc_term(struct YD_FILE *fh, char *search_term){

    struct YD_SEARCH_RESULT *search_array;
    search_array = malloc(sizeof(struct YD_SEARCH_RESULT)*10);

    size_t bufsize = 256;
    char *buffer;
    int array_count = 0;
    int line_number = 0;
    char *ret;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
        exit(79);
    
    char *line = NULL;
    size_t len = 0;
    ssize_t read; // no. of chars in line
    
    while ((read = getline(&line, &len, fh->file_ptr)) != -1) {
        printf("length %zu :%s\n", read, line);

        if ((ret = strstr(buffer, search_term)) != NULL){

            search_array[array_count].line_number = line_number;
            search_array[array_count].line_text = malloc(sizeof(char)*100);
            strcpy(search_array[array_count].line_text, ret);
            array_count++;
        }

        line_number++;
    }
    
    free(line);
    
    
    return search_array;
}

