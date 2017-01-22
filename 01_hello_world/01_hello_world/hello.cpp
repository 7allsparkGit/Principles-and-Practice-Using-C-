#include "std_lib_facilities.h" 

	// simple program to exercise operators

int square(int sqr) {
	int square = 0;
	for (int i = 0; i <sqr; i++)
	{
		square += sqr;
	}
	return square;
}

void charS() {
	char character = ' ';
	for (int i = 0; i < 23; i++) {
		cout << char('a' + i) << " " << i + 97 << "\n";


	}
	cout << "\n\n";
	for (int i = 0; i < 23; i++) {

		cout << char('A' + i) << " " << i + 97 << "\n";

	}

	cout << "Square root is " << square(7) << endl;
}

bool TerminatingWithPipeWhileLoop()
{
	string one = " ", two = " ";

	cout << "First: ";
	cin >> one;
	
	if (one != "|") {
		cout << "Second: ";
		cin >> two;
		/*cout << "First: " << one << " Second: " << two << endl;
		cout << "\n\n";*/
		if (two != "|") {
			cout << "First: " << one << " Second: " << two << endl;
			cout << "\n\n";

			while (true)
			{
				cout << "First: ";
				cin >> one;
				if (one != "|")
				{
					cout << "Second: ";
					cin >> two;
					if (two != "|")
					{
						cout << "First: " << one << " Second: " << two << endl;
						cout << "\n\n";
					}
				}
				if (two == "|" || one == "|")
					return false;
				else
					return true;
			}
		}
		else return false;
	}
	else return false;
}

int main()
{

	while (TerminatingWithPipeWhileLoop()) { };


	return 0;
}
