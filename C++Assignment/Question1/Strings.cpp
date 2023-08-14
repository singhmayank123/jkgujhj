#include <iostream>
#include <string>
#include <cctype> // For std::tolower

bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        // Convert characters to lowercase to ignore case sensitivity
        char leftChar = std::tolower(str[left]);
        char rightChar = std::tolower(str[right]);

        if (!std::isalnum(leftChar)) {
            left++;
        } else if (!std::isalnum(rightChar)) {
            right--;
        } else if (leftChar != rightChar) {
            return false;
        } else {
            left++;
            right--;
        }
    }

    return true;
}

int main() {
    std::string inputString;
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);

    if (isPalindrome(inputString)) {

