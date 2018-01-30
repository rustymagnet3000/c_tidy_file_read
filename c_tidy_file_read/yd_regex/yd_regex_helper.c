#include "yd_regex_helper.h"

/* purposely put the regex patterns inside same function as regex to avoid regex strings being spread throughout the code */

enum YD_REGEX_PATTERN {
    FILENAME,
    MENU_OPTION
};


static char * regex_finder(enum YD_REGEX_PATTERN *enum_ptr)
{
    switch (*enum_ptr) {
        case MENU_OPTION:
            return "^[A-Z]";
        case FILENAME:
            // fallthrough
        default:
            return "^[A-Z]";
    }
}

bool yd_regex_validation(char *string_to_validate, const char *regex_pattern)
{
    regex_t regex;
    int reti;
    char msgbuf[100];
    
    /* Compile regular expression */
    reti = regcomp(&regex, regex_pattern, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return false;
    }

    /* Execute regular expression */
    reti = regexec(&regex, string_to_validate, 0, NULL, 0);
    if (!reti) {
        puts("Match");
    }
    else if (reti == REG_NOMATCH) {
        puts("No match");
        return false;
    }
    else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        return false;
    }
    
    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
    
    return true;
}
