#include "yd_time.h"

/* Reference:  https://www.gnu.org/software/libc/manual/html_node/Time-Functions-Example.html   */
/* pass by reference added here. Size of buffer & strlen in the caller function                 */


void yd_print_time(unsigned long *size_of_time_buffer, char *buffer) {
    
    time_t rawtime; // epoch time
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    
    strftime (buffer, BOUNDARY, "** %A %H:%M:%S %p ", timeinfo);
   
    *size_of_time_buffer = strlen(buffer);
    
    fputs (buffer, stdout);

}
