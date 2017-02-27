#include "std_lib_facilities.h" 

//##########################################################################################
//##					lowest, highest, and average temperature						###
//##########################################################################################
int LowHighAvgTemprature()
{
	vector<double> temps; // temperatures

	for (double temp; std::cin >> temp; ) // read and put into temps
		temps.push_back(temp);

	double sum = 0;
	double high_temp = 0;
	double low_temp = 0;

	high_temp = temps[0];
	low_temp = temps[0];

	for (double x : temps)
	{
		if (x > high_temp) high_temp = x; // find high
		if (x < low_temp) low_temp = x; // find low
		sum += x; // compute sum
	}
	std::cout << "High temperature: " << high_temp << '\n';
	std::cout << "Low temperature: " << low_temp << '\n';
	std::cout << "Average temperature: " << sum / temps.size() << '\n';

	return 0;
}


//##########################################################################################
//##					Celsius to Kelvin converter - Exercises 2	 					##
//##########################################################################################
double Ctok(double c) // converts Celsius to Kelvin
	{
		double k = c + 273.15;
		return k;
	}
/// unkomment main Main for this, then comment it back after testing it!
//int main()
//{
//	double c = 0; // declare input variable
//	std::cin >> c; // retrieve temperature to input variable
//	double k = ctok(c); // convert temperature
//	std::cout << k << "\n"; // print out temperature
//
//	return 0;
//}


//##########################################################################################
//##					Celsius to Kelvin converter - Exercises 2,3,4, 5				##
//##########################################################################################
//double ctok(double c) // converts Celsius to Kelvin
//{
//	double k = c + 273.15;
//	return k;
//}
//
///// uncomment main Main for this, then comment it back after testing it!
//int main()
//{
//	
//	double c = 0; // declare input variable
//	std::cin >> c; // retrieve temperature to input variable
//	double k = ctok(c); // convert temperature
//	if (k < -273.15) 
//	{	
//		error("area() pre-condition");
//	}
//	std::cout << k << "\n"; // print out temperature
//
//	return 0;
//}


/// same program throw error with throw instead of errors
//class Too_low_value {};
//
//double ctok(double c) // converts Celsius to Kelvin
//{
//	double k = c + 273.15;
//	return k;
//}
//
///// uncomment main Main for this, then comment it back after testing it!
//int main()
//{
//	double c = 0; // declare input variable
//	/// abort program in case of bad input type
//	if (!std::cin) error("couldn't read a double!");
//	double k = 0;
//
//	try {
//		
//		std::cin >> c; // retrieve temperature to input variable
//		if (!std::cin) cerr << "couldn't read a double!";
//		else k = ctok(c); // convert temperature
//		if (k < -273.15) {
//			throw Too_low_value();
//		}
//		std::cout << k << "\n"; // print out temperature
//	}
//	catch (Too_low_value){
//		std::cout << "Oops the kelvin is too low!\n";
//	}
//	return 0;
//}


/// same program handle errors inside CtokTwo
//class Too_low_value {};
//
//double CtokTwo(double c) // converts Celsius to Kelvin
//{
//	//double k = 0;
//
//	double k = c + 273.15;
//	try {
//		if (k < -273.15) {
//			throw Too_low_value();
//		}
//	}
//	catch (Too_low_value) {
//		std::cout <<  "Kelvin is too low!\n"; // print out temperature
//		error("Too low input");
//		return 1;
//	}
//	return k;
//}
//
//double KtoC(double kelvin) // converts Celsius to Kelvin
//{
//	//double k = 0;
//	double celsius = 0;
//	
//	try {
//		celsius = kelvin - 273.15;
//		if (kelvin < -273.15) {
//			throw Too_low_value();
//		}
//	}
//	catch (Too_low_value) {
//		std::cout << "Kelvin is too low!\n"; // print out temperature
//		error("Too low input");
//		return 1;
//	}
//	return celsius;
//}
//
//
///// uncomment main Main for this, then comment it back after testing it!
//// main handles input error also, but it is optional
//int main()	
//{
//	char KelvinOrCelsius = ' ';
//	double k = 0;
//	double c = 0; // declare input variable
//				  /// abort program in case of bad input type
//	
//	std::cout << "Type 'k' to convert from Celsius to Kelvin or 'c' to convert from Kelvin to Celsius: \n";
//	std::cin >> KelvinOrCelsius;
//
//	if (KelvinOrCelsius == 'k') 
//	{
//		std::cout << "\nEnter the amount you do want to convert: ";
//		std::cin >> c; // retrieve temperature to input variable
//	
//		if (!std::cin) 
//		{
//			std::cout << "only numbers!\n"; // print out temperature
//			error("couldn't read a double!");
//		}
//		if (!std::cin) cerr << "couldn't read a double!";
//
//		k = CtokTwo(c); // convert temperature
//
//		std::cout << k << " is the calculated Kelvin!";
//	}
//	else if (KelvinOrCelsius == 'c')
//	{
//		std::cout << "\nEnter the amount you do want to convert: ";
//		std::cin >> c; // retrieve temperature to input variable
//
//		if (!std::cin)
//		{
//			std::cout << "only numbers!\n"; // print out temperature
//			error("couldn't read a double!");
//		}
//		if (!std::cin) cerr << "couldn't read a double!";
//
//		k = KtoC(c); // convert temperature
//
//		std::cout << k << " is the calculated Celsius!";
//
//	}
//	else std::cout << "Next time try appropriate input!";
//	return 0;
//}

