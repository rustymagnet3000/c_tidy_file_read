//  Created by rustymagnet on 01/01/2018
#include <stdio.h>
#include <unistd.h> // used for Sleep API
#include "file_read.h"  /* orchestrates file reading */
#include "console_io.h"
#include "yd_time.h"

int main() {
    
    // console_header();
    YD_TIME time_start = yd_init_time();
    sleep(1);
    YD_TIME time_end;
    
    long time_taken = yd_calculate_time_taken(&time_end.epoch_time, &time_start.epoch_time);
    
    printf("Time taken was %ld", time_taken);
    //    read_file_line_by_line();
    console_footer();
    
    return 0;
}
