#include <stdio.h>

// This is a practice program to help me get better with structs

// e.g. 'Rock', 'Spock'
#define MAX_KEY_LENGTH 10

// e.g. 'Lizard poisons Spock...'
#define MAX_VALUE_LENGTH 50

// Max entries for the middle dictionary
#define MAX_MID_ENTRIES 5

// Max entries for the inner dictionary
#define MAX_INNER_ENTRIES 10

/* The typedef keyword is used to create a new type alias. It allows you to 
give a name (alias) to a data type so that you can use it without repeating 
the full definition of the type. In this case, it's creating a type called 
InnerDict that represents the structure. */

// Define structure for inner dictionary, used for a single entry
typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} InnerDictEntry;

// Define structure for middle dictionary, used for a single entry
typedef struct {
    char key[MAX_KEY_LENGTH];
    // This array holds the inner dictionary
    InnerDictEntry entries[MAX_INNER_ENTRIES];
} MiddleDictEntry;

// Define structure for outer dictionary
typedef struct {
    char key[MAX_KEY_LENGTH];
    // This array holds the middle dictionary
    MiddleDictEntry entries[MAX_MID_ENTRIES];
} OuterDict;