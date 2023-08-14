#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructor
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    // Overloaded addition operator (+)
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overloaded subtraction operator (-)
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Overloaded multiplication operator (*)
    Complex operator*(const Complex& other) const {
        return Complex((real * other.real) - (imaginary * other.imaginary),
                       (real * other.imaginary) + (imaginary * other.real));
    }

    // Overloaded division operator (/)
    Complex operator/(const Complex& other) const {
        double denominator = (other.real * other.real) + (other.imaginary * other.imaginary);
        return Complex(((real * other.real) + (imaginary * other.imaginary)) / denominator,
                       ((imaginary * other.real) - (real * other.imaginary)) / denominator);
    }

    // Function to display the complex number
    void display() const {
        std::cout << real << " + " << imaginary << "i" << std::endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex product = c1 * c2;
    Complex quotient = c1 / c2;

    std::cout << "Complex number 1: ";
    c1.display();

    std::cout << "Complex number 2: ";
    c2.display();

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    diff.display();

    std::cout << "Product: ";
    product.display();

    std::cout << "Quotient: ";
    quotient.display();

    return 0;
}

