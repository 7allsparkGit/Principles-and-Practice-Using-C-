#pragma once
#include "std_lib_facilities.h"
#include  <ctype.h>

// some Struct
struct BookSt
{
	string titleSt;
	string authorSt;
	int copy_dateSt;
	string isbnSt;
	bool checkedSt;
};

class Book {
	

public:
	// constructor
		// ?? data validation : ISBN check form n-n-n-x / n is int, x is letter
	Book(string title, string author, int copy_date, string isbn, bool checked);
	Book();

	class Invalid {};
	bool IsIsbnValid(const string& isbn);
	bool IsInteger(const char& integer);
	bool IsLetter(const char& letter);

	// member properties
		// ISBN, title, author, copyright date
		// checked or not
		// store ISBN  as  a string	

	// member functions
		// get ISBN, title, author, copyright date
		//	check in and out 

	// non-modifying methods
	string GetTitle() const{ return title; }
	string GetAuthor() const { return author; }
	int GetCopyDate() const { return copy_date; }
	string GetIsbn() const { return isbn; }
	bool GetChecked() const { return checked; }

	// function check book in 
	// function check book out 

	
private:
	string title;
	string author;
	int copy_date;
	string isbn;
	bool checked;
}; // Book.h
   
// operator overloads
ostream& operator<<(ostream& os, const Book& book);