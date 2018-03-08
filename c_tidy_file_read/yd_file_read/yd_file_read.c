#include "yd_file_read.h"


void yd_return_file_ptr(const char *filename, struct YD_FILE *file_helper)
{
    // ******************************************************************************************** //
    // Attempt to open a file for read-only & guard against empty files                             //
    // ******************************************************************************************** //

    /* Ensure file exists or fail */
    if((file_helper->file_ptr = fopen(filename, "r")) == NULL)
        yd_handle_error(INPUT_FILE_CANNOT_READ_OR_FIND);

    /* check for empty file & then rewind to start of file */
    fseek(file_helper->file_ptr, 0, SEEK_END);

    if((file_helper->bytes_in_files = ftell(file_helper->file_ptr)) == 0 ) // White-Space != empty
        yd_handle_error(INPUT_EMPTY_FILE);

    if(file_helper->bytes_in_files < 50)  // stop almost empty files
        yd_handle_error(INPUT_EMPTY_FILE);
    
    rewind(file_helper->file_ptr);
    
}


