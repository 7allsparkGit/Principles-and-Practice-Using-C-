#pragma once
#include "std_lib_facilities.h"
#include  <ctype.h>

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
	enum Genre 
	{ 
		fiction = 0, nonfiction, periodical, biography, children 
	};
	Book(string title, string author, int copy_date, string isbn, Genre gen, bool checked);
	Book();

	class Invalid {};
	bool IsIsbnValid(const string& isbn);
	bool IsInteger(const char& integer);
	bool IsLetter(const char& letter);
	
	string GetTitle() const{ return title; }
	string GetAuthor() const { return author; }
	int GetCopyDate() const { return copy_date; }
	string GetIsbn() const { return isbn; }
	Genre GetGenre() const { return genre; }
	bool GetChecked() const { return checked; }

	string GetGenreFromEnum() const;
	// modifying methods 
	void checkOut();
	void checkIn();
private:
	string title;
	string author;
	int copy_date;
	string isbn;
	Genre genre;
	bool checked;
}; // Book.h
  
// operator overloads
bool operator==(const Book& b1, const Book& b2);
bool operator!=(const Book& b1, const Book& b2);
ostream& operator<<(ostream& os, const Book& book);

class Patron {
public:
	// constructor
		// default constructor
	Patron(string UserName, int CardNumber, double LibraryFee);
	Patron();
	// non modifying functions
	string GetUserName() const{ return UserName; }
	int GetCardNumber() const { return CardNumber; }
	double GetLibraryFee() const { return LibraryFee; }
		// getCardNumber
		// getLibraryFees
		
		// bIsUserOwesFee

	// mod functions
		// setFee
private:

	//member functions
	string UserName;
	int CardNumber;
	double	LibraryFee; //( if exists )


};
// other methods
// operator overloads

class Library
{
	// struct Transaction - include Book, Patron, Chrono

	// make a vector of Transaction

	// function to add books, patrons to the library
		// check out books function
		// check the user and book if check out - Error
			// check fee of owner - Error of there is fee
		// if GOOD create Transaction 
			// place it in vector Transaction
	// function that return Patron's name who owe fees
};