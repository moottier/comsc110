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

int main()
{
	string userInputPlan;
	string userInputHours;
	char parsedPlan;
	char validatedPlan;

	cout << "Hi, welcome to Komsplats billing service.\n\n" << endl;
	userInputPlan = promptForPlan();
	parsedPlan = parsePlan(userInputPlan);
	validatedPlan = validatePlan(parsedPlan);

	cout << "Now, let's see how much you owe us!\n" << endl;

}

string promptForPlan()
{
	// asks user for package name
	// discards all but first word, because we only need/want one word
	string userInput;

	cout << "Please input your package name (A, B, C, or D) as it is shown. \n";
	getline(cin, userInput);
	stringstream(userInput) >> userInput; // only store first word

	return userInput;
};

char parsePlan(const string & userInput)
{
	// return the first char of a string as uppercase
	// if string is longer than one letter long the user didn't follow directions
	// prompt user again if they didn't follow directions
	if (userInput.length() != 1) {
		string newUserInput;

		newUserInput = promptForPlan();
		parsePlan(newUserInput);
	};
	char inputPlan = toupper(userInput.at(0));
	
	return inputPlan;
};

char validatePlan(const char & userInput)
{
	// check if char matches any plan names
	// if it is a plan name, return it
	// if first char in string is not a plan, the user didn't follow directions
	// prompt user again if they didn't follow directions

	switch (userInput)
	{
	case 'A':
		break;
	case 'B':
		break;
	case 'C':
		break;
	case 'D':
		break;
	default:
		validatePlan(userInput);
	}

	return userInput;
};

