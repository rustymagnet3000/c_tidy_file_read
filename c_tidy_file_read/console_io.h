#ifndef console_io_h
#define console_io_h

#include <stdio.h>
#include <stdlib.h>     /* abort(), malloc(), realloc(), free() */
#include "yd_time.h"

extern int BOUNDARY;
void console_header(void);
void console_io(const char* label, const char* value);
void console_footer(void);

#endif /* console_io_h */
