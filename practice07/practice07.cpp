#include <iostream>
#include <vector>
#include <fstream>

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
        std::cout << "Commission Rate" << commissionRate * 100 << ", ";
        std::cout << "Salary: $" << calculateSalary() << std::endl;
    }
};
void TakeFileInput(std::vector<Employee*>& employeeList){
    
}
int main()
{
    std::vector<Employee*> employeeList;
    employeeList.push_back(new HourlyEmployee(102, "John", 20.02, 160));
    employeeList.at(0)->displayInfo();
    for (int i = 0; i < employeeList.size(); i++) {
        delete employeeList.at(i);
    }
}