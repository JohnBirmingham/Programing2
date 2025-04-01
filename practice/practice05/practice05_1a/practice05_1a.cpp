#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums;
    int input;
    int newInput;
    int sum=0;
    std::cout << "Enter the amount of numbers you will be using: ";
    std::cin >> input;
    for (int i = 0; i < input; i++) {
        std::cout << "Enter a number: ";
        std::cin >> newInput;
        nums.push_back(newInput);
    }
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums.at(i) << ' ';
    }
    std::cout << '\n';
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        if (*it%2 == 0) {
           sum += *it;
        }
    }
    std::cout << "The sum of the even numbers is: " << sum;

    return 0;
}
