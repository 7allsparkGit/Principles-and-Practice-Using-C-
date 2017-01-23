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

void TerminatingWithPipeWhileLoopSecond()
{
	double val1;
	double val2;
	char n;
	cout << "Enter | if you want to quit: ";
	cin >> n;
	double smaller = 0, bigger = 0;
	while (n != '|')
	{
		cout << "Enter two intergers:\n";
		cout << "Interger 1: ";
		cin >> val1;
		cout << "Interger 2: ";
		cin >> val2;
		//cout << val1 << '\t' << val2;
		cout << endl;


		if (val1 > val2) {
			cout << "Smaller value is:  " << val2 << "\n";
			cout << "The greater value is:  " << val1 << "\n";
			smaller = val2;
			bigger = val1;
		}
		else if (val2 > val1) {
			cout << "Smaller value is:  " << val1 << "\n";
			cout << "The greater value is:  " << val2 << "\n";
			smaller = val1;
			bigger = val2;
		}
		else if (val1 = val2) {
			cout << "The numbers are equal\n";
		}
		cout << "The difference between the two number is: "
			<< bigger - smaller << "\n";


		cout << "Enter | if you want to quit: ";
		cin >> n;
	}
}


void SmallestBiggestSoFar()
{
	double num;
	double smaller, bigger;
	char n;
	cout << "Enter | if you want to quit: ";
	cin >> n;
	cout << "Enter a number: \n";
	cin >> num;
	smaller = num;
	bigger = num;

	while (n != '|')
	{
		cout << "Enter a number: \n";
		cin >> num;

		if (num > bigger) {
			bigger = num;
			cout << "the highest so far\n";
		}
		else if (num < smaller) {
			smaller = num;
			cout << "the smallest so far\n";
		}
		cout << "Enter | if you want to quit: ";
		cin >> n;
	}
}

void ValueUnits()
{
	double num;
	double smaller, bigger;
	int numberOfValus = 0;
	string unit = "";
	char n;
	cout << "Enter | if you want to quit: ";
	cin >> n;
	cout << "Enter a number follow by a unit like this 3.33m \n"
		<< "only use cm, in, ft, m: ";
	cin >> num >> unit;
	smaller = num;
	bigger = num;

	while (n != '|')
	{	// TODO reject inputs such as: y, yard, meter, km, gallons by explicitly printing out
		// and reject every other non relevant input
		// TODO check string[0] if it is "_" then string[0] = string[1]
		// TODO case for cm, in, ft, m:
		// TODO keep track the sum of entered values  in meters
		// TODO keep track smallest largest
		// TODO keep all values enterd in vector, at the end write out those, 
		// before writing out sort them
		cout << "Enter a number: \n";
		cin >> num;

		if (num > bigger) {
			bigger = num;
			cout << "the highest so far\n";
		}
		else if (num < smaller) {
			smaller = num;
			cout << "the smallest so far\n";
		}
		cout << "Enter | if you want to quit: ";
		cin >> n;

		numberOfValus++;
	}
}

int main()
{

	ValueUnits();


	return 0;
}
