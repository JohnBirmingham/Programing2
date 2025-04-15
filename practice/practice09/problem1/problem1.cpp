#include <iostream>

int main()
{
    float redPotion{ 0.0f };
    float bluePotion{ 0.0f };
    float* flask{ nullptr };
    std::string input;
    double dInput;
    while (true) {
        std::cout << "Do you want to mix a Red or Blue Potion: ";
        std::cin >> input;
        if (input == "Red") {
            flask = &redPotion;
        }
        else if (input == "Blue") {
            flask = &bluePotion;
        }
        else if (input == "Done") {
            break;
        }
        std::cout << "How many millimeters do you want to put in the potion? ";
        std::cin >> dInput;
        *flask = dInput;
        std::cout << "Red: " << redPotion << std::endl;
        std::cout << "Blue: " << bluePotion << std::endl;
    }
}