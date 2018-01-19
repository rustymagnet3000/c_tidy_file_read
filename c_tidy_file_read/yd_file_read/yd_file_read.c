#include "yd_file_read.h"

void yd_return_file_ptr(const char *filename, struct YD_FILE *file_helper)
{
    // ******************************************************************************************** //
    // Attempt to open a file for read-only & guard against empty files                             //
    // ******************************************************************************************** //

    /* Ensure file exists or fail */
    if((file_helper->file_ptr = fopen(filename, "r")) == NULL) {
        printf("No such file\n");
        exit(99);
    }

    /* check for empty file & then rewind to start of file */
    fseek(file_helper->file_ptr, 0, SEEK_END);

    if((file_helper->bytes_in_files = ftell(file_helper->file_ptr)) == 0 ) // White-Space != empty
    {
        printf("Nothing in file\n");
        exit(98);
    }

    if(file_helper->bytes_in_files < 50)  // stop almost empty files
        exit(97);
    
    rewind(file_helper->file_ptr);
    
}

void yd_read_file_line_by_line(const char *filename)
{
    // ******************************************************************************************** //
    // Read in a file, line by line, into a malloc string, print and free                           //
    // use an api called getline() downside is this adds a \n to each read line so padded code      //
    // needs to deal with this when padding out the string to the boundary                          //
    // ******************************************************************************************** //
    FILE * fp;

    /* Ensure file exists or fail */
    if((fp = fopen(filename, "r")) == NULL) {
        printf("No such file\n");
        exit(99);
    }

    /* check for empty file & then rewind to start of file */
    fseek(fp, 0, SEEK_END);
    unsigned long fileLength = (unsigned long)ftell(fp);

    rewind(fp);

    if(fileLength == 0 ) // White-Space != empty
    {
        printf("Nothing in file\n");
        exit(98);
    }

    char * line = NULL;
    size_t len = 0;
    size_t read;
    while ((read = getline(&line, &len, fp)) != -1) {
        const char* result = yd_padded_string(line);
        yd_console_io(result, result);
        free((char*)result);
    }
    fclose(fp);
}
