#include <stdio.h>
// ctype.h contains tolower function, which converts all user-input text to
// lower-case, to control for user error;
#include <ctype.h>

// Define a struct for key-value pairs, which we will in turn use to create our dictionary;
struct KeyValue {
    // None of the possible options have more than 10 characters, so we can
    // set the limit there for memory preservation and security purposes;
    char key[10];
    char value[10];
};

// Define our dictionary struct of all possible user input combinations;
struct Dict {
    // Define struct of type KeyValue, mySign, as an array consisting of 5 elements;
    struct KeyValue mySign[5];
    // We will use the size variable to store the number of dictionary entries;
    int size;
};

// Define our subdictionary struct, which will contain the computer's possible "choices";
struct subDict {
    // We use char to define the name of our subdictionary as an array of up to 12 characters;
    char computerSign[12];
    // We place our sub-struct of type Dict inside of our main Dict;
    struct Dict subDict;
};

// Now we define our Dict and its subDict;
struct subDict computerSign = {
    .mySign = "Rock",
    .computerSign = {
        


};
//computerSign[4];

// Define a type-Dict dictionary, rpslsDict;
struct Dict rpslsDict = {
    .mySign = {
        {"rock", "paper"},
	{"rock", "scissors"},
	{"rock", "lizard"},
	{"rock", "spock"},
	{"paper", "scissors"},
	{"paper", "lizard"},
	{"paper", "spock"},
	{"scissors", "lizard"},
	{"scissors", "spock"},
	{"lizard", "spock"}
    },
    .size = 10
};

// Declare our rules to the game, it is simple text that will print to the terminal;
void rules();

// Declare the function that will prompt the user for their selection, and then store it in the variable, select;
char* userInput(char* select);

// Declare our printDict function;
void printDict(const struct Dict *dict);

// main function will contain all other functions in this program;
int main() {
    // Call the rules function;
    rules();
    // Declare the select variable we will use in our userInput function,
    // specify maximum number of input characters;
    char select[10];
    // Set the local variable, choice, to the userInput;
    char* choice = userInput(select);
    // Call the userInput function;
    //userInput(select);
    // This might not need to be here, using it for DEBUGGING;
    printf("Selection: %s\n", choice);
    // DEBUGGING
    printDict(&rpslsDict);
    return 0;
}

// Define the rules function;
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

// Define the userInput function;
char* userInput(char* select) {
    // Print the prompt to the terminal;
    printf("Please enter your selection now: ");
    // Take user input as string, up to 9 characters;
    scanf("%9s", select);
    // FOR TESTING PURPOSES
    printf("Test: %s\n", select);
    // Return variable so that other functions can use it;
    //return select;

    // Convert the input to lower-case by looping through every character one-by-one;
    for (int i = 0; select[i]; i++) {
        select[i] = tolower(select[i]);
    }
    // DEBUGGING
    printf("%s\n", select);
    // Return the input, now in lower-case;
    return select;
}

// Define the printDict function;
void printDict(const struct Dict *dict) {
    printf("Dictionary:\n");
    // dict->size is an arrow function that can also be expressed as (*dict).size ...
    for (int i=0; i<dict->size; i++) { // ... i.e. the arrow function dereferences a pointer... 
        printf("Key: %s, Value: %s\n", dict->combos[i].key, dict->combos[i].value);
    } // ...to a structure and then accesses a member of that structure;
}


