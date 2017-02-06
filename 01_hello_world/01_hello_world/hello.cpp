#include "std_lib_facilities.h" 
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

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
void NumberGuessingGame()
{
	constexpr int NUMBER_TO_GUESS = 61; // const int NUMBER_TO_GUESS = 99; - we can initialise with const
	int AddOrSubstractPerTwo = 50;
	int UnGuessedNumber = 50;
	//int SuccessfullyGuessedNumber = -1;
	int LoopCounterStepps = 0;
	char GuessYesOrNow = ' ';

	do
	{
		LoopCounterStepps++;
		AddOrSubstractPerTwo /= 2;
		std::cout << LoopCounterStepps << ". Is the number bigger then " << UnGuessedNumber  << ". Choose yes: y, no: n! : " ;
		std::cin >> GuessYesOrNow;
		if (GuessYesOrNow == 'y')
		{
			UnGuessedNumber += AddOrSubstractPerTwo + 1;
		}
		else
		{
			UnGuessedNumber -= AddOrSubstractPerTwo + 1;
		}
		//SuccessfullyGuessedNumber = UnGuessedNumber + 1;
	} while (UnGuessedNumber != NUMBER_TO_GUESS);

	std::cout << "The guessed number is: " << UnGuessedNumber << std::endl;
}
//##########################################################################################
//##						SIMPLE CALCULATOR - Exercise 5.								###
//##########################################################################################
void SimpleCalculator()
{
	char PlayMoreOrQuit = ' ';
	char Expression = ' ';
	double ValueOne = 0;
	double ValueTwo = 0;
	double ExpressionResult = 0;
	bool bInvalidExpression = false;

	std::cout << "------------------------    CALCULATOR     --------------------------" << std::endl;
	std::cout << "Supports +,-,/,* - add, substract, div, multi" << std::endl;
	std::cout << "Use only chars above and numbers 0-9, or floating numbers (e.g.: 1.3)" << std::endl;
	std::cout << "Enter first two value then one of +,-,/,*" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
	do
	{
		std::cout << "\nEnter first value: ";
		std::cin >> ValueOne;
		std::cout << "Enter second value: ";
		std::cin >> ValueTwo;
		std::cout << "Enter on of +,-,/,* expression: ";
		cin >> Expression;

		/// checking invalid input - there are maybe better solutins 
		/// bInvalidExpression initialized false
		if (Expression == '+' || Expression == '-' || Expression == '*' || Expression == '/')
		{
			bInvalidExpression = true;
		}
		else { bInvalidExpression = false; }
		while (!bInvalidExpression) 
		{
			std::cout << "\nInvalid input please try again!";
			std::cout << " Enter on of +,-,/,* expression: ";
			cin >> Expression;	
			if (Expression == '+' || Expression == '-' || Expression == '*' || Expression == '/')
			{
				bInvalidExpression = true;
			}		
		}
		/// checking invalid input - END
		
		/// we should using switch - but switch only accepts enum or int - can not figure it out now
		/// it may works with char type for +  -  * /
		if (Expression == '+')
		{
			ExpressionResult = ValueOne + ValueTwo;
			std::cout << ValueOne << " + " << ValueTwo << " = " << ExpressionResult << "\n ";
		}
		else if (Expression == '-')
		{
			ExpressionResult = ValueOne - ValueTwo;
			std::cout << ValueOne << " - " << ValueTwo << " = " << ExpressionResult << "\n ";
		}
		else if (Expression == '*')
		{
			ExpressionResult = ValueOne * ValueTwo;
			std::cout << ValueOne << " * " << ValueTwo << " = " << ExpressionResult << "\n ";
		}
		else if (Expression == '/')
		{
			if (ValueTwo == 0 || ValueTwo == 0.0) 
			{
				std::cout << "can not divide with ZERO! ";
			}
			else 
			{
				ExpressionResult = ValueOne / ValueTwo;
				std::cout << ValueOne << " / " << ValueTwo << " = " << ExpressionResult << "\n ";
			}
		}

		std::cout << "\nTo quit hit: \"q\" or anything else to play more: ";
		std::cin >> PlayMoreOrQuit;
	} while (PlayMoreOrQuit != 'q');
}
//##########################################################################################
//##			String to Int, vica-versa Converter - Exercise 6.						###
//##########################################################################################
void NumbersToString()
{
	char PlayMoreOrQuit = ' ';
	vector<string> NumbersToString{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	int VectorIndex = 0;
	int StringIntFindHelpre = 0;
	string StringNumber = "";

	///sort(NumbersToString.begin(), NumbersToString.end());   /// Do not sort it as it breaks the positions of elements of vector
	do
	{
		std::cout << "\nEnter number from 0 - 9: ";
		std::cin >> VectorIndex;
		std::cout << "\nEnter nubmer in string format from \"zero\" to \"nine\": ";
		std::cin >> StringNumber;
		
		for (string Numbers : NumbersToString)
		{
			if(Numbers == StringNumber)
			{ 
				std::cout << "\nStringNumber in's numberic value is " << StringIntFindHelpre << std::endl;
			}
			StringIntFindHelpre++;
		}

		
		cout << "Your input " << VectorIndex << " corresponds to " << NumbersToString[VectorIndex] << std::endl;

		/// checking invalid input - there are maybe better solutins 
		/// bInvalidExpression initialized false
		

		std::cout << "\nTo quit hit: \"q\" or anything else to play more: ";
		std::cin >> PlayMoreOrQuit;

		StringIntFindHelpre = 0;
	} while (PlayMoreOrQuit != 'q');
}

//##########################################################################################
//##						SIMPLE CALCULATOR MODIFIED - Exercise 7					###
//##########################################################################################
/// WARNING - many code duplicates, we should use methods/function to clear redundancy out
/// but it is out of this exercise scope.

void SimpleCalculatorModified()
{
	vector<string> NumbersToString{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	int VectorIndex = 0;
	int StringIntFindHelper = 0;
	string StringNumber = "";
	string StringStreamInputOne = "";
	string StringStreamInputTwo = "";
	string StringQuit = "";
	bool bIsInputAString = false;

	char PlayMoreOrQuit = ' ';
	char Expression = ' ';
	double ValueOne = 0;
	double ValueTwo = 0;
	double ExpressionResult = 0;
	bool bInvalidExpression = false;
	bool bIsNumberOneDigit = false;

	std::cout << "------------------------    CALCULATOR     --------------------------"	<< std::endl;
	std::cout << "Supports +,-,/,* - add, substract, div, multi"							<< std::endl;
	std::cout << "Use only chars above and numbers 0-9, or floating numbers (e.g.: 1.3)"	<< std::endl;
	std::cout << "Use can use string equivalent for numbers 0-9, like zero, one, two etc."	<< std::endl;
	std::cout << "Enter first two value then one of +,-,/,*"								<< std::endl;
	std::cout << "---------------------------------------------------------------------"	<< std::endl;
	do
	{
		//cin.clear();

		/// This cin.ignore clears, flushes the console stdinput, this is the only solution the works for now
		/// Because of this we must hit enter before the program starts
		/// There is a cin.fail()  method for cin, but do not know how to implement it. 
		/// Besides the first enter glitch the program works well.
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // This is a MUST HAVE implementation
		
				
		ValueOne = 0;
		ValueTwo = 0;
		/*StringStreamInputOne = "";
		StringStreamInputTwo = "";*/
		bInvalidExpression = false;
		bIsNumberOneDigit = false;
		bIsInputAString = false;
		StringIntFindHelper = 0;

		/*StringStreamInputOne.clear();
		StringStreamInputTwo.clear();
		StringQuit.clear();*/

		std::cout << "\nEnter first value, either use integer 0 - 9 digits, or string zero - nine: ";
		std::getline(cin, StringStreamInputOne); //std::cin >> ValueOne;
		std::cout << "Enter second value either use integer 0 - 9 digits, or string zero - nine: ";
		std::getline(cin, StringStreamInputTwo); //std::cin >> ValueTwo;

		/// Convert string number input to integer - did not checked input string validity.
		/// Takes to much time and no need for solving this exercise. 
		for (string Numbers : NumbersToString)
		{
			if (Numbers == StringStreamInputOne)
			{
				ValueOne = StringIntFindHelper;
				bIsInputAString = true;
			}
			if (Numbers == StringStreamInputTwo)
			{
				ValueTwo = StringIntFindHelper;
				bIsInputAString = true;
			}
			StringIntFindHelper++;
		}
		///  END - Convert string number input to integer 

		/// Checking invalid number input  
		if (!bIsInputAString)
		{
			stringstream(StringStreamInputOne) >> ValueOne;
			stringstream(StringStreamInputTwo) >> ValueTwo;
		}
		if ((ValueOne <= 9 && ValueTwo <= 9) && (ValueOne >= 0 && ValueTwo >= 0))
		{
			bIsNumberOneDigit = true;
		}
		else { bIsNumberOneDigit = false; }

		while (!bIsNumberOneDigit)
		{
			std::cout << "\nEnter only digits from 0  - 9!";
			std::cout << "Enter first value, either use integer 0 - 9 digits, or string zero - nine: ";
			std::getline(cin, StringStreamInputOne); //std::cin >> ValueOne;
			std::cout << "Enter second value either use integer 0 - 9 digits, or string zero - nine: ";
			std::getline(cin, StringStreamInputTwo); //std::cin >> ValueTwo;
			
			for (string Numbers : NumbersToString)
			{
				if (Numbers == StringStreamInputOne)
				{
					ValueOne = StringIntFindHelper + 1;
					bIsInputAString = true;
				}
				if (Numbers == StringStreamInputTwo)
				{
					ValueTwo = StringIntFindHelper + 1;
					bIsInputAString = true;
				}
				StringIntFindHelper++;
			}

			if (!bIsInputAString)
			{
				stringstream(StringStreamInputOne) >> ValueOne;
				stringstream(StringStreamInputTwo) >> ValueTwo;
			}
			if ((ValueOne <= 9 && ValueTwo <= 9) && (ValueOne >= 0 && ValueTwo >= 0))
			{
				bIsNumberOneDigit = true;
			}
		}
		 ///checking invalid number input  - END

		std::cout << "\nEnter on of +,-,/,* expression: ";
		std::cin >> Expression;
		//Expression = '+';

		/// checking invalid input - there are maybe better solutins 
		/// bInvalidExpression initialized false
		if (Expression == '+' || Expression == '-' || Expression == '*' || Expression == '/')
		{
			bInvalidExpression = true;
		}
		else { bInvalidExpression = false; }
		while (!bInvalidExpression)
		{
			std::cout << "\nInvalid input please try again!";
			std::cout << "Enter on of +,-,/,* expression: ";
			cin >> Expression;
			if (Expression == '+' || Expression == '-' || Expression == '*' || Expression == '/')
			{
				bInvalidExpression = true;
			}
		}
		/// checking invalid input - END

		/// we should using switch - but switch only accepts enum or int - can not figure it out now
		/// it may works with char type for +  -  * /
		if (Expression == '+')
		{
			ExpressionResult = ValueOne + ValueTwo;
			std::cout << ValueOne << " + " << ValueTwo << " = " << ExpressionResult << "\n ";
		}
		else if (Expression == '-')
		{
			ExpressionResult = ValueOne - ValueTwo;
			std::cout << ValueOne << " - " << ValueTwo << " = " << ExpressionResult << "\n ";
		}
		else if (Expression == '*')
		{
			ExpressionResult = ValueOne * ValueTwo;
			std::cout << ValueOne << " * " << ValueTwo << " = " << ExpressionResult << "\n ";
		}
		else if (Expression == '/')
		{
			if (ValueTwo == 0 || ValueTwo == 0.0)
			{
				std::cout << "can not divide with ZERO! ";
			}
			else
			{
				ExpressionResult = ValueOne / ValueTwo;
				std::cout << ValueOne << " / " << ValueTwo << " = " << ExpressionResult << "\n ";
			}
		}

		std::cout << "\nTo quit hit: \"q\" or anything else to play more: ";
		std::cin >> PlayMoreOrQuit;
		//PlayMoreOrQuit = 'q';
	} while (PlayMoreOrQuit != 'q');
}

//##########################################################################################
//##						 GAME OF CHESS - Exercise 8, 9							###
//##########################################################################################
void GameOfChess()
{
	int SquareWeAreAt = 1;
	//int NumberOfGrainsForCurrentSquare = 1;
	double NumberOfGrainsForCurrentSquare = 1;
	int TrackAllGrains = 0;
	bool bIsTrackAllGrainsPassedAThousand = false;
	bool bIsTrackAllGrainsPassedMillion = false;
	bool bIsTrackAllGrainsPassedBillion = false;

	while (SquareWeAreAt <= 1100)
	{
		std::cout << "Number of NumberOfGrainsForCurrentSquare: " << NumberOfGrainsForCurrentSquare << std::endl;
		NumberOfGrainsForCurrentSquare =  pow(2, SquareWeAreAt);
		//std::cout << "\nNumber of TrackAllGrains: " << TrackAllGrains << std::endl;
		TrackAllGrains += NumberOfGrainsForCurrentSquare;
		//std::cout << "\nNumber of SquareWeAreAt: " << SquareWeAreAt << std::endl;
		
		if (TrackAllGrains >= 1000 && !bIsTrackAllGrainsPassedAThousand)
		{
			std::cout << "Number of squares " << SquareWeAreAt << " Number of grains: " << TrackAllGrains << std::endl;
			bIsTrackAllGrainsPassedAThousand = true;
		}
		if (TrackAllGrains >= 1000000 && !bIsTrackAllGrainsPassedMillion)
		{
			std::cout << "Number of squares " << SquareWeAreAt << " Number of grains: " << TrackAllGrains << std::endl;
			bIsTrackAllGrainsPassedMillion = true;
		}
		if (TrackAllGrains >= 1000000000 && !bIsTrackAllGrainsPassedBillion)
		{
			std::cout << "Number of squares " << SquareWeAreAt << " Number of grains: " << TrackAllGrains << std::endl;
			bIsTrackAllGrainsPassedBillion = true;
		}
		SquareWeAreAt++;
	}	
}

//##########################################################################################
//##						ROCK, PAPER, SCISSORs - Exercise 10						###
//##########################################################################################
void RockPaperScissors()
{
	///  use switch to solve 
	///  machine should give random answer
	/// build integer vector with 0,1,2 value reffered to rock, paper, or scissors
	/// 1 = rock, 2 = paper, 3 = scissor

	vector<int> EnemyBets = { 1, 2, 1, 3, 2, 1, 2, 3, 2, 2, 3, 1, 2, 3, 3, 3, 1, 2, 1, 2,
								3, 3, 2, 1, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1, 2, 3, 3, 2 };
	int YourBet = 0;

	for (int Bet : EnemyBets)
	{
		std::cout << "\nYour bet, choose 1 = rock, 2 = paper, 3 = scissor: " << std::endl;
		std::cin >> YourBet;
		switch (YourBet)
		{
		case 1:
			if (Bet == 1)
			{
				std::cout << "Noone won!" << std::endl;
			}
			else if (Bet == 2)
			{
				std::cout << "You lost!" << std::endl;		
			}
			else if (Bet == 3)
			{
				std::cout << "You won!" << std::endl;

			}
			break;
		case 2:
			if (Bet == 2)
			{
				std::cout << "Noone won!" << std::endl;
			}
			else if (Bet == 1)
			{
				std::cout << "You won!" << std::endl;
			}
			else if (Bet == 3)
			{
				std::cout << "You lost!" << std::endl;
			}
			break;
		case 3:
			if (Bet == 3)
			{
				std::cout << "Noone won!" << std::endl;
			}
			else if (Bet == 1)
			{
				std::cout << "You lost!" << std::endl;
			}
			else if (Bet == 2)
			{
				std::cout << "You won!" << std::endl;
			}
			break;
		default:
			std::cout << "Invalid bet!" << std::endl;
		}
	}
}
//##########################################################################################
//##						FIND PRIME NUMBERS - Exercise 11						###
//##########################################################################################
void FindPrimeNumbers()
{
	/// find primes between 1 to 100
	/// can be devided by prime number smaler then itself
	vector<int> PrimeNumbers;
	bool bIsPrime = true;
	int MAX_TRY_PRIME_NUMBER = 0;

	std::cout << "Enter max number for loop to find prime: " << std::endl;
	std::cin >> MAX_TRY_PRIME_NUMBER;
	
	for (int PrimeLoop = 1; PrimeLoop <= MAX_TRY_PRIME_NUMBER; PrimeLoop++)
	{
		bIsPrime = true;
		if (PrimeLoop == 1)
		{
			bIsPrime = false;
		}
		for (int Prime : PrimeNumbers)
		{
			//std::cout << "Prime: " << Prime << std::endl;
			if ((PrimeLoop % Prime) == 0)
			{
				bIsPrime = false;
			}		
		}
		if (bIsPrime)
		{
			PrimeNumbers.push_back(PrimeLoop);
		}
	}

	for (int Prime : PrimeNumbers)
	{
		std::cout << "Prime: " << Prime << std::endl;
	}

}

//##########################################################################################
//##						MAIN													###
//##########################################################################################
int main()
{

	FindPrimeNumbers();

	return 0;
}
