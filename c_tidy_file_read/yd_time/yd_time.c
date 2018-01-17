#include "yd_time.h"

/* Reference:  https://www.gnu.org/software/libc/manual/html_node/Time-Functions-Example.html       */
/* pass by reference added here. Size of buffer & strlen in the caller function                     */
/* Added helper struct to keep code tidier and allow to group comparison of start & finish times    */

char* yd_readable_time(time_t *rawtime) {
    
    struct tm * timeinfo;
    timeinfo = localtime ( rawtime );
    char *malloc_buffer = malloc( sizeof( char ) * 50 + 1);

    strftime (malloc_buffer, BOUNDARY, "%A %H:%M:%S %p ", timeinfo);
    return malloc_buffer;
}

YD_TIME yd_init_time() {
    
    time_t rawtime; // epoch time
    time ( &rawtime );
    
    YD_TIME time_helper = { .epoch_time = rawtime, .readable_time = yd_readable_time(&rawtime)};
    
    return time_helper;
}

void yd_print_time(unsigned long *size_of_time_buffer, char *buffer) {
    
    time_t rawtime; // epoch time
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    
    strftime (buffer, BOUNDARY, "** %A %H:%M:%S %p ", timeinfo);
   
    *size_of_time_buffer = strlen(buffer);
    
    fputs (buffer, stdout);
}

long yd_calculate_time_taken(time_t *end_time, time_t *start_time){
    
    if (*end_time == 0 || *start_time == 0) {  /* handle uninitialized time structs */
        return 88888;
    }
    
    if (*end_time < *start_time) {  /* handle incorrect ordering of times */
        return 99999;
    }
    
    return *end_time - *start_time;
}
