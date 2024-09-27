#include <stdio.h>

// This is a practice program to help me get better with structs

// e.g. 'Rock', 'Spock'
#define MAX_SIGN_LENGTH 10

// e.g. 'Lizard poisons Spock...'
#define MAX_OUTCOME_LENGTH 50

// Max entries for the inner dictionary
#define MAX_ENTRIES 5

// Max number of possible outcomes
#define MAX_OUTCOMES 4

/* The typedef keyword is used to create a new type alias. It allows you to 
give a name (alias) to a data type so that you can use it without repeating 
the full definition of the type. In this case, it's creating a type called 
InnerDict that represents the structure. */

// Define structure for outcomes of sign1 and sign2
typedef struct {
    const char outcome[MAX_OUTCOME_LENGTH];
} Outcome;

// Define structure for inner dictionary, used for a single entry
typedef struct {
    const char sign2[MAX_SIGN_LENGTH];
    Outcome outcomes[MAX_OUTCOMES];
} InnerDictEntry;

// Define structure for outer dictionary
typedef struct {
    const char sign1[MAX_SIGN_LENGTH];
    // This array holds the middle dictionary
    InnerDictEntry entries[MAX_ENTRIES];
} OuterDict;

// Static initialization of our dictionary
OuterDict dict[] = {
    {"Rock", {
        {"Paper", "Paper covers rock, therefore you lose!"},
        {"Scissors", "Rock crushes scissors, therefore you win!"},
        {"Lizard", "Rock crushes lizard, therefore you win!"},
        {"Spock", "Spock vaporizes rock, therefore you lose!"}
        }
    },
    {"Paper", {
        {"Scissors", "Scissors cuts paper, therefore you lose!"},
        {"Lizard", "Lizard eats paper, therefore you lose!"},
        {"Spock", "Paper disproves Spock, therefore you win!"}
        }
    },
    {"Scissors", {
        {"Lizard", "Scissors decapitate lizard, therefore you win!"},
        {"Spock", "Spock smashes scissors, therefore you lose!"}
        }
    },
    {"Lizard", {
        {"Spock", "Lizard poisons Spock, therefore you win!"}
        }
    }
};

// Declare printDict function
void printDict(OuterDict dict[], int size);


int main() {
    int size = 3;
    // Debug
    printf("size: %i\n", size);
    // Call printDict function, 3 is the correct size argument to pass
    printDict(dict, size);
    return 0;
}

// Define printDict function
void printDict(OuterDict dict[], int size) {
    // n is the number of entries under each outer/P1 sign, we start with 4
    // and subtract 1 after each iteration
    int n=4;
    for (int i=0; i<=size; i++) {
        // Print the outer sign
        printf("\nHuman: %s\n", dict[i].sign1);
        // Iterate over all of the inner signs under the current outer sign
        for (int j=0; j<n; j++) {
            // Print the inner sign
            printf("Computer: %s\n", dict[i].entries[j].sign2);
            // Print the outcome of the outer and inner sign
            printf("Outcome: %s\n", dict[i].entries[j].outcomes[0].outcome);
        }
        // We must iterate over every for-loop layer before subtracting from n
        n--;
    }
}