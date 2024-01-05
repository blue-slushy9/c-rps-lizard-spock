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
