#include "yd_calculate_time_taken.h"

#define TIME_ARRAY_SIZE 5
#define SECOND 1
#define MINUTE 60
#define HOUR 3600
#define DAY 86400
#define WEEK 604800

/* TIME TAKEN FOR STEP A TO STEP B                                                  */
/*  logic changed; as labels were constants and did not require dynamic allocation. */
/*  Goal: Sort constant values. The concept of a remainder does not exist!          */


typedef struct YD_TIME_TYPE {
    char *label;
    int divider;
} YD_TIME_TYPE;

static int yd_compare(struct YD_TIME_TYPE *elem1, struct YD_TIME_TYPE *elem2)
{
    if ( elem1->divider > elem2->divider)
        return -1;
    
    else if (elem1->divider < elem2->divider)
        return 1;
    
    else
        return 0;
}

void yd_print_time_taken(unsigned long *total_secs){
    
    typedef int (*compfn)(const void*, const void*);
    
    // purposely out of order
    const struct YD_TIME_TYPE time_typee[TIME_ARRAY_SIZE] = {
        { "weeks", WEEK },
        { "minutes", MINUTE },
        { "days   ", DAY },
        { "hours", HOUR },
        { "seconds", SECOND }
    };
    
    if(*total_secs == 0){
        printf("seconds ");
        return;
    }

    int n = sizeof(time_typee)/sizeof(time_typee[0]);
    
    //  qsort not a requirement, if array is hard-coded in correect order. Explicity sorting for robustness.  //  Sorting high to low
    qsort((void *) &time_typee,              // Beginning address of array
          TIME_ARRAY_SIZE,                                 // Number of elements in array
          sizeof(struct YD_TIME_TYPE),              // Size of each element
          (compfn)yd_compare );                  // Pointer to compare function
    
    div_t result;
    
    for( int i = 0; i < n; i++ ) {
        
        if ((result.quot = (int)*total_secs / time_typee[i].divider) > 0) // cast unsigned long to int to suppress warning
        {
            result.rem = *total_secs % time_typee[i].divider;
            printf("%d %s.  ", result.quot, time_typee[i].label);
            *total_secs = result.rem;
        }
    }
}
