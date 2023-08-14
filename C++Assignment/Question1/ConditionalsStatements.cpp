#include <iostream>

int main() {
    // Set the account balance and PIN
    double accountBalance = 1000.0;
    int pin = 1234;

    // Get user input for PIN
    int enteredPin;
    std::cout << "Welcome to the ATM!" << std::endl;
    std::cout << "Please enter your PIN: ";
    std::cin >> enteredPin;

    // Verify the PIN
    if (enteredPin != pin) {
        std::cout << "Invalid PIN. Exiting..." << std::endl;
        return 0;
    }

    // User has entered the correct PIN
    std::cout << "Login successful!" << std::endl;

    // Get user input for the withdrawal amount
    double withdrawalAmount;
    std::cout << "Your account balance is $" << accountBalance << std::endl;
    std::cout << "Enter the amount you want to withdraw: $";
    std::cin >> withdrawalAmount;

    // Check if the withdrawal amount is valid
    if (withdrawalAmount <= 0 || withdrawalAmount > accountBalance) {
        std::cout << "Invalid withdrawal amount. Please enter a valid amount within your account balance." << std::endl;
    } else {
        // Perform the withdrawal
        accountBalance -= withdrawalAmount;
        std::cout << "Withdrawal successful!" << std::endl;
        std::cout << "Remaining balance: $" << accountBalance << std::endl;
    }

    return 0;
}

