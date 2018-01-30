#include "yd_handle_argv.h"
#define BUFFER 5

void quit() /* write error message and quit */
{
    fprintf(stderr, "memory exhausted\n");
    exit(1);
}

void yd_regex_and_branch_option(char* menu_option){
    
    /* change entry to uppercase to minimize switch statemet */
    if(!isupper(*menu_option)){
        *menu_option = toupper(*menu_option);
        if(!yd_regex_validation(menu_option, "^[A-Z]"))
        {
            fprintf(stderr, "Unsupported menu option\n");
            exit(89);
        }
    }
    
    switch(*menu_option) {
        case 'A':
            printf("Summary of all\n");
            break;
        case 'S':
            printf("Search first instance of keyword\n");
            break;
        case 'F':
            printf("Search ALL instance of keyword\n");
            break;
        default :
            printf("Unexpected character\n\n");
            break;
    }
}

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
            yd_menu();
            char* name = (char*) malloc(BUFFER); /* allocate buffer */
            if (name == 0)
                    quit();
            yd_handle_user_input(name);
                printf("Option selected:  %s\n", name);
            yd_regex_and_branch_option(name);
            free(name); /* release memory */
            
            break;
            
        default :
            printf("Unexpected failure\n\n");
            goto error_flow;
            
        error_flow:
            exit(99);
    }
}
