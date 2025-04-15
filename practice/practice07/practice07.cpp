/*  AI has been used in this project to assist in creating the file input system  */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Employee {
private:
    std::string name;
    int id;
public:
    Employee(std::string name, int id) :name{ name }, id { id } {}
    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const {
        std::cout << "ID: " << id << ", ";
        std::cout << "Name: " << name << ", ";
    }
};
class SalariedEmployee :public Employee {
private:
    double monthlySalary;
public:
    SalariedEmployee(int id, std::string name, double monthlySalary) :Employee{ name, id }, monthlySalary { monthlySalary } {}
    double calculateSalary() const override {
        return monthlySalary;
    }
    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << "Type: Salaried, ";
        std::cout << "Monthly Salary: $" << monthlySalary << std::endl;
    }
};
class HourlyEmployee :public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    HourlyEmployee(int id, std::string name, double hourlyRate, int hoursWorked) :Employee{ name, id }, hourlyRate{ hourlyRate }, hoursWorked{ hoursWorked }{}
    double calculateSalary() const override {
        return hoursWorked * hourlyRate;
    }
    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << "Type: Hourly, ";
        std::cout << "Hours Worked: " << hoursWorked << ", ";
        std::cout << "Hourly Rate: $" << hourlyRate << ", ";
        std::cout << "Salary: $" << calculateSalary() << std::endl;
    }
};
class CommissionEmployee :public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;
public:
    CommissionEmployee(int id, std::string name, double baseSalary, double salesAmount, double commissionRate) :Employee{ name, id }, baseSalary{ baseSalary }, salesAmount{ salesAmount }, commissionRate{ commissionRate }{}
    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }
    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << "Type: Commission, ";
        std::cout << "Base Salary: $" << baseSalary << ", ";
        std::cout << "Sales: $" << salesAmount << ", ";
        std::cout << "Commission Rate: " << commissionRate * 100 << "%, ";
        std::cout << "Salary: $" << calculateSalary() << std::endl;
    }
};
void TakeFileInput(std::vector<Employee*>& employeeList) {
    std::string filename = "employees.txt";
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        std::string type;
        while (inputFile >> type) {
            int id;
            std::string name;
            if (type == "Salaried") {
                double salary;
                inputFile >> id >> name >> salary;
                employeeList.push_back(new SalariedEmployee(id, name, salary));
            }
            else if (type == "Hourly") {
                double hourlyRate;
                int hoursWorked;
                inputFile >> id >> name >> hourlyRate >> hoursWorked;
                employeeList.push_back(new HourlyEmployee(id, name, hourlyRate, hoursWorked));
            }
            else if (type == "Commission") {
                double baseSalary, salesAmount, commissionRate;
                inputFile >> id >> name >> baseSalary >> salesAmount >> commissionRate;
                employeeList.push_back(new CommissionEmployee(id, name, baseSalary, salesAmount, commissionRate));
            }
        }
        inputFile.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

int main()
{
    std::vector<Employee*> employeeList;
    TakeFileInput(employeeList);
    for (int i = 0; i < employeeList.size(); i++) {
        employeeList.at(i)->displayInfo();
    }
    for (int i = 0; i < employeeList.size(); i++) {
        delete employeeList.at(i);
    }
}