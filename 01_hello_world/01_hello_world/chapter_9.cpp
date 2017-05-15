#include "std_lib_facilities.h"

//#########################################################################
//##					Chapter 9 - drill 	§9.4.1			###
//#########################################################################

// simple Date (too simple?)

		//struct Date {
		//	int y; // year
		//	int m; // month in year
		//	int d; // day of month
		//};

		/*enum class Month
		{
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};*/
		
				
		//class Date {
		//public:
		//	// . . .
		//	Date(int y, Month m, int d); // check for valid date and initialize
		//	Date(); // default constructor
		//	void add_day(Date& dat, int n);

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

//		void init_day(Date& dd, int y, int m, int d)
//		{
//			if (m < 1 || m > 12 || d < 1 || d > 31)
//			{
//				error("Invalid date");
//			}
//			dd.y = y;
//			dd.m = m;
//			dd.d = d;
//		}
//		void add_day(Date& dat, int d)
//		{
//			dat.d += d;
//		}
//		ostream& operator<<(ostream& os, const Date& d)
//		{
//			return os << '(' << d.y
//				<< ',' << d.m
//				<< ',' << d.d << ')';
//		}
//int main()
//{
//	try {		
//		
//		Date today { 1987 ,  2 ,  25 };
//		std::cout << today;
//		//tomorrow.add_day(today, 1);
//		
//
//	}
//	catch (exception& e) {
//		cerr << "exception: " << e.what() << endl;
//		char c;
//		while (cin >> c && c != ';');
//		return 1;
//	}
//	catch (...) {
//		cerr << "exception\n";
//		char c;
//		while (cin >> c && c != ';');
//		return 2;
//	}
//}
//#########################################################################
//##					Chapter 9 - drill 	§9.4.2			###
//#########################################################################

// simple Date (too simple?)

//struct Date {
//	int y; // year
//	int m; // month in year
//	int d; // day of month
//	Date(int y, int m, int d);
//	void add_day(Date& dd, int n);
//};
//Date::Date(int yy, int mm, int dd)
//{
//	y = yy;
//	m = mm;
//	d = dd;
//}
//void Date::add_day(Date& dat, int d)
//{
//	dat.d += d;
//}
//ostream& operator<<(ostream& os, const Date& d)
//{
//	return os << '(' << d.y
//		<< ',' << d.m
//		<< ',' << d.d << ')';
//}
//int main()
//{
//	try {
//		Date today{ 1987 ,  2 ,  25 };
//		Date tomorrow = today;
//		tomorrow.add_day(tomorrow, 1);
//		std::cout << tomorrow;
//	}
//	catch (exception& e) {
//		cerr << "exception: " << e.what() << endl;
//		char c;
//		while (cin >> c && c != ';');
//		return 1;
//	}
//	catch (...) {
//		cerr << "exception\n";
//		char c;
//		while (cin >> c && c != ';');
//		return 2;
//	}
//}

//#########################################################################
//##					Chapter 9 - drill 	§9.4.3			###
//#########################################################################
//class Date {
//private:
//	int y, m, d; 
//public:
//	Date(int y, int m, int d);
//	void add_day(Date& dd, int n);
//	int month() { return m; }
//	int day() { return d; }
//	int year() { return y; }
//
//};
//Date::Date(int yy, int mm, int dd)
//{
//	y = yy;
//	m = mm;
//	d = dd;
//}
//void Date::add_day(Date& dat, int d)
//{
//	dat.d += d;
//}
//ostream& const operator<<(ostream& os, Date& d)
//{
//	return os << '(' << d.year()
//		<< ',' << d.month()
//		<< ',' << d.day() << ')';
//}
//int main()
//{
//	try {
//		Date today{ 1987 ,  2 ,  25 };
//		Date tomorrow = today;
//		tomorrow.add_day(tomorrow, 1);
//		std::cout << tomorrow;
//	}
//	catch (exception& e) {
//		cerr << "exception: " << e.what() << endl;
//		char c;
//		while (cin >> c && c != ';');
//		return 1;
//	}
//	catch (...) {
//		cerr << "exception\n";
//		char c;
//		while (cin >> c && c != ';');
//		return 2;
//	}
//}

//#########################################################################
//##					Chapter 9 - drill 	§9.7.1			###
//#########################################################################

//enum class Month {
//	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
//};
//
//
//class Date {
//private:
//	int y, d;
//	int m;
//public:
//	Date(int y, int m, int d);
//	void add_day(Date& dd, int n);
//	int month() { return m; }
//	int day() { return d; }
//	int year() { return y; }
//};
//Date::Date(int yy, int mm, int dd)
//{
//	y = yy;
//	m = mm;
//	d = dd;
//}
//void Date::add_day(Date& dat, int d)
//{
//	dat.d += d;
//	if (d > 31) error("add_day() results in invalid date");
//}
//ostream& operator<<(ostream& os, Date& d)
//{
//	return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
//}
//int main()
//{
//	try {
//		Date today{ 1987 ,  2 ,  25 };
//		Date tomorrow = today;
//		tomorrow.add_day(tomorrow, 1);
//		std::cout << tomorrow;
//	}
//	catch (exception& e) {
//		cerr << "exception: " << e.what() << endl;
//		char c;
//		while (cin >> c && c != ';');
//		return 1;
//	}
//	catch (...) {
//		cerr << "exception\n";
//		char c;
//		while (cin >> c && c != ';');
//		return 2;
//	}
//}

