#include "yd_regex_helper.h"

/* purposely put the regex patterns inside same function as regex to avoid regex strings being spread throughout the code */


static char * regex_finder(const enum YD_REGEX_PATTERN *enum_ptr)
{
    switch (*enum_ptr) {
        case MENU_OPTION:
            return "^[ACFS]$";
        case FILENAME:
            // fallthrough
        default:
            return "^[A-Z].txt$";
    }
}

bool yd_regex_validation(char *string_to_validate, const enum YD_REGEX_PATTERN *regex_pattern)
{
    regex_t regex;
    int reti;
    char msgbuf[100];
    char *pattern = regex_finder(regex_pattern);
    
    /* Compile regular expression */
    reti = regcomp(&regex, pattern, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return false;
    }

    if(string_to_validate == NULL){ /* slightly redundant as I don't accept a null char entry */
        fprintf(stderr, "null input\n");
        return false;
    }
    
    /* Execute regular expression */
    reti = regexec(&regex, string_to_validate, 0, NULL, 0);
    if (!reti) {
        puts("Match");
    }
    else if (reti == REG_NOMATCH) {
        puts("No match - FAILED regex");
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
