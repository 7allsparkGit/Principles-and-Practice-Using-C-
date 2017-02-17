#include "std_lib_facilities.h" 
//#include <stdlib.h> 


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
//##						FIND PRIME NUMBERS 2 - Exercise 12	- 14					###
//##########################################################################################
void FindPrimeNumbersSecondEdition()
{
	/// vector<bool> primenumbers; // can not convert to bool ERROR
	int max_try_prime_number = 100; 
	bool *isComposite = new bool[max_try_prime_number + 1 ];
	memset(isComposite, false, sizeof(bool) * (max_try_prime_number + 1));

	bool bisprime = true;

	int upperBoundSquareRoot = (int)sqrt((double)max_try_prime_number);
	
	/// Commented out because of vector<bool> error
	/*for (int primeloop = 1; primeloop <= max_try_prime_number; primeloop++)
	{
		bisprime = true;
		primenumbers.push_back(false);	
	}*/

	for (int m = 1; m <= max_try_prime_number; m++)
	{
		if (m == 1)
		{
			isComposite[m] = true;
		}
		if (!isComposite[m])
		{
			for (int k = m * m; k <= max_try_prime_number; k += m)
			{
				isComposite[k] = true;
			}
		}
	}
	for (int x = 1; x <= max_try_prime_number; x++)
	{
		if (!isComposite[x])
			cout << x << " ";
	}
	

}

//##########################################################################################
//#							FIND MODE 2 - Exercise 16								###
//##########################################################################################
void FindMode()
{
	vector<int> RandomNumbersVector;
	//int RandomNumbersVector[] = { 1, 2, 3, 4 ,4, 4, 5,5, 5,5  };
	int ModeMostItem = 0;
	int ModeItem = 0;
	int VectorSize = 20;
	int CounterMode = 0;
	int LastElementOfArray = 0;

	for (int Counter = 0; Counter < VectorSize; Counter++)
	{
		RandomNumbersVector.push_back(rand() % 10 + 1);
	}
	sort(RandomNumbersVector.begin(), RandomNumbersVector.end());
	
	/// Find mode - the array is sorted, there maybe less resource expansive algorythm
	for (unsigned n = 1; n < 10; n++)
	{
		if (RandomNumbersVector[n] == RandomNumbersVector[n - 1])
		{
			CounterMode++;
			std::cout << "\nCounterMode " << CounterMode << std::endl;
		}
		else
		{
			if (ModeMostItem < CounterMode)
			{
				ModeMostItem = CounterMode;
				ModeItem = RandomNumbersVector[n-1];
			}
			CounterMode = 0;
		}
		LastElementOfArray = n;
	}
	/*/// checking last element
	if (RandomNumbersVector[LastElementOfArray - 1] == RandomNumbersVector[LastElementOfArray])
	{

	}*/
	
	std::cout << "\nMode " << ModeItem << std::endl;
	
	for (int Nums : RandomNumbersVector)
	{
		std::cout << " " << Nums;
	}
	std::cout << std::endl;
}

//##########################################################################################
//#				FIND MIN,MAX,MODE of strings 2 - Exercise 17							###
//##########################################################################################
//  TODO !!!!!  This whole program may could be made with pointers for the more efficiency
	// MaxLocal and MinLocal could be replaced with pointer and even maybe the 
	// MinMaxString.MinElement,  MinMaxString.MaxElement variables. 
	// using variable assignments all the time seems havey resource lake. Maybe some day I gonna try to do it with pointers 
		
