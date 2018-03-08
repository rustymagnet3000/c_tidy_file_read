#ifndef file_read_h
#define file_read_h

#include <stdio.h>
#include "yd_padded_label.h"
#include "yd_console_io.h"
#include "yd_error_handler.h"

/* init struct pointer and allocate size */
struct YD_FILE {
    FILE *file_ptr;
    // int line_count; removed by design, as counting lines here offer benefit but redundancy
    long bytes_in_files;
};

void yd_return_file_ptr(const char *filename, struct YD_FILE *file_helper);

#endif /* file_read_h */
