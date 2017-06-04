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