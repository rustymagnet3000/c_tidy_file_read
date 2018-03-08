#ifndef yd_file_parse_into_structs_h
#define yd_file_parse_into_structs_h

#include <stdio.h>
#include "yd_error_handler.h"
#include "search_file.h"
#include "yd_console_io.h"

//0/    Declare as global
extern struct YD_SEARCH_RESULT *global_result_array;
void yd_parse_file(const char *filename);
const int yd_setup_predefined_array(const char *filename, char *search_term);

#endif /* yd_file_parse_into_structs_h */
