#include "yd_file_read.h"

YD_FILE_HELPER* yd_return_file_ptr(const char *filename)
{
    // ******************************************************************************************** //
    // Attempt to open a file for read-only                                                         //
    // this does not CLOSE the file pointer                                                         //
    // ******************************************************************************************** //
    
    FILE * fp;
    
    /* Ensure file exists or fail */
    if((fp = fopen(filename, "r+")) == NULL) {
        printf("No such file\n");
        exit(99);
    }

    /* check for at least a single character, also count empty lines set a line count number */
    int line_count = 0;
    int ch=0;
    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\n')
        {
            line_count++;
        }
    }    
    
    /* init struct pointer and allocate size */
    const static struct YD_FILE_HELPER init_file_helper = {.file = NULL, .num_of_lines = 0};
    struct YD_FILE_HELPER *file_helper = malloc(sizeof(struct YD_FILE_HELPER));

    /* set values */
    *file_helper = init_file_helper;
    file_helper->num_of_lines = line_count;
    file_helper->file = fp;
    
    return file_helper;
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
    if((fp = fopen(filename, "r+")) == NULL) {
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
