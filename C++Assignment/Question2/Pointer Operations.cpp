#include <stdio.h>

// Function to swap the values of two variables using pointers
void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Get the addresses of the variables using & operator
    int *ptr1 = &num1;
    int *ptr2 = &num2;

    // Call the swap function to swap the values
    swap(ptr1, ptr2);

    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

