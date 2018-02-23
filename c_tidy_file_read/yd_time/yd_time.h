#ifndef yd_time_h
#define yd_time_h

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include "yd_console_io.h" // required to access global variable
#include "yd_error_handler.h"
#include "yd_calculate_time_taken.h" //required for knowing whether file took seconds, minutes or hours to read


/* the following Time structure is a public structure callable from anywhere         */
typedef struct YD_TIME {
    time_t epoch_time;
    struct timeval precise_time;
    char* readable_time;
} YD_TIME;

void yd_get_time(unsigned long *size_of_time_buffer, char *buffer);
YD_TIME yd_init_time(void);
void yd_print_precise_time_elapsed(struct timeval start, struct timeval end);
#endif /* yd_time_h */
