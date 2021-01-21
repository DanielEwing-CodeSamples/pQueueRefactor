#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {}

void PriorityQueue::addEmployee(Employee* temp) {
	WorkQueue.push_back(temp);
}

Employee* PriorityQueue::pop_max() { // pulls highest priority from queue : O(n)
	Employee* max = *WorkQueue.begin(); // assume max is first element
	vector<Employee*>::iterator it, toErase;
	it = toErase = WorkQueue.begin();
	it++; // start at second element so we don't compare max to itself
	for (it; it != WorkQueue.end(); it++) {             
		if (((max->getEmpPriority()*(max->getWait() - max->getAvgRetainTime()))) < (((*it)->getEmpPriority()*(*it)->getWait() - (*it)->getAvgRetainTime()))) { //priority*(wait-avgretain)
			max = *it;
			toErase = it;
		}
	}
	WorkQueue.erase(toErase);
	return max;
}

Employee* PriorityQueue::top() { // O(n)
	Employee* max = *WorkQueue.begin(); // assume max is first element
	vector<Employee*>::iterator it = WorkQueue.begin();
	it++; // start at second element so we don't compare max to itself
	for (it; it != WorkQueue.end(); it++) {
		if ((max->getWait() - max->getAvgRetainTime()) < ((*it)->getWait() - (*it)->getAvgRetainTime())) { // if new max is found, update pointer
			max = *it;
		}
	}
	return max;
}

bool PriorityQueue::empty() {
	return WorkQueue.size() < 1;
}