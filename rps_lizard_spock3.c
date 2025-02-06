#include <stdio.h>
// ctype.h contains tolower function, which converts all user-input text to
// lower-case, to control for user-input errors
#include <ctype.h>
// For rand() and srand()
#include <stdlib.h>
#include <string.h>
// Used to seed the random number generator
#include <time.h>

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

// Define array that will be used to select computer's sign
const char* signsArray[] = {"rock", "paper", "scissors", "lizard", "spock"};

// Static initialization of dictionary structure that pairs sign combinations
// with outcomes
OuterDict signsDict[] = {
    {"rock", {
        {"paper", "Paper covers rock, therefore you lose!"},
        {"scissors", "Rock crushes scissors, therefore you win!"},
        {"lizard", "Rock crushes lizard, therefore you win!"},
        {"spock", "Spock vaporizes rock, therefore you lose!"}
        }
    },
    {"paper", {
        {"scissors", "Scissors cuts paper, therefore you lose!"},
        {"lizard", "Lizard eats paper, therefore you lose!"},
        {"spock", "Paper disproves Spock, therefore you win!"}
        }
    },
    {"scissors", {
        {"lizard", "Scissors decapitate lizard, therefore you win!"},
        {"spock", "Spock smashes scissors, therefore you lose!"}
        }
    },
    {"lizard", {
        {"spock", "Lizard poisons Spock, therefore you win!"}
        }
    }
};

// Declare our rules to the game, simple text that will print to the terminal
void rules();

// Declare function that will verify whether memory was successfully allocated
int verifyMalloc(char* ptr);

// Declare function that will convert all letters in user input to lower-case
char* toLower(char* input);

// Declare the function that will prompt the user for their selection, 
// and then store it in the variable
const char* userSign();

// Declare function that will select a random sign from the signs array
char* selectRandom();

// Declare function that selects a sign at random, i.e. the computer's sign
const char* computerSign();

// Declare the function that will print the user's selection, as well as the
// computer's, to the terminal(; followed by the outcome ?)
void printSigns(char* choice, char* random);

// Declare the function that will print the outcome of the sign combination
void printOutcome(char* choice, char* random);

// Declare function that will print the score tally
void printScore(int* wins, int* losses);

// Declare function that will prompt the user whether they want to play again
void playAgain(int* wins, int* losses);

// Declare function that will encompass the repeatable parts of the program
void repeatSection(int* wins, int* losses, char user[], char computer[]);

// Declare printDict function
//void printDict(const struct Dict *dict);

// main function will contain all other functions in this program
int main() {
    // Declare the wins and losses variables
    int wins = 0, losses = 0;
    // Declare modifiable arrays that will store user and computer signs, MAX is 10 characters
    char user[MAX_SIGN_LENGTH], computer[MAX_SIGN_LENGTH];
    // Call the repeatSection() function to play the game for up to 100 rounds
    repeatSection(&wins, &losses, user, computer);
    return 0;
}

// Define the rules function
void rules() {
    printf("\nThis is Rock-Paper-Scissors-Lizard-Spock, from the hit TV show,\n"
           "The Big Bang Theory! It's basically Rock-Paper-Scissors, but with\n"
	       "two additional signs: Lizard and Spock.\n\n"
           "Nobody can explain the rules like Sheldon Cooper can, so I will\n"
           "simply quote him: 'Scissors cuts paper, paper covers rock,\n"
           "rock crushes lizard, lizard poisons Spock, Spock smashes scissors,\n"
           "scissors decapitates lizard, lizard eats paper, paper disproves Spock,\n"
           "Spock vaporizes rock, and as it always has, rock crushes scissors!'\n\n");
}

// Define function that will verify whether memory was successfully allocated
int verifyMalloc(char* ptr) {
    if (ptr == NULL) {
        // fprintf allows you to print to any file stream, e.g. standard error
        fprintf(stderr, "Memory allocation has failed.\n");
        return 1;
    }
    // Implicit else returns success code
    return 0;
}

// Define toLower function, which converts all input characters to lower-case
char* toLower(char* input) {
    // Convert input to lower-case by looping through every character
    // one-by-one and calling tolower() method on it
    for (int i=0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }
    return input;
}

