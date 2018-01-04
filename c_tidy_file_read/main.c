//  Created by rustymagnet on 01/01/2018
#include <stdio.h>
#include "file_read.h"  /* orchestrates file reading */
#include "console_io.h"

int main(int argc, const char * argv[]) {
    
    console_header();
    read_file_line_by_line();
    console_footer();
    
    return 0;
}
