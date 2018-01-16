## A tidy C file parser

### Code features
•    C only
•    Source controlled directly from xCode 9, on purpose
•    Reads file A (the file to search)
•    Reads file B (the strings to find)
•    Print chars to stdout
•    Padsthe read lines
•    Times the operations

### Interesting APIs, types and structs
    Time ->  time_t struct, strftime
    div_t   -> useful for a division (you get the quotient and remainder as int values)
    Added qsort to sort a const array before use

### Learnings

    At the start of your project, you will always choose a better Type or Data Structure if you can answer the simple question "is the data constant or can it change?"
    
    char *test = "hello" is a read-only value. Don't try and write to it. You can write to char *test, when it is not initialized.

    Enums are 2nd class citizens in C. You are better off using a constant C array and define statements, as you can't sort or find the name of an enum at run-time (they are removed).
    
    Incrementing a pass by refence int value:  *start_char = *start_char + 1;
    
    Notable: whether use Pass By Reference and make the Padding function a Void (return nothing).  Pass By Reference offered a smaller amount of variables but ultimately