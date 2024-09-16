#include <stdio.h>

// This is a practice program to help me get better with structs

// e.g. 'Rock', 'Spock'
#define MAX_KEY_LENGTH 10

// e.g. 'Lizard poisons Spock...'
#define MAX_VALUE_LENGTH 50

//#define 

/* The typedef keyword is used to create a new type alias. It allows you to 
give a name (alias) to a data type so that you can use it without repeating 
the full definition of the type. In this case, it's creating a type called 
InnerDict that represents the structure. */

// Define structure for inner dictionary
typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} InnerDict;

// Define structure for outer dictionary
typedef struct {
    
} OuterDict;