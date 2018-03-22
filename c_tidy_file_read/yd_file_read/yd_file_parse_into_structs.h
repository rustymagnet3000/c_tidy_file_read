#ifndef yd_file_parse_into_structs_h
#define yd_file_parse_into_structs_h

#include <stdio.h>
#include "yd_error_handler.h"
#include "search_file.h"
#include "yd_console_io.h"

// Globally accessible struct
struct YD_RESULTS {
    uint total_found;
    struct YD_SEARCH_RESULT *result_array;
};

void yd_print_results(void);
void yd_parse_file(const char *filename);
void yd_setup_predefined_array(const char *filename, char *search_term);

#endif /* yd_file_parse_into_structs_h */
