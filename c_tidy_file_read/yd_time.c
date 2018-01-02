#include "yd_time.h"

#define SIZE 256

/* Reference:  https://www.gnu.org/software/libc/manual/html_node/Time-Functions-Example.html */

void yd_print_time(void) {
    
    char buffer[SIZE];
    time_t rawtime; // epoch time
    struct tm * timeinfo;
    
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    
    strftime (buffer, SIZE, "%A %H:%M:%S %p \n", timeinfo);
    fputs (buffer, stdout);

}
