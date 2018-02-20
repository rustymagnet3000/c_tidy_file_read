#include "yd_error_handler.h"

void yd_handle_error(enum YD_ERROR reported_error) /* write error message and quit */
{

    switch (reported_error) {
        case THREAD_CREATE_ERROR:
            fprintf(stderr, "thread create error\n");
        case THREAD_JOIN_ERROR:
            fprintf(stderr, "thread join error\n");
        case INPUT_FILE_CANNOT_READ_OR_FIND:
            fprintf(stderr, "Cannot read / find file\n");
            break;
        case INPUT_EMPTY_FILE:
            fprintf(stderr, "empty file\n");
            break;
        case INPUT_TOO_LONG:
            fprintf(stderr, "memory exhausted\n");
            break;
        case NO_INPUT_SUPPLIED:
            fprintf(stderr, "no filename entered\n");
            break;
        case TOO_MANY_INPUTS:
            fprintf(stderr, "too many inputs supplied\n");
            break;
        case MENU_OPTION_NOT_RECOGNIZED:
            fprintf(stderr, "menu option not recognized\n");
            break;
        default:
            fprintf(stderr, "generic error\n");
            break;
    }
    
    exit(99);
}
