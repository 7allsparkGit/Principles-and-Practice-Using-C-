

 ////This is example code from Chapter 6.7 "Trying the second version" of
 ////"Software - Principles and Practice using C++" by Bjarne Stroustrup


/*
This file is known as calculator02buggy.cpp

I have inserted 5 errors that should cause this not to compile
I have inserted 3 logic errors that should cause the program to give wrong results

First try to find an remove the bugs without looking in the book.
If that gets tedious, compare the code to that in the book (or posted source code)

Happy hunting!

*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};


//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full) {       // do we already have a Token ready?
					  // remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
	case '=':    // for "print"
	case 'x':    // for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/': case '{': case '}': case '!': 
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
		// case '5': case '6': case '7': case '9': // logic error(1)
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token('8', val);   // let '8' represent "a number"
	}
	default:
		error("Bad token");
	}
}

//------------------------------------------------------------------------------


Token_stream ts;        // provides get() and putback() 

						//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()
//double term();
//double primary();
						//------------------------------------------------------------------------------
//double factorial(double number);
// deal with ! (factorial)
double factorial(double d)
{
	int p = d;
	if (double(p) != d)
		error("factorial not defined for non-integers");
	if (p < 0)
		error("factorial not defined for negative values");
	else if (p > 31)
		error("factorial too large");
	else if (p == 0)
		return 1;
	else {
		int res = p;
		for (int i = p - 1; i > 0; --i)
			res *= i;
		return res;
	}

}
//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
	Token t = ts.get();
	double d = 0;
	switch (t.kind)
	{
	case '(':    // handle '(' expression ')'
	{
		d = expression();
		t = ts.get();
		// if (t.kind != ')') error("')' expected); // error(3)
		if (t.kind != ')') error("')' expected");
		//return d;
		break;
	}
	case '{':    // handle '(' expression ')'
	{
		d = expression();
		t = ts.get();
		// if (t.kind != ')') error("')' expected); // error(3)
		if (t.kind != '}') error("'}' expected");
		//return d;
		break;
	}
	case '8':           // we use '8' to represent a number
	{
		//return t.value;  // return the number's value
		d = t.value;
		break;
	}
	default:
		error("primary expected");
	}

	t = ts.get();
		if (t.kind != '!') {    // not a factorial: put token back, return value from above
			ts.putback(t);
			return d;
		}
		return factorial(d);   // a factorial; call factorial function

	
}
//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
	double left = primary();
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			// logic error(2)
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		
		default:
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
	// double left = term(;      // read and evaluate a Term // error(4)
	double left = term();      // read and evaluate a Term
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			// left += term();    // evaluate Term and subtract // logic error(3)
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}

//------------------------------------------------------------------------------



int main()
try
{
	double val = 0;
	while (cin) {
		
		Token t = ts.get();

		if (t.kind == 'x') break; // 'q' for quit
		if (t.kind == '=')        // ';' for "print now"
			cout << "=" << val << '\n';
		else
			ts.putback(t);
		val = expression();
	}
	keep_window_open();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}

//------------------------------------------------------------------------------

	// Chapter 06, exercise 02: add {} and () to calculator
	// Exercise 03: add factorial operator (suffix '!')

	/*
	Grammar implemented for factorial:
	Expression:
	Term
	Expression "+" Term
	Expression "-" Term
	Term:
	Primary
	Term "*" Primary
	Term "/" Primary
	Term "%" Primary
	Primary:
	Number
	"(" Expression ")"
	Primary "!"
	Number:
	floating-point-literal
	*/


