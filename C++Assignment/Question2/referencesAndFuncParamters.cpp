#include <stdio.h>

// Function to increment the value of an integer using a reference (pointer)
void incrementByReference(int *num) {
    (*num)++; // Increment the value pointed to by 'num'
}

int main() {
    int number = 10;

    printf("Before increment: %d\n", number);

    // Call the function to increment the value of 'number'
    incrementByReference(&number);

    printf("After increment: %d\n", number);

    return 0;
}

