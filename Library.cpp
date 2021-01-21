#include "Library.h"
#include<iostream>
using namespace std;

Library::Library() {
}


void Library::addBook(string newBook, Date date) {
	Book tempBook(newBook, date);
	archived.push_back(tempBook);
}

void Library::addEmployee(string name, int priority) {
	Employee* temp;
	temp = new Employee(name, priority);
	employeeList.push_back(temp);
}

void Library::checkOutBook(string employeeName, string bookTitle, Date dateBookWasRequested) {  // places the employee onto the books wait list if the given employee name is on the list on employees
	list<Employee*>::iterator iterat;
	for (iterat = employeeList.begin(); iterat != employeeList.end(); iterat++) { // check if the employee requesting the book is in the list of employees
		if ((*iterat)->getName() == employeeName) {
			list<Book>::iterator iter;
			for (iter = toBeCirculated.begin(); iter != toBeCirculated.end(); iter++) { // check list of checked out books for the title, if true add employee to queue
				if (iter->getname() == bookTitle) {
					iter->addEmployeeToQueue(employeeList, employeeName);
					iter->setstartDate(dateBookWasRequested);
					return;
				}
			}
			for (iter = archived.begin(); iter != archived.end(); iter++) {	// check list of archived books for the title, if true add book to circulation list, which passes 
				if (iter->getname() == bookTitle) {							// it to the employee and removes it from the archive. 
					iter->addEmployeeToQueue(employeeList, employeeName);
					iter->setstartDate(dateBookWasRequested);
					cout << "Removing book, " << bookTitle << ", from archive for employee, " << (*iterat)->getName() << "\n";
					iter->setarchived(false);
					toBeCirculated.push_back(*iter);
					archived.erase(iter);
					return;
				}
			}
			cerr << "The book, " << bookTitle << ", is not in the system.\n\n";
			return;
		}
	}
	cerr << "No employee named " << employeeName << " in the system. Speak to a system administrator to add " << employeeName << " to the employee list.\n\n";
}

void Library::printEmpList() {
	list<Employee*>::iterator iterat;
	for (iterat = employeeList.begin(); iterat != employeeList.end(); iterat++) {
		(*iterat)->printEmployee();
	}
}
void Library::returnBook(string bookToMove, Date date) {
	Employee* next, * prev; // prev is employee that is popped
	list<Book>::iterator it;
	for (it = toBeCirculated.begin(); it != toBeCirculated.end(); it++) { // find book : O(n)
		if (it->getname() == bookToMove) {
			prev = it->pop_max(); // pop max, save to prev
			prev->retain(date - it->getHeld()); // retain = current date - last pass of book
			if (!it->isEmpty()) { // employees waiting on this book
				next = it->top(); // next is now max
				next->wait(date - it->getstartDate()); // wait = current date - book start date
				it->setHeld(date); // save pass date for next employee
				cout << "Circulating book, " << bookToMove << ", to next employee, " << next->getName() << ".\n";
				return;
			}
			else { // circulation complete
				it->setarchived(true);
				it->setendDate(date);
				it->setHeld(date);
				archived.push_back(*it); // archive
				toBeCirculated.erase(it); // erase
				cout << "No more employees waiting on the book, "<< bookToMove << ", returning it to the library.\n";
				return;
			}
			break;
		}
	}
	cerr << "The book, " << bookToMove << ", is not in the system.\n" << endl;
}

Library::~Library() {
	list<Employee*>::iterator it;
	for (it = employeeList.begin(); it != employeeList.end(); it++) {
		delete* it;
	}
}