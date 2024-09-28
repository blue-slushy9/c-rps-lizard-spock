#include <stdio.h>
// ctype.h contains tolower function, which converts all user-input text to
// lower-case, to control for user-input errors
#include <ctype.h>
// For rand() and srand()
#include <stdlib.h>

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

/* Might need parts of int main() later on, that's about it
// Declare printDict function
//void printDict(OuterDict dict[], int size);


int main() {
    int size = 3;
    // Debug
    printf("size: %i\n", size);
    // Call printDict function, 4 is the correct size argument to pass
    printDict(dict, size);
    return 0;
}
*/

// Declare our rules to the game, simple text that will print to the terminal
void rules();

// Declare the function that will convert all letters in user input to lower-
// case
char* toLower(char* select);

// Declare the function that will prompt the user for their selection, 
// and then store it in the variable, select
char* userInput();
//char* userInput(char* select);

// Declare the function that will print the user's selection, as well as the
// computer's, to the terminal(; followed by the outcome ?)
char* printChoice(char* choice);

// Declare function that selects a sign at random, i.e. the computer's sign
char* computerSign();

// Declare our printDict function;
//void printDict(const struct Dict *dict);

// main function will contain all other functions in this program
int main() {
    // Call the rules function
    rules();
    // Declare the select variable we will use in our userInput function,
    // specify maximum number of input characters
    //char select[10];
    // Set the local variable, choice, to the output of the userInput function
    char* choice = userInput();
    //char* choice = userInput(select);
    // Print user input to terminal
    printChoice(choice);
    // 

    return 0;
}

// Define the rules function
void rules() {
    printf("\nThis is Rock-Paper-Scissors-Lizard-Spock, from the hit TV show,\n"
           "Big Bang Theory! It is similar to Rock-Paper-Scissors, but with\n"
	       "two additional options: Lizard and Spock.\n\n"
           "Nobody can explain the rules like Sheldon Cooper can, so I will\n"
           "simply quote him: 'Scissors cuts paper, paper covers rock,\n"
           "rock crushes lizard, lizard poisons Spock, Spock smashes scissors,\n"
           "scissors decapitates lizard, lizard eats paper, paper disproves Spock,\n"
           "Spock vaporizes rock, and as it always has, rock crushes scissors!'\n\n");
}

// Define toLower function, which converts all input characters to lower-case
char* toLower(char* select) {
    // Convert input to lower-case by looping through every character
    // one-by-one and calling tolower() method on it
    for (int i=0; select[i]; i++) {
        select[i] = tolower(select[i]);
    }
    return select;
}

// Define the userInput function
//char* userInput(char* select) {
    char* userInput() {
    // Define variable select, which will be used to store user input
    char select[10];
    // Print the prompt to the terminal
    printf("Please enter your selection now: ");
    // Take user input as string, up to 9 characters
    scanf("%9s", select);
    // FOR TESTING PURPOSES
    printf("Test: %s\n", select);
    // Call function to convert all letters in user input to lower-case
    select = toLower(select);
    // DEBUGGING
    printf("%s\n", select);
    // Return the input, now in lower-case
    return select;
}

// Define the printChoice function
char* printChoice(char* choice, char* random) {
    printf("You have selected %s as your sign, the computer has selected %s.", choice, random);
}

// Define the computerSign function
char* computerSign() {
    char random[10];
    return random;
}

/* Don't think I need this anymore
// Define the printDict function;
void printDict(const struct Dict *nestDict) {
    printf("Dictionary:\n");
    // dict->size is an arrow function that can also be expressed as (*dict).size ...
    for (int i=0; i<dict->size; i++) { // ... i.e. the arrow function dereferences a pointer... 
        printf("Key: %s, Value: %s\n", nestDict->KeyValue[i].key, nestDict->KeyValue[i].value);
    } // ...to a structure and then accesses a member of that structure;
}
*/