void FindMinMaxModeOfAString()
{
	struct MinMaxString
	{
		string MinElement;
		string MaxElement;
	};
	
	string StringVectorInitz[] = { "proba", "makkos", "kerika",  "cicamica", "kerika", "kerika", "zizotop" };
	int EndOfStringArray = 0; // size of the string
	int StartOfStringArray = 0;
	int SizeOfStringArray = 0;
	int ArrayIndex = 0;
	string MaxLocal = " ";
	string MinLocal = " ";
	int CounterMode = 0;
	int ModeMostItem = 0;
	string ModeStringItem = ""; 
	int LastElementOfArray = 0;
	/// MIN MAX elemetn of array: sorting is expansive in terms of processor and memory copy, and maybe calc times
	/// but it may required once for an array to be sorted
	/// then a new element can be placed to the right place of the array. 
	SizeOfStringArray = sizeof(StringVectorInitz) / sizeof(StringVectorInitz[0]);
	EndOfStringArray = SizeOfStringArray - 1;

	std::cout << "\nZ: " << EndOfStringArray << std::endl;
	std::cout << "\nFirst element of the array: " << StringVectorInitz[0] << "\nlast element of the array: " << StringVectorInitz[size(StringVectorInitz) - 1] << std::endl;

	//std::cout << "\nFirst element of the array: " << (StringVectorInitz[2] > StringVectorInitz[3]) << std::endl;

	/// MIN MAX element of array: another way to find is an algorythm that finds min, max in 3n/2 number of comparisons.
	/// the algorythm processes the elements in pairs 
	
	// check values := std::cout << "\nFirst element of the array: " << SizeOfStringArray << std::endl;
	/// checking whether the array size is even or odd - we assume the start element is of array index [0]
	SizeOfStringArray = EndOfStringArray - StartOfStringArray + 1;
	EndOfStringArray = SizeOfStringArray - 1;

	MinMaxString MinMaxString;

	if (SizeOfStringArray % 2 != 0)
	{
		MinMaxString.MinElement = StringVectorInitz[StartOfStringArray];
		MinMaxString.MaxElement = StringVectorInitz[StartOfStringArray];

		ArrayIndex = StartOfStringArray + 1;
	}
	else
	{
		if (StringVectorInitz[StartOfStringArray] < StringVectorInitz[StartOfStringArray + 1])
		{
			MinMaxString.MinElement = StringVectorInitz[StartOfStringArray];
			MinMaxString.MaxElement = StringVectorInitz[StartOfStringArray + 1];
		}
		else
		{
			MinMaxString.MinElement = StringVectorInitz[StartOfStringArray + 1];
			MinMaxString.MaxElement = StringVectorInitz[StartOfStringArray];
		}
		ArrayIndex = StartOfStringArray + 2;
	}

	for (int Index = ArrayIndex; Index < SizeOfStringArray - 1; Index += 2)
	{
		if (StringVectorInitz[Index] < StringVectorInitz[Index + 1])
		{
			MinLocal = StringVectorInitz[Index];
			MaxLocal = StringVectorInitz[Index + 1];
		}
		else
		{
			MinLocal = StringVectorInitz[Index + 1];
			MaxLocal = StringVectorInitz[Index];
		}
		if (MinLocal < MinMaxString.MinElement)
		{
			MinMaxString.MinElement = MinLocal;
		}
		if (MaxLocal > MinMaxString.MaxElement)
		{
			MinMaxString.MaxElement = MaxLocal;
		}
	}

	std::cout << "\nMin: " << MinMaxString.MinElement << "\nMax: " << MinMaxString.MaxElement << std::endl;
	
	/// Find mode of String Array,
	/// the array is sorted at this point, there maybe less resource expansive algorythm though
	
	//sort(StringVectorInitz[0], StringVectorInitz[SizeOfStringArray]);
	std::sort(std::begin(StringVectorInitz), std::end(StringVectorInitz));
	for (unsigned Counter = 1; Counter < SizeOfStringArray; Counter++)
	{
		/// checking elements one other 
		if (StringVectorInitz[Counter] == StringVectorInitz[Counter - 1])
		{
			CounterMode++;
		}
		else
		{
			if (ModeMostItem < CounterMode)
			{
				ModeMostItem = CounterMode;
				ModeStringItem = StringVectorInitz[Counter - 1];
			}
			CounterMode = 0;
		}
		//LastElementOfArray = Counter;
	}
	/*/// checking last element
	if (RandomNumbersVector[LastElementOfArray - 1] == RandomNumbersVector[LastElementOfArray])
	{

	}*/
	std::cout << "\nMode " << ModeStringItem << std::endl;

}

