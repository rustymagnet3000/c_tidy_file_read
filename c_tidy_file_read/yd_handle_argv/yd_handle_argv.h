#ifndef yd_handle_argv_h
#define yd_handle_argv_h

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "yd_menu.h"
#include "yd_handle_user_input.h"
#include "yd_regex_helper.h"
#include "yd_string_search.h"
#include "yd_error_handler.h"
#include "yd_file_read.h"

extern char *filename_to_parse;
extern int FILENAME_BUFFER;
void yd_handle_command_line_input(int *argc, const char * argv[]);
#endif /* yd_handle_argv_h */
