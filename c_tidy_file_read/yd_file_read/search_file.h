#ifndef search_file_h
#define search_file_h

#include <stdio.h>
#include <stdlib.h>     /* abort(), malloc(), realloc(), free() */
#include <strings.h>
#include "yd_file_read.h" /* added for file helper struct */

/* the following Time structure is a public structure callable from anywhere         */
typedef struct YD_SEARCH_RESULT {
    unsigned int count;
    unsigned int line_number;
    char * line_text;
} YD_SEARCH_RESULT;

YD_SEARCH_RESULT* yd_search_specifc_term(YD_FILE_HELPER *file_helper, char *search_term);
#endif /* search_file_h */
