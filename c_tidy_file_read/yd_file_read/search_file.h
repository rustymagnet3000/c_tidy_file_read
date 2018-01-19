#ifndef search_file_h
#define search_file_h

#include <stdio.h>
#include <stdlib.h>     /* abort(), malloc(), realloc(), free() */
#include <strings.h>
#include "yd_file_read.h" /* added for file helper struct */

struct YD_SEARCH_RESULT {
    unsigned int line_number;
    char * line_text;
};

struct YD_SEARCH_RESULT* yd_search_specifc_term(struct YD_FILE *fh, char *search_term);
#endif /* search_file_h */