// Define the function that will receive and process the user input
const char* userSign() {
    // Declare the variable that will store user input as is
    char rawInput[9];
    // Print the prompt to the terminal
    printf("Please enter your selection now: ");
    // Take user input as string, up to 8 characters (we need 9 to account for
    // the null terminator)
    scanf("%9s", rawInput);
    // Dynamically allocate memory for the variable copyInput; we need 8
    // chars because the longest sign is 8 chars, and we need + 1 for the
    // null terminator (\0)
    char* copyInput = (char *)malloc(9 * sizeof(char));
    // Call function to verify memory was successfully allocated
    verifyMalloc(copyInput);
    // Copy the value from original input into the copy thereof
    strcpy(copyInput, rawInput);
    // FOR TESTING PURPOSES
    printf("Test: %s\n", copyInput);
    // Call function to convert all letters in user input to lower-case
    char* lowerInput = toLower(copyInput);
    // DEBUGGING
    printf("%s\n", lowerInput);
    // Return the input, now in lower-case
    return lowerInput;
}

// Define the function that allocates the memory for a string array


// Define function that selects a sign at random for the computer
char* selectRandom() {
    // Seed the random number generator with the current time, this is 
    // necessary to ensure different numbers are generated each time
    srand(time(NULL));
    // The size variable will be used to confine the output of the random
    // number generator to values which are useful for our case, i.e. 0-4
    int size_generator = sizeof(signsArray) / sizeof(signsArray[0]);
    // Assign manipulated output of random number generator to the variable
    int index = rand() % size_generator;
    // Create sign variable that will store the randomly selected sign
    char[] sign;
    // Use random index to select a sign from the signs array, 
    // then copy it to the variable
    strcopy(sign, signsArray[index]);
    // Assign the sizeof (i.e. length) of our randomly generated sign to variable
    int size_string = sizeof(sign);
    // Create random variable with dynamically allocated memory
    char* random = (char*)malloc(size_string * sizeof(char));
    if (random == NULL) {
        // Handle allocation failure
        printf("Memory allocation has failed.\n");
        return NULL;
    }
    // Copy the contents of the sign variable to our new pointer, random
    strcopy(random, sign);
    // DEBUG
    printf("Computer's Sign: %s\n", random);
    // Return computer's sign so it can be used by other functions
    return random;
}

/* Leaving this here for now in case I mess up the above version
// Define function that selects a sign at random for the computer
char* selectRandom(int size) {
    // Seed the random number generator with the current time, this is 
    // necessary to ensure different numbers are generated each time
    srand(time(NULL));
    // The size variable will be used to confine the output of the random
    // number generator to values which are useful for our case, i.e. 0-4
    int size = sizeof(signsArray) / sizeof(signsArray[0]);
    // Assign manipulated output of random number generator to the variable
    int index = rand() % size;
    // Use random index to select a sign from the signs array
    const char* random = signsArray[index];
    // DEBUG
    printf("Computer's Sign: %s\n", random);
    // Return computer's sign so it can be used by other functions
    return random;
}
*/

// Define function that will randomly select a sign for the computer
const char* computerSign() {
    // Declare variable that will store computer's sign
    //char computer[9];
    // Assign output of function to variable
    const char* computer = selectRandom();
    return computer;
}

// Define the printSigns function
void printSigns(const char* user, const char* computer) {
    printf("You have selected %s as your sign, the computer has selected %s.\n", user, computer);
}

// Define the function that will print the outcome of the sign combination
void printOutcome(char* choice, char* random) {
    printf("");
}

// Define the function that will print the score tally
void printScore(int* wins, int* losses) {
    // Wins and losses
    printf("Human: %d\nComputer: %d\n", wins, losses);
}

// Define the function that will prompt the user whether they want to play again
void playAgain(int* wins, int* losses) {
    // Declare variable that will store user input for this function
    char yes_no[2];
    printf("Do you want to play again? [Y/n]");
    scanf("%2s", yes_no);
    // Convert input to lower case, assign to variable
    char* lowerInput = toLower(yes_no);
    if (yes_no == "y") {
        // Call the function that contains the repeatable sections of the program
        repeatSection(&wins, &losses);
    }
    else if (yes_no == "n") {
        printf("Okay, thank you for playing! Here is the final score: ");
        printScore();
    }
    else {
        printf("Invalid entry, please try again.\n");
        // Call function recursively until valid entry is made
        playAgain();
    } 
}

// Define the function that will encompass the repeatable parts of the program
void repeatSection(int* wins, int* losses) {
    // Set the local variable, user, to the output of the userSign function
    char* user = userSign();
    // Set the local variable, computer, to the output of the computerSign function
    char* computer = computerSign();
    // Print the user and computer signs to terminal
    printSigns(user, computer);
    // Print the outcome of the above signs
    printOutcome(user, computer);
    // Print the score tally
    printScore(&wins, &losses);
    // Prompt user whether they want to play again
    playAgain(&wins, &losses);
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