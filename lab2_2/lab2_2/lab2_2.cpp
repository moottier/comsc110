/*****************************************************************************************
Problem:     Lab 2.2 Working with Constants, Variables and the Arithmetic Operators
Description: This program will output the circumference and area of the circle with a given radius.

Name: Andre Mottier
ID:   1742339
Date: 6/22/18

Status: complete
*****************************************************************************************/

#include "stdafx.h"
#include <iostream>

using namespace std;

const  double PI = 3.14;
const  double RADIUS = 5.4;


int main()

{
	double  area;			  	        // definition of area of circle

	int	    circumference;				// definition of circumference

	circumference = 2 * PI * RADIUS;	// computes circumference

	area = PI * pow(RADIUS, 2);        // computes area

	cout << "The circumference of the circle is " << circumference << "\n";
	cout.width(3); cout << ""; cout << "The area of the circle is " << area << endl;

	cout << "\n" << "circumference type is int: The decimal part of the answer is lost." << "\n" 
		<< "when circumference is an int it cannot hold all of the data that results" 
		<< "\n" << "from evaluating the doubles on the right of the statement." 
		<< endl;

	return 0;
}
