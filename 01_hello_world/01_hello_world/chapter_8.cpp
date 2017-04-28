#include "std_lib_facilities.h"

//#########################################################################
//##					Chapter 8 - exercise 2.							###
//#########################################################################


void Print (const string &ArgStrn,const vector<int> &ArgIntVector) 
{
	std::cout << ArgStrn;
	for (int i = 0; i < ArgIntVector.size(); i++)
	{
		std::cout << ArgIntVector[i];
	}
}


int main()
{
	try
	{
		vector<int> IntVector = { 2,3,4,5,6 };
		string StringLabelVector = "Label";
		Print(StringLabelVector, IntVector);

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