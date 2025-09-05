#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

void displayEmployee(const Employee& emp) {
    cout << "ID: " << emp.id << endl;
    cout << "Name: " << emp.name << endl;
    cout << "Salary: $" << emp.salary << endl;
}

int main() {
    vector<Employee> employees = {
        {101, "Omit", 100000},
        {102, "Hitesh", 50000},
        {103, "Anik", 70000},
        {104, "Naeem", 60000},
        {105, "Hasan", 30000}
    };

    sort(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2) {
        return e1.salary > e2.salary;
    });

    cout << "Employees sorted by salary -> Highest to lowest \n";
    for_each(employees.begin(), employees.end(), displayEmployee);

    vector<Employee> highEarners;

    copy_if(employees.begin(), employees.end(), back_inserter(highEarners), [](const Employee& e) {
        return e.salary > 50000;
    });

    cout << "Employees who are high earners \n";
    for_each(highEarners.begin(), highEarners.end(), displayEmployee);

    double totalSalary = accumulate(employees.begin(), employees.end(), 0.0, [](double sum, const Employee& e) {
        return sum + e.salary;
    });

    cout << "Total salary: $" << totalSalary << endl;
    double averageSalary = totalSalary / employees.size();
    cout << "AverageSalary: $" << averageSalary << endl;

    auto highestPaid = max_element(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2) {
        return e1.salary < e2.salary;
    });

    cout << "Highest Paid: " << highestPaid->name << " $" << highestPaid->salary << endl;

    auto lowestPaid = min_element(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2) {
        return e1.salary < e2.salary;
    });

    cout << "Lowest Paid: " << lowestPaid->name << " $" << lowestPaid->salary << endl;

    return 0;
}