// practice04_2a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T>

void calculate() {
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
}

int main()
{
    char c;
    while (true) {
        std::cout << "Do you want int(i) or a double(d): ";
        std::cin >> c;
        if(c == 'i'){
            calculate<int>();
        }
        else if (c == 'd') {
            calculate<double>();
        }
    }
}