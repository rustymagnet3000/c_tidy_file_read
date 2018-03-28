#include "yd_handle_argv.h"
#define BUFFER 5

char *filename_to_parse;
int FILENAME_BUFFER = 50;

static void yd_print_menu_get_input(void);

int yd_print_in_mem_results(struct YD_SEARCH_RESULT *result_array, int *total_found){

        yd_console_header();
    
        char *padded_label;
        char padded_label_int[12]; //12 big enough for int inside a char array
    
        if(total_found > 0){
    
            yd_console_line_break();
            for(int i = 0; i < *total_found; i++)
            {
                padded_label = yd_padded_string(result_array[i].line_text);
                sprintf(padded_label_int, "%d", result_array[i].line_number);
                yd_console_io(padded_label, padded_label_int);
                free(result_array[i].line_text);
            }
    
        } else {
            yd_console_io_lbl_and_pttrn("No items founds with that search term");
        }
    
    return 0;
}

void yd_regex_and_branch_option(char* menu_option){
    
    /* change entry to uppercase to minimize switch statemet; despite being able to handle in regex */
    if(!isupper(*menu_option)){
        *menu_option = toupper(*menu_option);
        
        const enum YD_REGEX_PATTERN pattern = MENU_OPTION;
        if(!yd_regex_validation(menu_option, &pattern))
            yd_handle_error(MENU_OPTION_NOT_RECOGNIZED);
    }

    const char *bye_message;
    struct YD_SEARCH_RESULT *ptr_results;
    int result = -1;
    int strings_found = 0;
    
    switch(*menu_option) {
    
            
        case 'A':
            ptr_results = yd_string_search(&strings_found);
            result = yd_print_in_mem_results(ptr_results, &strings_found);
            free(ptr_results); // remove the dynamically generated struct arrays after printing, as a new search could be conducted
            break;
        case 'C':
            printf("Count keyword\n");
            break;
        case 'S':
            printf("Search first instance of keyword\n");
            break;
        case 'N':
//            if(global_result_1.total_found > 0){
//                yd_print_results(<#const int *total_found#>)
//            }
            yd_console_io_lbl_and_pttrn("Read global array");
            break;
        case 'F':
            printf("Search ALL instance of keyword\n");
            break;
        case 'Q':
            bye_message = yd_padded_string("🔥 Thanks for using Logparser 🔥");
            yd_console_io_lbl_and_pttrn((char *)bye_message);
            yd_console_line_break();
            exit(99);
        default :
            printf("Unexpected character\n\n");
            break;
    }
    yd_print_menu_get_input();
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
            
            /* read file & prepare global arrays on background thread */
            yd_read_file_background_thread(filename_to_parse);
            
            yd_print_menu_get_input();

            break;
            
        default :
            yd_handle_error(UNEXPECTED_ERROR);
            
    }
}

static void yd_print_menu_get_input(){
    /* display menu and capture user input */
    yd_menu();
    char* name = (char*) malloc(BUFFER); /* allocate buffer */
    if (name == 0)
        yd_handle_error(MALLOC_CALLOC_MEMORY_ASSIGNMENT);
    yd_handle_user_input(name, MENU_OPTION);
    yd_regex_and_branch_option(name);
    free(name); /* release memory */
}

