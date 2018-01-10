//  Created by rustymagnet on 01/01/2018
#include <stdio.h>  // sprintf
#include <unistd.h> // used for Sleep API
#include "file_read.h"  /* orchestrates file reading */
#include "console_io.h"
#include "yd_time.h"

enum TIME_TAKEN{
    SECONDS,
    MINUTES,
    HOURS,
    DAYS,
    WEEKS
};

enum TIME_TAKEN yd_time_taken(unsigned long *result) {
  
    if (*result > 0 && *result <= 60) {
        return SECONDS;
    }
    if (*result > 61 && *result <= 3600) {
        return MINUTES;
    }
    if (*result > 3600 && *result <= 86400) {
        return HOURS;
    }
    if (*result > 86400 && *result <= 604800) {
        return DAYS;
    }
    return WEEKS;
}

/* pass by reference */
void yd_combine_string_data(int *size_of_buffer, char *buffer, int result, int remainder, char *time_value) {
    
    // inline check an snprintf operation
    if(snprintf(buffer, *size_of_buffer, "%lu %s", result, time_value) >= *size_of_buffer){
        *size_of_buffer *= 2;
        free(buffer);
        buffer = malloc(*size_of_buffer);

        if(snprintf(buffer, *size_of_buffer, "%lu Seconds woohoop", result) >= *size_of_buffer){
            printf("Still not enough space. Aborting\n");
            exit(1);
        }
    }
}

char* yd_set_readable_string(unsigned long *result) {

    int bufSize = 30;
    char *buf = malloc(bufSize); // +1 not required due to >= check
    char *time_value;
    div_t result_summary;
    
    switch (yd_time_taken(result)) {
        case SECONDS:
            time_value = "seconds";break;
        case MINUTES:
            result_summary = div(*result, 60);
            time_value = "minutes";break;
        case HOURS:
            time_value = "hours";break;
        case DAYS:
            time_value = "days";break;
        default:
            *result = 666;
            time_value = "weeks";break;
    }
    
    yd_combine_string_data(&bufSize, buf, result_summary.quot, result_summary.rem, time_value);
    return buf;
}

int main() {
    
    // console_header();
    YD_TIME time_start = yd_init_time();
    sleep(1);
    YD_TIME time_end = yd_init_time();;
    
    unsigned long time_taken = yd_calculate_time_taken(&time_end.epoch_time, &time_start.epoch_time);
    
    char *time_taken_lbl = yd_set_readable_string(&time_taken);
    
    console_io(time_taken_lbl, time_taken_lbl);
    
    // read_file_line_by_line();
    console_footer();
    
    return 0;
}
