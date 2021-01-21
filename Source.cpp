#include <iostream>
#include <queue>
#include <list>
#include "Book.h"
#include "Library.h"

int main() {
	Library CompanyLibrary;

	CompanyLibrary.addEmployee("Adam Smith", 1);
	CompanyLibrary.addEmployee("Sam White", 2);
	CompanyLibrary.addEmployee("Ann Perkins", 2);
	CompanyLibrary.addEmployee("Ann Peters", 3);

	CompanyLibrary.addBook("Software Engineering", Date(2020, 3, 1, DateFormat::US));
	CompanyLibrary.addBook("Chemistry", Date(2020, 3, 1, DateFormat::US));

	CompanyLibrary.checkOutBook("Ann Perkins", "Chemistry", Date(2020, 3, 1, DateFormat::US));
	CompanyLibrary.checkOutBook("Adam Smith", "Software Engineering", Date(2020, 3, 5, DateFormat::US));
	CompanyLibrary.checkOutBook("Ann Perkins", "Software Engineering", Date(2020, 3, 6, DateFormat::US));
	CompanyLibrary.returnBook("Chemistry", Date(2020, 3, 6, DateFormat::US));
	CompanyLibrary.checkOutBook("Sam White", "Chemistry", Date((2020, 3, 7, DateFormat::US)));
	
	CompanyLibrary.returnBook("Software Engineering", Date(2020, 3, 12, DateFormat::US));
	CompanyLibrary.returnBook("Software Engineering", Date(2020, 3, 20, DateFormat::US));
	CompanyLibrary.returnBook("Chemistry", Date(2020, 3, 22, DateFormat::US));

	CompanyLibrary.printEmpList();

	system("pause");
	return 0;
}