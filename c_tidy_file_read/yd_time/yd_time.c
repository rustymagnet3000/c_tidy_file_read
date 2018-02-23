#include "yd_time.h"
const int TIME_CHAR_BUFFER = 80;

/*** Aimed to have consistent functions.  Self-contained functions that use Pass By Reference   ***/
/*** self-contained print function, so no way to miss free()                                    ***/

void static yd_readable_date(char *buffer, time_t *rawtime) {
    
    struct tm * timeinfo;
    timeinfo = localtime ( rawtime );
    strftime (buffer, BOUNDARY, "%A %H:%M:%S %p ", timeinfo);
}

void static yd_precise_time(struct timeval *time_precise) {
    
    gettimeofday(time_precise, NULL);
}

void yd_print_precise_time_elapsed(struct timeval start, struct timeval end){
    
    struct timeval tval_result;
    timersub(&end, &start, &tval_result);
    char *malloc_buffer = malloc( sizeof( char ) * TIME_CHAR_BUFFER + 1);
    if(malloc_buffer == NULL)
        yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);
    
    sprintf(malloc_buffer, "** file read in: %ld.%02ld seconds ", (long int)tval_result.tv_sec,(long int)tval_result.tv_usec);
    size_t size_of_precise_time_buffer = strlen(malloc_buffer);
    
    yd_console_header_with_custom_buffer(malloc_buffer, &size_of_precise_time_buffer);
    free(malloc_buffer);
}

YD_TIME yd_init_time() {
    
    time_t rawtime; // epoch time
    time ( &rawtime );
    struct timeval time_precise; // precise time epoch + usecs
    
    char *malloc_buffer = malloc( sizeof( char ) * TIME_CHAR_BUFFER + 1);
    if(malloc_buffer == NULL)
        yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);
    
    yd_readable_date(malloc_buffer, &rawtime);
    yd_precise_time(&time_precise);
    
    YD_TIME time_helper;
    time_helper.epoch_time = rawtime;
    time_helper.precise_time = time_precise;
    time_helper.readable_time = malloc_buffer;
    
    free(malloc_buffer);
    return time_helper;
}

void yd_get_time(unsigned long *size_of_time_buffer, char *buffer) {
    
    time_t rawtime; // epoch time
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    
    strftime (buffer, BOUNDARY, "** %A %H:%M:%S %p ", timeinfo);
   
    *size_of_time_buffer = strlen(buffer);
}
