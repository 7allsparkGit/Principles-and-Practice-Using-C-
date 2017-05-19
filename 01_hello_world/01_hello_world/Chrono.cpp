#include "std_lib_facilities.h"
#include "Chrono.h"

namespace Chrono
{
	Date::Date(int yy, Month mm, int dd)
		: y{ yy }, m{ mm }, d{ dd }
	{
		if (!isValidDate(yy, mm, dd)) throw Incalid();
	}

	const Date& default_date()
	{
		static Date dd{ 2001, Month::jan, 1 };
		return dd;
	}
	// default constructor 
	Date::Date()
		:y{ default_date().year() },
		m{ default_date().month() },
		d{ default_date().day() }
	{
	}
	void Date::add_day(int n)
	{
		d += n;
		if (d > 31) error("add_day() results in invalid date");
	}
	void Date::add_month(int n)
	{
		// too complicated
	}
	void Date::add_year(int n)
	{
		/// it is now leap year, if the next one going to be again, 
		/// do not change anything, otherwise it will be March 1.
		/// so we loose one day by jumping to the next month
		if (m == Month::feb && d == 29 && !isLeapYear(y + n)) {    // beware of leap years!
			m = Month::mar;                                // use March 1 instead of February 29
			d = 1;
		}
		y += n;
	}
	bool const isValidDate(int y, Month m, int d)
	{
		if (d <= 0) return false;
		if (m < Month::jan || Month::dec < m) return false;

		int days_of_month = 31;

		switch (m)
		{
		case Month::feb:
			days_of_month = isLeapYear(y) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days_of_month = 30;
		}
		if (days_of_month > d) return false;

		return true;
	}
	bool const isLeapYear(int y)
	{
		/* 
		if (y % 4 != 0) { return false; }
		else if (y % 100 != 0) { return false; }
		else if (y % 400 != 0) { return false; }
		else { return true; } // leap year
		*/
		if (y % 4 != 0)  return false;
		if (y % 100 == 0) {
			if (y % 400 == 0) { return true; }
			return false;
		}
		else return true; // leap year
	}
	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}
	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}
	ostream& operator<<(ostream& os, const Date& d)
	{
		//Month months = d.month();
		os << '(' << d.year()
			<< ',' << d.month()
			<< ',' << d.day();
		 return os;
	}
	istream& operator >> (istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') { // oops: format error
			is.clear(ios_base::failbit); // set the fail bit
			return is;
		}
		dd = Date(y, Month(m), d); // update dd
		return is;
	}
	enum class Day {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};
}  /// Chrono