// practice03.cpp (Buggy Code to be tested)
#include <iostream>
#include <vector>

class MathUtils {
public:
    static int sumRange(int start, int end) {
        int sum = 0;
        for (int i = start; i <= end; i++) { // Bug: Off-by-one error
            sum += i;
        }
        return sum;
    }

    static bool containsNegative(const std::vector<int>& numbers) {
        for (int i = 0; i <= numbers.size(); i++) { // Bug invalid type
            if (numbers[i] < 0) { // Bug wrong value type to detect negative great for positives though
                return true;
            }
        }
        return false;
    }

    static int findMax(const std::vector<int>& numbers) {
        if (numbers.empty() == 1) return 0; // Bug 
        int maxVal = numbers[0];
        for (int i = 1; i <= numbers.size(); i++) { // Bug invalid type
            if (numbers[i] > maxVal) { // Bug should just be greater than.
                maxVal = numbers[i];
            }
        }
        return maxVal;
    }
};

int main() {
    std::cout << "Sum from 1 to 5: " << MathUtils::sumRange(1, 5) << std::endl;
    std::vector<int> values = { 3, -1, 5, 7 };
    std::cout << "Contains negative? " << MathUtils::containsNegative(values) << std::endl;
    std::cout << "Max value: " << MathUtils::findMax(values) << std::endl;
    return 0;
}