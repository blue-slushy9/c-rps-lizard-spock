#include <stdio.h>
// ctype.h contains tolower function;
#include <ctype.h>

// These are the rules to the game, it is simple text that will print to the terminal;
void rules();

// This is the function that will prompt the user for their selection, and then store it in the variable, select;
char* userInput(char* select);

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
    return 0;
}

// Define rules function;
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

// Define userInput function;
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
