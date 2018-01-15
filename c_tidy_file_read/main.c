//  Created by rustymagnet on 01/01/2018
#include <stdio.h>  // sprintf
#include <unistd.h> // used for Sleep API
#include "file_read.h"  /* orchestrates file reading */
#include "console_io.h"
#include "yd_time.h"

/* this is a large convenience initializor. You set the total seconds and then all other pieces are auto calculated */

//enum TIME_TAKEN{
//    WEEKS,
//    DAYS ,
//    HOURS,
//    MINUTES,
//    SECONDS
//} TIME_TAKEN;
//
//typedef struct YD_TIME_RESULT {
//    char *primary_time_value;
//    char *secondary_time_value;
//    unsigned long total_seconds;
//    int remainder;
//    int quot;
//    int divisor;
//} YD_TIME_RESULT;
//
//enum TIME_TAKEN yd_time_taken(unsigned long *result) {
//
//    if (*result > 0 && *result <= 60) {
//        return SECONDS;
//    }
//    if (*result > 61 && *result <= 3600) {
//        return MINUTES;
//    }
//    if (*result > 3600 && *result <= 86400) {
//        return HOURS;
//    }
//    if (*result > 86400 && *result <= 604800) {
//        return DAYS;
//    }
//    return WEEKS;
//}
//
///* pass by reference */
//void yd_combine_string_data(int *size_of_buffer, char *buffer, YD_TIME_RESULT *time_result) {
//
//    time_result->quot = (int) time_result->total_seconds/time_result->divisor;
//
//    if (time_result->total_seconds % 60 == 0)
//    {
//        time_result->remainder = 0;
//    } else {
//        time_result->remainder = time_result->total_seconds%60;
//    }
//
//    // inline check an snprintf operation
//    if(snprintf(buffer,
//                    *size_of_buffer, "%d %s %d %s",
//                    time_result->quot,
//                    time_result->primary_time_value,
//                    time_result->remainder,
//                    time_result->secondary_time_value) >= *size_of_buffer){
//        *size_of_buffer *= 2;
//        free(buffer);
//        buffer = malloc(*size_of_buffer);
//
//        if(snprintf(buffer,
//                    *size_of_buffer, "%d %s %d %s",
//                    time_result->quot,
//                    time_result->primary_time_value,
//                    time_result->remainder,
//                    time_result->secondary_time_value) >= *size_of_buffer){
//            printf("Still not enough space. Aborting\n");
//            exit(1);
//        }
//    }
//}
//
//char* yd_set_readable_string(YD_TIME_RESULT *time_result) {
//
//    int bufSize = 30;
//    char *buf = malloc(bufSize); // +1 not required due to >= check
//
//    switch (yd_time_taken(&time_result->total_seconds)) {
//        case SECONDS:
//            time_result->primary_time_value ="seconds";
//            time_result->secondary_time_value="";
//            time_result->divisor=1;
//            break;
//        case MINUTES:
//            time_result->primary_time_value ="minutes";
//            time_result->secondary_time_value="seconds";
//            time_result->divisor=60;
//            break;
//        case HOURS:
//            time_result->primary_time_value ="hours";
//            time_result->secondary_time_value="minutes";
//            time_result->divisor=3600;
//            break;
//        case DAYS:
//            //            fallthrough;
//        default:
//            //            tba
//            break;
//    }
//
//    yd_combine_string_data(&bufSize, buf, time_result);
//    return buf;
//}


// logic is incorrect.  I need a recursive loop that generates an array of values to show.  Starts at weeks and iterates down through each value.  Instead of trying to convert all into minutes or hours.  It has to be and.
#define TIME_ARRAY_SIZE 5
#define _SECOND 1
#define _MINUTE 60
#define _HOUR 3600
#define _DAYS 86400
#define _WEEKS 604800

enum YD_TIME_TAKEN{
    WEEKS =_WEEKS,
    DAYS =_DAYS
} YD_TIME_TAKEN;

static int yd_compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

// removed remainder as new logic means no remainder
typedef struct YD_TIME_TYPE {
    char *label;
    int divider;
} YD_TIME_TYPE;

// const char* int yd_time_names[2] = {{222,"Weeks"}, {333,"Days"}};


int main() {
    
    console_header();

    struct YD_TIME_TYPE time_typee[3] = {{ "Weeks", _WEEKS },{ "dayys", _DAYS }, { "hours", _HOUR }};
    int n = sizeof(time_typee)/sizeof(time_typee[0]);
    
    for( int i = 0; i <= n; i++ ) {
        printf("%s\n",  time_typee[i].label );

    }
    
  //  YD_TIME_TYPES time_type_array[TIME_ARRAY_SIZE] = { SECOND, MINUTE, HOUR, DAYS, WEEKS };
    
    
    
//    // qsort not a requirement, if array is hard-coded in correect order. Explicity sorting for robustness.

//    qsort(time_type_array, n, sizeof(int), yd_compare);
//
//    for( int i = (n - 1); i >= 0; i-- ) {
//        printf("%d\n",  time_type_array[i] );
//
//    }
    
    //    YD_TIME time_start = yd_init_time();
//    YD_TIME time_end = yd_init_time();;
//    YD_TIME_RESULT time_result;
//
//    /* initialize time result */
//    time_result.total_seconds = yd_calculate_time_taken(&time_end.epoch_time, &time_start.epoch_time);
//
//    /* print result */
//    char *time_taken_lbl = yd_set_readable_string(&time_result);
//    console_io(time_taken_lbl, time_taken_lbl);
//
////     read_file_line_by_line();
//    console_footer();
    
    return 0;
}
