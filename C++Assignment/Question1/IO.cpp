#include <iostream>

int main() {
	
    double num1, num2;

    // Get user input for the first number
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    // Get user input for the second number
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Perform calculations
    double sum = num1 + num2;
    double difference = num1 - num2;
    double product = num1 * num2;
    double quotient = num1 / num2;

    // Output the results
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;

    return 0;
}

