#include "search_file.h"

YD_SEARCH_RESULT* yd_search_specifc_term(YD_FILE_HELPER *file_helper, char *search_term){

    const static struct YD_SEARCH_RESULT init_result = {.count = 0 , .line_number = 0 , .line_text = "<not found>" };
    struct YD_SEARCH_RESULT *search_array[file_helper->num_of_lines];

    int array_count = 0;
    int line_number = 0;
    char *ret;
    
    size_t bufsize = 256;
    char *buffer;
    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
        exit(79);

    //    /* need to add new struct to array on each substring find */
    //    /* this sets the line_text FROM the substring to end of line. Not beginning of line */
    
    char * line = NULL;
    size_t len = 0;
    size_t read;

    printf("num of lines %d\n", file_helper->num_of_lines);
    printf("file pointer %p\n", file_helper->file);


    if( fgets (buffer, 60, file_helper->file)!=NULL )
    {
        /* writing content to stdout */
        puts(buffer);
    }
    
    //    while ((read = getline(&line, &len, file_helper->file)) != -1) {
//
//        putchar('X');
//
//        if ((ret = strstr(buffer, search_term)) != NULL){
//            /* init pointer to struct and allocate size */
//            search_array[array_count] = malloc(sizeof(struct YD_SEARCH_RESULT));
//           // search_array[array_count] = init_result;
//            search_array[array_count]->count = search_array[array_count]->count + 1;
//            search_array[array_count]->line_number = line_number;
//           // search_array[array_count]->line_text =
//            array_count++;
//        }
//
//        line_number++;
//    }

    
    return NULL;
}
