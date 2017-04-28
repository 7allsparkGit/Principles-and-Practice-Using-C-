#include "std_lib_facilities.h"

//#########################################################################
//##					Chapter 8 - exercise 2.							###
//#########################################################################


//void Print (const string &ArgStrn,const vector<int> &ArgIntVector) 
//{
//	std::cout << ArgStrn;
//	for (int i = 0; i < ArgIntVector.size(); i++)
//	{
//		std::cout << ArgIntVector[i];
//	}
//}
//
//
//int main()
//{
//	try
//	{
//		vector<int> IntVector = { 2,3,4,5,6 };
//		string StringLabelVector = "Label";
//		Print(StringLabelVector, IntVector);
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
//##					Chapter 8 - exercise 3.							###
//#########################################################################

//vector<int> fibonacci(int x, int y, vector<int> &v, int n)
//{
//	v.push_back(x);
//	v.push_back(y);
//
//	int helper = 0;
//	for (int i = 2; i < n; i++)
//	{
//		v.push_back(x + y);
//		helper = y;
//		y = x + y;
//		x = helper;
//		// other alternative: v.push_back(v[i-2] + v[-1];
//	}
//
//	return v;
//}
//
//void Print(const string &ArgStrn, const vector<int> &ArgIntVector)
//{
//	std::cout << ArgStrn;
//	for (int i = 0; i < ArgIntVector.size(); i++)
//	{
//		std::cout << ArgIntVector[i];
//		std::cout << ' ';
//	}
//}
//
//int main()
//{
//	try
//	{
//		string StringFibo = "Fibonacci numbers: ";
//		vector<int> IntVector = { 2,3,4,5,6 };
//		int numberOfElements = 10;
//		vector<int> FiboVector = { numberOfElements };
//		string StringLabelVector = "Label";
//		Print(StringLabelVector, IntVector);
//
//		FiboVector = fibonacci(1, 2, FiboVector, numberOfElements);
//		std::cout << '\n';
//		Print(StringFibo, FiboVector);
//		std::cout << '\n';
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
//##					Chapter 8 - exercise 5.							###
//#########################################################################

vector<int> ReverseNewtVector(vector<int> v, int n)
{
	vector<int> ReversedVector ( n );
	for (int i = 0; i < n; i++)
	{
		ReversedVector[(n-1)-i] = v[i];
	}
	return ReversedVector;
}

void ReverseSameVector(vector<int> &v)
{
	for (int i = 0; i <= v.size()/2; i++)
	{
		swap(v[(v.size()-1)-i],v[i]);
	}
}

void Print(const string &ArgStrn, const vector<int> &ArgIntVector)
{
	std::cout << ArgStrn;
	for (int i = 0; i < ArgIntVector.size(); i++)
	{
		std::cout << ArgIntVector[i];
		std::cout << ' ';
	}
}

int main()
{
	try
	{
		string StringReverse = "Reversed vector: ";
		vector<int> IntVector = { 2,3,4,5,6 };
		int numberOfElements = 5;
				vector<int>ReversedVector = ReverseNewtVector(IntVector, numberOfElements);
		std::cout << '\n';
		
		Print(StringReverse, ReversedVector);
		std::cout << '\n';
		ReverseSameVector(IntVector);
		Print(StringReverse, IntVector);
		std::cout << '\n';

		
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