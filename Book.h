#ifndef book_h
#define book_h

#include "PriorityQueue.h"
#include "Date.h"
#include "Employee.h"
#include <stdio.h>
#include <string>
#include <list>


class Book {
private:
	string name;
	Date startDate;
	Date endDate;
	bool archived;
	PriorityQueue waiting;
	Date lastHeld;
public:
	Book();
	Book(string bookName, Date start);
	Book(const Book& other);

	string getname();
	Date getstartDate();
	Date getendDate();
	bool getarchived();
	Date getHeld();

	void setname(string newName);
	void setstartDate(Date newDate);
	void setendDate(Date newDate);
	void setarchived(bool newBool);
	void setHeld(Date date);

	void addEmployeeToQueue(const list<Employee*> employeeList, string employeeName);
	void populate_queue(list<Employee*> empList);
	Employee* pop_max();
	Employee* top();
	bool isEmpty();
};

#endif /* book_hpp */

