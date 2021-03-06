/*****************************************************************************************
Problem:      Lab 2.1 Working with the cout statement
Description: This program will write the name, address and telephone number of the programmer.

Name: Andre Mottier
ID:   1742339
Date: 6/22/18

Status: complete
*****************************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const string NAME = "Andre Mottier";
const string ADDRESS = "643 Corte Castro", CITY = "Vacaville", STATE = "CA", ZIP = "95688";
const string PHONE = "707-301-1133";

const string PROGRAMMER_LINE_PREFIX = "Programmer: ";
const string TELEPHONE_LINE_PREFIX = "Telephone: ";
const string PRETTY_BORDER = "************";

const int MINIMUM_LEFT_PADDING = PRETTY_BORDER.length() / 2;
const int ADDRESS_LINE_LEFT_PADDING = MINIMUM_LEFT_PADDING + TELEPHONE_LINE_PREFIX.length() + 3;
const int TELEPHONE_LINE_LEFT_PADDING = MINIMUM_LEFT_PADDING + 1;


int main()
{

	cout << PRETTY_BORDER << "\n";

	cout.width(MINIMUM_LEFT_PADDING); cout << "" << 
		PROGRAMMER_LINE_PREFIX << NAME 
		<< "\n";

	cout.width(ADDRESS_LINE_LEFT_PADDING); cout << "" 
		<< ADDRESS << "\n";

	cout.width(ADDRESS_LINE_LEFT_PADDING); cout << ""
		<< CITY << ", " << STATE << " " << ZIP << "\n\n";
	
	cout.width(TELEPHONE_LINE_LEFT_PADDING); cout << "" 
		<< TELEPHONE_LINE_PREFIX << PHONE << "\n\n" 
		<< PRETTY_BORDER << endl;

	return 0;

}