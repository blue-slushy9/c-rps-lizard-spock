#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Got this code from ChatGPT, I plan on using it to help me get practice
// with pointers, references, etc.

// Function to copy a single string
char* copyString(const char* original) {
    // Allocate memory for the new string, including the null terminator
    char* copy = malloc((strlen(original) + 1) * sizeof(char));
    if (copy == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Copy the content of the original string to the new string
    strcpy(copy, original);

    return copy;
}

int main() {
    // Original string
    char original[] = "Hello, World!";

    // Call the function to copy the string
    char* copy = copyString(original);

    // Print the copied string
    printf("Original: %s\n", original);
    printf("Copy: %s\n", copy);

    // Free the allocated memory for the copied string
    free(copy);

    return 0;
}
