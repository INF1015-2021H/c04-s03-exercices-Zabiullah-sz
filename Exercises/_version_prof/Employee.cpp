///
/// Classe d'employé dans une compagnie.
///


#include <cstddef>
#include <cstdint>

#include <iostream>
#include <string>

#include "Employee.hpp"

using namespace std;

// TODO: Les définitions.

Employee::Employee() {
	cout << "Employee()" << "\n";
}

Employee::Employee(const string& name, double salary)
: name_(name),
  salary_(salary) {
	cout << "Employee(const string&, double)" << "\n";
}

Employee::~Employee() {
	cout << "~Employee() : " << name_ << "\n";
}

double Employee::getSalary() const {
	return salary_;
}

const string& Employee::getName() const {
	return name_;
}

void Employee::setSalary(double salary) {
	salary_ = salary;
}

