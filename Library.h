#ifndef library_h
#define library_h

#include <stdio.h>
#include <string>
#include <queue>
#include <list>
#include "Date.h"
#include "Book.h"

class Library {
private:
	list<Book> toBeCirculated;
	list<Book> archived;
	list<Employee*> employeeList;

public:
	Library();
	~Library();

	void printEmpList();
	void checkOutBook(string employeeName, string bookTitle, Date dateBookWasRequested);
	void addBook(string newBook, Date date);
	void addEmployee(string newEmployee, int priority);
	void returnBook(string bookToMove, Date date);
	
};

#endif
