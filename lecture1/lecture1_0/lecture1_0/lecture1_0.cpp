// lecture1_0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;
const int AR_SIZE = 10;

int main()
{
	string s1, name;
	int hours, minutes;
	char c;

	cout << "please input the time as hh:mm and your name";
	getline(cin, s1);
	stringstream(s1) >> hours >> c >> minutes >> name;

	hours += 10;
	minutes += 1;

	cout << endl << "it is " << hours << " hours and " 
		<< minutes << " minutes and your are " << name << endl;

    return 0;
}

