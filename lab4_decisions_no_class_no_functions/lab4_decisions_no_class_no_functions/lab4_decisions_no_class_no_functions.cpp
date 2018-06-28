/*****************************************************************************************
Problem:
Description:

Name: Andre Mottier
ID:   1742339
Date:

Status: in progress
*****************************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

const double A_BASE_RATE = 9.95,  A_OVERAGE_RATE = 2.00;
const double B_BASE_RATE = 14.95, B_OVERAGE_RATE = 1.00;
const double C_BASE_RATE = 19.95;
const int    A_HOURS = 10;
const int    B_HOURS = 20;

const int    SHORT_MONTH_HOURS = 672;
const int    MED_MONTH_HOURS = 720;
const int    LONG_MONTH_HOURS = 744;


int main()
{
	string userInputPlan;
	string userInputMonth;
	string userInputHours;


	char   parsedPlan;
	char   validatedPlan;
	double validatedHours;

	bool   isGoodPlan;
	bool   isGoodHours = false;

	int    hoursInMonth;
	int    decimalPosition;

	double moneyOwed;
	double aOwed;
	double bOwed;
	double maxPotentialSavings;

	cout << "Hi, welcome to Komsplats billing service." << endl;
	cout << "Please input your package name (A, B, or C) as it is shown." << endl;
	getline(cin, userInputPlan);
	stringstream(userInputPlan) >> userInputPlan;

	parsedPlan = toupper(userInputPlan.at(0));

	switch (parsedPlan)
	{
	case 'A':
	case 'B':
	case 'C':
		isGoodPlan = true;
		validatedPlan = parsedPlan;
	default:
		cout << "You entered an invalid plan name. Please restart the program." << endl;
		isGoodPlan = false;
	};

	if (isGoodPlan)
	{
		cout << endl << "Now, let's see how much you owe us!" << endl;
		cout << "Which month's bill would you like to check? (Please capitalize the month)" << endl;
		getline(cin, userInputMonth);
		stringstream(userInputMonth) >> userInputMonth;

		cout << "Please input how many hours you've used this month." << endl;
		getline(cin, userInputHours);
		stringstream(userInputHours) >> userInputHours;
		
		decimalPosition = (userInputHours.find('.') == string::npos ? 0 : userInputHours.find('.'));
	};

	if (
		(isGoodPlan) &&
		// tried just using (userInputHours.find_first_not_of("123456789.") != string::npos, but the find_first_not_of function was unexpectedly returning large numbers
		// added 'or' condition as workaround
		(userInputHours.find_first_not_of("123456789.") >= userInputHours.length() || userInputHours.find_first_not_of("123456789.") != string::npos) &&
		(userInputHours.find('.', decimalPosition) == string::npos)
		)
	{	
		isGoodHours = true;
		validatedHours = stof(userInputHours);
		
		switch (userInputMonth == "February" ? 1 : ((userInputMonth == "April") || (userInputMonth == "June") || (userInputMonth == "September") || (userInputMonth == "November") ? 2 : 3))
		{
		case 1:
			(validatedHours > SHORT_MONTH_HOURS ? isGoodHours = false : isGoodHours = true);
			break;
		case 2:
			(validatedHours > MED_MONTH_HOURS ? isGoodHours = false : isGoodHours = true);
			break;
		case 3:
			(validatedHours > LONG_MONTH_HOURS ? isGoodHours = false : isGoodHours = true);
			break;
		};
		cout << (isGoodHours ? "" : "You used more hours than exist in that month. Check your hours and the month and try again.") << endl;
	}
	else 
	{
		cout << "You entered an invalid number of hours. Please run the program again using real numbers." << endl;
	};

	if (isGoodHours)
	{
		aOwed = A_BASE_RATE + (validatedHours > A_HOURS ? (validatedHours - A_HOURS) * A_OVERAGE_RATE : 0.0);
		bOwed = B_BASE_RATE + (validatedHours > B_HOURS ? (validatedHours - B_HOURS) * B_OVERAGE_RATE : 0.0);
		switch (validatedPlan)
		{
		case 'A':
			moneyOwed = aOwed;
			maxPotentialSavings = (moneyOwed > C_BASE_RATE ? moneyOwed - C_BASE_RATE : moneyOwed - bOwed);
			break;
		case 'B':
			moneyOwed = bOwed;
			maxPotentialSavings = moneyOwed - C_BASE_RATE;
			break;
		case 'C':
			moneyOwed = C_BASE_RATE;
			maxPotentialSavings = 0.0;
		}

		cout << endl << "You owe us $" << fixed << setprecision(2) << moneyOwed << endl;
		if (maxPotentialSavings > 0.0) cout << "You could save $" << fixed << setprecision(2) << maxPotentialSavings
			<< " by switching to plan " << (moneyOwed > C_BASE_RATE ? 'C' : 'B') << endl;

	};
	
	return 0;
};