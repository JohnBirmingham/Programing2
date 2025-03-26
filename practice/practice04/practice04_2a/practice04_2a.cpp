// practice04_2a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T>

T calculate() {
    char operation;
    T numOne;
    T numTwo;
    T output;
    std::cout << "Enter First Number: ";
    std::cin >> numOne;
    std::cout << "Enter Second Number: ";
    std::cin >> numTwo;
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;
    if (operation == '*') {
        std::cout << numOne * numTwo << std::endl;
    }
    else if (operation == '-') {
        std::cout << numOne - numTwo << std::endl;
    }
    else if (operation == '+') {
        std::cout << numOne + numTwo << std::endl;
    }
    else if (operation == '/') {
        std::cout << numOne / numTwo << std::endl;
    }
    output = 1;
    return output;
}

int main()
{
    while (true) {
        calculate<double>();
    }
}