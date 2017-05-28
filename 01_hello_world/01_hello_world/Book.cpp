#include "Book.h"
#include  <ctype.h>

Book::Book() {};

Book::Book( string title, string author, int copy_date, string isbn, bool checked)
	:title(title), author(author), copy_date(copy_date),
	isbn(isbn), checked(checked)
{
	// validate isbn
	if (!IsIsbnValid(isbn)) { error("Not a valid ISBN number"); }
	
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
ostream& operator<< (ostream& os, const Book& book)
{
	os << "Title: " << book.GetTitle()
		<< "\nAuthor: " << book.GetAuthor()
		<< "\nCopy Date: " << book.GetCopyDate()
		<< "\nISBN number: " << book.GetIsbn()
		<< "\nChecked or not: " << book.GetChecked() << "\n";
	return os;
}
