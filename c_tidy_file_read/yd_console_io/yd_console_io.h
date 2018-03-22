#ifndef yd_console_io_h
#define yd_console_io_h

#include <stdio.h>
#include <stdlib.h>     /* abort(), malloc(), realloc(), free() */
#include "yd_time.h"
#include "yd_padded_label.h"

extern const int BOUNDARY;
void yd_console_header(void);
void yd_console_line_break(void);
void yd_console_header_with_custom_buffer(char *buffer, size_t *buffer_size);
void yd_console_io(char* label, char* value);
void yd_console_footer(void);
void yd_console_io_lbl_and_pttrn(char* label);

#endif /* yd_console_io_h */
