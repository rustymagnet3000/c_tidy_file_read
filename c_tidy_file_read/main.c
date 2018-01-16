//  Created by rustymagnet on 01/01/2018
#include <stdio.h>  // sprintf
#include <unistd.h> // used for Sleep API
#include "file_read.h"  /* orchestrates file reading */
#include "console_io.h"
#include "yd_time.h"
#include "yd_calculate_time_taken.h"


int main() {
    
    console_header();    
    YD_TIME time_start = yd_init_time();
    YD_TIME time_end = yd_init_time();;

    /* initialize time result */
    unsigned long total_seconds = yd_calculate_time_taken(&time_end.epoch_time, &time_start.epoch_time);

    yd_print_time_taken(&total_seconds);
    
    read_file_line_by_line();
    console_footer();
    
    putchar('\n');
    return 0;
}
