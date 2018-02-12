#ifndef yd_handle_user_input_h
#define yd_handle_user_input_h

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "yd_error_handler.h"
#include "yd_regex_helper.h"
#include "yd_console_io.h"
#include "yd_padded_label.h"

void yd_handle_user_input(char* name, enum YD_REGEX_PATTERN pattern);

#endif /* yd_handle_user_input_h */
