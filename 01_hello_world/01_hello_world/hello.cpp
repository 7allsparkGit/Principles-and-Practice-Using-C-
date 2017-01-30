#include "std_lib_facilities.h" 
#include <algorithm>
#include <vector>

// simple program to exercise operators
//##########################################################################################
//##																					###
//##########################################################################################
int square(int sqr) {
	int square = 0;
	for (int i = 0; i <sqr; i++)
	{
		square += sqr;
	}
	return square;
}
//##########################################################################################
//##																					###
//##########################################################################################
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
//##########################################################################################
//##																					###
//##########################################################################################
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
//##########################################################################################
//##																					###
//##########################################################################################
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
			<< bigger - smaller <<"\n";


		cout << "Enter | if you want to quit: ";
		cin >> n;
	}
}

//##########################################################################################
//##																					###
//##########################################################################################
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
//##########################################################################################
//##																					###
//##########################################################################################
void ValueUnits()
{
	// can NOT use with switch, can not figure out the logic
	enum Choice
	{
		Y = 0,
		YARD = 1,
		METER = 2,
		KM = 3,
		GALLONS = 4
	};

	bool firstLoop = false;
	double num;
	double smaller, bigger;
	double numberOfValus = 0, sumOfValues = 0;
	bool bErrorIncorrectInput = false;
	vector<string> NotAllowedMesaurments{ "y", "yard", "meter", "km", "gallons" };
	string unit = "";
	char n;
	vector<double> AllEnteredValue{};
	
	cout << "Enter | if you want to quit now or ANYTHING to continue: ";
	cin >> n;
	
	while (n != '|')
	{	
		cout << "Enter a number follow by a unit like this 3.33m \n"
			<< "only use cm, in, ft, m: ";
		cin >> num >> unit;
		/// Loop until input measure type become true
		while (!bErrorIncorrectInput) 
		{
			// initialize firsloop for the first while run
			if (!firstLoop) {
				smaller = num;
				bigger = num;
			}
			/// Checking incorrect input for measure type
			if (unit.compare("cm") == 0 || unit.compare("m") == 0 ||
				unit.compare("in") == 0 || unit.compare("tf") == 0 ||
				unit.compare(" cm") == 0 || unit.compare(" m") == 0 ||
				unit.compare(" in") == 0 || unit.compare(" tf") == 0) {
					bErrorIncorrectInput = true;
					cout << "OOOOOKKKK\n ";
			}
			else {
				if (unit == "") {
					cout << "The measure can not be empty, choose again a NEW unit:\n ";
				}
				else if (unit == "y") {
					cout << "The " << unit << " is ILLEGAL!\n";
					cout << "Choose again NEW unit: ";
				}
				else if (unit == "yard") {
					cout << "The " << unit << " is ILLEGAL!\n";
					cout << "Choose again NEW unit: ";
				}
				else if (unit == "meter") {
					cout << "The " << unit << " is ILLEGAL!\n";
					cout << "Choose again NEW unit: ";
				}
				else if (unit == "km") {
					cout << "The " << unit << " is ILLEGAL!\n";
					cout << "Choose again NEW unit: ";
				}
				else if (unit == "gallons") {
					cout << "The " << unit << " is ILLEGAL!\n";
					cout << "Choose again NEW unit: ";
				}
				else {
					cout << "The " << unit << " is ILLEGAL!\n";
					cout << "Choose again NEW unit: ";
				}
				cin >> unit;
			}
		}
		/// convert units to meter
		if (unit == "cm") {
			num /= 100;
		}
		else if (unit == "in") {
			num *= 2.45;
			num /= 100;
		}
		else if (unit == "ft") {
			num *= 12;
			num *= 2.54;
			num /= 100;
		}
		/// keep track smallest and largest
		if (num > bigger) {
			bigger = num;
			cout << "the highest so far\n";
		}
		else if (num < smaller) {
			smaller = num;
			cout << "the smallest so far\n";
		}

		cout << "Enter | if you want to quit now or ANYTHING to continue: ";
		cin >> n;

		numberOfValus++;
		sumOfValues += num;
		bErrorIncorrectInput = false;
		firstLoop = true;
		AllEnteredValue.push_back(num);		
	}	
	/// Print out statistics
	cout << "Sum: " << sumOfValues << " !\n";
	cout << "Number of enterd values: " << numberOfValus << " !\n";
	cout << "Smallest: " << smaller << " !\n";
	cout << "Largest: " << bigger << " !\n";

	/// sorting the int vector  and then print them out
	sort(AllEnteredValue.begin(), AllEnteredValue.end());
	int i = 1;
	for (double elements : AllEnteredValue){
		cout << i++ << ". " << elements << "\n";
	}
}



