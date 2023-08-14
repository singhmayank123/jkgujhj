#include <iostream>

bool isPrime(int number) {
    if (number <= 1)
        return false;
    if (number <= 3)
        return true;

    if (number % 2 == 0 || number % 3 == 0)
        return false;

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0)
            return false;
    }

    return true;
}

int main() {
    int N;
    std::cout << "Enter the value of N: ";
    std::cin >> N;

    int count = 0;
    std::cout << "The first " << N << " prime numbers are:" << std::endl;

    for (int number = 2; count < N; number++) {
        if (isPrime(number)) {
            std::cout << number << " ";
            count++;
        }
    }

    std::cout << std::endl;

    return 0;
}

