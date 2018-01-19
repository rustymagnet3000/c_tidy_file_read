#ifndef file_read_h
#define file_read_h

#include <stdio.h>
#include "yd_padded_label.h"
#include "yd_console_io.h"

typedef struct YD_FILE_HELPER {
    FILE *file;
    unsigned int num_of_lines;
} YD_FILE_HELPER;

void yd_read_file_line_by_line(const char *filename);
YD_FILE_HELPER* yd_return_file_ptr(const char *filename);

#endif /* file_read_h */
