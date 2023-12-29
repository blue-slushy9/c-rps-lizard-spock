#include <stdio.h>


// You want to declare your functions you plan to use in your program as
// function prototypes before you call them inside of main() or define them;

// This is the introduction to the game, it is just text that will print to
// the terminal;
void intro();

// These are the actual rules to the game, again it is simple text that will
// print to the terminal;
void rules();

// main function will contain all other functions in this program;
int main() {
    // Call the introduction function;
    void intro();
    // Call the rules function;
    void rules();

    return 0;
}

// Define intro function;
void intro() {
    printf("This is Rock-Paper-Scissors-Lizard-Spock, from the hit TV show, Big\n"
           "Bang Theory! It is similar to Rock-Paper Scissors, but with\n"
	   "two additional options: Lizard and Spock.\n");
}

// Define rules function;
void rules() {
    printf("Nobody can explain the rules like Sheldon Cooper can, so I will\n" 
	   "simply quote him: 'Scissors decapitate Scissors cuts paper,\n" 
	   "paper covers rock, rock crushes lizard, lizard poisons Spock,\n" 
	   "Spock smashes scissors, scissors decapitates lizard, lizard eats\n" 
	   "paper, paper disproves Spock, Spock vaporizes rock, and as it always\n" 
	   "has, rock crushes scissors."
}
