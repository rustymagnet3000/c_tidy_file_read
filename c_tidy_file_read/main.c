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

char* yd_set_readable_string(unsigned long *result) {

    int bufSize = 5;
    char *buf = malloc(bufSize); // +1 not required due to >= check
    
    if(snprintf(buf, bufSize, "%lu Seconds woohoop", *result) >= bufSize){
        bufSize *= 2;
        free(buf);
        buf = malloc(bufSize);
        
        if(snprintf(buf, bufSize, "%lu Seconds", *result) >= bufSize){
            printf("Still not enough space. Aborting\n");
            exit(1);
        }
    }
    
    switch (yd_time_taken(result)) {
        case SECONDS:
            return buf;
        case MINUTES:
            return "MINUTES in a nice format";
        case HOURS:
            return "HOURS in a nice format";
        case DAYS:
            return "DAYS in a nice format";
        default:
            return "unhandled - default to weeks";
    }
}

int main() {
    
    // console_header();
    YD_TIME time_start = yd_init_time();
    sleep(2);
    YD_TIME time_end = yd_init_time();;
    
    unsigned long time_taken = yd_calculate_time_taken(&time_end.epoch_time, &time_start.epoch_time);

    char *time_taken_lbl = yd_set_readable_string(&time_taken);
    
    console_io(time_taken_lbl, time_taken_lbl);
    
    //    read_file_line_by_line();
    console_footer();
    
    return 0;
}
