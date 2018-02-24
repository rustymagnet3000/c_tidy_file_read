#include "yd_console_io.h"
#define DELIMETER "|" /* TO SEPARATE PADDING */
const int BOUNDARY = 70;

/* memset does not add a null terminator so had to ensure I used Calloc instead of Malloc to zero-initialize strings */
static void yd_vanilla_stars(size_t *number_of_chars, char *chars_to_pad)
{
    memset(chars_to_pad,'*',*number_of_chars);
}


void yd_console_header_with_custom_buffer(char *buffer, size_t *buffer_size)
{
    size_t size_of_padding_buffer = (BOUNDARY) - *buffer_size;
    char *padding_buffer  = (char *)calloc( size_of_padding_buffer + 1, sizeof( char ) );
    if(padding_buffer == NULL)
        yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);
    
    yd_vanilla_stars(&size_of_padding_buffer, padding_buffer);
    
    strcat(buffer, padding_buffer);
    yd_console_io_lbl_and_pttrn(buffer);
    
    free(padding_buffer);
}

void yd_console_header()
{
    size_t size_of_time_buffer = 0;
    char *time_string_buffer = malloc( sizeof( char ) * (BOUNDARY*2) + 1);
    if(time_string_buffer == NULL)
        yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);
    
    yd_get_time(&size_of_time_buffer, time_string_buffer);
    
    size_t size_of_padding_buffer = (BOUNDARY*2) - size_of_time_buffer;
    char *padding_buffer  = (char *)calloc( size_of_padding_buffer + 1, sizeof( char ) );
    if(padding_buffer == NULL)
        yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);
    
    yd_vanilla_stars(&size_of_padding_buffer, padding_buffer);
    
    strcat(time_string_buffer, padding_buffer);
    yd_console_io_lbl_and_pttrn(time_string_buffer);
    
    free(time_string_buffer);
    free(padding_buffer);
}

void yd_console_footer()
{
    size_t size_of_buffer = BOUNDARY*2;
    char *footer_buffer = (char *)calloc( size_of_buffer + 1, sizeof( char ) );
    yd_vanilla_stars(&size_of_buffer, footer_buffer);
    yd_console_io_lbl_and_pttrn(footer_buffer);
}

void yd_console_io(char* label, char* value)
{
    printf("%s%s %s\n", label, DELIMETER, value);
}

void yd_console_io_lbl_and_pttrn(char* label)
{
    printf("%s\n", label);
}
