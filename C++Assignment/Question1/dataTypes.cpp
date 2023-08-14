#include <iostream>
#include <limits>

int main() {
    // Integer data types
    int integerNumber = 42;
    short shortNumber = 12345;
    long longNumber = 1234567890;
    long long veryLongNumber = 9876543210;

    // Floating-point data types
    float floatNumber = 3.14f;
    double doubleNumber = 2.718281828459045;
    long double longDoubleNumber = 1.618033988749894848;

    // Character data type
    char character = 'A';

    // Boolean data type
    bool booleanValue = true;

    // Output the values and limits of the data types
    std::cout << "Integer Number: " << integerNumber << ", Size: " << sizeof(int) << " bytes, Min: " << std::numeric_limits<int>::min() << ", Max: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Short Number: " << shortNumber << ", Size: " << sizeof(short) << " bytes, Min: " << std::numeric_limits<short>::min() << ", Max: " << std::numeric_limits<short>::max() << std::endl;
    std::cout << "Long Number: " << longNumber << ", Size: " << sizeof(long) << " bytes, Min: " << std::numeric_limits<long>::min() << ", Max: " << std::numeric_limits<long>::max() << std::endl;
    std::cout << "Very Long Number: " << veryLongNumber << ", Size: " << sizeof(long long) << " bytes, Min: " << std::numeric_limits<long long>::min() << ", Max: " << std::numeric_limits<long long>::max() << std::endl;

    std::cout << "Float Number: " << floatNumber << ", Size: " << sizeof(float) << " bytes, Min: " << std::numeric_limits<float>::min() << ", Max: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Double Number: " << doubleNumber << ", Size: " << sizeof(double) << " bytes, Min: " << std::numeric_limits<double>::min() << ", Max: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "Long Double Number: " << longDoubleNumber << ", Size: " << sizeof(long double) << " bytes, Min: " << std::numeric_limits<long double>::min() << ", Max: " << std::numeric_limits<long

