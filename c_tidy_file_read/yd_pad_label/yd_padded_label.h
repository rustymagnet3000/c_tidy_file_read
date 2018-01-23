#ifndef padded_label_h
#define padded_label_h

#include <stdio.h>
#include <stdlib.h>     /* abort(), malloc(), realloc(), free() */
#include <string.h>     /* memcpy(), strlen() */
#include "yd_console_io.h"

char* yd_padded_string(const char *raw_label_ptr);

#endif /* padded_label_h */
