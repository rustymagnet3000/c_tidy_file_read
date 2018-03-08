#ifndef yd_thread_file_read_h
#define yd_thread_file_read_h

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "yd_time.h"
#include "yd_file_read.h"
#include "yd_error_handler.h"
#include "yd_file_parse_into_structs.h"

void yd_read_file_background_thread(char *filename);

#endif /* yd_thread_file_read_h */
