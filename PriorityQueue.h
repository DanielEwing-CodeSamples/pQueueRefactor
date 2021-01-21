#ifndef PriorityQueue_h
#define PriorityQueue_h

#include <stdio.h>
#include <list>
#include "Employee.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class PriorityQueue {
private:
	vector<Employee*> WorkQueue;
public:
	PriorityQueue();
	void addEmployee(Employee* tempEmployee);
	Employee* pop_max();
	Employee* top();
	bool empty();
};

#endif