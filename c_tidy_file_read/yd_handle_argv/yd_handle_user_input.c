#include "yd_handle_user_input.h"
#define BUFFER 5

void quit() /* write error message and quit */
{
    fprintf(stderr, "memory exhausted\n");
    exit(1);
}

void yd_handle_user_input(void){
    
    char* name = (char*) malloc(BUFFER); /* allocate buffer */
    if (name == 0) quit();
    
    printf("Please enter option: ");
    
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
    
    printf("Option selected:  %s\n", name);
    free(name); /* release memory */
}
