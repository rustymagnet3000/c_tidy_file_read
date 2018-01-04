#include "file_read.h"
#include "padded_label.h"
#include "console_io.h"

#define FILE_MAX 200 /* FILE SIZE */
#define FILE_NAME "labels.txt" /* FILE NAME */
#define FIELD_MAX 40

// ******************************************************************************************** //
// Read in a file, line by line, into a malloc string, print and free                           //
// use an api called getline() downside is this adds a \n to each read line so padded code      //
// needs to deal with this when padding out the string to the boundary                          //
// TBD:  Take the filename and filepath as attributes, instead of a fixed void                  //
// ******************************************************************************************** //

void read_file_line_by_line()
{
    FILE * fp;

    /* Ensure file exists or fail */
    if((fp = fopen(FILE_NAME, "r+")) == NULL) {
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
        const char* result = padded_string(line);
        console_io(result, result);
        free((char*)result);
        
    }

    fclose(fp);
}