//##########################################################################################
//##								MEDIAN - Exercise 2.								###
//##########################################################################################
double ReturnMedianOfVector()
{
	int VectorSize = 0;
	double Median = 0;
	vector<double> Vectors = { 5, 7, 9, 4, 6, 8, 7, 6 };
	VectorSize = Vectors.size();

	/// Check if vector size even or odd number
	if (VectorSize % 2 != 0)
	{
		Median = Vectors[(VectorSize-1) / 2];
		//cout << Median;
	}
	else if(VectorSize % 2 == 0)
	{
		cout << (Vectors[((VectorSize / 2))]) / 2 << std::endl;
		cout << Vectors[((VectorSize / 2) - 1)] << std::endl;

		Median = ((Vectors[(VectorSize / 2) - 1] + Vectors[VectorSize / 2])) / 2;
	}
	return Median;
}

//##########################################################################################
//##						TOTAL DISTANCE - Exercise 3.								###
//##########################################################################################
void CityDistanceCalculator()
{
	constexpr int MAX_VECTOR_SIZE = 20;
	bool bIsMoreUserInput = true;
	int LoopCounter = 0;
	double VectorInputValues = 0;
	char PLayerDecisionQuitOrNot = ' ';
	double TotalDistance = 0;
	double SmallestDistance = 0;
	double GreatestDistance = 0;
	double MeanDistance = 0;

	int VectorSize = 0;
	double Median = 0;
	vector<double> VectorsDistance = {};
	VectorSize = VectorsDistance.size();

	/// Populate vector until its max or true
	
	while (bIsMoreUserInput && (LoopCounter != MAX_VECTOR_SIZE-1))
	{
		/// Populate vector with distances
		std::cout << "Enter a distance: ";
		std::cin >> VectorInputValues;
		TotalDistance += VectorInputValues;
		VectorsDistance.push_back(VectorInputValues);
		
		std::cout << "To quit hit: \"q\" or anything else to play more: ";
		std::cin >> PLayerDecisionQuitOrNot;
		std::cout << std::endl;
		if (PLayerDecisionQuitOrNot == 'q' )
		{
			bIsMoreUserInput = false;
		}
		LoopCounter++;
	}

	/// Find smallest - greates distance - mean distance - sum of distances
	  auto MinDistance = std::min_element(std::begin(VectorsDistance), std::end(VectorsDistance));
	  std::cout << "Smallest distance: "<< *MinDistance << '\n';

	  auto MaxDistance = std::max_element(std::begin(VectorsDistance), std::end(VectorsDistance));
	  std::cout << "Greatest distance: " << *MaxDistance << '\n';

	  MeanDistance = TotalDistance / LoopCounter;
	  std::cout << "Mean distance: " << MeanDistance << '\n';
	  
	  std::cout << "Sum of distances: " << TotalDistance << '\n';

}

//##########################################################################################
//##						NUMBER GUESSING GAME - Exercise 4.							###
//##########################################################################################

//##########################################################################################
//##						MAIN.c++													###
//##########################################################################################
int main()
{

	CityDistanceCalculator();


	return 0;
}
