// practice04_3a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

int main()
{
    int intInput;
    std::string input;
    std::list<std::string> tasks;
    int i=1;
    while (true) {
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Remove Task" << std::endl;
        std::cout << "3. Show Tasks" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> intInput;
        if (intInput == 1) {
            std::cout << "Enter task: ";
            std::cin >> input;
            tasks.push_back(input);
            std::cout << "Task added!" << std::endl;
        }
        else if (intInput == 2) {
            std::cout << "Enter task number to remove: ";
            std::cin >> intInput;
            auto it = std::next(tasks.begin(), intInput - 1);
            it=tasks.erase(it);
            std::cout << "Task removed!" << std::endl;
        }
        else if (intInput == 3) {
            std::cout << "Tasks: " << std::endl;
            for (auto help: tasks) {
                std::cout << i << ". " << help << std::endl;
                i++;
            }
        }
        else if (intInput == 4) {
            break;
        }
    }
}