//	const char number = '8';    // t.kind==number means that t is a number Token
//const char quit = 'q';      // t.kind==quit means that t is a quit Token
//const char print = ';';     // t.kind==print means that t is a print Token
//const string prompt = "> ";
//const string result = "= "; // used to indicate that what follows is a result
//
//							//------------------------------------------------------------------------------
//
//class Token {
//public:
//	char kind;        // what kind of token
//	double value;     // for numbers: a value
//	Token(char ch)    // make a Token from a char
//		:kind(ch), value(0) { }
//	Token(char ch, double val)     // make a Token from a char and a double
//		:kind(ch), value(val) { }
//};
//
////------------------------------------------------------------------------------
//
//class Token_stream {
//public:
//	Token_stream();   // make a Token_stream that reads from cin
//	Token get();      // get a Token (get() is defined elsewhere)
//	void putback(Token t);    // put a Token back
//private:
//	bool full;        // is there a Token in the buffer?
//	Token buffer;     // here is where we keep a Token put back using putback()
//};
//
////------------------------------------------------------------------------------
//
//// The constructor just sets full to indicate that the buffer is empty:
//Token_stream::Token_stream()
//	:full(false), buffer(0)    // no Token in buffer
//{
//}
//
////------------------------------------------------------------------------------
//
//// The putback() member function puts its argument back into the Token_stream's buffer:
//void Token_stream::putback(Token t)
//{
//	if (full) error("putback() into a full buffer");
//	buffer = t;       // copy t to buffer
//	full = true;      // buffer is now full
//}
//
////------------------------------------------------------------------------------
//
//Token Token_stream::get()
//{
//	if (full) {       // do we already have a Token ready?
//					  // remove token from buffer
//		full = false;
//		return buffer;
//	}
//
//	char ch;
//	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)
//
//	switch (ch) {
//	case print:
//	case quit:
//	case '!':   // for factorials
//	case '(': case ')': case '+': case '-': case '*': case '/':
//	case '{': case '}':
//		return Token(ch);        // let each character represent itself
//	case '.':
//	case '0': case '1': case '2': case '3': case '4':
//	case '5': case '6': case '7': case '8': case '9':
//	{
//		cin.putback(ch);         // put digit back into the input stream
//		double val;
//		cin >> val;              // read a floating-point number
//		return Token(number, val);
//	}
//	default:
//		error("Bad token");
//	}
//}
//
////------------------------------------------------------------------------------
//
//Token_stream ts;        // provides get() and putback()
//
//						//------------------------------------------------------------------------------
//
//double expression();    // declaration so that primary() can call expression()
//
//						//------------------------------------------------------------------------------
//
//						// calculate factorial
//						// d must be a non-negative integer; 0! is defined as 1
//double factorial(double d)
//{
//	int p = d;
//	if (double(p) != d)
//		error("factorial not defined for non-integers");
//	if (p < 0)
//		error("factorial not defined for negative values");
//	else if (p > 31)
//		error("factorial too large");
//	else if (p == 0)
//		return 1;
//	else {
//		int res = p;
//		for (int i = p - 1; i>0; --i)
//			res *= i;
//		return res;
//	}
//}
//
////------------------------------------------------------------------------------
//
//// deal with parentheses, numbers and factorials
//double primary()
//{
//	Token t = ts.get();
//	double d = 0;
//	switch (t.kind) 
//  {
//	case '(':    // handle '(' expression ')'
//		d = expression();
//		t = ts.get();
//		if (t.kind != ')') error("')' expected");
//		break;
//	case '{':   // handle '{' expression '}'
//		d = expression();
//		t = ts.get();
//		if (t.kind != '}') error("'}' expected");
//		break;
//	case number:
//		d = t.value;  // return the number's value
//		break;
//	case '-':
//		d = -primary();
//		break;
//	case '+':
//		d = primary();
//		break;
//	default:
//		error("primary expected");
//	}
//
//	// check if we have the case Primary "!" (a factorial)
//	t = ts.get();
//	if (t.kind != '!') {    // not a factorial: put token back, return value from above
//		ts.putback(t);
//		return d;
//	}
//	return factorial(d);   // a factorial; call factorial function
//}
//
////------------------------------------------------------------------------------
//
//// deal with *, /, and %
//double term()
//{
//	double left = primary();
//	Token t = ts.get();        // get the next token from token stream
//
//	while (true) {
//		switch (t.kind) {
//		case '*':
//			left *= primary();
//			t = ts.get();
//			break;
//		case '/':
//		{
//			double d = primary();
//			if (d == 0) error("divide by zero");
//			left /= d;
//			t = ts.get();
//			break;
//		}
//		case '%':
//		{
//			double d = primary();
//			int i1 = int(left);
//			if (i1 != left) error("left-hand operand of % not int");
//			int i2 = int(d);
//			if (i2 != d) error("right-hand operand of % not int");
//			if (i2 == 0) error("%: divide by zero");
//			left = i1 % i2;
//			t = ts.get();
//			break;
//		}
//		default:
//			ts.putback(t);     // put t back into the token stream
//			return left;
//		}
//	}
//}
//
////------------------------------------------------------------------------------
//
//// deal with + and -
//double expression()
//{
//	double left = term();      // read and evaluate a Term
//	Token t = ts.get();        // get the next token from token stream
//
//	while (true) {
//		switch (t.kind) {
//		case '+':
//			left += term();    // evaluate Term and add
//			t = ts.get();
//			break;
//		case '-':
//			left -= term();    // evaluate Term and subtract
//			t = ts.get();
//			break;
//		default:
//			ts.putback(t);     // put t back into the token stream
//			return left;       // finally: no more + or -: return the answer
//		}
//	}
//}
//
////------------------------------------------------------------------------------
//
//// expression evaluation loop
//void calculate()
//{
//	while (cin) {
//		cout << prompt;
//		Token t = ts.get();
//		while (t.kind == print) t = ts.get();   // first discard all "prints"
//		if (t.kind == quit) return;
//		ts.putback(t);
//		cout << result << expression() << endl;
//	}
//}
//
//int main()
//try
//{
//	cout << "Welcome to our simple calculator.\n";
//	cout << "Please enter expressions using floating-point numbers.\n";
//	cout << "Operators available: +, -, *, /, !, (), {}.\n";
//	cout << "Enter '" << print << "' to print the result; enter '" << quit << "' to quit.\n";
//	calculate();
//	keep_window_open();
//	return 0;
//}
//catch (exception& e) {
//	cerr << "error: " << e.what() << '\n';
//	keep_window_open("~~");
//	return 1;
//}
//catch (...) {
//	cerr << "Oops: unknown exception!\n";
//	keep_window_open("~~");
//	return 2;
//}
//
////------------------------------------------------------------------------------