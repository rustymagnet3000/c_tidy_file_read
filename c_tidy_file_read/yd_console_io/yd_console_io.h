#ifndef yd_console_io_h
#define yd_console_io_h

#include <stdio.h>
#include <stdlib.h>     /* abort(), malloc(), realloc(), free() */
#include "yd_time.h"

extern int BOUNDARY;
void yd_console_header(void);
void yd_console_io(char* label, char* value);
void yd_console_footer(void);

#endif /* yd_console_io_h */
