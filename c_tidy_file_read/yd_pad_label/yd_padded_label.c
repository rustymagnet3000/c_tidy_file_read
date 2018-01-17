#include "yd_padded_label.h"

enum LABEL_TYPE{
    NORMAL,
    EMPTY,
    LONG,
    UNKNOWN
};

static enum LABEL_TYPE label_validator(const char *label_ptr)
{
    
    if ( strlen(label_ptr) > 0 && strlen(label_ptr) < BOUNDARY )
        return NORMAL;
    if (strlen(label_ptr) > BOUNDARY)
        return LONG;
    if (strlen(label_ptr) == 0)
        return EMPTY;
    return UNKNOWN;
}

static char* setup_vanilla_line()
{
    char *vanilla_line = malloc( sizeof( char ) * BOUNDARY + 1);
    
    if(vanilla_line == NULL)
        exit(99);
    
    for(int i = 0; i <= BOUNDARY; i++)
        strcpy(&vanilla_line[i]," ");
    
    return vanilla_line;
}

const char* yd_padded_string(const char *raw_label_ptr)
{
    
    char* padded_label = setup_vanilla_line();
    size_t max_label_size = BOUNDARY - 2;
    unsigned long len_until_char_return = strcspn(raw_label_ptr, "\n");
    
    switch (label_validator(raw_label_ptr)) {
            
        case NORMAL:
            memcpy(padded_label, raw_label_ptr, len_until_char_return);
            break;
            
        case LONG:
            memcpy(padded_label, raw_label_ptr, max_label_size);
            break;
            
        case EMPTY:
            /* fallthrough */
        default:
            setup_vanilla_line();
            break;
    }
    return padded_label;
}


