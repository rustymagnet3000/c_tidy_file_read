#include <stdio.h>  // sprintf
#include <unistd.h>
#include "yd_handle_argv.h"
#include <pthread.h>

/* Read the file line by line, into seperate Structs, when found    */
/* then each menu option just reads through the Structs             */

// ******************************************************************************************** //
// Search the file, on a background thread                                                      //
/* Not thread safe code as not locking variables with mutex or conditional variables             */
// ******************************************************************************************** //


int completed = 1;

void *yd_search_file_ptr(void *data)
{
    printf("start file read\n");
    yd_parse_file((char*)data);
    completed = 0;
    printf(" file loaded\n");
    return NULL;
}

static void *yd_progress_bar(void *data)
{
    unsigned int usecs = 100;
    do {
        putchar('*');
        usleep(usecs);
    } while (completed == 1);

    return NULL;
}

int main(int argc, const char * argv[]) {

   // yd_handle_command_line_input(&argc, argv);


    pthread_t file_reading_thread;
    pthread_t in_progress_thread;

    if(pthread_create(&file_reading_thread, NULL, yd_search_file_ptr, "plaintext.txt"))
        yd_handle_error(THREAD_CREATE_ERROR);

    if(pthread_create(&in_progress_thread, NULL, yd_progress_bar, NULL))
        yd_handle_error(THREAD_CREATE_ERROR);

    /* wait for the second thread to finish */
    if(pthread_join(file_reading_thread, NULL))
            yd_handle_error(THREAD_JOIN_ERROR);

    /* close in progress bar */
    if(pthread_join(in_progress_thread, NULL))
        yd_handle_error(THREAD_JOIN_ERROR);

    return 0;
}

