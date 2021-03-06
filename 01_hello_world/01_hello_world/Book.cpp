#include "Book.h"
#include  <ctype.h>

///////////////////////////////////////////////////////////////////////////
//				BOOK
///////////////////////////////////////////////////////////////////////////
Book::Book( string title, string author, int copy_date, string isbn, Genre gen , bool checked)
	:title(title), author(author), copy_date(copy_date),
	isbn(isbn), genre(gen) ,checked(checked)
{
	// validate isbn
	if (!IsIsbnValid(isbn)) { error("Not a valid ISBN number"); }
	
}
// default constructor
	/// Book default object 
const Book& defaultBook()
{
	static const Book bookStatic("", "", 0, "0-0-0-0-n", Book::fiction ,false);
	return bookStatic;
}
	/// default constructor with default object supplied
Book::Book()
	:title(defaultBook().GetTitle()),
	author(defaultBook().GetAuthor()),
	copy_date(defaultBook().GetCopyDate()),
	isbn(defaultBook().GetIsbn()),
	genre(defaultBook().GetGenre()),
	checked(defaultBook().GetChecked())
{
}
///////////////////////////////////////////////////////////////////////////
// Get functions
///////////////////////////////////////////////////////////////////////////
string Book::GetGenreFromEnum() const
{ 
	
	switch (GetGenre()) 
	{
	case biography:
		return "Biography";
		break;
	case  children:
		return "Children";
		break;
	case periodical :
		return "Periodical";
		break;
	case nonfiction:
		return "Nonfiction";
		break;
	case fiction:
		return "Fiction";
		break;
	default: 
		error("No suitable enum found");
	}
}
///////////////////////////////////////////////////////////////////////////
// Checked in-out functions 
///////////////////////////////////////////////////////////////////////////
void Book::checkOut()
{
	if (checked == false) std::cout << "Already check out!";
	else
	{
		checked == false;
		std::cout << "Successfully checked out!";
	}
}
void Book::checkIn()
{
	if (checked == true) std::cout << "Already check in!";
	else
	{
		checked == true;
		std::cout << "Successfully checked in!";
	}
}
///////////////////////////////////////////////////////////////////////////
// IsIsvnValid  : format n-n-n-x 
///////////////////////////////////////////////////////////////////////////
bool Book::IsInteger(const char& integer) 
{
	return isdigit(integer);
}
bool Book::IsLetter(const char& letter) 
{
	return isalpha(letter);
}
bool Book::IsIsbnValid(const string& isbn)
{
	// string format n-n-n-x
	// check string length, must be 7
	if( isbn.length() == 9) 
	{
		if (IsInteger(isbn[0]) && IsInteger(isbn[2]) && IsInteger(isbn[4])  && IsInteger(isbn[6]))
		{
			if (isbn[1] == '-' && isbn[3] == '-' && isbn[5] == '-')
			{
				if (IsLetter(isbn[8]))
				{
					return true;
				}
			}
		}
	}
	else { return false; }
	// check 1st, 3rd, 5th as they are int 
		// 2nd, 4th, 6th as they are '-'
		// 7th as it is a digit or a letter 
}
///////////////////////////////////////////////////////////////////////////
//  print, get methods 
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
//  operator overloading members
///////////////////////////////////////////////////////////////////////////
bool operator==(const Book& b1, const Book& b2)
{
	if (b1.GetIsbn() == b2.GetIsbn())
	{
		return true;
	}
	else return false;
	// return b1.GetIsbn() == b2.GetIsbn();
}	
bool operator!=(const Book& b1, const Book& b2)
{
	return !(b1.GetIsbn() == b2.GetIsbn());
}
ostream& operator<< (ostream& os, const Book& book)
{
	os << "Title: " << book.GetTitle()
		<< "\nAuthor: " << book.GetAuthor()
		<< "\nCopy Date: " << book.GetCopyDate()
		<< "\nISBN number: " << book.GetIsbn()
		<< "\nGenre: " << book.GetGenreFromEnum()
		<< "\nChecked or not: " << book.GetChecked << "\n";
	return os;
}

///////////////////////////////////////////////////////////////////////////
//				PATRON
///////////////////////////////////////////////////////////////////////////
Patron::Patron(string UserName, int CardNumber, double LibraryFee)
	:UserName(UserName), CardNumber(CardNumber), LibraryFee(LibraryFee)
{
	// error checking could be goes here
}
Patron::Patron()
	: UserName(PatronDefaultConst().GetUserName()),
	CardNumber(PatronDefaultConst().GetCardNumber()),
	LibraryFee(PatronDefaultConst().GetLibraryFee())
{
}
// return a Patron object so that we can reach members of Petron class
const Patron& PatronDefaultConst()
{
	static const Patron patronConst("", 0, 0);
	return patronConst;
}