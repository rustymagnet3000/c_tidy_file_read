#include "yd_handle_argv.h"
#define BUFFER 5
#define FILENAME_BUFFER 50

char *filename_to_parse;

void quit() /* write error message and quit */
{
    fprintf(stderr, "memory exhausted\n");
    exit(1);
}

void yd_regex_and_branch_option(char* menu_option){
    
    /* change entry to uppercase to minimize switch statemet; despite being able to handle in regex */
    if(!isupper(*menu_option)){
        *menu_option = toupper(*menu_option);
        
        const enum YD_REGEX_PATTERN pattern = MENU_OPTION;
        if(!yd_regex_validation(menu_option, &pattern))
        {
            fprintf(stderr, "Unsupported menu option\n");
            exit(89);
        }
    }
    
    switch(*menu_option) {
        case 'A':
            printf("Summary of all\n");
            
            
            struct YD_FILE fh;
            
            fh.file_ptr = malloc(sizeof(FILE));
            if (!fh.file_ptr) {
                printf("Malloc issue\n");
                exit(EXIT_FAILURE);
            }
            
            yd_return_file_ptr(filename_to_parse, &fh);
            
            // start at max size of 10 for struct array                     //
            // loop through file to a max of <10 found instances            //
            // the ralloc on the array to bring it to proper size           //
            
            struct YD_SEARCH_RESULT *result_array = malloc(10 * sizeof(struct YD_SEARCH_RESULT));
            int total_found = 0;
            char* search_term = (char*) malloc(FILENAME_BUFFER); /* allocate buffer */
            yd_handle_user_input(search_term, SEARCH_TERM);

            yd_console_io("Search term:", search_term);
            total_found = yd_search_specifc_term(result_array, &fh, search_term);
            
            result_array = realloc(result_array, (total_found * sizeof(struct YD_SEARCH_RESULT)));
            
            
            yd_console_header();
            char *padded_label;
            char padded_label_int[12]; //12 big enough for int inside a char array
            for(int i = 0; i < total_found; i++)
            {
                padded_label = yd_padded_string(result_array[i].line_text);
                sprintf(padded_label_int, "%d", result_array[i].line_number);
                yd_console_io(padded_label, padded_label_int);
                free(result_array[i].line_text);
            }
            yd_console_footer();
            free(result_array);
            fclose(fh.file_ptr);
            putchar('\n');
            
            break;
        case 'C':
            printf("Count keyword\n");
            break;
        case 'S':
            printf("Search first instance of keyword\n");
            break;
        case 'N':
            printf("Network requests option\n");
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
            filename_to_parse = malloc( sizeof( char ) * FILENAME_BUFFER + 1);
            strcpy(filename_to_parse, argv[1]);
            yd_menu();
            char* name = (char*) malloc(BUFFER); /* allocate buffer */
            if (name == 0)
                    quit();
            yd_handle_user_input(name, MENU_OPTION);
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
