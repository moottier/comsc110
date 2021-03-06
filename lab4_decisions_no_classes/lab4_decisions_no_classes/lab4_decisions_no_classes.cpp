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
using namespace std;

const float A_BASE_RATE = 9.95, A_OVERAGE_RATE = 1.00;
const float B_BASE_RATE = 14.95, B_OVERAGE_RATE = 2.00;
const float C_BASE_RATE = 19.95;

const int A_HOURS = 10;
const int B_HOURS = 20;

string promptForPlan()
{
	string userInput;

	cout << "Please input your package name (A, B, or C) as it is shown." << endl;
	getline(cin, userInput);
	stringstream(userInput) >> userInput;

	return userInput;
};

string promptForHours()
{
	string userInput;

	cout << "Please input how many hours you've used this month." << endl;
	getline(cin, userInput);
	stringstream(userInput) >> userInput;

	return userInput;
};

int main()
{
	string userInputPlan,
		   userInputHours;

	char   parsedPlan,
		   validatedPlan;
	float  validatedHours;

	bool   isGoodInput = false;
	
	
	float  moneyOwed,
		   aOwed,
		   bOwed,
		   maxPotentialSavings;
	
	cout << "Hi, welcome to Komsplats billing service." << endl << endl;
	userInputPlan = promptForPlan();

	while (!isGoodInput)
	{
		while (userInputPlan.length() != 1)
		{
			userInputPlan = promptForPlan();
		};

		parsedPlan = toupper(userInputPlan.at(0));		
		switch (parsedPlan)
		{
		case 'A':
			break;
		case 'B':
			break;
		case 'C':
			break;
		default:
			userInputPlan = promptForPlan();
		};
		validatedPlan = parsedPlan;
		isGoodInput = true;
	};
	
	cout << endl << "Now, let's see how much you owe us!" << endl; 
	userInputHours = promptForHours();
	
	while ( 
		(userInputHours.find_first_not_of("123456789.") != string::npos) &&
		(count(userInputHours.begin(), userInputHours.end(), '.') > 1) // FIXME passing strings breaks on this line
		)
	{
		// FIXME check that hours given is not more than hours in month
		userInputHours = promptForHours();
	};
	
	validatedHours = stof(userInputHours);

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

	cout << endl << "You owe us $" << moneyOwed << endl; // FIXME use fixed and setprecision to ensure proper formatting here
	if (maxPotentialSavings > 0.0) cout << "You could save $" << maxPotentialSavings // FIXME use fixed and setprecision to ensure proper formatting here
		<< " by switching to plan " << (moneyOwed > 19.95 ? 'C' : 'B') << endl;

	return 0;
};