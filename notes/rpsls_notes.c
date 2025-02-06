// EXAMPLE OF PROPER INITIALIZER

#include <stdio.h>

struct Player {
    int score;
    char name[20];
};

struct Game {
    struct Player player1;
    struct Player player2;
};

int main() {
    // Correct initializer
    struct Game myGame1 = {
        .player1 = { .score = 10, .name = "Alice" },
        .player2 = { .score = 8, .name = "Bob" }
    };

    // Incorrect initializer (will produce the mentioned error)
    struct Game myGame2 = {
        .computer = { .score = 5, .name = "AI" }  // Error: field name not in record or union initializer
    };

    return 0;
}

// END EXAMPLE INITIALIZER

######################################

// * is the dereference operator, it is used to access the value stored at the address
// held by a pointer;

// & is the address-of operator, it returns the memory address of a variable;

// DEREFERENCE OPERATOR * 
// takes you to the value which the pointer references; 

// When you DEREFERENCE a pointer, you are asking the program to go to the memory
// location specified by the pointer and retrieve the value stored there;

// ADDRESS-OF &
// brings you the memory address of a variable;


// EXAMPLES

// &rpslsDict retrieves the memory address of the variable, rpslsDict, which is then 
// used to print the dictionary, rpslsDict;
printDict(&rpslsDict);


// Declare a pointer and intialize it with the address of x;
int *ptr = &x;

// Dereference the pointer to access the value at the memory address it points to;
int value = *ptr;

// EXAMPLE CODE

#include <stdio.h>

int main() {
    int x = 42;

    // Declare a pointer and initialize it with the address of x
    int *ptr = &x;

    // Dereference the pointer to access the value at the memory address it points to
    int value = *ptr;

    // Print the value
    printf("The value of x is: %d\n", value);

    return 0;
}

// OUTPUT
// The value of x is: 42
