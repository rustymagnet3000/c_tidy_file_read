#include "yd_handle_argv.h"
#define BUFFER 5

char *filename_to_parse;
int FILENAME_BUFFER = 50;

void yd_regex_and_branch_option(char* menu_option){
    
    /* change entry to uppercase to minimize switch statemet; despite being able to handle in regex */
    if(!isupper(*menu_option)){
        *menu_option = toupper(*menu_option);
        
        const enum YD_REGEX_PATTERN pattern = MENU_OPTION;
        if(!yd_regex_validation(menu_option, &pattern))
            yd_handle_error(MENU_OPTION_NOT_RECOGNIZED);
    }

    switch(*menu_option) {
        
        case 'A':
            yd_string_search();
            break;
        case 'C':
            printf("Count keyword\n");
            break;
        case 'S':
            printf("Search first instance of keyword\n");
            break;
        case 'N':
            yd_parse_file(filename_to_parse);
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
        yd_handle_error(TOO_MANY_INPUTS);
    }
    
    switch(*argc) {
        case 1:
            yd_handle_error(NO_INPUT_SUPPLIED);
        
        case 2:
            filename_to_parse = (char *)calloc( FILENAME_BUFFER + 1, sizeof( char ) );
            strcpy(filename_to_parse, argv[1]);
            
            /* read file on background thread */
            yd_read_file_background_thread(filename_to_parse);
            
            /* display menu */
            yd_menu();
            char* name = (char*) malloc(BUFFER); /* allocate buffer */
            if (name == 0)
                yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);
            yd_handle_user_input(name, MENU_OPTION);
            yd_regex_and_branch_option(name);
            free(name); /* release memory */
            
            break;
            
        default :
            yd_handle_error(UNEXPECTED_ERROR);
            
    }
}