//#########################################################################
//##					Chapter 9 - drill 	§9.7.4			###
//#########################################################################
//enum Month {
//	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
//};
//class Date {
//public:
//	Date(); // default constructor
//	Date(int y, Month m, int d); // check for valid date before default const
//	// no const, can change the object
//	void add_day(Date& dd, int n);
//	void month_add(Date& mm, int n);
//	void year_add(Date& yy, int n);
//	// const class/struct member function can not modify the object 
//	Month month() const;
//	int day() const;
//	int year() const;
//private:
//	int y;
//	int d;
//	Month m;
//};
//
//// check for valid date before default const
//Date::Date(int y, Month m, int d)
//	:y(y), m(m), d(d)
//{
//	if (m < Month::jan || m > Month::dec || d < 1 || d > 31) error("invalid date");
//}
//
//const Date& default_date()
//{
//	static Date dd(2001, Month::jan, 1);
//	return dd;
//}
//Date::Date()
//	:y{ default_date().year() }, m{ default_date().month() }, d{ default_date().day() }
//{
//}
//
//// return methods 
// Month Date::month() const
//{
//	return m;
//}
//int Date::day() const
//{
//	return d;
//}
//int Date::year() const
//{
//	return y;
//}
//// add methods
//void Date::month_add(Date& mm, int n)
//{
//	// probably too complicated to implement yet
//}
//void Date::year_add(Date& yy, int n)
//{
//	yy.y += n;
//}
//void Date::add_day(Date& dat, int d)
//{
//	dat.d += d;
//	if (d > 31) error("add_day() results in invalid date");
//}
//ostream& operator<<(ostream& os, const Date& d)
//{
//	return os << '(' << d.year()
//		<< ',' << d.month()
//		<< ',' << d.day() << ')';
//}
//int main()
//{
//	try {
//		Date today{ 1987 ,  Month::jan ,  25 };
//		Date tomorrow = today;
//		tomorrow.add_day(tomorrow, 1);
//		std::cout << tomorrow;
//	}
//	catch (exception& e) {
//		cerr << "exception: " << e.what() << endl;
//		char c;
//		while (cin >> c && c != ';');
//		return 1;
//	}
//	catch (...) {
//		cerr << "exception\n";
//		char c;
//		while (cin >> c && c != ';');
//		return 2;
//	}
//}

//#########################################################################
//##					Chapter 9 - exercise  	2			###
//#########################################################################

class NamePair {
public:
	//NamePair(); 
	void ReadNames();
	void ReadAges();

	const vector<string>& getName() const { return names; }
	const vector<double>& getAge() const { return ages; }
	void print() const;
	void sort();
private:
	vector<string> names;
	vector<double> ages;
};
// reads series of names
void NamePair::ReadNames()
{
	string s = "";
	while (cin >> s && s != "No")
	{
		for (int i=0; i < names.size(); i++)
		{
			if (names[i] == s) { error("Name is already exist: " , s); }
		}
		names.push_back(s);
	}
}
// prompt user to enter age for each name
void NamePair::ReadAges()
{
	for (int i = 0; i < getName().size(); i++)
	{
		std::cout << "Age of " << names[i] << ": ";
		double a;
		std::cin >> a;
		ages.push_back(a);
	}
}

void NamePair::sort()
{
	if (names.size() != ages.size()) 
		error("sort(): name and age must be the same size");

	vector<string>presort = names;
	Vector<double>age_cp = ages;
	std::sort(names.begin(), names.end());
	for (int i = 0; i < names.size(); ++i)
	{
		for (int j = 0; j < presort.size(); ++j)
		{
			if (names[i] == presort[j])
			{
				ages[i] = age_cp[j];
			}
		}	
	}
}

// prints (name[i],age[i]) pairs
void NamePair::print() const
{
	if (names.size() != ages.size())
		error("print(): name and age must be the same size");
	for (int i = 0; i < names.size(); ++i) {
		cout << '(' << names[i] << ',' << ages[i] << ')' << endl;
	}
}

ostream& operator<<(ostream& os, const NamePair& np)
{
	if (np.getName().size() != np.getAge().size())
		error("<<: name and age must be the same size");
	for (int i = 0; i < np.getName().size(); i++)
	{
		os << '(' << np.getName()[i] << ',' << np.getAge()[i] << ')' << endl;
	}
	return os;
}


int main()
{
	try {
		NamePair np1;
		np1.ReadNames();
		np1.ReadAges();
		np1.sort();
		std::cout << "np1:\n" << np1;
		
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
