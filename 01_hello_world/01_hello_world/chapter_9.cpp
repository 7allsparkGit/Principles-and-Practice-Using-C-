#include "std_lib_facilities.h"

//#########################################################################
//##					Chapter 9 - exercise 1.					###
//#########################################################################

// simple Date (too simple?)

		struct Date {
			int y; // year
			int m; // month in year
			int d; // day of month
		};
		/*enum class Month
		{
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};*/
		
				
		//class Date {
		//public:
		//	// . . .
		//	Date(int y, Month m, int d); // check for valid date and initialize
		//	Date(); // default constructor		//	void add_day(Date& dat, int n);

		//void init_day(Date& dd, int y, int m, int d);
		//void add_day(Date& dd, int n);

		//ostream& operator<<(ostream& os, const Date& d);
		//private:
		//	int y;
		//	Month m;
		//	int d;
		//};

		/*void init_day(Date& dd, int y, int m, int d) {};
		void add_day(Date& dat, int d) {};*/

		void init_day(Date& dd, int y, int m, int d)
		{
			if (m < 1 || m > 12 || d < 1 || d > 31)
			{
				error("Invalid date");
			}
			dd.y = y;
			dd.m = m;
			dd.d = d;
		}
		void add_day(Date& dat, int d)
		{
			dat.d += d;
		}
		ostream& operator<<(ostream& os, const Date& d)
		{
			return os << '(' << d.y
				<< ',' << d.m
				<< ',' << d.d << ')';
		}
int main()
{
	try {		
		
		Date today { 1987 ,  2 ,  25 };
		std::cout << today;
		//tomorrow.add_day(today, 1);
		

	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}
}

