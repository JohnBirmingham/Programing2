// practice04_1a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int type;
    double total;
    double temp;
    while(true){
        std::cout << "1. Convert Celsius to Fahrenheit" << std::endl;
        std::cout << "2. Convert Fahrenheit to Celsius" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> type;
        std::cout << "Choose a temperature: ";
        std::cin >> temp;
        if (type == 1) {
            total = (temp * 1.80) + 32;
        }
        else if (type == 2) {
            total = (temp - 32) * 1.80;
        }
        std::cout << "Converted: " << total << std::endl;
    }
    
}
