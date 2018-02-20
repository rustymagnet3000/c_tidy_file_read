#ifndef file_read_h
#define file_read_h

#include <stdio.h>
#include "yd_padded_label.h"
#include "yd_console_io.h"
#include "yd_error_handler.h"

/* init struct pointer and allocate size */
struct YD_FILE {
    FILE *file_ptr;
    int line_count;
    long bytes_in_files;
};

void *yd_read_file(void *data); // background thread file read
void yd_parse_file(const char *filename);
void yd_return_file_ptr(const char *filename, struct YD_FILE *file_helper);

#endif /* file_read_h */
