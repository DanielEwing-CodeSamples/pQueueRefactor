#include "Employee.h"

Employee::Employee() {
	name = "unknown";
	waitTime = 0;
	retainTime = 0;
	numOfBooksCheckedOut = 0;
}

Employee::Employee(string newName, int priority) {
	name = newName;
	waitTime = 0;
	retainTime = 0;
	numOfBooksCheckedOut = 0;
	employeePriority = priority;
}

const Employee& Employee::operator = (const Employee& rhs) {
	name = rhs.name;
	waitTime = rhs.waitTime;
	retainTime = rhs.retainTime;
	numOfBooksCheckedOut = rhs.numOfBooksCheckedOut;
	return *this;
}

void Employee::setName(string newName) {
	name = newName;
}

void Employee::wait(double wait) {
	waitTime += wait;
}

void Employee::retain(double retain) {
	retainTime += retain;
}

string Employee::getName() {
	return name;
}

double Employee::getWait() {
	return waitTime;
}

double Employee::getRetain() {
	return retainTime;
}

double Employee::getAvgRetainTime() {
	if (numOfBooksCheckedOut < 1) {
		return 5;
	}
	return retainTime / numOfBooksCheckedOut;
}

int Employee::getEmpPriority() {
	return employeePriority;
}

void Employee::incrementNumBooksCheckedOut() {
	numOfBooksCheckedOut++;
}

void Employee::printEmployee() {
	cout << "Employee, " << name << ", has checked out " << numOfBooksCheckedOut << " books, has waited a total of " << waitTime << " days, has total retain time of " << retainTime << 
		"\n days and has an average retain time of " << setprecision(2) << getAvgRetainTime() << " days. Employee total priority ranking is " << (getWait() - getAvgRetainTime())*employeePriority << ".\n";
}

bool operator<(const Employee& lhs, const Employee& rhs) {
	return ((lhs.waitTime - lhs.retainTime) < (rhs.waitTime - rhs.retainTime));
}

bool operator>(const Employee& lhs, const Employee& rhs) {
	return ((lhs.waitTime - lhs.retainTime) > (rhs.waitTime - rhs.retainTime));
}