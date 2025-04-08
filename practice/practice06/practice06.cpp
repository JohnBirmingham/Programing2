#include "MixedFraction.h"
#include "Fraction.h"
#include <iostream>
Fraction FractionInput() {
    int num, den;
    std::cout << "Enter numerator: ";
    std::cin >> num;
    std::cout << "Enter denominator (not 0): ";
    std::cin >> den;
    return Fraction(num, den);
}
void menu() {
    std::cout << "1. Enter a fraction manually" << std::endl;
    std::cout << "2. Add a fraction" << std::endl;
    std::cout << "3. Subtract a fraction" << std::endl;
    std::cout << "4. Multiply by a fraction" << std::endl;
    std::cout << "5. Divide by a fraction" << std::endl;
    std::cout << "6. Display as Mixed Fraction" << std::endl;
    std::cout << "7. Clear Fraction" << std::endl;
    std::cout << "8. Exit" << std::endl;
}
int main(){
    int choice;
    Fraction currentFrac;
    Fraction otherFrac;
    while (true) {
        std::cout << "Since your current fraction is " << currentFrac << ".\nWhat do you want to do?\n";
        menu();
        std::cin >> choice;
        if (choice == 1) {
            currentFrac = FractionInput();
            std::cout << "Current fraction: " << currentFrac << "\n";
        }
        else if (choice == 2) {
            std::cout << "Enter fraction to add:\n";
            otherFrac = FractionInput();
            currentFrac = currentFrac + otherFrac;
            std::cout << "The sum of the fractions is: " << currentFrac << "\n";
        }
        else if (choice == 3) {
            std::cout << "Enter fraction to subtract:\n";
            otherFrac = FractionInput();
            currentFrac = currentFrac - otherFrac;
            std::cout << "The difference of the fractions is: " << currentFrac << "\n";
        } 
        else if (choice == 4) {
            std::cout << "Enter fraction to multiply:\n";
            otherFrac = FractionInput();
            currentFrac = currentFrac * otherFrac;
            std::cout << "The product of the fractions is: " << currentFrac << "\n";
        }
        else if (choice == 5) {
            std::cout << "Enter fraction to divide by:\n";
            otherFrac = FractionInput();
            currentFrac = currentFrac / otherFrac;
            std::cout << "The quotient of the fractions is: " << currentFrac << "\n";
        }
        else if (choice == 6) {
            MixedFraction newMixedFrac(currentFrac);
            std::cout << "The fraction in mixed form is: " << newMixedFrac << "\n";
        }
        else if (choice == 7) {
            currentFrac = Fraction();
            std::cout << "The fraction has been reset to: " << currentFrac << "\n";
        }
        else if (choice == 8) {
            break;
        }
        else {
            std::cout << "Invalid choice. Try again.\n";
        }    
    }
}
