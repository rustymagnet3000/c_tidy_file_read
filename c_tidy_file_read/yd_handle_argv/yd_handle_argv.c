#include "yd_handle_argv.h"

void yd_handle_command_line_input(int *argc, const char * argv[]){
    
    if (*argc > 2) {
        printf("Too many inputs\n\n");
        goto error_flow;
    }
    
    switch(*argc) {
        case 1:
            printf("No inputs supplied\n");
            goto error_flow;
        case 2:
            printf("Argument supplied: %s\n", argv[1]);
            break;
        default :
            printf("Unexpected failure\n\n");
            goto error_flow;
            
        error_flow:
            exit(99);
    }
}
