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
		static Date dd{ 2001, Date::Month::jan, 1 };
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
	bool const isValidDate(int y, Date::Month m, int d)
	{
		if (d <= 0) return false;
		if (m < Date::Month::jan || Date::Month::dec < m) return false;

		int days_of_month = 31;

		switch (m)
		{
		case Date::Month::feb:
			days_of_month = isLeapYear(y) ? 29 : 28;
			break;
		case Date::Month::apr: case Date::Month::jun: case Date::Month::sep: case Date::Month::nov:
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
		dd = Date(y, Date::Month(m), d); // update dd
		return is;
	}

	const Date first_date = Date(1700, Date::Month::jan, 1);
	const Day first_day = thursday;

	Day DayOfWeak(const Date& d)
	{
		if (d.year() < first_date.year()) error("day_of_week: works only for 1970 and later");
		int days = NumberOfDaysSinceFirstDay(d);
		return Day((first_day + days) % 7);
	}
	int NumberOfDaysOfLeapYears(const Date& d)
	{
		int days = 0;
		for (int i = 1970; i < d.year(); i++)
		{
			if (isLeapYear(i))
			{
				++days;
			}
		}
		return days;
	}
	int NumberOfDaysInEveryMOnth(Date::Month m)
	{
		switch (m)
		{
		case Chrono::Date::jan: return 0;
			break;
		case Chrono::Date::feb: return 31;
			break;
		case Chrono::Date::mar: return 31 + 28;
			break;
		case Chrono::Date::apr: return 31 + 28 + 31;
			break;
		case Chrono::Date::may: return 31 + 28 + 31 + 30;
			break;
		case Chrono::Date::jun: return 31 + 28 + 31 + 30 + 31;
			break;
		case Chrono::Date::jul: return 31 + 28 + 31 + 30 + 31 + 30;
			break;
		case Chrono::Date::aug: return 31 + 28 + 31 + 30 + 31 + 30 + 31;
			break;			
		case Chrono::Date::sep: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
			break;
		case Chrono::Date::oct: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
			break;
		case Chrono::Date::nov: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31; 
			break;
		case Chrono::Date::dec: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
			break;
		default:
			break;
		}(m);
	}
	int DaysInYear(const Date& d)
	{
		int numberOfDay = 0;
		// count days of year 
		numberOfDay += NumberOfDaysInEveryMOnth(d.month());
		// check leap year if date has passed February
		if (d.month() > Date::feb && isLeapYear(d.year())) { ++numberOfDay; }
		return numberOfDay;
	}
	long int NumberOfDaysSinceFirstDay(const Date& d)
	{
		if (d.year() < first_date.year()) error("days_linear: year must be 1970 or later");
		int years = d.year() - first_date.year();
		return years * 365 + NumberOfDaysOfLeapYears(d.year()) + DaysInYear(d) - 1;
	}
	Date next_Sunday(const Date& d)
	{
		Date nextDate = d;
		Day Day = DayOfWeak(d);
		nextDate.add_day(7 - Day);
		return d;
	}
	Date next_weekday(const Date& d)
	{
		Date nextWeekDate = d;
		Day Day = DayOfWeak(d);
		switch (Day)
		{
		case sunday:
		case monday:
		case tuesday:
		case wednesday:
		case thursday:
			nextWeekDate.add_day(1);
			break;
		case saturday:
			nextWeekDate.add_day(2);
		case friday:
			nextWeekDate.add_day(3);
			break;
		}
		return d;
	}
	
}  /// Chrono