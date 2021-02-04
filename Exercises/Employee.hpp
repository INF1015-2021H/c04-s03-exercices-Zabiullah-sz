///
/// Classe d'employé dans une compagnie.
///

#pragma once


#include <cstddef>
#include <cstdint>

#include <string>

using namespace std;


class Employee {
public:
	//Employee(); // Si on n'en met pas un, le compilateur n'en met pas un pour nous.
	Employee(const string& name, double salary = 0.0);
	~Employee();

	double getSalary() const;
	const string& getName() const;
	void setSalary(double salary);

private:
	string name_;
	double salary_;
};

