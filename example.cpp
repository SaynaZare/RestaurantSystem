#include <iostream>
#include <vector>
using namespace std;

//Base Class
class Employee {
protected:
	string Name;
	int Id;

public:
	//Constructor to initialise variables
	Employee(string name, int id) : Name(name), Id(id) {}
	//pure virtual functions
	virtual double calcPay() = 0;
	virtual void display() = 0;
};

//Derive the child classes
//Child Class            inheriting a class which then becomes the base class
class HourlyEmployee : public Employee {
private:
	double HourlyRate;
	int HoursWorked;

public:
	HourlyEmployee(string name, int id, double hourlyrate, int hoursworked)
		: Employee(name, id), HourlyRate(hourlyrate),
		HoursWorked(hoursworked) {

		//Empty implementation
	}

	double calcPay() {
		return HourlyRate * HoursWorked;
	}
	void display() {
		cout << "Employee Name : " << Name << endl
			<< "Employee Id : " << Id << endl
			<< " Hourly Rate : " << HourlyRate << endl
			<< "Hours worked : " << HoursWorked << endl;
	}
};

class FullTimeEmployee : public Employee
{
private:
	double Salary;
public:
	FullTimeEmployee(string name, int id, double salary) : Employee(name, id), Salary(salary) {}

	double calcPay() {
		return Salary / 12;
	}

	void display() {
		cout << "Employee Name : " << Name << endl
			<< "Employee Id : " << Id << endl
			<< "Salary : " << Salary << endl;
	}
};

void DisplayEmployees(vector<Employee*>& employees) {
	for (Employee* e : employees)
	{
		cout << "\n\n**Employee**\n\n";
		e->display();
		cout << "Monthly pay is: " << e->calcPay();

	}
}

void addEmployee(vector<Employee*>& employees)
{
	string name;
	int id, type;
	double salary, hourlyrate;
	int hoursworked;

	cout << endl;
	cout << "Enter Employee Name: ";
	cin >> name;

	cout << "Enter Employee ID: ";
	cin >> id;

	cout << "Enter the Employee type: (1 for Salaried, 2 for Hourly) : ";
	cin >> type;

	if (type == 1)
	{
		cout << endl;
		cout << "Enter the Employee's Full Salary: ";
		cin >> salary;
		employees.push_back(new FullTimeEmployee(name, id, salary));
		cout << endl;
	}
	else if (type == 2)
	{
		cout << "Employee's Hourly Rate is: ";
		cin >> hourlyrate;

		cout << "\nEmployee's hours worked :";
		cin >> hoursworked;

		employees.push_back(new HourlyEmployee(name, id, hourlyrate, hoursworked));
		cout << endl;
	}
}

int main()
{
	vector<Employee*> employees;
	int choice;
	do {
		cout << "\n\nHR Payroll System" << endl;
		cout << "1. Add Employee" << endl;
		cout << "2. Display all Employees" << endl;
		cout << "3. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			addEmployee(employees);
			break;
		case 2:
			DisplayEmployees(employees);
			break;
		case 3:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "Invalid choice! Please try again" << endl;
			break;
		}
	} while (choice != 3);

}

