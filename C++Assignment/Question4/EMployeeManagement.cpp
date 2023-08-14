#include <iostream>
#include <string>
#include <vector>

class Employee {
private:
    std::string name;
    int age;
    std::string designation;
    double salary;

public:
    // Constructor
    Employee(std::string name, int age, std::string designation, double salary)
        : name(name), age(age), designation(designation), salary(salary) {}

    // Function to display employee details
    void display() {
        std::cout << "Name: " << name << ", Age: " << age << ", Designation: " << designation << ", Salary: " << salary << std::endl;
    }

    // Function to update employee details
    void updateDetails(std::string newName, int newAge, std::string newDesignation, double newSalary) {
        name = newName;
        age = newAge;
        designation = newDesignation;
        salary = newSalary;
    }

    // Function to get employee name
    std::string getName() const {
        return name;
    }
};

class EmployeeManager {
private:
    std::vector<Employee> employees;

public:
    // Function to add a new employee
    void addEmployee(std::string name, int age, std::string designation, double salary) {
        Employee newEmployee(name, age, designation, salary);
        employees.push_back(newEmployee);
    }

    // Function to update employee details
    bool updateEmployee(std::string name) {
        for (size_t i = 0; i < employees.size(); i++) {
            if (employees[i].getName() == name) {
                std::string newName, newDesignation;
                int newAge;
                double newSalary;

                std::cout << "Enter new name: ";
                std::cin >> newName;
                std::cout << "Enter new age: ";
                std::cin >> newAge;
                std::cout << "Enter new designation: ";
                std::cin >> newDesignation;
                std::cout << "Enter new salary: ";
                std::cin >> newSalary;

                employees[i].updateDetails(newName, newAge, newDesignation, newSalary);
                std::cout << "Employee details updated successfully." << std::endl;
                return true;
            }
        }

        std::cout << "Employee not found." << std::endl;
        return false;
    }

    // Function to delete an employee
    bool deleteEmployee(std::string name) {
        for (size_t i = 0; i < employees.size(); i++) {
            if (employees[i].getName() == name) {
                employees.erase(employees.begin() + i);
                std::cout << "Employee deleted successfully." << std::endl;
                return true;
            }
        }

        std::cout << "Employee not found." << std::endl;
        return false;
    }

    // Function to display all employees' details
    void displayAllEmployees() {
        if (employees.empty()) {
            std::cout << "No employees in the records." << std::endl;
        } else {
            std::cout << "Employee Details:" << std::endl;
            for (const auto& employee : employees) {
                employee.display();
            }
        }
    }
};

int main() {
    EmployeeManager employeeManager;

    int choice;
    std::string name;

    do {
        std::cout << "\nEmployee Record Management" << std::endl;
        std::cout << "1. Add Employee" << std::endl;
        std::cout << "2. Update Employee Details" << std::endl;
        std::cout << "3. Delete Employee" << std::endl;
        std::cout << "4. Display All Employees" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::string name, designation;
            int age;
            double salary;

            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter age: ";
            std::cin >> age;
            std::cout << "Enter designation: ";
            std::cin >> designation;
            std::cout << "Enter salary: ";
            std::cin >> salary;

            employeeManager.addEmployee(name, age, designation, salary);
            break;

        case 2:
            std::cout << "Enter the name of the employee whose details you want to update: ";
            std::cin >> name;
            employeeManager.updateEmployee(name);
            break;

        case 3:
            std::cout << "Enter the name of the employee to be deleted: ";
            std::cin >> name;
            employeeManager.deleteEmployee(name);
            break;

        case 4:
            employeeManager.displayAllEmployees();
            break;

        case 5:
            std::cout << "Exiting the program." << std::endl;
            break;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (choice != 5);

    return 0;
}

