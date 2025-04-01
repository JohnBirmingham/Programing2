#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    int loop;
    int num;
    std::vector<int> nums;
    std::cout << "Enter the size of the list: ";
    std::cin >> loop;
    for (int i = 1; i <= loop; i++) {
        std::cout << "Enter Number: ";
        std::cin >> num;
        nums.push_back(num);
    }
    std::for_each(nums.begin(), nums.end(), [](int n) {
        std::cout << n * n << std::endl;
    });
    int sum = std::accumulate(nums.begin(), nums.end(), 0, [](int acc, int n) {return acc + n * n; });
    std::cout << sum << std::endl;
}