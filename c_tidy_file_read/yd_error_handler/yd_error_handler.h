#ifndef yd_error_handler_h
#define yd_error_handler_h

#include <stdio.h>
#include <stdlib.h>  // required for Exit()

enum YD_ERROR {
    THREAD_CREATE_ERROR,
    THREAD_JOIN_ERROR,
    FILENAME_NOT_RECOGNIZED,
    INPUT_TOO_LONG,
    INPUT_EMPTY_FILE,
    INPUT_FILE_CANNOT_READ_OR_FIND,
    TOO_MANY_INPUTS,
    NO_INPUT_SUPPLIED,
    MALLOC_CALLOC_MEMORY_ASSIGNMENT,
    REGEX,
    MENU_OPTION_NOT_RECOGNIZED,
    UNEXPECTED_ERROR
};

void yd_handle_error(enum YD_ERROR reported_error); /* write error message and quit */

#endif /* yd_error_handler_h */
