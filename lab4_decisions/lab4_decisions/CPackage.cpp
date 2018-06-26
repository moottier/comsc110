/*****************************************************************************************
Problem:
Description:

Name: Andre Mottier
ID:   1742339
Date:

Status: in progress
*****************************************************************************************/

#include "CPackage.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

CPackage::CPackage(const char & newPackageName)
{
	setPlan(newPackageName);
};

CPackage::CPackage()
{
	string newPackageName;
	char validatedPackageName;

	newPackageName = promptForPlan();
	validatedPackageName = validatePlan(newPackageName);
	setPlan(validatedPackageName);
	// if new package name is in list of package names then setplan
};

void CPackage::setPlan(const char & newPackageName) {
	packageName = newPackageName;
};

char CPackage::getPlan() const {
	return packageName;
}

float CPackage::getOwed() const
{
	string userHours;
	
	userHours = promptForHours();
	//validatedHours = validateHours(userHours);
	

	return 0.0f;
};

string CPackage::promptForPlan()
{
	string userInput;
	
	cout << "Please select a package (A, B, C, or D) by inputting it's name as shown. \n";
	getline(cin, userInput);
	
	return userInput;
};

string CPackage::promptForHours()
{
	string userInput;

	cout << "Let's figure out how much you owe...\n\n";
	cout << "How many hours did you use this month?\n"; 
	getline(cin, userInput);

	return userInput;
};

char CPackage::validatePlan(const string & userInput)
{
	if (userInput.length() != 1) {
		string newUserInput;
		
		newUserInput = promptForPlan();
		validatePlan(newUserInput);
	};
	
	char inputPlan = userInput.at(0);
	// FIXME verify that char matches an existing plan

	return inputPlan;
};

float CPackage::validateHours(const string & userInput)
{
/*	if (userInput.length() != 1) {
		string newUserInput;

		newUserInput = promptForHours();
		validateHours(newUserInput);
	};
*/


	// if user input a string or char, it will be converted to a float
	float inputHours = userInput.at(0);

	return inputHours;
};

