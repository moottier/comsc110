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

using namespace std;

int main()
{
	string userHours;
	float moneyOwed;

	cout << "Welcome to the Komsplast Billing Tool.\n";
	CPackage myPackage; // creates class instance with minimal constructor
	moneyOwed = myPackage.getOwed();
	cout << moneyOwed;

};


