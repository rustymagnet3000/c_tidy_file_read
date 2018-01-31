#ifndef yd_regex_helper_h
#define yd_regex_helper_h

#include <stdio.h>
#include <regex.h> // regex
#include<stdlib.h> // malloc
#include <stdbool.h>

enum YD_REGEX_PATTERN {
    FILENAME,
    MENU_OPTION
};

bool yd_regex_validation(char *string_to_validate, const enum YD_REGEX_PATTERN *regex_pattern);


#endif /* yd_regex_helper_h */
