#include "yd_handle_user_input.h"
#define BUFFER 30

/*  Handles whitespace, too long buffer and no entry of a character    */
void yd_handle_user_input(char* name, enum YD_REGEX_PATTERN pattern){
    
    char *padded_label;
    
    switch (MENU_OPTION) {
        case FILENAME:
            padded_label = yd_padded_string("Enter filename");
            break;
        case MENU_OPTION:
            padded_label = yd_padded_string("Enter menu option");
            break;
        default:
            padded_label = yd_padded_string("Enter search term");
            break;
    }
    yd_console_io_lbl_and_pttrn(padded_label);
    
    while (1) { /* skip leading whitespace */
        int c = getchar();
        if (c == EOF) break;
        if (!isspace(c)) {
            ungetc(c, stdin);
            break;
        }
    }
    
    int i = 0;
    while (1) {
        int c = getchar();
        if (isspace(c) || c == EOF) { /* at end, add terminating zero */
            name[i] = 0;
            break;
        }
        name[i] = c;

        if (i == BUFFER - 1) { /* buffer full */
                fprintf(stderr, "Input too long\n");
                exit(69);
        }
        i++;
    }
}
