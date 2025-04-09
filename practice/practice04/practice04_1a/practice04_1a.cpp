// practice04_1a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
double TempConversion(double temp, char type='F') {
    double total;
    if (type == 'C') {
        total = (temp * 1.80) + 32;
    }
    else if (type == 'F') {
        total = (temp - 32) * 1.80;
    }
    return total;
}

int main()
{
    char type;
    double total;
    double temp;
    while(true){
        std::cout << "C. Convert Celsius to Fahrenheit" << std::endl;
        std::cout << "F. Convert Fahrenheit to Celsius" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cin >> type;
        std::cout << "Choose a temperature: ";
        std::cin >> temp;
        total = TempConversion(temp,type);
        std::cout << "Converted: " << total << std::endl;
    }
}
