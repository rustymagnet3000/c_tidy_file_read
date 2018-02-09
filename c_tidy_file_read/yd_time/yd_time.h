#ifndef yd_time_h
#define yd_time_h

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "yd_console_io.h" // required to access global variable

/* the following Time structure is a public structure callable from anywhere         */
typedef struct YD_TIME {
    time_t epoch_time;
    char* readable_time;
} YD_TIME;

void yd_get_time(unsigned long *size_of_time_buffer, char *buffer);
YD_TIME yd_init_time(void);
char* yd_readable_time(time_t *rawtime);
long yd_calculate_time_taken(time_t *end_time, time_t *start_time);

#endif /* yd_time_h */
