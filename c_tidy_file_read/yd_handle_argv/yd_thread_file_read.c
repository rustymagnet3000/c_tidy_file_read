#include "yd_thread_file_read.h"
// ******************************************************************************************** //
// Search the file, on a background thread                                                      //
/* Not thread-safe code as not locking variables with mutex or conditional variables             */
// ******************************************************************************************** //

int completed = 1;
unsigned int usecs = 500000;

static void *yd_search_file_ptr(void *data)
{
    YD_TIME start_time = yd_init_time();
        yd_parse_file((char*)data);
        yd_setup_predefined_array("labels.txt", "A");
        completed = 0;
    YD_TIME end_time = yd_init_time();
    yd_print_precise_time_elapsed(start_time.precise_time, end_time.precise_time);
    return NULL;
}

static void *yd_progress_bar(void *data)
{
    static const char progress_title[] = { 0x52, 0x65, 0x61, 0x64, 0x69, 0x6E, 0x67 };
    printf("%s >>", progress_title);
    
    do {
        putchar('>');
        usleep(usecs);
    } while (completed == 1);
    return NULL;
}

void yd_read_file_background_thread(char *filename) {
    
    pthread_t file_reading_thread;
    pthread_t in_progress_thread;
    
    if(pthread_create(&in_progress_thread, NULL, yd_progress_bar, NULL))
        yd_handle_error(THREAD_CREATE_ERROR);
        
    if(pthread_create(&file_reading_thread, NULL, yd_search_file_ptr, filename))
        yd_handle_error(THREAD_CREATE_ERROR);

    /* wait for the second thread to finish */
    if(pthread_join(file_reading_thread, NULL))
        yd_handle_error(THREAD_JOIN_ERROR);

    /* close in progress bar */
    if(pthread_join(in_progress_thread, NULL))
        yd_handle_error(THREAD_JOIN_ERROR);
}
