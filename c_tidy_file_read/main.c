//  Created by rustymagnet on 01/01/2018
#include <stdio.h>  // sprintf
#include <stdlib.h> // getline, malloc
#include <unistd.h> // used for Sleep API
#include "yd_file_read.h"  /* orchestrates file reading */
#include "yd_console_io.h"
#include "yd_time.h"
#include "yd_calculate_time_taken.h"
#include "search_file.h"
#include "yd_handle_argv.h"

/* next step: update to support file parsing                                    */
/* then start to parse the file, on a background thread, while you load a menu  */

int main(int argc, const char * argv[]) {

  //  yd_handle_command_line_input(&argc, argv);
    yd_console_header();
    yd_console_footer();

    return 0;
}

