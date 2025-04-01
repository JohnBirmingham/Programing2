#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = { 3, 1, 4, 1, 5, 9, 2, 6 };

    auto maxElement = std::max_element(nums.begin(), nums.end());
    std::cout << "The maximum element is: " << *maxElement << std::endl;
    auto minElement = std::min_element(nums.begin(), nums.end());
    std::cout << "Then minimum element is: " << *minElement << std::endl;

    return 0;
}