#include <iostream>
#include <vector>
#include <string>
#include <limits>

int getInt(const std::string& prompt) {
  int input;
  while (true) {
    std::cout << prompt;
    std::cin >> input;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer.\n";
    }
    else {
      std::cin.ignore();
      return input;
    }
  }
}

int Menu() {
  int returnNum;
  std::cout << "Welcome to number componder."<< std::endl;
  std::cout << "1. Add a whole number to the system." << std::endl;
  std::cout << "2. Print the numbers." << std::endl;
  std::cout << "3. Double the numbers inside." << std::endl;
  std::cout << "4. Add the numbers together." << std::endl;
  std::cout << "5. Find same numbers in the vector." << std::endl;
  std::cout << "6. Exit." << std::endl;
  returnNum = getInt("What option do you want to pick? ");
  return returnNum;
}

void PrintVector(const std::vector<int>& nums){
  std::cout << "Numbers in Vector: ";
  for(int i = 0; i < nums.size()-1; i++){
    std::cout << nums.at(i) << ", ";
  }
  std::cout << nums.back() << std::endl;
}

void DoubleVector(std::vector<int>& nums){
  std::cout << "Before: ";
  for(int i = 0; i < nums.size()-1; i++){
    std::cout << nums.at(i) << ", ";
  }
  std::cout << nums.back() << std::endl;
  for(int i = 0; i < nums.size(); i++){
    nums.at(i) *= 2;
  }
  std::cout << "Now: ";
  for(int i = 0; i < nums.size()-1; i++){
    std::cout << nums.at(i) << ", ";
  }
  std::cout << nums.back() << std::endl;
}
    
void CalculateSum(std::vector<int>& nums){
  int num;
  for(int i = 0; i < nums.size(); i++){
    num += nums.at(i);
  }
  std::cout << "The sum is " << num << "." << std::endl;
}

void FindMultiples(std::vector<int> nums, int inputNum) {
  for(int i=0; i < nums.size(); i++){
    if(nums.at(i) == inputNum){
      std::cout << nums.at(i) << ", ";
    }
    std::cout << std::endl;
  }
}

int main() {
  std::vector<int> nums;
  int menu;
  int temp;
  while(true) {
    menu = Menu();
    if(menu==1){
      nums.push_back(getInt("Please enter a whole number: "));
    }
    else if(menu==2){
      PrintVector(nums);
    }
    else if(menu==3){
      DoubleVector(nums);
    }
    else if(menu==4){
      CalculateSum(nums);
    }
    else if(menu==5){
      temp = getInt("What is the number you want to locate? ");
      FindMultiples(nums, temp);
    }
    else if(menu==6){
      break;
    }
    else {
      std::cout << "Invalid Input" << std::endl;
    }
  }
}
