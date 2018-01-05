#include "console_io.h"
#define DELIMETER "|" /* TO SEPARATE PADDING */

int BOUNDARY = 40;

static void yd_print_banners(size_t *start_char)
{
    char c = '*'; // single quotes intentional
    
    do {
        putchar(c);
        *start_char = *start_char + 1;
    }while(*start_char <= (BOUNDARY * 2) + sizeof(DELIMETER));
    putchar('\n');
}

void console_header()
{
    size_t size_of_time_buffer = 0;
    char *malloc_buffer = malloc( sizeof( char ) * BOUNDARY + 1);

    yd_print_time(&size_of_time_buffer, malloc_buffer);
    yd_print_banners(&size_of_time_buffer);
}

void console_footer()
{
    size_t start_char = 0;
    yd_print_banners(&start_char);
}

void console_io(const char* label, const char* value)
{
    printf("%s%s %s\n", label, DELIMETER, value);
}
