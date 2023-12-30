#include <stdio.h>

// You want to declare your functions you plan to use in your program as
// function prototypes before you call them inside of main() or define them;

// These are the rules to the game, it is simple text that will print to the terminal;
void rules();

// This is the function that will prompt the user for their selection, and then store it in the variable, select;
char* userInput(char* select);

// main function will contain all other functions in this program;
int main() {
    // Call the rules function;
    rules();
    // Declare the select variable we will use in our userInput function;
    char* select;
    // Call the userInput function;
    userInput(select);
    
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
	   "Spock vaporizes rock, and as it always has, rock crushes scissors.'\n\n");
}

// Define userInput function;
char* userInput(char* select) {
    // Print the prompt to the terminal;
    printf("Please enter your selection now: ");
    // Take user input as string;
    scanf("%s", select);
    // FOR TESTING PURPOSES
    printf("Test: %s\n", select);
}

// For testing purposes
