#pragma once
#include "std_lib_facilities.h"

namespace Chrono {
	
	enum  Month {
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};
	
	class Date {
	public:
		class Incalid {};
		
		Date(int y, Month m, int d);
		Date();

		// NomModifier methods
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }
		// Modifier methods
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);

	private:
		int y;
		Month m;
		int d;
	};
	// const maybe not required
	bool const isValidDate(int y, Month m, int d);    
	bool const isLeapYear(int y); 
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);
	ostream& operator<<(ostream& os, const Date& d);
	istream& operator >> (ostream& os, const Date& d);
}		/// Chrono 
	