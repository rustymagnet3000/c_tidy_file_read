#include "yd_menu.h"
#define MAX_MENU_OPTIONS 6

/* Started a single Char for menu option but that has no \n character so padded_label functionality broke    */

struct YD_MENU_ITEMS {
    char menu_option[2];
    char description[25];
};

void yd_menu(void){
    yd_console_header();

    const static struct YD_MENU_ITEMS menu_options[MAX_MENU_OPTIONS] =
            {{.menu_option = "a", .description = "all items"},
            {.menu_option = "c", .description = "count interesting items"},
            {.menu_option = "f", .description = "all cert info"},
            {.menu_option = "n", .description = "all api requests"},
            {.menu_option = "s", .description = "specific items"},
            {.menu_option = "q", .description = "quit"}};

    yd_console_line_break();
    
    for (int i = 0; i < MAX_MENU_OPTIONS; i++ ){
        char *padded_menu_option = yd_padded_string(menu_options[i].menu_option);
        char *padded_label = yd_padded_string(menu_options[i].description);
        yd_console_io(padded_menu_option, padded_label);
    }
    
    yd_console_footer();
}
