#include "console_io.h"

#define DELIMETER "|" /* TO SEPARATE PADDING */
int BOUNDARY = 40;

void console_header()
{
    unsigned long size_of_time_buffer = 0;
    
    yd_print_time(&size_of_time_buffer);

    char c = '*'; // single quotes required, not double quotes
    
    do {
        putchar(c);
        size_of_time_buffer++;
    }while(size_of_time_buffer <= (BOUNDARY * 2) + sizeof(DELIMETER));
    putchar('\n');
}

void console_footer()
{
    char c = '*'; // single quotes required, not double quotes
    
    int i = 0;
    do {
        putchar(c);
        i++;
    }while(i <= (BOUNDARY * 2) + sizeof(DELIMETER));
    putchar('\n');
}

void console_io(const char* label, const char* value)
{
    printf("%s%s %s\n", label, DELIMETER, value);
}
