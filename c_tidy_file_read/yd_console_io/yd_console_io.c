#include "yd_console_io.h"
#define DELIMETER "|" /* TO SEPARATE PADDING */
int BOUNDARY = 40;

/* memset does not null terminate char arrays */
static void yd_vanilla_stars(size_t *number_of_chars, char *chars_to_pad)
{
    memset(chars_to_pad,'*',*number_of_chars);
}

void yd_console_header()
{
    size_t size_of_time_buffer = 0;
    char *time_string_buffer = malloc( sizeof( char ) * BOUNDARY + 1);
    if(time_string_buffer == NULL)
        exit(96);
    yd_get_time(&size_of_time_buffer, time_string_buffer);
    
    size_t size_of_padding_buffer = BOUNDARY - size_of_time_buffer;
    char *padding_buffer = (char*)malloc(size_of_padding_buffer + 1);
    if(padding_buffer == NULL)
        exit(96);
    yd_vanilla_stars(&size_of_padding_buffer, padding_buffer);
    
    strcat(time_string_buffer, padding_buffer);
    yd_console_io_lbl_and_pttrn(time_string_buffer);
    
    free(time_string_buffer);
    free(padding_buffer);
}

void yd_console_footer()
{
    size_t size_of_buffer = BOUNDARY;
    char *malloc_buffer = malloc( sizeof( char ) * BOUNDARY + 1);
    yd_vanilla_stars(&size_of_buffer, malloc_buffer);
    yd_console_io_lbl_and_pttrn(malloc_buffer);
}

void yd_console_io(char* label, char* value)
{
    printf("%s%s %s\n", label, DELIMETER, value);
}

void yd_console_io_lbl_and_pttrn(char* label)
{
    printf("%s\n", label);
}
