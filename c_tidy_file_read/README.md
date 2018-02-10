## A tidy C file parser

### Code features
    •    C only
    •    Source controlled directly from xCode 9, on purpose
    •    Reads file A (the file to search)
    •    Reads file B (the strings to find)
    •    Print chars to stdout
    •    Pads the read lines
    •    Times the operations
    •    Regex of filename and menu-option
    
### Interesting APIs, types and structs
    Time ->  time_t struct, strftime
    div_t   -> useful for a division (you get the quotient and remainder as int values)
    Added qsort to sort a const array before use
    Calloc instead of Malloc
    Memset for repeating characters
    
### Learnings

    At the start of your project, you will always choose a better Type or Data Structure if you can answer the simple question "is the data constant or can it change?"
    
    char *test = "hello" is a read-only value. Don't try and write to it. You can write to char *test, when it is not initialized.

    /* A character 'c' has no \n character.  Any APIs that look for a \n won't work. char option[2] is the substitute   */

    /* memset does not add a null terminator so had to ensure I used Calloc instead of Malloc to zero-initialize strings */

    Enums are 2nd class citizens in C. You are better off using a constant C array and define statements, as you can't sort or find the name of an enum at run-time (they are removed).
    
    Incrementing a pass by refence int value:  *start_char = *start_char + 1;
    
    Notable: whether use Pass By Reference and make the Padding function a Void (return nothing).  Pass By Reference offered a smaller amount of variables but ultimately
    
    Your choice of a static or dynamic Struct.  This can lead to difficult bugs to fix as you can get into heap or stack memory differences. I had code working perfectly when everything was in main.c. Take it out of main (and off the local stack) and it broke down.  But for struct I was declaring I did not really require Dynamic Memory Allocation as I knew I wanted 1 struct and I knew how long it would last.  https://www.cs.swarthmore.edu/~newhall/cs31/resources/C-structs_pointers.php
    