//##########################################################################################
//##					Fahrenheit - Celsius converter - Exercises 6	 ##
//##########################################################################################
class Too_low_value {};

double CelsiusToFahreinheit(double Celsius) // converts Celsius to Kelvin
{
	//double k = 0;
	double Fahreinheit = 0;
	
	try {
		Fahreinheit = 9.0/5 * Celsius + 32;
		if (Fahreinheit < -459.67) {
			throw Too_low_value();
		}
	}
	catch (Too_low_value) {
		std::cout << "Fahrenheit is too low!\n"; // print out temperature
		error("Too low input");
		return 1;
	}
	return Fahreinheit;
}

double FahreinheitToCelsius(double Fahrenheit) // converts Celsius to Kelvin
{
	//double k = 0;
	double Celsius = 0;

	try {
		Celsius = (Fahrenheit - 32) * 5/9;
		if (Celsius < -273.15) {
			throw Too_low_value();
		}
	}
	catch (Too_low_value) {
		std::cout << "Celsius is too low!\n"; // print out temperature
		error("Too low input");
		return 1;
	}
	return Celsius;
}

/// uncomment main Main for this, then comment it back after testing it!
// main handles input error also, but it is optional
void ProgramFahreinheitToCelsius()
{
	char FahrToCelsius = ' ';
	double f = 0;
	double c = 0; // declare input variable
				  /// abort program in case of bad input type
	
	std::cout << "Type 'f' to convert from Celsius to Fahrenheit or 'c' to convert from Fahrenheit to Celsius: \n";
	std::cin >> FahrToCelsius;

	if (FahrToCelsius == 'f')
	{
		std::cout << "\nEnter the amount you do want to convert: ";
		std::cin >> c; // retrieve temperature to input variable
	
		if (!std::cin) 
		{
			std::cout << "only numbers!\n"; // print out temperature
			error("couldn't read a double!");
		}
		if (!std::cin) cerr << "couldn't read a double!";

		f = CelsiusToFahreinheit(c); // convert temperature

		std::cout << f << " is the calculated Fahrenheit!";
	}
	else if (FahrToCelsius == 'c')
	{
		std::cout << "\nEnter the amount you do want to convert: ";
		std::cin >> f; // retrieve temperature to input variable

		if (!std::cin)
		{
			std::cout << "only numbers!\n"; // print out temperature
			error("couldn't read a double!");
		}
		if (!std::cin) cerr << "couldn't read a double!";

		c = FahreinheitToCelsius(f); // convert temperature

		std::cout << c << " is the calculated Celsius!";

	}
	else std::cout << "Next time try appropriate input!";
}

//##########################################################################################
//##					 quadratic formula - Exercises 7	 ##
//##########################################################################################
void RootsOfQuadraticEquation(double a, double b, double c)
{

}


//##########################################################################################
//##						MAIN													###
//##########################################################################################
int main()
{
	ProgramFahreinheitToCelsius();

	return 0;
}
