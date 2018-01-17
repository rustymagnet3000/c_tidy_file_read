#include "search_file.h"

YD_SEARCH_RESULT* yd_search_specifc_term(FILE *fp, char *search_term){

    YD_SEARCH_RESULT search_result = {.count = 0,.line_number = 0,.line_text = "not found"};

    return &search_result;
}
