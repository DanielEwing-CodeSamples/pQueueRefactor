
#include "book.h"

Book::Book() {
	archived = true;
}


Book::Book(string bookName, Date start) {
	name = bookName;
	startDate = start;
	archived = true;
	lastHeld = start;
}

Book::Book(const Book& other) {
	name = other.name;
	startDate = other.startDate;
	endDate = other.endDate;
	archived = other.archived;
	waiting = other.waiting;
	lastHeld = other.lastHeld;
}

string Book::getname() {
	return name;
}

Date Book::getstartDate() {
	return startDate;
}

Date Book::getendDate() {
	return endDate;
}

bool Book::getarchived() {
	return archived;
}

Date Book::getHeld() {
	return lastHeld;
}

void Book::setname(string newName) {
	name = newName;
}

void Book::setstartDate(Date newDate) {
	startDate = newDate;
}

void Book::setendDate(Date newDate) {
	endDate = newDate;
}

void Book::setarchived(bool newBool) {
	archived = newBool;
}

void Book::setHeld(Date date) {
	lastHeld = date;
}

void::Book::addEmployeeToQueue(const list<Employee*> employeeList, string employeeName) {
	list<Employee*>::const_iterator iter;
	for (iter = employeeList.begin(); iter != employeeList.end(); iter++) {
		if ((*iter)->getName() == employeeName) {
			waiting.addEmployee(*iter);
			(*iter)->incrementNumBooksCheckedOut();
			cout << "Adding employee, " << employeeName << ", to the wait list for the book, " << name << ".\n";
		}
	}
}

void Book::populate_queue(const list<Employee*> empList) {
	list<Employee*>::const_iterator it;
	for (it = empList.begin(); it != empList.end(); it++) { // add all current employees to queue
		waiting.addEmployee(*it);
	}
}

Employee* Book::pop_max() {
	return waiting.pop_max();
}

Employee* Book::top() {
	return waiting.top();
}

bool Book::isEmpty() {
	return waiting.empty();
}
