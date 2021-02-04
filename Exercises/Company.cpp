///
/// Une compagnie avec des employés.
///


#include <cstddef>
#include <cstdint>

#include <string>
#include <iostream>

#include <cppitertools/range.hpp>

#include "Employee.hpp"

#include "Company.hpp"

using namespace std;
using namespace iter;


// TODO: Les définitions.

void Company::print() const {
	cout << "Name: " << name_ << "\n"
	     << "President: " << president_.getName() << "\n"
	     << "Employees (" << numEmployees_ << "):" << "\n";
	for (int i : range(numEmployees_))
		cout << "  " << employees_[i]->getName() << " (" << employees_[i]->getSalary() << ")" << "\n";
}
