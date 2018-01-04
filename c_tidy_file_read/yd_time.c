#include "yd_time.h"

#define SIZE 256

/* Reference:  https://www.gnu.org/software/libc/manual/html_node/Time-Functions-Example.html */

// pass by reference added here. Size of time string set in the caller function //
// buffer set in caller function                                                //
// can maintain this as a void function                                         //

void yd_print_time(unsigned long *size_of_time_buffer) {
    
    char buffer[SIZE];
    time_t rawtime; // epoch time
    struct tm * timeinfo;
    
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    
    strftime (buffer, SIZE, "** %A %H:%M:%S %p ", timeinfo);
   
    *size_of_time_buffer = strlen(buffer);
    
    fputs (buffer, stdout);

}
