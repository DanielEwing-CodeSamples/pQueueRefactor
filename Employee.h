#ifndef employee_h
#define employee_h

#include <stdio.h>
#include <string>
#include "Date.h"
#include<iostream>

using namespace std;

class Employee {
private:
	double waitTime;
	double retainTime;
	int numOfBooksCheckedOut;
	int employeePriority;
	string name;

public:
	Employee();
	Employee(string newName, int priority);
	const Employee& operator = (const Employee& rhs);

	void setName(string newName);
	void wait(double wait);
	void retain(double retain);
	void incrementNumBooksCheckedOut();
	void printEmployee();

	string getName();
	double getWait();
	double getRetain();
	double getAvgRetainTime();
	int getEmpPriority();

	friend bool operator<(const Employee& lhs, const Employee& rhs);
	friend bool operator>(const Employee& lhs, const Employee& rhs); 
};

#endif 