//##########################################################################################
//##					Quadratic formula - Exercise 18									###
//##########################################################################################
void QuadraticFormula()
{
	double a = 0;
	double b = 0;
	double c = 0;
	double XOne = 0;
	double XTwo= 0;
	double Determinant = 0;
	double RealPart = 0;
	double ImaginaryPart = 0;
	
	

	std::cout << "\nEnter a: " << std::endl;
	std::cin >> a;
	std::cout << "\nEnter b: " << std::endl;
	std::cin >> b;
	std::cout << "\nEnter c: " << std::endl;
	std::cin >> c;	
	
	Determinant = b*b - 4 * a*c;
	
	if (Determinant > 0) {
		XOne = (-b + sqrt(Determinant)) / (2 * a);
		XTwo = (-b - sqrt(Determinant)) / (2 * a);
		cout << "Roots are real and different." << endl;
		cout << "x1 = " << XOne << endl;
		cout << "x2 = " << XTwo << endl;
	}
	else if (Determinant == 0) {
		cout << "Roots are real and same." << endl;
		XOne = (-b + sqrt(Determinant)) / (2 * a);
		cout << "x1 = x2 =" << XOne << endl;
	}
	else {
		RealPart = -b / (2 * a);
		ImaginaryPart = sqrt(-Determinant) / (2 * a);
		cout << "Roots are complex and different." << endl;
		cout << "x1 = " << RealPart << "+" << ImaginaryPart << "i" << endl;
		cout << "x2 = " << RealPart << "-" << ImaginaryPart << "i" << endl;
	}

	XOne = (b + sqrt(Determinant)) / (2 * a);
	XTwo = (b - sqrt(Determinant)) / (2 * a);

	std::cout << "\nOne: " << XOne << "\tTwo: "  << XTwo << std::endl;
}

//##########################################################################################
//##					Name-and-value pairs - Exercise 19,20,21.						###
//##########################################################################################
void NameAndValuePairs()
{
	string Name = "";
	int Score = 0;
	int ScoreInt = 0;
	bool bIsNameScoreUniqueError = true;
	bool bIsNameFound = false;
	bool bIsScoreFound = false;
	vector<string> Names;
	vector<int> Scores;
	int NameScoreCounter = 0;
	int WhileCounter = 0;
	

	/*std::cout << "\nEnter name: " << std::endl;
	std::cin >> Name;
	std::cout << " Enter score: " << std::endl;
	std::cin >> Score;*/

	/// exercise 19
	// -------------------------------------------------------------------------------
	while (Name != "NoName")
	{
		//RESET
		Score = 0;
		Name = "";

		bIsNameScoreUniqueError = true;
		std::cout << "\nEnter name: " << std::endl;
		std::cin >> Name;
		std::cout << "\nEnter score: " << std::endl;
		if (Name != "NoName") { std::cin >> Score; }

		if ( ((Name == "") || (Score == 0)) && Name != "NoName")
		{	
			bIsNameScoreUniqueError = false;
			std::cout << "Please provide valid input and try again!";
			Score = 0;
			Name = "";
		}
		if (Name != "NoName") {
			for (string NameVector : Names)
			{
				if (Name == NameVector)
				{
					bIsNameScoreUniqueError = false;
				}
			}
		}
		if(bIsNameScoreUniqueError && Name != "NoName")
		{
			Names.push_back(Name);
			Scores.push_back(Score);
		}
	}

	/// exercise 20
	// -------------------------------------------------------------------------------
	std::cout << "\nSeacrh for a name: " << std::endl;
	std::cin >> Name;
	while (Name != "NoName")
	{
		/// RESET 
		bIsNameFound = false;
		WhileCounter = 0;
		while ((bIsNameFound == false) && (WhileCounter < (Names.size())))
		{
			if (Name == Names[WhileCounter])
			{
				bIsNameFound = true;
				Score = WhileCounter;
			}
			//else { bIsNameFound = true; }
			WhileCounter++;
		}
		
		if (bIsNameFound)
		{
			std::cout << "\nName: " << Name << " Scores: " << Scores[Score] << std::endl;
		}
		else { std::cout << "\nName not found: " << std::endl; }

		std::cout << "\nSeacrh for a name: " << std::endl;
		std::cin >> Name;
	}

	/// exercise 21
	// -------------------------------------------------------------------------------
	std::cout << "\nSeacrh for a score: " << std::endl;
	std::cin >> ScoreInt;

	while (ScoreInt != 0)
	{
		/// RESET 
		bIsScoreFound = false;
		WhileCounter = 0;
		if (ScoreInt != 0) {
			while (WhileCounter < Scores.size())
			{
				if (Scores[WhileCounter] == ScoreInt)
				{
					//bIsScoreFound = true;
					std::cout << "Name: " << Names[WhileCounter] << " Score: " << ScoreInt << "\t" << std::endl;
				}
				//else { std::cout << "\Score not found: " << std::endl; }
				WhileCounter++;
			}
		}

	std::cout << "\nSeacrh for a score: " << std::endl;
	std::cin >> ScoreInt;
	}
}



//##########################################################################################
//##						MAIN													###
//##########################################################################################
int main()
{

	NameAndValuePairs();

	return 0;
}
